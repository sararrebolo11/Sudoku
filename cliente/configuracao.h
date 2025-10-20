#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

typedef struct {
    char ipServidor[64];
    int porta;
    char idCliente[64];
} ConfigCliente;

int carregarConfiguracaoCliente(const char *ficheiro, ConfigCliente *cfg);

#endif

