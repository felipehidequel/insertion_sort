#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.c"

#define N_FUNCIONARIOS 10

int main() {
    int opcao;
    Funcionario **funcs = (Funcionario **)malloc(N_FUNCIONARIOS * sizeof(Funcionario *));
    int numFuncionarios = 0;
    FILE* arquivo = abrir_arquivo(funcs, &numFuncionarios);
    

    char nome[50];
    char cargo[50];
    int documento;

    do {
        printf("-- BEM VINDO --\n");
        printf("-- DIGITE A OPCAO DESEJADA --\n");
        printf("1-- CADASTRAR FUNCIONARIO --\n");
        printf("2-- LISTAR FUNCIONARIO\n");
        printf("3-- SAIR\n");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
            if (numFuncionarios < N_FUNCIONARIOS){
                printf("Digite o nome do funcionario: ");
                scanf("%s", nome);
                printf("Digite o cargo do funcionario: ");
                scanf("%s", cargo);
                printf("Digite o numero do documento do funcionario: ");
                scanf("%d", &documento);                
                funcs[numFuncionarios] = cria_funcionario(nome, cargo, documento);
                numFuncionarios++; 
                break;
            }
            else{
                printf("Limite de funcionarios atingido");
                break;
            }
            case 2:
                if(numFuncionarios != 0){
                    imprime(funcs, numFuncionarios);
                }
                else{
                    printf("Nenhum Funcionario Cadastrado!\n");
                }

                break;
            default:
                break;
        }
    } while (opcao != 3);

    grava_arquivo(funcs, numFuncionarios);

    // Libera a memoria alocada para os funcionarios
    for (int i = 0; i < numFuncionarios; i++) {
        free(funcs[i]);
    }
    free(funcs);
    return 0;
}