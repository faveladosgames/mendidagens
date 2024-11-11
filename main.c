#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define Q 10
#define W 3

int main(void) {
    int matriz1[Q][Q] = {0};
    float matriz2[Q][Q] = {0};

    int x[N];
    int y[N];

    for (int i = 0; i < N; i++) {
        x[i] = rand() % (Q - 1);
    }

    puts("Pares Ordenados:");
    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = i - 1; j < W + i - 1; j++) {
            if (j < 0) soma += x[0];
            else if (j > N - 1) soma += x[N - 1];
            else soma += x[j];
        }

        y[i] = soma / W;
        matriz1[x[i]][y[i]]++;
        matriz2[x[i]][y[i]] = (double)matriz1[x[i]][y[i]] / N;
        printf("x = %d, y = %d\n", x[i], y[i]);
    }

    puts("\nMatriz 1:");
    int somaMatriz1 = 0;
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q; j++) {
            printf("%4d\t", matriz1[i][j]);
            somaMatriz1 += matriz1[i][j];
        }

        printf("\n");
    }

    puts("\nMatriz 2:");
    float somaMatriz2 = 0;
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q; j++) {
            printf("%5f\t", matriz2[i][j]);
            somaMatriz2 += matriz2[i][j];
        }

        printf("\n");
    }

    printf("\nSoma da Matriz 1: %d\t\t|\tDimensao 1: %d\n", somaMatriz1, N);
    printf("Soma da Matriz 2: %f\t|\tDimensao 2: %d", somaMatriz2, N);

    return 0;
}
