# FIAP - Faculdade de Informática e Administração Paulista

<p align="center">
<a href= "https://www.fiap.com.br/"><img src="assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=40% height=40%></a>
</p>

<br>

# CardioAI

## CardioSync

## 👨‍🎓 Integrantes: 
- Alex da Silva Lima (RM559784)
- Johnatan Sousa Macedo Loriano (RM559546)
- Bruno Henrique Nielsen Conter (RM560518)
- Fabio Santos Cardoso (RM560479)

## 👩‍🏫 Professores:
### Tutor(a) 
- Lucas Gomes Moreira
### Coordenador(a)
- André Godoi

## 📜 Descrição

Este repositório é dedicado ao projeto acadêmico CardioIA, desenvolvido para o curso de Inteligência Artificial da FIAP. O objetivo final do projeto é criar uma plataforma digital inteligente que simule um ecossistema de cardiologia moderna, integrando dados clínicos, modelos de Machine Learning, Visão Computacional, IoT e agentes inteligentes para auxiliar na triagem, diagnóstico, monitoramento e previsões médicas.

Este repositório foi criado com uma estrutura modular, pensando na evolução do projeto ao longo das próximas 7 fases do curso. A cada nova fase, o código-fonte e a documentação serão atualizados e expandidos.

---

### **Fase 1: Batimentos de Dados**

Nesta primeira fase, o grupo atuou como **Cientista de Dados Hospitalar**. O foco principal foi a coleta, organização e preparação de três tipos de dados fundamentais que servirão de base para o desenvolvimento dos módulos de IA.

---

### **1. Dados Numéricos (IoT)**

*   **Descrição e Origem**: O dataset numérico utilizado é o "Heart Disease UCI", um conjunto de dados clássico e amplamente utilizado, proveniente da Cleveland Clinic Foundation e disponibilizado via UCI Machine Learning Repository e Kaggle. Ele contém 303 instâncias e 14 atributos, incluindo idade, sexo, tipo de dor no peito, pressão arterial em repouso, colesterol sérico, e o atributo alvo que indica a presença ou ausência de doença cardíaca. Este dataset não simula dados de IoT, mas serve como uma base de dados estruturada fundamental para treinar modelos de classificação de risco cardiovascular.

