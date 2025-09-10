
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10


void preencheTabuleiro(int tabuleiro[SIZE][SIZE],char input[1000]){

    char *token;
    token = strtok(input, ";"); // Divide a entrada em partes separadas por ";" - tipo do .split do python
    while (token != NULL) {
        int linha, coluna, valor;
        // Le os indices e o valor da celula
        if (sscanf(token, "%d %d %d", &linha, &coluna, &valor) == 3) {
            if (linha >= 0 && linha < SIZE && coluna >= 0 && coluna < SIZE) {
                tabuleiro[linha][coluna] = valor; // Atualiza a celula na tabuleiro
            } else {
                printf("Indice fora do intervalo permitido (0-9): %d %d\n", linha, coluna);
            }
        } else {
            printf("Formato invalido: %s\n", token);
        }
        token = strtok(NULL, ";"); // Passa para o próximo bloco
    }
}


void printTabuleiro(int tabuleiro[SIZE][SIZE]){
    printf("\nTabuleiro:\n");
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("[%2d]",tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void caminhadaFixa(int tabuleiro[SIZE][SIZE]){ //Primeiro para frente e depois para cima
    int linha = SIZE - 1, coluna = 0;
    int custo_total = tabuleiro[linha][coluna];

    printf("=== Caminhada Fixa ===\n");
    while ((coluna < SIZE - 1) && (linha > 0)){ // FAZER COMPARAÇÃO DIRETO
        coluna ++;
        printf("0 ");
        custo_total += tabuleiro[linha][coluna];

        if (linha > 0){
            linha --;
            printf("1 ");
            custo_total += tabuleiro[linha][coluna];

        }
    }
    printf("\nCusto Total: %d ", custo_total);
    printf("\n");
}


void caminhadaAleatoria(int tabuleiro[SIZE][SIZE]){
    srand(time(NULL)); //Apoio do rand() //Ver com o professor pq ta dando erro!!!
    printf("\n=== Caminhadas Aleatorias ===\n");
    for (int i = 0; i < 10; i ++){//Loop para ser 10 vezes a aleatoria
        int linha = SIZE - 1, coluna = 0, passos = 0;
        int custo_total = tabuleiro[linha][coluna];
         
        printf("Caminhada Aleatoria %d:\n",i+1);
        while (linha > 0 || coluna < SIZE - 1){ //Chega até tabuleiro[0][9] - USAR EM TODOS!!
            int num_aleatorio = rand() % 2;
            if (num_aleatorio == 0 && coluna < SIZE - 1){
                coluna ++;
                printf("0 ");
            }else if (num_aleatorio == 1 && linha > 0){
                linha --;
                printf("1 ");
            }else{
                continue; 
            }
            custo_total += tabuleiro[linha][coluna];
            passos ++;
        }
        printf("\nCusto Total da Caminhada %d: %d\n ",i + 1, custo_total);
        printf("\n");
    }
    
}


void caminhadaGulosa(int tabuleiro[SIZE][SIZE]) {
    //CIMA E PRA FRENTE -- COMEÇA EM CIMA 
    int linha = SIZE - 1, coluna = 0, custo_total = tabuleiro[linha][coluna];
    printf("=== Caminhada Gulosa ===\n");

    while (linha > 0 || coluna < SIZE - 1) {
        if (coluna == SIZE - 1) {
            linha--;
            printf("1 ");
        } else if (linha == 0) {
            coluna++;
            printf("0 ");
        } else {
            int valorC = tabuleiro[linha - 1][coluna];
            int valorF = tabuleiro[linha][coluna + 1];

            if (valorC < valorF) {
                linha--;
                printf("1 ");
            } else {
                coluna++;
                printf("0 ");
            }
        }
        custo_total += tabuleiro[linha][coluna];
    }

    printf("\nCusto Total: %d\n", custo_total);
}
   

void GulosaV2(int tabuleiro[SIZE][SIZE]){ 
    //CIMA , FRENTE OU PARA BAIXO VERIFICAR NESSA ORDEM !!!!
    int linha = SIZE - 1, coluna = 0, custo_total = tabuleiro[linha][coluna];
    int passos [SIZE][SIZE] = {0};
    printf("\n=== Caminhada Gulosa V2 ===\n");


    while (linha > 0 || coluna < SIZE - 1) {
        passos[linha][coluna] = 1; 
        
        if (coluna == SIZE - 1) { 
            linha--;
            printf("1 ");
        } 
        else if (linha == 0) { 
            coluna++;
            printf("0 ");
        } 
        else { 
            int valorC = 300, valorF = 300, valorB = 300; // Valor qualquer

            if (linha > 0 && !passos[linha - 1][coluna]) {
                valorC = tabuleiro[linha - 1][coluna];
            }
            
            if (coluna < SIZE - 1 && !passos[linha][coluna + 1]) {
                valorF = tabuleiro[linha][coluna + 1];
            }
            
            if (linha < SIZE - 1 && !passos[linha + 1][coluna]) {
                valorB = tabuleiro[linha + 1][coluna];
            }
            
            if (valorF <= valorC && valorF <= valorB) {
                coluna++;
                printf("0 ");
            } else if (valorC <= valorB) {
                linha--;
                printf("1 ");
            } else {
                linha++;
                printf("2 ");
            }
        }
        custo_total += tabuleiro[linha][coluna];
    }

    printf("\nCusto Total: %d\n", custo_total);
}


void Sondagem(int tabuleiro[SIZE][SIZE]) { // COMEÇA PELA FRENTE 
    int linha = SIZE - 1, coluna = 0, custo_total = tabuleiro[linha][coluna];
    printf("\n=== Caminhada Sondagem ===\n"); 

    //LEMBRAR DE VERIFICAR TAMANHO !!!
    while (linha > 0 || coluna < SIZE - 1) {
        if (coluna == SIZE - 1) { 
            linha--; 
            printf("1 "); 
        } else if (linha == 0) { 
            coluna++; 
            printf("0 "); 
        } else { 
            int FrenteF = 300, FrenteC = 300, CimaC = 300, CimaF = 300; // Valor qualquerr
            // NAO DEIXAR ULTRAPASSAR !!! VERIFICAR CADA POSI PRA MOVIMENTTO 
            if (coluna + 2 < SIZE){
                FrenteF = tabuleiro[linha][coluna + 1] + tabuleiro[linha][coluna + 2];
            }
            if (coluna + 1 < SIZE && linha - 1 >= 0){
                FrenteC = tabuleiro[linha][coluna + 1] + tabuleiro[linha - 1][coluna + 1];
            } 
            if (linha - 2 >= 0){
                CimaC = tabuleiro[linha - 1][coluna] + tabuleiro[linha - 2][coluna];
            } 
            if (linha - 1 >= 0 && coluna + 1 < SIZE){
                CimaF = tabuleiro[linha - 1][coluna] + tabuleiro[linha - 1][coluna + 1];
            } 

            if (FrenteF <= FrenteC && FrenteF <= CimaC && FrenteF <= CimaF) { 
                coluna += 2; 
                printf("0 0 "); 
            } else if (FrenteC <= FrenteF && FrenteC <= CimaC && FrenteC <= CimaF) { 
                coluna++; 
                linha--; 
                printf("0 1 "); 
            } else if (CimaC <= FrenteF && CimaC <= FrenteC && CimaC <= CimaF) { 
                linha -= 2; 
                printf("1 1 "); 
            } else { 
                linha--; 
                coluna++; 
                printf("1 0 "); 
            }
        }

        custo_total += tabuleiro[linha][coluna];
    }

    printf("\nCusto Total: %d\n", custo_total);
}


int main() {
    int tabuleiro[SIZE][SIZE] = {0};
    char input[1000]=" 0 0 3; 0 1 25; 0 2 3; 0 3 8; 0 4 8; 0 5 1; 0 6 25; 0 7 1; 0 8 3; 0 9 8; 1 0 1; 1 1 3; 1 2 8; 1 3 3; 1 4 8; 1 5 1; 1 6 25; 1 7 3; 1 8 8; 1 9 1; 2 0 25; 2 1 1; 2 2 8; 2 3 1; 2 4 1; 2 5 1; 2 6 1; 2 7 25; 2 8 3; 2 9 1; 3 0 8; 3 1 25; 3 2 25; 3 3 25; 3 4 1; 3 5 3; 3 6 8; 3 7 8; 3 8 3; 3 9 25; 4 0 1; 4 1 1; 4 2 1; 4 3 25; 4 4 25; 4 5 3; 4 6 3; 4 7 25; 4 8 25; 4 9 8; 5 0 1; 5 1 25; 5 2 25; 5 3 1; 5 4 8; 5 5 8; 5 6 1; 5 7 3; 5 8 1; 5 9 8; 6 0 3; 6 1 8; 6 2 8; 6 3 3; 6 4 8; 6 5 3; 6 6 3; 6 7 3; 6 8 25; 6 9 8; 7 0 3; 7 1 25; 7 2 25; 7 3 3; 7 4 8; 7 5 1; 7 6 1; 7 7 8; 7 8 25; 7 9 3; 8 0 8; 8 1 1; 8 2 25; 8 3 3; 8 4 8; 8 5 8; 8 6 3; 8 7 3; 8 8 1; 8 9 25; 9 0 1; 9 1 25; 9 2 1; 9 3 1; 9 4 8; 9 5 25; 9 6 8; 9 7 3; 9 8 25; 9 9 1;";
    preencheTabuleiro(tabuleiro,input);
    printTabuleiro(tabuleiro);
    caminhadaFixa(tabuleiro);
    caminhadaAleatoria(tabuleiro);
    caminhadaGulosa(tabuleiro);
    GulosaV2(tabuleiro);
    Sondagem(tabuleiro);

    return 0;
}


