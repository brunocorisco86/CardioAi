# -*- coding: utf-8 -*-
"""
Este script realiza a análise de frases que descrevem sintomas cardiovasculares.

Ele utiliza a biblioteca spaCy para Processamento de Linguagem Natural (NLP) para
comparar as frases de entrada com uma base de conhecimento de sintomas e, em seguida,
sugere um possível diagnóstico, grau de risco e o nome técnico do sintoma.

**Instalação das dependências:**
Antes de rodar o script, instale as bibliotecas necessárias:
pip install pandas spacy
python -m spacy download pt_core_news_sm
"""

import pandas as pd
import spacy
import re

# Carrega o modelo de linguagem em português do spaCy
try:
    nlp = spacy.load("pt_core_news_sm")
except OSError:
    print("Modelo 'pt_core_news_sm' não encontrado.")
    print("Por favor, execute: python -m spacy download pt_core_news_sm")
    exit()

# Caminhos para os arquivos de dados
KNOWLEDGE_BASE_FILE = "assets/tabela_sintoma_diagnostico_risco.csv"
SYMPTOM_PHRASES_FILE = "assets/frases_descricao_sintomas.txt"

def load_knowledge_base(file_path):
    """Carrega a base de conhecimento a partir de um arquivo CSV."""
    try:
        df = pd.read_csv(file_path)
        # Cria um Doc spaCy para cada frase na base de conhecimento para comparação futura
        df['doc'] = list(nlp.pipe(df['Expressão em 1ª Pessoa']))
        return df
    except FileNotFoundError:
        print(f"Erro: Arquivo da base de conhecimento não encontrado em '{file_path}'")
        return None

def load_symptom_phrases(file_path):
    """Carrega as frases de sintomas a partir de um arquivo de texto."""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            # Remove números, pontos e markdown de formatação (**), e espaços extras
            phrases = [re.sub(r'^\d+\.\s*|\*|"', '', line).strip() for line in f.readlines()]
            return phrases
    except FileNotFoundError:
        print(f"Erro: Arquivo de frases de sintomas não encontrado em '{file_path}'")
        return []

def analyze_symptoms(phrases, knowledge_base):
    """
    Analisa cada frase, compara com a base de conhecimento usando similaridade de vetores
    e imprime o diagnóstico correspondente.
    """
    if knowledge_base is None:
        return

    print("="*80)
    print("Análise de Sintomas Cardiovasculares")
    print("="*80)

    # Processa todas as frases de entrada com o pipeline do spaCy
    phrase_docs = list(nlp.pipe(phrases))

    for i, phrase_doc in enumerate(phrase_docs):
        # Calcula a similaridade com todas as expressões da base de conhecimento
        similarities = [phrase_doc.similarity(kb_doc) for kb_doc in knowledge_base['doc']]
        
        # Encontra o índice da maior similaridade
        best_match_index = similarities.index(max(similarities))
        
        # Define um limiar de confiança para a correspondência
        similarity_threshold = 0.8
        
        print(f"Frase {i+1}: \"{phrases[i]}\" ")
        
        if max(similarities) > similarity_threshold:
            matched_symptom = knowledge_base.iloc[best_match_index]
            print(f"  - Sintoma Identificado: {matched_symptom['Sintoma Cardiovascular']}")
            print(f"  - Grau de Risco: {matched_symptom['Grau de Risco']}")
            print(f"  - Diagnóstico Principal Associado: {matched_symptom['Diagnóstico Cardíaco Principal Associado']}")
        else:
            print("  - Não foi possível identificar um sintoma correspondente com alta confiança.")
        
        print("-"*80)

def main():
    """Função principal para orquestrar a análise."""
    knowledge_base = load_knowledge_base(KNOWLEDGE_BASE_FILE)
    symptom_phrases = load_symptom_phrases(SYMPTOM_PHRASES_FILE)
    
    if symptom_phrases:
        analyze_symptoms(symptom_phrases, knowledge_base)

if __name__ == "__main__":
    main()
