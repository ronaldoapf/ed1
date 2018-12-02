#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct no{
    char nome[200];
    float salario;
    struct no *prox;
};

struct no *funcionarios = NULL;

void inserirFuncionario(struct no *novo, char name[], float salario){

    strcat(novo->nome, name);
    novo->salario = salario;

    if(funcionarios == NULL){
        novo->prox = NULL;
        funcionarios = novo;
    }

    else{
        novo->prox = funcionarios;
        funcionarios = novo;
    }
    printf("\n");
}

void imprimir(){

    struct no *p;

    p = funcionarios;

    while(p != NULL){
        printf("Nome do Funcionário: %s\n", p->nome);
        printf("Salário do Funcionário: %.2lf\n", p->salario);
        p = p->prox;
        printf("\n\n");
    }

}


void maiorSalario(){

    struct no *p;
    double x = 0;
    char nome[200];

    p = funcionarios;

    while(p->prox != NULL){
        if(p->salario > x){
            x = p->salario;
            strcat(p->nome, nome);
        }
    }
    
    printf("Nome do funcionário: %s", nome);
    printf("Salário do funcionário: %.2lf\n", x);
}


int main(){

    setlocale(LC_ALL, "Portuguese");
    struct no *novo;
    int op;
    float sl;
    char name[200];


    do{

        printf("[0] Sair\n");
        printf("[1] Cadastrar funcionário\n");
        printf("[2] Funcionário com maior salário\n");
        printf("[3] Média da salarial dos funcionários\n");
        printf("[4] Digite um valor para buscar salários\n");
        printf("[5] Mostrar todos os funcionários\n");

        printf("Sua escolha: ");

        scanf("%d", &op);

        fflush(stdin);

        printf("\n");

        switch(op){

            case 0:
                printf("Valeu falou\n");
                break;

            case 1:
                printf("Digite o nome do funcionário: ");
                gets(name);

                printf("Digite o salário do funcionário: ");
                scanf("%f", &sl);

                novo = (struct no *) malloc(sizeof(struct no));

                if(!novo) printf("Sem memória!!\n");
                else inserirFuncionario(novo, name, sl);
                break;

            case 2:
                maiorSalario();
                break;

                case 5:
                    imprimir();
                    break;
        }

    }while(op!=0);


return 0;
}
