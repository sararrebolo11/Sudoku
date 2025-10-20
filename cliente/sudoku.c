#include <stdio.h>
#include "sudoku.h"

void lerSudokuDeString(const char *str, int tab[TAM][TAM]) {
    for (int i = 0; i < TAM * TAM; i++)
        tab[i / TAM][i % TAM] = str[i] - '0';
}

int verificarSudoku(int sudoku[TAM][TAM], int solucao[TAM][TAM]) {
    int erros = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (sudoku[i][j] != solucao[i][j])
                erros++;
    return erros;
}

void mostrarSudoku(int sudoku[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (i % 3 == 0 && i != 0) printf("---------------------\n");
        for (int j = 0; j < TAM; j++) {
            if (j % 3 == 0 && j != 0) printf("| ");
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

