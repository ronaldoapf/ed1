#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct lista{
	char nome[40];
	struct lista *prox;
	struct lista *ant;
};

void inserirLista(struct lista **nomes, struct lista *novo, char nome[]){
	
	strcpy(novo->nome, nome);
	novo->ant = NULL;
	
	if(*nomes == NULL){
		*nomes = novo;
		novo->prox = NULL;
		novo->ant = *nomes;
	}
	
	else{
		/*struct lista *p = *nomes;
		
		while(p){
			if(strcmp(p->nome, nome)  0)
		}*/
		novo->prox = *nomes;
		(*nomes)->ant = novo;
		*nomes = novo;
	}
}

void mostrarLista(struct lista *nomes){
    struct lista *p;
    p = nomes;

    while(p){
        printf("Nome salvo: %s\n", p->nome);
        p = p->prox;
        printf("\n\n");
    }
}

int removerLista(struct lista **nomes, char nome[]){

	struct lista *p, *aux, *aux1;
	p = *nomes;
	int x = 0;
	
	while(p != NULL){
		if(strcmp(p->nome, nome) == 0){
			 aux = p->prox;
			 aux1 = p;
			 p = p->ant;
			 
			 if(p){
				p->prox = aux;
				aux->ant = p;
			 } 
			 
			 else {
				 aux->ant = NULL;
				 *nomes = aux;
			 }
			 
			 free(aux1);
			 x = 1;
		}
		p = p->prox;
	}
	
	return x;
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int op;
	char nome[40];
	struct lista *nomes = NULL, *node;
	
	do{
		
		printf("[1] Inserir novo nome\n");
		printf("[2] Remover nome da lista\n");
		printf("[3] Mostrar lista\n");
		printf("Sua escolha: ");
		
		scanf("%d", &op);
		printf("\n");
		
		getchar();
		
		switch(op){
			case 1:
				printf("Digite o nome para inserir: ");
				gets(nome);
				
				node = (struct lista *) malloc(sizeof(struct lista));
				
				if(!node) printf("Memória cheia!!\n");
				
				else inserirLista(&nomes, node, nome);
				break;
				
			case 2:
				printf("Digite o nome para remover: ");
				gets(nome);
				
				if(removerLista(&nomes, nome) == 1) printf("Nome encotrado e removido com sucesso\n\n");
				
				else printf("Nome não encontrado\n\n");
				break;
				
				
			case 3:
				mostrarLista(nomes);
				
				break;
		}
	}while(op!=0);
	
return 0;
}
