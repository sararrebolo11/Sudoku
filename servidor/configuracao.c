#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracao.h"

int carregarConfiguracaoServidor(const char *ficheiro, ConfigServidor *cfg) {
    FILE *f = fopen(ficheiro, "r");
    if (!f) {
        perror("Erro ao abrir ficheiro de configuração do servidor");
        return 0;
    }

    char linha[256], chave[64], valor[128];
    while (fgets(linha, sizeof(linha), f)) {
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

