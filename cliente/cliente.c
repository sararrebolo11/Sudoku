#include <stdio.h>
#include "configuracao.h"
#include "logs.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <ficheiro_config>\n", argv[0]);
        return 1;
    }

    ConfigCliente cfg;
    if (!carregarConfiguracaoCliente(argv[1], &cfg)) {  // ← aqui está a correção
        return 1;
    }

    char ficheiroLog[128];
    snprintf(ficheiroLog, sizeof(ficheiroLog), "logs/%s.log", cfg.idCliente);
    registarEvento(ficheiroLog, "Cliente iniciado");

    printf("Cliente %s ligado ao servidor %s:%d\n",
           cfg.idCliente, cfg.ipServidor, cfg.porta);

    return 0;
}


