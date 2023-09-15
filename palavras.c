#include <stdio.h>
#include <stdlib.h>
#define MAX 1000



int caca_horizontal(char matriz[][MAX], char palavra[], int n_linhas, int n_colunas,int n_palavras){
    int i = 0;
    int find = 0;
    for (int linhas = 0; linhas < n_linhas; linhas++) {
        for (int colunas = 0; colunas , n_colunas; colunas++) {
            while (palavra != '\0') {
                if (palavra[i] == matriz[linhas][colunas]) {
                    
                }
            }
        }
    }
}
void caca_palavras(char matriz[][MAX], char palavras[][MAX], int n_linhas, int n_colunas, int n_palavras) {
   for (int i = 0; i < n_palavras; i++) {
    char palavra = palavras[i];
    caca_horizontal(matriz, palavra, n_linhas, n_colunas, n_palavras);
   }


}

int main() {
    int n_linhas, n_colunas, n_palavras;
    char matriz[MAX][MAX];
    char palavras[MAX][MAX];
    scanf("%d %d %d", &n_linhas, &n_colunas, &n_palavras);
    printf("%d %d %d \n", n_linhas, n_colunas, n_palavras);
    for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j ++) {
            scanf(" %c", &matriz[i][j]);
            }
    }
    for (int i = 0; i < n_palavras; i++) {
        scanf("%s", &palavras[i]);
    }

     printf("Palavras digitadas:\n");
    for (int i = 0; i < n_palavras; i++) {
        printf("%s\n", palavras[i]);
        }
    printf("Matriz: \n");
    for (int i = 0; i < n_linhas; i++) {
        printf("%s\n", matriz[i]);
        }
    caca_horizontal(matriz, palavras, n_linhas, n_colunas, n_palavras);
    return 0;
}