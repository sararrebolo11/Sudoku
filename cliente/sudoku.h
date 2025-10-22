#ifndef SUDOKU_H
#define SUDOKU_H

#define TAM 9  // Tamanho do tabuleiro de Sudoku (9x9)

/**
 * @brief Lê um tabuleiro de Sudoku a partir de uma string de 81 caracteres.
 *
 * @param str String contendo os números do Sudoku (81 dígitos de '0' a '9')
 * @param tab Matriz 9x9 (TAM x TAM) onde será armazenado o tabuleiro
 */
void lerSudokuDeString(const char *str, int tab[TAM][TAM]);

/**
 * @brief Verifica se a string de entrada contém exatamente 81 caracteres.
 *
 * @param str String contendo o Sudoku em formato linear
 * @return int 1 se o tamanho for válido, 0 caso contrário
 */
int verificarValidezTamanho(const char *str);

/**
 * @brief Verifica se todos os valores no Sudoku são válidos (entre 0 e 9).
 *
 * @param sudoku Matriz 9x9 a verificar
 * @return int 0 se tudo ok, -1 se houver valores inválidos
 */
int verificarValoresValidos(int sudoku[TAM][TAM]);

/**
 * @brief Verifica se existem repetições nas linhas.
 *
 * @param sudoku Matriz 9x9 a verificar
 * @return int Número de repetições encontradas
 */
int verificarLinhas(int sudoku[TAM][TAM]);

/**
 * @brief Verifica se existem repetições nas colunas.
 *
 * @param sudoku Matriz 9x9 a verificar
 * @return int Número de repetições encontradas
 */
int verificarColunas(int sudoku[TAM][TAM]);

/**
 * @brief Verifica se existem repetições nos blocos 3x3 do Sudoku.
 *
 * @param sudoku Matriz 9x9 a verificar
 * @return int Número de repetições encontradas
 */
int verificarBlocos(int sudoku[TAM][TAM]);

/**
 * @brief Compara o Sudoku do jogador com a solução correta.
 *
 * @param sudoku Matriz 9x9 preenchida pelo jogador
 * @param solucao Matriz 9x9 com a solução correta
 * @return int Número de diferenças encontradas
 */
int compararComSolucao(int sudoku[TAM][TAM], int solucao[TAM][TAM]);

/**
 * @brief Verifica a validade completa do Sudoku:
 * - Verifica valores válidos
 * - Verifica linhas, colunas e blocos
 * - Compara com a solução (se fornecida)
 *
 * @param sudoku Matriz 9x9 a verificar
 * @param solucao Matriz 9x9 com a solução correta
 * @return int 0 se válido e igual à solução,
 *             >0 se válido mas diferente,
 *             -1 se inválido
 */
int verificarSudoku(int sudoku[TAM][TAM], int solucao[TAM][TAM]);

/**
 * @brief Mostra o tabuleiro de Sudoku formatado no ecrã.
 *
 * @param sudoku Matriz 9x9 a exibir
 */
void mostrarSudoku(int sudoku[TAM][TAM]);

#endif
