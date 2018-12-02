#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    int dado;
    struct no *prox;
    struct no *ant;
};
typedef struct no lista;

void inserirElemento(lista **inicio, lista *novo, int x){

    novo->dado = x;
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

void mostrarLista(lista *inicio){
    lista *p;
    p = inicio;

    while(p){
        printf("\nCódigo do produto: %d\n",p->dado);
        p = p->prox;
        printf("\n");
    }
}

void trocarPosicoes(lista **inicio, int elemA, int elemB){


}

int main(){

    setlocale(LC_ALL, "Portuguese");
    lista *node, *inicio = NULL;

    int op, x, a, b;

    do{

        printf("[1] Inserir elemento\n");
        printf("[2] Remover elemento\n");
        printf("[3] Trocar elementos de posição\n");
        printf("[4] Mostrar lista\n");
        printf("[5] Sair\n");

        printf("Sua escolha: ");

        scanf("%d", &op);

        printf("\n");

        switch(op){

            case 1:
                printf("Digite um número para inserir: ");
                scanf("%d", &x);

                node = (lista *) malloc(sizeof(lista));

                if(!node) printf("Memória cheia\n\n");

                else inserirElemento(&inicio, node, x);
                break;

            case 2:
                break;

            case 3:
                printf("Digite as posições que gostaria de trocar: ");
                printf("Posição A: ");
                scanf("%d", &a);

                printf("Posição B: ");
                scanf("%d", &b);

                trocarPosicoes(&inicio, a, b);
                break;

            case 4:
                mostrarLista(inicio);
                break;

            default:
                printf("Opção invalida!!\n\n");

        }
    }while(op!=4);

return 0;
}
