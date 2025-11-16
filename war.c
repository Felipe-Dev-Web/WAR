#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ---------------------------
// PROTÓTIPOS
// ---------------------------
void cadastrarTerritorios(Territorio *mapa, int n);
void exibirTerritorios(Territorio *mapa, int n);
void atacar(Territorio *atacante, Territorio *defensor);
void liberarMemoria(Territorio *mapa);

// ---------------------------
// FUNÇÃO PRINCIPAL
// ---------------------------
int main() {
    srand(time(NULL));  // aleatoriedade

    int n;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);

    // ALOCAÇÃO DINÂMICA
    Territorio *mapa = (Territorio *) calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    cadastrarTerritorios(mapa, n);

    int opcao;
    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Exibir territorios\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            exibirTerritorios(mapa, n);
        } 
        else if (opcao == 2) {
            int a, d;

            exibirTerritorios(mapa, n);

            printf("\nEscolha o numero do territorio ATACANTE: ");
            scanf("%d", &a);
            printf("Escolha o numero do territorio DEFENSOR: ");
            scanf("%d", &d);

            // validações
            if (a < 0 || a >= n || d < 0 || d >= n) {
                printf("Indice invalido!\n");
                continue;
            }
            if (a == d) {
                printf("Um territorio nao pode atacar a si mesmo.\n");
                continue;
            }
            if (strcmp(mapa[a].cor, mapa[d].cor) == 0) {
                printf("Nao e possivel atacar um territorio da mesma cor!\n");
                continue;
            }
            if (mapa[a].tropas <= 1) {
                printf("O atacante precisa de mais de 1 tropa para atacar.\n");
                continue;
            }

            atacar(&mapa[a], &mapa[d]);

        }

    } while (opcao != 0);

    liberarMemoria(mapa);
    return 0;
}

// ---------------------------
// FUNÇÕES
// ---------------------------

// Cadastro dos territórios
void cadastrarTerritorios(Territorio *mapa, int n) {
    printf("\n--- Cadastro dos Territorios ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nTerritorio %d:\n", i);

        printf("Nome: ");
        scanf(" %29[^\n]", mapa[i].nome);

        printf("Cor (jogador): ");
        scanf(" %9s", mapa[i].cor);

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// Exibe todos os territórios
void exibirTerritorios(Territorio *mapa, int n) {
    printf("\n===== LISTA DE TERRITORIOS =====\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] Nome: %s | Cor: %s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função que simula um ataque
void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n--- ATAQUE EM ANDAMENTO ---\n");
    printf("Atacante: %s (%s) com %d tropas\n",
           atacante->nome, atacante->cor, atacante->tropas);
    printf("Defensor: %s (%s) com %d tropas\n",
           defensor->nome, defensor->cor, defensor->tropas);

    int dadoA = (rand() % 6) + 1;
    int dadoD = (rand() % 6) + 1;

    printf("Dado do atacante: %d\n", dadoA);
    printf("Dado do defensor: %d\n", dadoD);

    if (dadoA > dadoD) {
        printf("RESULTADO: O atacante venceu!\n");

        // defensor muda de dono
        strcpy(defensor->cor, atacante->cor);

        // defensor recebe metade das tropas do atacante
        int tropas_transferidas = atacante->tropas / 2;
        defensor->tropas = tropas_transferidas;

        // atacante perde as tropas transferidas
        atacante->tropas -= tropas_transferidas;

    } else {
        printf("RESULTADO: O defensor resistiu ao ataque!\n");

        // atacante perde uma tropa
        atacante->tropas--;

        if (atacante->tropas < 1)
            atacante->tropas = 1;
    }

    printf("\n--- Situação Final ---\n");
    printf("Atacante: %s (%s) Tropas: %d\n",
           atacante->nome, atacante->cor, atacante->tropas);
    printf("Defensor: %s (%s) Tropas: %d\n",
           defensor->nome, defensor->cor, defensor->tropas);
}

// Liberação da memória
void liberarMemoria(Territorio *mapa) {
    free(mapa);
    printf("\nMemoria liberada com sucesso!\n");
}
