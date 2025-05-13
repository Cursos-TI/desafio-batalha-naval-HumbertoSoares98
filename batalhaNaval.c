#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define NAVIOS 3

void imprimir_Letras(int letras[]){
    printf("\nTABULEIRO BATALHA NAVAL\n");

    printf("  ");
    for (int i = 0; i < 10; i++){
        printf(" %2c", letras[i]);
    }
    printf("\n");
}

void imprimir_tabela(int tabela[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++){
        printf("%-3d", i + 0);
        for (int j = 0; j < COLUNAS; j++){
            printf("%2d ", tabela[i][j]);
        }
        printf("\n");
    }
}

void Habilidade_Cone(int tabela[LINHAS][COLUNAS], int linha_inicio, int coluna_inicio){
    for(int i = 0; i < 3; i++){
        for(int j = coluna_inicio - i; j <= coluna_inicio + i; j++){
            if(linha_inicio + i < LINHAS && j >= 0 < COLUNAS){
                tabela[linha_inicio + i][j] = NAVIOS;
            }
        }
    }
}

void Habilidade_Octaedro(int tabela[LINHAS][COLUNAS], int linha_centro, int coluna_centro){
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) + abs(j) <= 1) { // Forma de losango
                int linha = linha_centro + i;
                int coluna = coluna_centro + j;
                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                    tabela[linha][coluna] = NAVIOS;
                }
            }
        }
    }
}

void Habilidade_Cruz(int matriz[LINHAS][COLUNAS], int linha_centro, int coluna_centro){
    for (int i = -2; i <= 2; i++) {           
        for (int j = -2; j <= 2; j++) {        
            if ((i == 0) || (j == 0)) {        
                int linha = linha_centro + i;
                int coluna = coluna_centro + j;
                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                    matriz[linha][coluna] = NAVIOS;
                }
            }
        }
    }
}
int main(){
    int tabela[LINHAS][COLUNAS];
    int letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabela[i][j] = 0;
        }
    }

    Habilidade_Cone(tabela, 0, 2);
    Habilidade_Octaedro(tabela, 3, 6);
    Habilidade_Cruz(tabela, 6, 3);
    imprimir_Letras(letras);
    imprimir_tabela(tabela);

    return 0;
}