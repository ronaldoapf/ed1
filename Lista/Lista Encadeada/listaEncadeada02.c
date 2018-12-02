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
        printf("Nome do Funcion�rio: %s\n", p->nome);
        printf("Sal�rio do Funcion�rio: %.2lf\n", p->salario);
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
    
    printf("Nome do funcion�rio: %s", nome);
    printf("Sal�rio do funcion�rio: %.2lf\n", x);
}


int main(){

    setlocale(LC_ALL, "Portuguese");
    struct no *novo;
    int op;
    float sl;
    char name[200];


    do{

        printf("[0] Sair\n");
        printf("[1] Cadastrar funcion�rio\n");
        printf("[2] Funcion�rio com maior sal�rio\n");
        printf("[3] M�dia da salarial dos funcion�rios\n");
        printf("[4] Digite um valor para buscar sal�rios\n");
        printf("[5] Mostrar todos os funcion�rios\n");

        printf("Sua escolha: ");

        scanf("%d", &op);

        fflush(stdin);

        printf("\n");

        switch(op){

            case 0:
                printf("Valeu falou\n");
                break;

            case 1:
                printf("Digite o nome do funcion�rio: ");
                gets(name);

                printf("Digite o sal�rio do funcion�rio: ");
                scanf("%f", &sl);

                novo = (struct no *) malloc(sizeof(struct no));

                if(!novo) printf("Sem mem�ria!!\n");
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
