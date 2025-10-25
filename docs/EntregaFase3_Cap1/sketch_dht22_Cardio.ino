#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// --- Configurações de Rede (Sua) ---
const char* WIFI_SSID = "ZN-BRUNO_CONTER";
const char* WIFI_PASS = "veracruz";

// --- Configurações de MQTT (Sua) ---
const char* MQTT_SERVER = "192.168.1.7";
const char* MQTT_USER = "bruno";
const char* MQTT_PASS = "blurbang";
const char* MQTT_CLIENT_ID = "Ventilador_ESP32C3_Filtro"; 

// --- Configurações de Hardware e Lógica ---
#define DHT_PIN 2       // GPIO 2 no ESP32-C3 (Pino de Dados)
#define RELAY_PIN 4     // GPIO 4 no ESP32-C3
#define DHT_TYPE DHT11

// Limite de temperatura para automação (Em °C)
const float TEMP_LIMITE_AUTO = 28.0; 
// Intervalo de leitura e publicação (Em milissegundos)
const long READ_INTERVAL_MS = 10000; // 60 segundos

// Tópicos MQTT
const char* TOPIC_TEMP = "home/filtro/temperatura";
const char* TOPIC_HUM = "home/filtro/umidade";
const char* TOPIC_CMD = "home/filtro/ventilador/comando";
const char* TOPIC_STATE = "home/filtro/ventilador/estado";

// Instâncias
WiFiClient espClient;
PubSubClient mqttClient(espClient);
DHT dht(DHT_PIN, DHT_TYPE);

// Variável de estado para controle manual/automático
bool isManualControlActive = false;

// --- Funções de Conexão ---
void setupWiFi() {
  Serial.print("\nConectando-se ao WiFi: ");
  Serial.println(WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  // Limita a 20s para conectar e evita loop infinito
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFalha ao conectar ao WiFi. Reinicie o dispositivo.");
    // Aqui seria bom implementar um reset automático ou modo de falha
  }
}

void reconnectMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Tentando conexão MQTT...");
    // Tenta conectar usando ClientID, Username e Password
    if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASS)) {
      Serial.println("conectado!");
      // Subscreve ao tópico de comando para controle manual
      mqttClient.subscribe(TOPIC_CMD);
      mqttClient.publish(TOPIC_STATE, "DISPONIVEL (Aguardando Comando)");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" - Tentando novamente em 5s");
      delay(5000);
    }
  }
}

// --- Funções de Lógica ---
void handleFanControl(float currentTemp) {
  // Lógica de atuação: Alto = Liga Relé (depende da configuração do relé, ajuste HIGH/LOW)
  if (isManualControlActive) {
    // Se o controle manual estiver ativo, o controle automático é ignorado
    return;
  }

  if (currentTemp >= TEMP_LIMITE_AUTO) {
    if (digitalRead(RELAY_PIN) == LOW) { // Assume LOW para LIGAR o relé (típico)
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("Auto: Temperatura alta. LIGANDO ventoinha.");
        mqttClient.publish(TOPIC_STATE, "LIGADO (AUTO)");
    }
  } else {
    if (digitalRead(RELAY_PIN) == HIGH) { // Assume HIGH para DESLIGAR o relé (típico)
        digitalWrite(RELAY_PIN, LOW);
        Serial.println("Auto: Temperatura OK. DESLIGANDO ventoinha.");
        mqttClient.publish(TOPIC_STATE, "DESLIGADO (AUTO)");
    }
  }
}

void readAndPublishData() {
    float umidade = dht.readHumidity();
    float temperatura = dht.readTemperature();

    if (isnan(temperatura) || isnan(umidade)) {
      Serial.println("Erro de leitura: Sensor DHT falhou!");
      return;
    }

    // Publica no MQTT
    char tempStr[8], humStr[8];
    dtostrf(temperatura, 4, 2, tempStr);
    dtostrf(umidade, 4, 2, humStr);
    
    mqttClient.publish(TOPIC_TEMP, tempStr, true); // true para retained (opcional)
    mqttClient.publish(TOPIC_HUM, humStr, true);

    Serial.printf("Dados Publicados - T: %s°C, H: %s%%\n", tempStr, humStr);

    // Chama a lógica de controle
    handleFanControl(temperatura);
}

// --- Função de Callback MQTT (Reage a comandos remotos) ---
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.printf("Comando recebido em [%s]: %s\n", topic, message.c_str());

  if (strcmp(topic, TOPIC_CMD) == 0) {
    if (message == "ON") {
      digitalWrite(RELAY_PIN, HIGH);
      isManualControlActive = true;
      mqttClient.publish(TOPIC_STATE, "LIGADO (MANUAL)");
    } else if (message == "OFF") {
      digitalWrite(RELAY_PIN, LOW);
      isManualControlActive = false;
      mqttClient.publish(TOPIC_STATE, "DESLIGADO (MANUAL)");
    } else if (message == "AUTO") {
      isManualControlActive = false;
      mqttClient.publish(TOPIC_STATE, "MODO AUTOMATICO ATIVADO");
      Serial.println("Mudando para Modo Automático.");
      // Força a execução da lógica automática imediatamente após o comando AUTO
      readAndPublishData(); 
    }
  }
}

// --- Setup e Loop Principal ---
void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Inicia desligado (Assumindo LOW=OFF)
  
  dht.begin();
  setupWiFi();

  mqttClient.setServer(MQTT_SERVER, 1883); // Porta padrão MQTT
  mqttClient.setCallback(callback);
}

void loop() {
  // Garante que o Wi-Fi e MQTT estejam sempre conectados
  if (WiFi.status() != WL_CONNECTED) {
    setupWiFi(); 
    return;
  }
  
  if (!mqttClient.connected()) {
    reconnectMQTT();
  }
  mqttClient.loop();

  // Rotina de Leitura e Publicação
  static unsigned long lastReadTime = 0;
  if (millis() - lastReadTime >= READ_INTERVAL_MS) { 
    lastReadTime = millis();
    readAndPublishData();
  }
}