#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *prox;
};

struct no *lista1 = NULL;
struct no *lista2 = NULL;

void inserirLista1(struct no *novo, int x){

    novo->dado = x;

    if(lista1 == NULL){
        novo->prox = NULL;
        lista1 = novo;
    }

    else{
        novo->prox = lista1;
        lista1 = novo;
    }

}

void inserirLista2(struct no *novo, int x){

     novo->dado = x;

    if(lista2 == NULL){
        novo->prox = NULL;
        lista2 = novo;
    }

    else{
        novo->prox = lista2;
        lista2 = novo;
    }
}

void juntarListas(){

    struct no *p;
    p = lista1;

    while(p->prox != NULL){
        p=p->prox;
    }

    p->prox = lista2;

}

void imprimir(){

    struct no *p;
    p = lista1;

    while(p){
        printf("\nSaida: %d",p->dado);
        p = p->prox;
    }
    printf("\n\n");
}

int main(){

	int op, x;
	struct no *novo;

	do{

        printf("[0] Sair\n");
        printf("[1] Inserir elementos na primeira lista\n");
        printf("[2] Inserir elementos na segunda lista\n");
        printf("[3] Juntar listas\n");
        printf("[4] Imprimir\n");
        printf("Sua escolha: ");

        scanf("%d", &op);

        printf("\n");


        switch(op){
            case 0:
                printf("VALEU FALOU!\n");
                break;

            case 1:
                printf("Digite o numero que gostaria de inserir: ");
                scanf("%d", &x);

                novo = (struct no *) malloc(sizeof(struct no));

                if(!novo) printf("Sem memoria!!\n");

                else inserirLista1(novo, x);
                break;

            case 2:
                printf("Digite o numero que gostaria de inserir: ");
                scanf("%d", &x);

                novo = (struct no *) malloc(sizeof(struct no));

                if(!novo) printf("Sem memoria!!\n");

                else inserirLista2(novo, x);
                break;

            case 3:
                juntarListas();
                break;

            case 4:
                imprimir();
                break;

            default:
                printf("Opcao invalida\n");
        }
	}while(op!=0);

return 0;
}
