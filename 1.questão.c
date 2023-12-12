#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Contato {
    char nome[50];
    char numeroTelefone[20];
    char email[50];
};

char* buscarNumeroTelefone(struct Contato contatos[], int tamanho, char* nome) {
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return contatos[i].numeroTelefone;
        }
    }
    return "Contato não encontrado";
}

int main() {
   
   setlocale(LC_ALL, "portuguese");
   
    struct Contato contatos[3];

    for (int i = 0; i < 3; ++i) {
        printf("Digite o nome do contato %d: ", i + 1);
        scanf("%s", contatos[i].nome);
        printf("Digite o número de telefone do contato %d: ", i + 1);
        scanf("%s", contatos[i].numeroTelefone);
        printf("Digite o email do contato %d: ", i + 1);
        scanf("%s", contatos[i].email);
    }

    char nomeBusca[50];
    printf("\nDigite o nome do contato que deseja buscar: ");
    scanf("%s", nomeBusca);

    char* numeroEncontrado = buscarNumeroTelefone(contatos, 3, nomeBusca);
    printf("O número de telefone de %s é: %s\n", nomeBusca, numeroEncontrado);

    return 0;
}