#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>



struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};


float calcularTotalEstoque(struct Produto produto) {
    return produto.preco * produto.quantidadeEstoque;
}

void realizarCompra(struct Produto *produto, int quantidadeComprada) {
    if (quantidadeComprada > 0) {
        produto->quantidadeEstoque += quantidadeComprada;
        printf("%d unidades de %s compradas com sucesso!\n", quantidadeComprada, produto->nome);
    } else {
        printf("Quantidade inválida.\n");
    }
}


void consultarEstoque(struct Produto produto) {
    printf("Nome do produto: %s\n", produto.nome);
    printf("Preço unitário: R$%.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("Valor total em estoque: R$%.2f\n", calcularTotalEstoque(produto));
}

int main() {
     setlocale(LC_ALL, "portuguese");
    struct Produto meuProduto;
    strcpy(meuProduto.nome, "Produto X");
    meuProduto.preco = 10.50;
    meuProduto.quantidadeEstoque = 50;

    int opcao, quantidade;

    do {
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade a comprar: ");
                scanf("%d", &quantidade);
                realizarCompra(&meuProduto, quantidade);
                break;
            case 2:
                consultarEstoque(meuProduto);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}