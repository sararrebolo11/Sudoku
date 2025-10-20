#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracao.h"

int carregarConfiguracaoCliente(const char *ficheiro, ConfigCliente *cfg) {
    FILE *f = fopen(ficheiro, "r");
    if (!f) {
        perror("Erro ao abrir ficheiro de configuração do cliente");
        return 0;
    }

    char linha[256], chave[64], valor[128];
    while (fgets(linha, sizeof(linha), f)) {
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

