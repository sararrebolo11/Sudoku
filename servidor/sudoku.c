#include <stdio.h>
#include "sudoku.h"

/**
 * @brief Lê um tabuleiro de Sudoku a partir de uma string de 81 caracteres.
 *
 * Cada caractere da string representa uma célula do tabuleiro, da esquerda para a direita
 * e de cima para baixo. Por exemplo, o primeiro caractere é a posição (0,0),
 * o segundo é (0,1) e assim por diante.
 *
 * @param str String contendo os números do Sudoku (81 dígitos de '0' a '9')
 * @param tab Matriz 9x9 (TAM x TAM) onde será armazenado o tabuleiro
 */
void lerSudokuDeString(const char *str, int tab[TAM][TAM]) {
    for (int i = 0; i < TAM * TAM; i++)
        tab[i / TAM][i % TAM] = str[i] - '0';
}

/**
 * @brief Compara um Sudoku com a sua solução correta e retorna o número de erros.
 *
 * Percorre todas as células da matriz e conta quantas estão diferentes da solução.
 * 
 * @param sudoku Matriz 9x9 com o Sudoku preenchido (parcial ou completo)
 * @param solucao Matriz 9x9 com a solução correta
 * @return int Número de erros (diferenças encontradas)
 */
int verificarSudoku(int sudoku[TAM][TAM], int solucao[TAM][TAM]) {
    int erros = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (sudoku[i][j] != solucao[i][j])
                erros++;
    return erros;
}

/**
 * @brief Mostra o tabuleiro de Sudoku formatado no ecrã.
 *
 * Apresenta o Sudoku com separadores entre as regiões 3x3 para facilitar a leitura.
 * Zeros representam células vazias.
 *
 * Exemplo de saída:
 * 5 3 0 | 0 7 0 | 0 0 0
 * 6 0 0 | 1 9 5 | 0 0 0
 * 0 9 8 | 0 0 0 | 0 6 0
 * ---------------------
 * 8 0 0 | 0 6 0 | 0 0 3
 * ...
 *
 * @param sudoku Matriz 9x9 com o Sudoku a exibir
 */
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
