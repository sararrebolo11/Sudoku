/**
 * @file logs.c
 * @brief Implementação das funções de registo de logs do cliente.
 *
 * Este módulo fornece funções para criar a pasta de logs (caso não exista)
 * e registar eventos com timestamp num ficheiro de log específico.
 *
 * Cada evento é gravado numa linha com o formato:
 * ```
 * [HH:MM:SS] Descrição do evento
 * ```
 *
 * O nome do ficheiro de log é definido pelo chamador (por exemplo: "logs/cliente01.log").
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "logs.h"

/**
 * @brief Cria a pasta "logs" caso ainda não exista.
 *
 * Esta função verifica se o diretório "logs" já existe no diretório atual.
 * Se não existir, é criado com permissões 0755 (leitura e execução para todos,
 * escrita apenas para o dono).
 */
void criarPastaLogs(void) {
    struct stat st = {0};

    // Verifica se a pasta "logs" existe
    if (stat("logs", &st) == -1)
        // Cria a pasta com permissões padrão
        mkdir("logs", 0755);
}

/**
 * @brief Regista um evento num ficheiro de log.
 *
 * A função garante que a pasta "logs" existe, abre (ou cria) o ficheiro de log
 * especificado e escreve uma linha contendo a hora atual e a descrição do evento.
 *
 * Exemplo de linha gravada:
 * ```
 * [14:32:08] Cliente iniciado
 * ```
 *
 * @param ficheiro Caminho para o ficheiro de log (exemplo: "logs/cliente01.log").
 * @param descricao Texto descritivo do evento a registar.
 */
void registarEvento(const char *ficheiro, const char *descricao) {
    criarPastaLogs();  // Garante que a pasta existe

    FILE *f = fopen(ficheiro, "a");  // Abre o ficheiro em modo append
    if (!f)
        return;  // Se falhar, sai silenciosamente

    // Obtém a hora atual
    time_t t = time(NULL);
    struct tm *tmp = localtime(&t);

    // Escreve o evento no formato [HH:MM:SS] Descrição
    fprintf(f, "[%02d:%02d:%02d] %s\n",
            tmp->tm_hour, tmp->tm_min, tmp->tm_sec, descricao);

    fclose(f);
}
