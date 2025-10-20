
#ifndef SUDOKU_H
#define SUDOKU_H

#define TAM 9

int verificarSudoku(int sudoku[TAM][TAM], int solucao[TAM][TAM]);
void mostrarSudoku(int sudoku[TAM][TAM]);
void lerSudokuDeString(const char *str, int tab[TAM][TAM]);

#endif

