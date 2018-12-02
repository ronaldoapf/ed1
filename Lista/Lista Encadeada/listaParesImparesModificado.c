#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    int dados;
    struct no *prox;
};

void inserirLista(struct no **lista, struct no *novo, int valor){

    novo->dados = valor;

    if(*lista == NULL){
        novo->prox = NULL;
        *lista = novo;
    }

    else{
        novo->prox = *lista;
        *lista = novo;
    }
}

void mostrarLista(struct no *lista){
    struct no *aux;

    if(lista == NULL) printf("Lista vazia!!\n");

    else{
        aux = lista;

        while(aux){
            printf("\nSaida: %d",aux->dados);
            aux = aux->prox;
        }
    }

    printf("\n\n");
}

void separarListas(struct no **lista, struct no **listaPar, struct no **listaImpar){

    struct no *aux;
    struct no *novo;

    aux = *lista;

    if(*lista == NULL) printf("Lista vazia!!\n");

    else {
        while(aux){
            novo = (struct no *) malloc(sizeof(struct no));

            novo->prox = NULL;

            if(aux->dados%2 == 0){
                novo->dados = aux->dados;

                if(*listaPar == NULL){
                    novo->prox = NULL;
                    *listaPar = novo;
                }

                 else{
                    novo->prox = *listaPar;
                    *listaPar = novo;
                }
            }

            else{
                novo->dados = aux->dados;

                if(*listaImpar == NULL){
                    novo->prox = NULL;
                    *listaImpar = novo;
                }

                 else{
                    novo->prox = *listaImpar;
                    *listaImpar = novo;
                }
            }
            aux = aux->prox;
        }
    }
}

void mostrarListaPar(struct no *listaPar){
    struct no *aux;

    if(listaPar == NULL) printf("Lista vazia!!\n");

    else{
        aux = listaPar;

        while(aux){
            printf("\nSaida: %d",aux->dados);
            aux = aux->prox;
        }
    }

    printf("\n\n");
}

void mostrarListaImpar(struct no *listaImpar){
    struct no *aux;

    if(listaImpar == NULL) printf("Lista vazia!!\n");

    else{
        aux = listaImpar;

        while(aux){
            printf("\nSaida: %d",aux->dados);
            aux = aux->prox;
        }
    }

    printf("\n\n");
}

int main(){

    setlocale(LC_ALL, "Portuguese");
	
    struct no *node, *inicio = NULL, *pares = NULL, *impares = NULL;
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

                else inserirLista(&inicio, node, x);
                break;

            case 2:
                mostrarLista(inicio);
                break;

            case 3:
                separarListas(&inicio, &pares, &impares);
                mostrarListaPar(pares);
                mostrarListaImpar(impares);

        }
    }while(op!=0);
return 0;
}
