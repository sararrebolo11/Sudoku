/**
 * @file main.c
 * @brief Programa principal do cliente.
 *
 * Este programa lê um ficheiro de configuração, inicializa o cliente
 * e regista o início da execução num ficheiro de logs. 
 * 
 * Utiliza as funções definidas em:
 *  - configuracao.h → para carregar os parâmetros do cliente.
 *  - logs.h → para registar eventos em ficheiros de log.
 */

#include <stdio.h>
#include "configuracao.h"
#include "logs.h"

/**
 * @brief Função principal do programa cliente.
 *
 * O programa espera como argumento o caminho para um ficheiro de configuração.
 * A configuração é carregada, e se for válida, o cliente inicia e regista o
 * evento de arranque no log correspondente ao seu ID.
 *
 * @param argc Número de argumentos passados ao programa.
 * @param argv Vetor de strings com os argumentos:
 *             - argv[0]: nome do executável
 *             - argv[1]: caminho do ficheiro de configuração
 * @return int Código de saída:
 *         - 0 se o programa terminou corretamente.
 *         - 1 se ocorreu um erro (por exemplo, falta de argumentos
 *           ou erro ao carregar configuração).
 */
int main(int argc, char *argv[]) {
    // Verifica se o utilizador forneceu o ficheiro de configuração
    if (argc < 2) {
        printf("Uso: %s <ficheiro_config>\n", argv[0]);
        return 1;
    }

    ConfigCliente cfg;

    // Carrega a configuração do cliente a partir do ficheiro indicado
    if (!carregarConfiguracaoCliente(argv[1], &cfg)) {
        // Se falhar o carregamento, termina o programa com erro
        return 1;
    }

    // Define o nome do ficheiro de log (ex: logs/cliente123.log)
    char ficheiroLog[128];
    snprintf(ficheiroLog, sizeof(ficheiroLog), "logs/%s.log", cfg.idCliente);

    // Regista o evento de início do cliente
    registarEvento(ficheiroLog, "Cliente iniciado");

    // Mostra na consola as informações de ligação
    printf("Cliente %s ligado ao servidor %s:%d\n",
           cfg.idCliente, cfg.ipServidor, cfg.porta);

    return 0;
}



