#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct alunos
{
    char nome[200];
    char DataNascimento[200];
    float Notas[2];
    float Media;
};

float CalcularMedia(float soma)
{
    return soma / 2;
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    int i, j;
    struct alunos aluno[5];
    int SomaNotas = 0;

    for (i = 0; i < 5; i++)
    {
        fflush(stdin);
        SomaNotas = 0;
        printf("%d Aluno\n", i + 1);
        printf("Digite seu nome: ");
        gets(aluno[i].nome);
        printf("Digite sua data de nascimento: ");
        gets(aluno[i].DataNascimento);
        for (j = 0; j < 2; j++)
        {
            printf("Digite sua %d nota: ", j + 1);
            scanf("%f", &aluno[i].Notas[j]);
            SomaNotas += aluno[i].Notas[j];
        }
        aluno[i].Media = CalcularMedia(SomaNotas);
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d Aluno\n", i + 1);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Data de nascimento: %s\n", aluno[i].DataNascimento);
        for (j = 0; j < 2; j++)
        {
            printf("%d nota: %.2f\n", j + 1, aluno[i].Notas[j]);
        }
        printf("Media: %.2f\n", aluno[i].Media);
    }

    return 0;
}
