#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    int dados;
    struct no *ant;
    struct no *prox;
};

void inserirInicio(struct no **inicio, struct no *novo, int x){

    novo->x = x;
    novo->ant = NULL;

    if(*inicio == NULL){
        *inicio = novo;
        novo->prox = NULL;
    }

    else{
        novo->prox = *inicio;
        *inicio = novo;
    }

}

int main(){

    setlocale(LC_ALL, "Portuguese");
    struct no *inicio = NULL, *novo;
    int x, op;

    do{

        printf("[0] Sair\n");
        printf("[1] Inserir elemento no in�cio\n");
        printf("[2] Inserir elemento no fim\n");
        printf("[3] Remover elemento no in�cio\n");
        printf("[4] Remover elemento no fim\n");
        printf("[5] Remover elemento espec�fico\n");
        printf("Sua escolha: ");

        scanf("%d", &op);

        printf("\n");

        switch(op){

            case 1:
                printf("Digite o n�mero que deseja inserir: ");
                scanf("%d", &x);

                novo = (struct no *) malloc(sizeof(struct no));

                if(!novo) printf("Mem�ria cheia!\n");

                else inserirInicio(&inicio, &novo, x);
                break;
        }

    }while(op!=);

return 0;
}
