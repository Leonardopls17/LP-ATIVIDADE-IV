#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

// Definição da estrutura Funcionario
struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
};

// Função para calcular a média salarial dos funcionários com um cargo específico
float mediaSalarialPorCargo(struct Funcionario funcionarios[], int numFuncionarios, const char* cargo) {
    float somaSalarios = 0.0;
    int contador = 0;

    for (int i = 0; i < numFuncionarios; ++i) {
        if (strcmp(funcionarios[i].cargo, cargo) == 0) {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador == 0) {
        printf("Nenhum funcionário com o cargo de %s encontrado.\n", cargo);
        return 0.0;
    }

    return somaSalarios / contador;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS] = {
        {"Joao", "Programador", 3000.00},
        {"Maria", "Gerente", 5000.00},
        {"Pedro", "Programador", 3500.00},
        {"Ana", "Analista", 4000.00},
        // Adicione mais funcionários conforme necessário...
    };

    int numFuncionarios = 4; // Altere de acordo com o número de funcionários inseridos no array

    const char cargoBusca[] = "Programador";
    float mediaSalarioProgramadores = mediaSalarialPorCargo(funcionarios, numFuncionarios, cargoBusca);

    if (mediaSalarioProgramadores > 0.0) {
        printf("Média salarial dos programadores: R$%.2f\n", mediaSalarioProgramadores);
    }

    return 0;
}
