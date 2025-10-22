/**
 * @file configuracao.c
 * @brief Implementação das funções de leitura da configuração do cliente.
 *
 * Este módulo é responsável por carregar os parâmetros de configuração
 * de um cliente a partir de um ficheiro de texto. O ficheiro deve conter
 * linhas no formato:
 * 
 * ```
 * IP_SERVIDOR: 192.168.1.10
 * PORTA: 5000
 * ID_CLIENTE: cliente01
 * ```
 * 
 * Cada parâmetro é lido e armazenado na estrutura `ConfigCliente`.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracao.h"

/**
 * @brief Carrega as definições de um cliente a partir de um ficheiro de configuração.
 *
 * Esta função lê um ficheiro de texto contendo parâmetros no formato
 * `CHAVE: valor`. São esperadas as chaves:
 * - `IP_SERVIDOR`: endereço IP do servidor a contactar.
 * - `PORTA`: número da porta TCP a usar.
 * - `ID_CLIENTE`: identificador único do cliente.
 *
 * Os valores lidos são armazenados na estrutura `ConfigCliente` passada por parâmetro.
 *
 * @param ficheiro Caminho para o ficheiro de configuração.
 * @param cfg Ponteiro para uma estrutura `ConfigCliente` onde os dados serão armazenados.
 * 
 * @return int Retorna `1` se o ficheiro foi lido com sucesso, ou `0` em caso de erro.
 */
int carregarConfiguracaoCliente(const char *ficheiro, ConfigCliente *cfg) {
    FILE *f = fopen(ficheiro, "r");
    if (!f) {
        perror("Erro ao abrir ficheiro de configuração do cliente");
        return 0;
    }

    char linha[256], chave[64], valor[128];

    // Lê cada linha do ficheiro até ao fim
    while (fgets(linha, sizeof(linha), f)) {
        // Extrai a chave e o valor de cada linha no formato "CHAVE: valor"
        if (sscanf(linha, "%[^:]: %s", chave, valor) == 2) {
            if (strcmp(chave, "IP_SERVIDOR") == 0)
                strcpy(cfg->ipServidor, valor);
            else if (strcmp(chave, "PORTA") == 0)
                cfg->porta = atoi(valor);
            else if (strcmp(chave, "ID_CLIENTE") == 0)
                strcpy(cfg->idCliente, valor);
        }
    }

    fclose(f);
    return 1;
}
