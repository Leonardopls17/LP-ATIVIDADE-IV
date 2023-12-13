#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

struct Funcionarios
{
    char nome[200];
    char cargo[200];
    float salario;
};

void menu()
{

    printf("1 ---------- ADICIONAR FUNCIONARIO\n");
    printf("2 ---------- MOSTAR MÉDIA SALARIO\n");
    printf("3 ----------   FINALIZAR PROGRAMA\n");
    printf("\n");
}

void media(float soma, int quantidade)
{
    printf("Média: %.2f", soma / (float)(quantidade + 1));
}

int main()
{

    
    setlocale(LC_ALL, "portuguese");
    int posicao = 0;
    int codigo;
    struct Funcionarios funcionario[9999];
    float soma;
   

    do
    {
        menu();
        printf("Informe o código desejado: ");
        scanf("%d", &codigo);

        fflush(stdin);
        switch (codigo)
        {
        case 1:
            printf("Informe o nome do funcionario: ");
            gets(funcionario[posicao].nome);

            printf("Informe o cargo do funcionario: ");
            gets(funcionario[posicao].cargo);

            printf("Informe o salario: ");
            scanf("%f", funcionario[posicao].salario);

            soma += funcionario[posicao].salario;

            posicao++;
            break;
        case 2:
            media(soma, posicao);
            break;
        case 3:
            sleep(2);
            printf("Finalizando o sistema\n");
            sleep(2);
            printf("Encerrando o sistema\n");
            sleep(2);
            limpatela();
            printf("Sistema encerrado\n");
            break;
        default:
            printf("CÓDIGO INVÁLIDO\nTENTE NOVAMENTE\n");
            break;
            sleep(2);
            limpatela();
        }
    } while (codigo != 3);

    getchar();
    return 0;
}
