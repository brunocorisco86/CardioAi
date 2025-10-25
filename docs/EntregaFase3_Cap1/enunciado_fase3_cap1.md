
Fase 3 - Além das Fronteiras Digitais: Chips Neuromórficos

Cap 1 - CardioIA Conectada: IoT e Visualização de Dados para a Saúde Digital
ATIVIDADE – FASE 3: Monitoramento Contínuo – IoT na Saúde

Enunciado da atividade:

Nesta fase, você e sua equipe irão avançar no projeto CardioIA, integrando conceitos de IoT, computação em nuvem, Edge/Fog Computing e visualização de dados. O desafio é simular um sistema de monitoramento contínuo que capture sinais vitais de pacientes cardiológicos, armazene e processe informações localmente, transmita os dados para a nuvem e exiba resultados em dashboards interativos.

Você irá trabalhar com ESP32 no Wokwi, protocolos de comunicação (MQTT), armazenamento local (SPIFFS) e dashboards (Node-RED/Grafana). Essa combinação permitirá compreender o fluxo completo de dados em IoT aplicado à saúde: captura → processamento → transmissão → visualização → alerta.

Para situar melhor a jornada, observe no mapa mental em que ponto o projeto CardioIA se encontra nesta fase. É importante destacar que o material teórico que dará suporte a este projeto está concentrado nas fases 2 e 3, consideradas mais adequadas para você neste momento. A visualização contribui para a compreensão de como as etapas já realizadas se conectam com as próximas fases.

Para visualizar o mapa mental completo, acesso o link: mapaMental - CardioIA_ A Nova Era da Cardiologia Inteligente.svg


Objetivo geral dessa atividade:

O objetivo é desenvolver um protótipo funcional que simule um sistema vestível de monitoramento cardíaco, capaz de:

    Capturar sinais vitais simulados (exemplo: batimentos cardíacos, temperatura, umidade e movimento).
    Armazenar localmente e garantir resiliência offline (Edge Computing).
    Transmitir dados para a nuvem via MQTT.
    Visualizar informações em dashboards com alertas automáticos.
    Refletir sobre eficiência, segurança e boas práticas em IoT médico.

Observação: o aluno não é obrigado a comprar nenhum hardware ou sensores para realizar esta atividade. O uso de dispositivos físicos é opcional, no entanto recomendamos que você tenha todo o material necessário por perto para uma melhor formação profissional. Caso deseje utilizar equipamentos da FIAP em suas atividades, favor entrar em contato com a tutoria para realizar o agendamento. As unidades FIAP mais próxima de você estão preparadas com ambientes de laboratório maker para sua experiência ser ainda maior.

Ao final desta fase, sua equipe terá desenvolvido uma solução prática que demonstra de forma técnica como as tecnologias de IoT podem ser aplicadas no monitoramento de saúde, priorizando eficiência, segurança e responsabilidade no uso dos dados. E essa solução é 100% aplicável em projetos reais de mercado.
 

Atividade detalhada:

PARTE 1 – Armazenamento e processamento local (Edge Computing):

Desenvolver no Wokwi uma aplicação com ESP32, onde:

    Seu projeto tenha no mínimo 2 sensores distintos.
        Um sensor obrigatório de temperatura, responsável por ler periodicamente dados do sensor DHT22 (como o DHT22, que mede tanto temperatura quanto umidade — por isso, vamos considerar o DHT22 como sendo 1 sensor). O segundo sensor é de livre escolha do grupo para desenvolver a sua aplicação.
    Simule conectividade Wi-Fi (variável booleana). Quando “conectado”, envie os dados armazenados para a nuvem via Serial.println e apague o arquivo local.
    Garanta resiliência offline: mesmo sem conexão, o sistema continua coletando dados e quando voltar a ficar online, os dados não enviados sejam sincronizados. Escolha uma estratégia de armazenamento limitado nesse processo de resiliência alinhado com o modelo de negócio do seu projeto, isto é, quantas milhares de amostra você pretende registrar no seu ESP32 até ficar online novamente.
        Essa etapa demonstra o papel do Edge Computing em aplicações críticas de saúde. Pela limitação dos simuladores em executar o recurso SPIFFS, considere o Monitor Serial como sendo uma opção de resiliência offline alternativa.


Entregáveis:

    Link do projeto no Wokwi.
    Código em C++ comentado.
    Relatório simples (mínimo de uma página) descrevendo o fluxo de funcionamento e a lógica de resiliência.


PARTE 2 – Transmissão para nuvem e visualização (Fog/Cloud Computing):

Criar um sistema completo de monitoramento que:

    Envie dados simulados do ESP32 para a nuvem via protocolo MQTT (exemplo de broker: HiveMQ Cloud).
    Monte uma dashboard no Node-RED para exibir em tempo real:
        Gráfico de um sinal vital escolhido pelo grupo (temperatura + outro sensor simule batimentos cardíacos, como um botão de pressão, que você aperta x vezes por minuto).
        Medidor (gauge) de outro parâmetro relevante (exemplo: temperatura ou sensor alternativo).
        Indicador visual de alerta (LED virtual ou texto) quando valores ultrapassarem limites definidos pelo grupo (exemplo: > 120 bpm, temperatura > 38 °C ou outro parâmetro relevante).
    Opcionalmente, integrar com Grafana Cloud para visualização avançada.
        Essa etapa integra conceitos de Fog e Cloud Computing com visualização em saúde digital.

Entregáveis:

    Código do ESP32 (Arduino IDE/Wokwi).
    Prints evidenciando a aplicação ou export do dashboard no Node-RED (e Grafana, se utilizado).
    Relatório (mínino de duas páginas) sobre o fluxo de comunicação MQTT e configuração do dashboard.


Critérios de avaliação (10 pontos totais):

Critério
	

Pontos

Leitura de sensores. O item SPIFFS não será computado devido à limitação dos simuladores. O grupo que o fizer no chip real, vamos considerar que foi além.
	

2

Implementação de resiliência offline (Edge Computing)
	

2

Envio via MQTT e integração com broker
	

2

Dashboard funcional e alertas automáticos
	

2

Documentação clara (código + relatórios)
	

2

 


Mensagem final:

Integrar Edge, Fog e Cloud Computing em aplicações médicas é um dos maiores desafios atuais da IoT. Nesta fase, você terá vivenciado o ciclo completo de captura, processamento, transmissão e visualização de dados em saúde digital. Ao avançar para os desafios “Ir Além”, você expande ainda mais seu repertório, conectando IoT a Front-End e Inteligência Artificial aplicada.

