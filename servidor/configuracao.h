#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

typedef struct {
    char ficheiroJogos[128];
    char ficheiroSolucoes[128];
    int porta;
} ConfigServidor;

int carregarConfiguracaoServidor(const char *ficheiro, ConfigServidor *cfg);

#endif

