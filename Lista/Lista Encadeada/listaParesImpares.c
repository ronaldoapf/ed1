#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    int dados;
    struct no *prox;
};

struct no *inicio, *pares, *impares;

void inserirLista(struct no *novo, int valor){

    novo->dados = valor;

    if(inicio == NULL){
        novo->prox = NULL;
        inicio = novo;
    }

    else{
        novo->prox = inicio;
        inicio = novo;
    }
}

void mostrarLista(){
    struct no *aux;

    if(inicio == NULL) printf("Lista vazia!!\n");

    else{
        aux = inicio;

        while(aux){
            printf("\nSaida: %d",aux->dados);
            aux = aux->prox;
        }
    }

    printf("\n\n");
}

void separarListas(){

    struct no *aux;
    struct no *novo;

    aux = inicio;

    if(inicio == NULL) printf("Lista vazia!!\n");

    else {
        while(aux){
            novo = (struct no *) malloc(sizeof(struct no));

            novo->prox = NULL;

            if(aux->dados%2 == 0){
                novo->dados = aux->dados;

                if(pares == NULL){
                    novo->prox = NULL;
                    pares = novo;
                }

                 else{
                    novo->prox = pares;
                    pares = novo;
                }
            }

            else{
                novo->dados = aux->dados;

                if(impares == NULL){
                    novo->prox = NULL;
                    impares = novo;
                }

                 else{
                    novo->prox = impares;
                    impares = novo;
                }
            }
            aux = aux->prox;
        }
    }
}

void mostrarListaPar(){
    struct no *aux;

    if(pares == NULL) printf("Lista vazia!!\n");

    else{
        aux = pares;

        while(aux){
            printf("\nSaida: %d",aux->dados);
            aux = aux->prox;
        }
    }

    printf("\n\n");
}

void mostrarListaImpar(){
    struct no *aux;

    if(impares == NULL) printf("Lista vazia!!\n");

    else{
        aux = impares;

        while(aux){
            printf("\nSaida: %d",aux->dados);
            aux = aux->prox;
        }
    }

    printf("\n\n");
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    struct no *node;
    int op, x;


    inicio = NULL;

    do{
        printf("[0] Sair\n");
        printf("[1] Inserir número na lista\n");
        printf("[2] Visualizar listas\n");
        printf("[3] Separar a lista em pares e impares e mostrar\n");
        printf("Sua escolha: ");

        scanf("%d", &op);

        printf("\n");

        switch(op){
            case 0:
                printf("Até mais!\n");
                break;

            case 1:
                printf("Digite o número para inserir: ");
                scanf("%d", &x);

                node = (struct no *) malloc(sizeof(struct no));

                if(!node){
                    printf("\nSem Memoria!!!");
                    return 0;
                }

                else inserirLista(node, x);
                break;

            case 2:
                mostrarLista();
                break;

            case 3:
                separarListas();
                mostrarListaPar();
                mostrarListaImpar();

        }
    }while(op!=0);
return 0;
}