*   **Fontes e Acesso aos Dados**:
    *   **Fonte Original (Kaggle)**: [Heart Disease UCI](https://www.kaggle.com/datasets/data855/heart-disease?resource=download)
    *   **Análise de Referência (Kaggle Notebook)**: [Heart Disease Predictions](https://www.kaggle.com/code/desalegngeb/heart-disease-predictions)
    *   **Cópia Local**: Os dados brutos podem ser salvos no diretório `data/raw/` (ex: `data/raw/previsões de doenças cardíacas.csv`).
    *   **Cópia em Nuvem (Google Drive)**: [Link para o Google Drive](https://drive.google.com/file/d/1A8RgDcJegtEAq41ApoB67SSJTOjWMBmU/view?usp=sharing)

*   **Relevância Clínica e para a IA**: A escolha dessas variáveis é estratégica, pois são indicadores-chave de risco cardiovascular, validados clinicamente. Modelos de Machine Learning podem ser treinados com estes dados do mundo real para:
    *   **Classificar Pacientes**: Prever a probabilidade de um paciente ter uma doença cardíaca com base em seus dados clínicos.
    *   **Identificar Fatores de Risco**: Analisar quais variáveis (features) são mais preditivas para o diagnóstico.
    *   **Benchmark de Modelos**: Por ser um dataset conhecido, ele é excelente para testar e comparar a performance de diferentes algoritmos de classificação (ex: Regressão Logística, SVM, Random Forest), estabelecendo uma base sólida para futuras iterações do projeto com dados de IoT.

### **2. Dados Textuais (NLP)**

*   **Descrição e Origem**: Foram selecionados quatro artigos científicos em formato `.txt`, obtidos de fontes acadêmicas e de saúde pública. Os textos abordam diferentes dimensões das doenças cardiovasculares (DCV) no Brasil. Os trabalhos incluídos são:
    *   **"Epidemiologia das Doenças Cardiovasculares no Brasil: A Verdade Escondida nos Números"**: Discute a epidemiologia das DCV no Brasil, abordando a importância e os desafios da coleta de dados de mortalidade para a criação de políticas de saúde.
    *   **"Fatores associados às doenças cardiovasculares na população adulta brasileira"**: Investiga a prevalência e os fatores sociodemográficos, de saúde e de estilo de vida associados ao diagnóstico de DCV na população adulta do Brasil, com base na Pesquisa Nacional de Saúde de 2019.
    *   **"Fatores psicossociais associados à doença cardíaca e manejo clínico psicológico"**: Explora a percepção de psicólogos e pacientes sobre os fatores psicossociais (como estresse e depressão) ligados às cardiopatias e as possibilidades de manejo psicológico.
    *   **"Prevalência das Doenças Cardíacas Ilustrada em 60 Anos dos Arquivos Brasileiros de Cardiologia"**: Analisa a evolução das publicações científicas sobre doenças cardíacas ao longo de 60 anos para refletir as tendências e a prevalência dessas doenças no Brasil.

*   **Caminho no Repositório**: Os arquivos de texto estão localizados na pasta `assets/`.

*   **Relevância e Exploração com NLP**: Os textos fornecem uma base rica para a aplicação de algoritmos de Processamento de Linguagem Natural (NLP), gerando insights valiosos para um projeto de IA em saúde. A relevância está na capacidade de transformar dados não estruturados (texto) em informações acionáveis para profissionais de saúde, pesquisadores e gestores.

    *   **Extração de Informações (Information Extraction) e Entidades (NER)**: Os artigos contêm uma vasta quantidade de dados clínicos e epidemiológicos. Um modelo de IA pode ser treinado para identificar e extrair automaticamente:
        *   **Condições e Sintomas**: "insuficiência cardíaca", "infarto agudo do miocárdio", "hipertensão", "diabetes".
        *   **Fatores de Risco**: "tabagismo", "sedentarismo", "estresse", "obesidade abdominal".
        *   **Dados Estatísticos**: Prevalência ("5,3%"), mortalidade ("18,6 milhões"), fatores de risco associados (Razão de Prevalência - RP).
        *   **Justificativa**: Essa extração automatizada é crucial para popular bancos de dados, construir painéis epidemiológicos em tempo real e auxiliar na identificação de perfis de risco em prontuários eletrônicos.

    *   **Modelagem de Tópicos (Topic Modeling)**: Com a grande quantidade de literatura médica disponível, algoritmos como o Latent Dirichlet Allocation (LDA) podem analisar os textos e agrupá-los em temas centrais, como "Políticas de Saúde Pública", "Fatores Psicossociais", "Tratamento e Manejo Clínico" e "Fatores de Risco Sociodemográficos".
        *   **Justificativa**: Isso permite que pesquisadores e médicos naveguem de forma eficiente pelo conhecimento existente, identifiquem tendências de pesquisa e encontrem rapidamente artigos relevantes para suas áreas de interesse.

    *   **Análise de Sentimentos**: O texto sobre fatores psicossociais descreve emoções e percepções dos pacientes ("medo", "ansiedade", "frustração", "desamparo"). Um modelo de análise de sentimentos poderia quantificar essas percepções em larga escala, analisando, por exemplo, relatos de pacientes em fóruns online ou anotações em prontuários.
        *   **Justificativa**: Compreender o impacto emocional da doença é fundamental para o manejo clínico integral do paciente. A IA pode ajudar a identificar pacientes que necessitam de suporte psicológico, melhorando a adesão ao tratamento e a qualidade de vida.

    *   **Sumarização Automática**: Os artigos são densos e extensos. Algoritmos de sumarização podem criar resumos concisos, destacando os principais objetivos, métodos e conclusões de cada estudo.
        *   **Justificativa**: Para médicos com tempo limitado, a sumarização automática acelera o acesso a evidências científicas, apoiando a tomada de decisão clínica baseada em informações atualizadas.

### **3. Dados Visuais (Visão Computacional)**

*   **Descrição e Origem**: O conjunto de dados visual é composto por mais de 100 imagens de Eletrocardiogramas (ECG) em formato `.png`. As imagens foram obtidas do repositório público "ECG-Image-Kit", que fornece um kit de ferramentas para trabalhar com imagens de ECG.

*   **Link para as Imagens**: [https://github.com/alphanumericslab/ecg-image-kit/tree/main/sample-data/ecg-images](https://github.com/alphanumericslab/ecg-image-kit/tree/main/sample-data/ecg-images)
  
*   **Imagens - Google Drive**: https://drive.google.com/drive/folders/1Q4JwGnt5m5cCo0OJoQPVVP7BS6pkjcJo?usp=drive_link

*   **Fonte Complementar (Google Drive)**: [Link para o Google Drive](https://drive.google.com/drive/folders/1Q4JwGnt5m5cCo0OJoQPVVP7BS6pkjcJo?usp=drive_link)

*   **Relevância e Exploração com Visão Computacional**: Imagens de ECG são fundamentais para o diagnóstico de uma vasta gama de condições cardíacas. A aplicação de algoritmos de Visão Computacional (VC) sobre esses dados permite automatizar e escalar a análise, trazendo grande valor para a área da saúde.

    *   **Detecção de Padrões e Segmentação**: Modelos de VC podem ser treinados para identificar e segmentar as diferentes ondas (P, QRS, T), segmentos (ST) e intervalos (PR, QT) em uma imagem de ECG.
        *   **Justificativa**: A análise precisa das características e durações desses padrões é a base do diagnóstico por ECG. A automação dessa tarefa permite extrair medições quantitativas de forma rápida e consistente, auxiliando na identificação de irregularidades.

    *   **Reconhecimento de Anomalias e Classificação**: Uma vez que os padrões são identificados, a IA pode ser usada para detectar anomalias e classificar os ECGs. Por exemplo, um modelo pode aprender a diferenciar um ritmo sinusal normal de arritmias comuns, como fibrilação atrial, ou a identificar sinais de isquemia e infarto do miocárdio (ex: elevação ou depressão do segmento ST).
        *   **Justificativa**: Um sistema de IA capaz de realizar essa classificação pode atuar como uma ferramenta de triagem, alertando médicos sobre exames críticos que necessitam de atenção imediata. Isso otimiza o fluxo de trabalho, reduz o tempo para o diagnóstico e pode ser crucial em emergências.

    *   **Identificação de Bordas e Características Morfológicas**: Algoritmos de identificação de bordas podem ser aplicados para analisar a morfologia das ondas (sua forma, altura e contorno), que também contém informações diagnósticas importantes.
        *   **Justificativa**: Mudanças sutis na forma das ondas, que podem ser difíceis de quantificar manualmente, podem ser detectadas por um modelo de IA, oferecendo um nível adicional de detalhe para o diagnóstico e auxiliando na detecção precoce de patologias.

---

## 📁 Estrutura de Pastas

O projeto está organizado com uma estrutura de pastas modular para suportar as diferentes fases de desenvolvimento, desde a análise de dados até a implementação dos modelos de IA.

```
.
├── .github/         # Configurações do GitHub (ex: templates de issue).
├── assets/          # Arquivos de dados não-estruturados (textos, imagens, etc.).
├── config/          # Arquivos de configuração do projeto.
├── data/            # Datasets utilizados no projeto.
│   ├── raw/         # Dados brutos e imutáveis (ex: CSVs originais).
│   └── processed/   # Dados intermediários ou limpos após processamento.
├── document/        # Documentação oficial do projeto e relatórios.
├── notebooks/       # Jupyter notebooks para análise exploratória e modelagem.
├── scripts/         # Scripts auxiliares (ex: automação, deploy, migração).
├── src/             # Código-fonte principal da aplicação e modelos de IA.
├── .gitattributes   # Define atributos por caminho do Git.
├── .gitignore       # Especifica arquivos a serem ignorados pelo Git.
└── README.md        # Este arquivo.
```

## 🔧 Como executar o código

**Fase 1: Preparação de Dados**

1.  **Pré-requisitos**:
    * Python 3.x
    * Bibliotecas Python para análise de dados (ex: Pandas, Matplotlib, scikit-learn).
    * Git para clonar o repositório.

2.  **Instalação e Execução**:
    ```bash
    # Clone o repositório
    git clone [https://github.com/brunocorisco86/cardioai.git](https://github.com/brunocorisco86/cardioai.git)

    # Navegue até a pasta do projeto
    cd cardioai

    # Instale as dependências (se aplicável para fases futuras)
    pip install -r requirements.txt
    ```
    Nesta fase, o foco é a organização dos dados e da documentação. O código de análise será desenvolvido nas próximas etapas e adicionado na pasta `src/`.

3.  **Jupyter Notebooks**:

    Na pasta `notebooks/`, você encontrará os seguintes notebooks:

    *   `eda.ipynb`: Realiza uma análise exploratória dos dados (EDA) do dataset de doenças cardíacas. Este notebook carrega os dados, exibe informações básicas, estatísticas descritivas e visualizações para entender a distribuição e as relações entre as variáveis.
    *   `model_building.ipynb`: Demonstra a construção de um modelo de classificação simples (Regressão Logística) para prever a presença de doenças cardíacas. O notebook inclui o pré-processamento dos dados, a divisão em conjuntos de treino and teste, o treinamento do modelo e a avaliação de sua performance.

    Para executar os notebooks, você precisará ter o Jupyter Notebook ou o JupyterLab instalado:

    ```bash
    # Instale o JupyterLab
    pip install jupyterlab

    # Inicie o JupyterLab na pasta do projeto
    jupyter-lab
    ```

## 🗃 Histórico de lançamentos

* 0.2.0 - 03/09/2025
    * Adicionado diretório `notebooks` para análise de dados e modelagem.
    * Criado notebook `eda.ipynb` para análise exploratória dos dados.
    * Criado notebook `model_building.ipynb` para construção de um modelo de classificação.
    * Adicionado `requirements.txt` com as dependências do projeto.
    * Atualizado o `README.md` com as novas seções e informações.
* 0.1.0 - 14/08/2025
    * Estrutura inicial do repositório
    * Coleta e organização dos datasets numéricos, textuais e visuais (Fase 1)
    * Criação do README.md detalhado

## 📋 Licença

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/agodoi/template">MODELO GIT FIAP</a> por <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://fiap.com.br">Fiap</a> está licenciado sobre <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">Attribution 4.0 International</a>.</p>
