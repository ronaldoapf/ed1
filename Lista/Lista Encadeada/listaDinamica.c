#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int dados;
    struct no *prox;
}noptr;

noptr *inicio;

void insere_lista(noptr *novo, int valor);
void lista_todos();
void remove_lista();
void lista_todos();

int main(){

    int recebe, op;

    inicio=NULL;
    noptr *info;

    do{

        printf("[0] Sair\n");
        printf("[1] Inserir no inicio da lista\n");
        printf("[2] Inserir no fim da lista\n");
        printf("[3] Remover toda a lista\n");
        printf("[4] Remover ao contrario\n");
        printf("Escolha: ");

        scanf("%d", &op);

        printf("\n");

        switch(op){

            case 0:
                printf("VALEU FALOOOU!\n");
                break;

            case 1:
                printf("Digite um valor: ");
                scanf("%d",&recebe);
                printf("\n");

                info=(struct no *) malloc(sizeof(noptr));

                if(!info){
                    printf("\nSem Memoria!!!");
                    return 0;
                }
                insere_listaInicio(info,recebe);
                break;

            case 2:
                printf("Digite um valor: ");
                scanf("%d",&recebe);
                printf("\n");

                info=(struct no *) malloc(sizeof(noptr));

                if(!info){
                    printf("\nSem Memoria!!!");
                    return 0;
                }

                insere_listaFim(info,recebe);
                break;

            case 3:
                remove_all();
                break;

            case 4:
                remove_last();
                break;



            default:
                printf("Digite uma opcao valida\n\n");
        }

    }while(op!=0);
}

void insere_listaInicio(noptr *novo, int valor){
    novo->dados=valor;

    if(inicio==NULL) {
        novo->prox = NULL;
        inicio = novo;
    }

    else{
        novo->prox=inicio;
        inicio=novo;
    }
    printf("\n");
}

void insere_listaFim(noptr *novo, int valor){

    noptr *p;
    novo->dados=valor;
    novo->prox = NULL;

    if(inicio==NULL) inicio=novo;

    else{
        p=inicio;

    while(p->prox!=NULL)
        p=p->prox;
        p->prox=novo;
    }
    printf("\n");
}

void remove_all(){
    noptr *p;

    if(inicio==NULL){
        printf("\nLista Vazia!!!");
        return;
    }

    else{

        while(inicio!=NULL){
            p=inicio;
            printf("\nValor Removido: %d\n",p->dados);
            inicio=p->prox;
            free(p);
        }
    }
    printf("\n");
}

void lista_todos(){

    if(inicio==NULL) {
        printf("\nLista Vazia!!!");
        return;
    }

    noptr *p;
    p = inicio;

    while(p) {
        printf("\nSaida: %d",p->dados);
        p = p->prox;
    }

    printf("\n");
}

void remove_last(){

    noptr *p, *ant;

    if(inicio==NULL){
        printf("\nLista Vazia!!!\n\n");
        return;
    }

    else{

        while(inicio != p){
            p=inicio;
            while(p->prox!=NULL){
                ant=p;
                p=p->prox;
            }
            printf("\nValor Removido: %d",p->dados);
            ant->prox=NULL;
            free(p);
        }
            inicio = NULL;

    }
    printf("\n");
}

