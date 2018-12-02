#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
	int x;
	struct no *prox;
};

w
void remover(struct no **lista){

	struct no *p;

	if(*lista == NULL) printf("Lista cheia!!\n");

	else{
		p = *lista;

		p = p->prox;
		*lista = p->prox;
	}

}

void listaTodos(struct no *lista){

	struct no *p;
	p = lista;

	while(p!=NULL){
		printf("Dados: %d\n", p->x);
		p = p->prox;
	}
}

int main(){

	struct no *inicio = NULL, *info;
	int x, op;

	do{

		printf("[1] Inserir na lista\n");
		printf("[2] Remover da lista\n");
		printf("[3] Mostrar todos\n");
		printf("Sua escolha: ");

		scanf("%d", &op);

		printf("\n");

		switch(op){
			case 1:
				printf("Digite o numero: ");
				scanf("%d", &x);

				info = (struct no *) malloc(sizeof(struct no));
				inserir(&inicio, info, x);
				break;

			case 2:
				remover(&inicio);
				break;

			case 3:
				listaTodos(inicio);
				break;
		}
	}while(op!=0);
return 0;
}
