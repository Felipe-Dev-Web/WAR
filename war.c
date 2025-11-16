#include <stdio.h>
#include <string.h>

/*
    Struct Territorio:
    Serve para guardar vários dados juntos sobre um território.
    Aqui temos 3 informações:
      - nome: nome do território
      - cor: cor do exército
      - tropas: quantidade de tropas
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {

    // Criamos um vetor com 5 posições para armazenar os 5 territórios
    Territorio territorios[5];

    printf("=== Cadastro de Territorios ===\n\n");

    // Loop para cadastrar os 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do territorio %d:\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf("%s", territorios[i].nome);  // lê string sem espaços

        printf("Digite a cor do exercito: ");
        scanf("%s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Após cadastrar, mostramos tudo
    printf("\n=== Territorios cadastrados ===\n");

    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
