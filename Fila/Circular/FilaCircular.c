#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
	int dado;
	struct no *prox;
	struct no *ant;
};

typedef struct no fila;

void inserirElemento(fila **Fila, fila *novo, int valor){
	
	fila *p = *Fila;
	novo->dado = valor;
	novo->ant = NULL;
	
	if(*Fila == NULL){
		*Fila = novo;
		novo->prox = *Fila;
		novo->ant = *Fila;
	}
	
	else{
		while(p->prox != *Fila){
			p = p->prox;
		}
		p->prox = novo;
        novo->prox = *Fila;
        novo->ant = p;
	}
	
	system("cls");
}

void removerElemento(fila **Fila){
	
	fila *p, *aux;
	p = *Fila;
	
	if(*Fila == NULL) printf("Fila vazia!\n");
	
	else{

		if(p == p->prox){
			free(p);
			*Fila = NULL;
		}
		
		else{
			
			aux = p;
			
			while(aux->prox != *Fila){
				aux = aux->prox;
			}
			
			aux->prox = p->prox;
			free(p);
			
			*Fila = p->prox;
		}
	}
	
	system("CLS");
}

void visualizarFila(fila *Fila){
	
	fila *p = Fila;
	
	if(Fila == NULL) printf("Fila vazia!\n");
	
	else{
		do{
			printf("Valor salvo: %d\n", p->dado);
			p = p->prox;
		}while(p != Fila);
	}
	printf("\n");
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	fila *inicio = NULL, *node;
	
	int x, a;
	
	do{
		
		printf("\tFila Circular\n\n");
		printf("[1] Inserir elemento\n");
		printf("[2] Remover elemento\n");
		printf("[3] Visualizar fila\n\n");
		
		printf("Sua escolha: ");
		scanf("%d", &a);
		
		printf("\n");
		
		switch(a){
			case 0:
				break;
				
			case 1:
				printf("Digite o elemento para inserir: ");
				scanf("%d", &x);
			
				node = (fila *) malloc(sizeof(fila));
				
				if(!node) printf("Memória cheia!!\n");
				
				else inserirElemento(&inicio, node, x);
				break;
				
			case 2:
				removerElemento(&inicio);
				break;
				
			case 3:
				visualizarFila(inicio);
				break;
			
		}
		
	}while(a!=0);
	
return 0;
}
