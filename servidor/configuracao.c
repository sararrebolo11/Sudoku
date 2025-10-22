/**
 * @file configuracao_servidor.c
 * @brief Implementação das funções de leitura da configuração do servidor.
 *
 * Este módulo é responsável por carregar os parâmetros de configuração
 * de um servidor a partir de um ficheiro de texto. O ficheiro deve conter
 * linhas no formato:
 * 
 * ```
 * FICHEIRO_JOGOS: jogos.txt
 * FICHEIRO_SOLUCOES: solucoes.txt
 * PORTA: 5000
 * ```
 *
 * Cada parâmetro é lido e armazenado na estrutura `ConfigServidor`.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracao.h"

/**
 * @brief Carrega as definições do servidor a partir de um ficheiro de configuração.
 *
 * Esta função lê um ficheiro de texto contendo pares `CHAVE: valor`, que definem
 * os parâmetros de execução do servidor. São esperadas as chaves:
 * - `FICHEIRO_JOGOS`: caminho para o ficheiro com os dados dos jogos.
 * - `FICHEIRO_SOLUCOES`: caminho para o ficheiro com as soluções.
 * - `PORTA`: número da porta TCP onde o servidor irá escutar.  
 *
 * Os valores lidos são armazenados na estrutura `ConfigServidor` fornecida.
 *
 * @param ficheiro Caminho para o ficheiro de configuração.
 * @param cfg Ponteiro para uma estrutura `ConfigServidor` onde serão guardados os dados.
 *
 * @return int Retorna `1` se o ficheiro foi carregado com sucesso, ou `0` se ocorreu erro.
 */
int carregarConfiguracaoServidor(const char *ficheiro, ConfigServidor *cfg) {
    FILE *f = fopen(ficheiro, "r");
    if (!f) {
        perror("Erro ao abrir ficheiro de configuração do servidor");
        return 0;
    }

    char linha[256], chave[64], valor[128];

    // Lê o ficheiro linha a linha
    while (fgets(linha, sizeof(linha), f)) {
        // Extrai a chave e o valor no formato "CHAVE: valor"
        if (sscanf(linha, "%[^:]: %s", chave, valor) == 2) {
            if (strcmp(chave, "FICHEIRO_JOGOS") == 0)
                strcpy(cfg->ficheiroJogos, valor);
            else if (strcmp(chave, "FICHEIRO_SOLUCOES") == 0)
                strcpy(cfg->ficheiroSolucoes, valor);
            else if (strcmp(chave, "PORTA") == 0)
                cfg->porta = atoi(valor);
        }
    }

    fclose(f);
    return 1;
}
