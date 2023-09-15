#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int lin_col) {
    int **matriz = malloc(lin_col * sizeof(int *));
    for (int i = 0; i <lin_col; i++) {
        matriz[i] = malloc(lin_col * sizeof(int));
        for (int j = 0; j < lin_col; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz;
}

void imprime_matriz(int **matriz, int lin_col) {
    for (int i = 0; i < lin_col; i++) {
        for (int j = 0; j < lin_col; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void libera_memoria( int **matriz, int i_matriz) {
    for (int i = 0; i < i_matriz; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int soma_submatriz(int **matriz,int i, int j,int max ) {
    int i_inicial = i;
    int j_inicial = j;
    int soma_atual = 0;
        for (i = i_inicial; i < max; i++) {
        for (j = j_inicial; j < max; j++) {
            soma_atual += matriz[i][j];
        }
    }
    return soma_atual;
}


int **soma_matriz(int **matriz, int lin_col) {
    int maior_soma = 0;
    int contador = 0;
    int i;
    int j;
    while (contador < 4) {
        int soma_atual = 0;
        if (contador == 0) {
            soma_atual = soma_submatriz(matriz, 0, 0, lin_col - 1);
            maior_soma = soma_atual;
            i = 0;
            j = 0;
        }
        else if (contador == 1) {
            soma_atual = soma_submatriz(matriz, 1, 0, lin_col);
            if (soma_atual > maior_soma) {
            maior_soma = soma_atual;
            i = 1;
            j = 0;
            }
        }
        else if (contador == 2) {
            soma_atual = soma_submatriz(matriz, 0, 1, lin_col - 1);
            if (soma_atual > maior_soma) {
            maior_soma = soma_atual;
            i = 0;
            j = 1;
            }
        }
        else if (contador == 3) {
            soma_atual = soma_submatriz(matriz, 1, 1, lin_col);
            if (soma_atual > maior_soma) {
            maior_soma = soma_atual;
            i = 1;
            j = 1;
        }
        }
        contador++;
    }
    int **sub_matriz = malloc((lin_col - 1) * sizeof(int*));
    for (int linhas = 0; linhas < lin_col - 1; linhas++) {
        sub_matriz[linhas] = malloc((lin_col - 1) * sizeof(int));
        for (int colunas = 0; colunas < lin_col - 1; colunas++) {
            sub_matriz[linhas][colunas] = matriz[i][j];
            j++;
        }
        i++;
        j -= lin_col - 1;
    }   

    return sub_matriz;
}
int main() {
    int lin_col;
    scanf("%d", &lin_col);
    int **matriz = cria_matriz(lin_col);
    printf("Quadra:\n");
    imprime_matriz(matriz, lin_col);
    while (lin_col > 1) {
        if (lin_col - 1 == 1) {
            int soma_atual;
            int soma_campea;
            for (int i = 0; i < lin_col; i++) {
                for (int j = 0; j < lin_col; j++) {
                    soma_atual = matriz[i][j];
                    if (i == 0 && j == 0) {
                        soma_campea = soma_atual;
                    }
                    else if (soma_atual == soma_campea) {
                        soma_campea = soma_atual;
                    }
                }
            }
            printf("Conjuntos que precisam de atenção:\n");
            printf("%d", soma_campea);
            break;
        }
        int **sub_matriz = soma_matriz(matriz, lin_col);
        libera_memoria(matriz, lin_col);
        matriz = sub_matriz;
        printf("Conjuntos que precisam de atenção:\n");
        imprime_matriz(matriz, lin_col - 1);
        int alt;
        scanf("%d", &alt);
        if (alt == 1) {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            matriz[i][j] = val;
            printf("Sub_matriz:\n");
            for (i = 0; i < lin_col - 1; i++) {
                for (j = 0; j < lin_col - 1; j++) {
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
        } else {
            break;
        }
        lin_col--;
    }
    libera_memoria(matriz, lin_col);
    return 0;
}