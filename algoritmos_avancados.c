#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ======================
//   STRUCT DA SALA
// ======================
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// ======================
//   CRIA UMA NOVA SALA
// ======================
Sala* criarSala(char nome[]) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar sala!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ======================
//   EXPLORA AS SALAS
// ======================
void explorarSalas(Sala* atual) {
    char opcao;

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);
        printf("Escolha um caminho:\n");
        printf("  e - Ir para a esquerda\n");
        printf("  d - Ir para a direita\n");
        printf("  s - Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            printf("\nEncerrando exploração...\n");
            break;
        }

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esquerda == NULL) {
                printf("Não há caminho à esquerda! Você encontrou um beco sem saída.\n");
            } else {
                atual = atual->esquerda;
            }
        }
        else if (opcao == 'd' || opcao == 'D') {
            if (atual->direita == NULL) {
                printf("Não há caminho à direita! Você encontrou um beco sem saída.\n");
            } else {
                atual = atual->direita;
            }
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}

// ======================
//   MONTA A MANSÃO
// ======================
Sala* montarMansao() {

    // Raiz
    Sala* hall = criarSala("Hall de Entrada");

    // Nível 1
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita  = criarSala("Biblioteca");

    // Nível 2 - esquerda
    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita  = criarSala("Sala de Jantar");

    // Nível 2 - direita
    hall->direita->esquerda = criarSala("Escritório");
    hall->direita->direita  = criarSala("Porão Sombrio");

    return hall;
}

// ======================
//   MAIN
// ======================
int main() {

    Sala* mansao = montarMansao();

    printf("===== DETECTIVE QUEST – Mapa da Mansão =====\n");
    printf("Explore os cômodos usando e/d/s.\n");

    explorarSalas(mansao);

    return 0;
}