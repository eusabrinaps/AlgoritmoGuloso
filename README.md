# 📘 Relatório de Trabalho – Algoritmos e Programação II

## 🧠 Introdução

Este trabalho foi desenvolvido durante a disciplina **Algoritmos e Programação II**, com foco na linguagem de programação **C**. O objetivo foi implementar e analisar diferentes estratégias de movimentação em um ambiente simulado, utilizando conceitos fundamentais de algoritmos, estruturas de decisão e análise de custo.

## 🚶‍♂️ Tipos de Caminhada Implementados

Foram desenvolvidos cinco tipos distintos de caminhada, cada um com uma lógica específica:

### 1️⃣ Caminhada Fixa
➡️⬆️ Movimento constante: **1 passo para frente** e **1 passo para cima**, independentemente do custo.

### 🎲 Caminhada Aleatória
❓ A direção (frente ou cima) é escolhida **aleatoriamente**, sem considerar o custo.

### 🧮 Caminhada com Abordagem Gulosa
🔍 Escolhe-se a direção com o **menor custo entre frente e cima**.  
⚖️ Em caso de empate, o movimento é feito para **frente**.

### 🔁 Caminhada Gulosa V2
📉 Expande a lógica anterior, considerando também o movimento para **baixo**.  
✅ Escolhe-se o **menor custo entre frente, cima e baixo**.  
⚖️ Em caso de empate, o movimento é feito para **frente**.

### 🔭 Caminhada com Sondagem
🧭 Realiza uma **análise preditiva de até dois passos**, considerando todas as combinações possíveis entre os movimentos para frente e para cima.  
📊 A decisão é tomada com base na **menor soma de custos futuros**.

## 📚 Aprendizados

Durante o desenvolvimento do trabalho, foram adquiridos e consolidados os seguintes conhecimentos:

- 🧩 Manipulação de **matrizes** e estruturas de dados em C;
- 🧠 Implementação de **algoritmos de decisão** baseados em custo;
- 🛠️ Uso de **funções** e **modularização** do código para melhor organização;
- ⏱️ Análise de **eficiência e complexidade** das estratégias;

