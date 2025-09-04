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
- Matheus Augusto Rodrigues Maia (RM560683)
- Bruno Henrique Nielsen Conter (RM560518)
- Fabio Santos Cardoso (RM560479)

## 👩‍🏫 Professores:
### Tutor(a) 
- Nome do Tutor
### Coordenador(a)
- Nome do Coordenador

## 📜 Descrição

Este repositório é dedicado ao projeto acadêmico CardioIA, desenvolvido para o curso de Inteligência Artificial da FIAP. O objetivo final do projeto é criar uma plataforma digital inteligente que simule um ecossistema de cardiologia moderna, integrando dados clínicos, modelos de Machine Learning, Visão Computacional, IoT e agentes inteligentes para auxiliar na triagem, diagnóstico, monitoramento e previsões médicas.

Este repositório foi criado com uma estrutura modular, pensando na evolução do projeto ao longo das próximas 7 fases do curso. A cada nova fase, o código-fonte e a documentação serão atualizados e expandidos.

---

### **Fase 1: Batimentos de Dados**

Nesta primeira fase, o grupo atuou como **Cientista de Dados Hospitalar**. O foco principal foi a coleta, organização e preparação de três tipos de dados fundamentais que servirão de base para o desenvolvimento dos módulos de IA.

---

### **1. Dados Numéricos (IoT)**

* **Descrição e Origem**: O dataset numérico, com mais de 100 linhas, foi compilado para simular dados de pacientes com foco em saúde cardiovascular. Ele contém variáveis como idade, sexo, pressão arterial (sistólica e diastólica), colesterol, histórico familiar de doenças cardíacas e frequência cardíaca. As informações são fictícias, criadas para a finalidade deste projeto acadêmico.

* **Link para o Dataset**: [https://drive.google.com/file/d/1A8RgDcJegtEAq41ApoB67SSJTOjWMBmU/view?usp=sharing](https://drive.google.com/file/d/1A8RgDcJegtEAq41ApoB67SSJTOjWMBmU/view?usp=sharing)

* **Relevância Clínica e para a IA**: A escolha dessas variáveis é estratégica para a IA, pois são indicadores-chave de risco cardiovascular. Modelos de Machine Learning podem ser treinados com esses dados para identificar padrões e prever a probabilidade de eventos cardíacos. A governança de dados é crucial aqui; a qualidade e a veracidade dos dados de entrada (mesmo que simulados) são fundamentais para garantir que os modelos de IA não gerem vieses ou diagnósticos imprecisos no futuro.

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

*   **Relevância e Exploração com Visão Computacional**: Imagens de ECG são fundamentais para o diagnóstico de uma vasta gama de condições cardíacas. A aplicação de algoritmos de Visão Computacional (VC) sobre esses dados permite automatizar e escalar a análise, trazendo grande valor para a área da saúde.

    *   **Detecção de Padrões e Segmentação**: Modelos de VC podem ser treinados para identificar e segmentar as diferentes ondas (P, QRS, T), segmentos (ST) e intervalos (PR, QT) em uma imagem de ECG.
        *   **Justificativa**: A análise precisa das características e durações desses padrões é a base do diagnóstico por ECG. A automação dessa tarefa permite extrair medições quantitativas de forma rápida e consistente, auxiliando na identificação de irregularidades.

    *   **Reconhecimento de Anomalias e Classificação**: Uma vez que os padrões são identificados, a IA pode ser usada para detectar anomalias e classificar os ECGs. Por exemplo, um modelo pode aprender a diferenciar um ritmo sinusal normal de arritmias comuns, como fibrilação atrial, ou a identificar sinais de isquemia e infarto do miocárdio (ex: elevação ou depressão do segmento ST).
        *   **Justificativa**: Um sistema de IA capaz de realizar essa classificação pode atuar como uma ferramenta de triagem, alertando médicos sobre exames críticos que necessitam de atenção imediata. Isso otimiza o fluxo de trabalho, reduz o tempo para o diagnóstico e pode ser crucial em emergências.

    *   **Identificação de Bordas e Características Morfológicas**: Algoritmos de identificação de bordas podem ser aplicados para analisar a morfologia das ondas (sua forma, altura e contorno), que também contém informações diagnósticas importantes.
        *   **Justificativa**: Mudanças sutis na forma das ondas, que podem ser difíceis de quantificar manualmente, podem ser detectadas por um modelo de IA, oferecendo um nível adicional de detalhe para o diagnóstico e auxiliando na detecção precoce de patologias.

---

## 📁 Estrutura de pastas

Dentre os arquivos e pastas presentes na raiz do projeto, definem-se:

- <b>.github</b>: Nesta pasta ficarão os arquivos de configuração específicos do GitHub que ajudam a gerenciar e automatizar processos no repositório.

- <b>assets</b>: aqui estão os arquivos relacionados a elementos não-estruturados deste repositório, como imagens.

- <b>config</b>: Posicione aqui arquivos de configuração que são usados para definir parâmetros e ajustes do projeto.

- <b>document</b>: aqui estão todos os documentos do projeto que as atividades poderão pedir. Na subpasta "other", adicione documentos complementares e menos importantes.

- <b>scripts</b>: Posicione aqui scripts auxiliares para tarefas específicas do seu projeto. Exemplo: deploy, migrações de banco de dados, backups.

- <b>src</b>: Todo o código fonte criado para o desenvolvimento do projeto ao longo das 7 fases.

- <b>README.md</b>: arquivo que serve como guia e explicação geral sobre o projeto (o mesmo que você está lendo agora).

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

## 🗃 Histórico de lançamentos

* 0.1.0 - 14/08/2025
    * Estrutura inicial do repositório
    * Coleta e organização dos datasets numéricos, textuais e visuais (Fase 1)
    * Criação do README.md detalhado

## 📋 Licença

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/agodoi/template">MODELO GIT FIAP</a> por <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://fiap.com.br">Fiap</a> está licenciado sobre <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">Attribution 4.0 International</a>.</p>
