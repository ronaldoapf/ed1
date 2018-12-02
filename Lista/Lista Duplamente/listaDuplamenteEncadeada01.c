#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista{
	int cod;
	float preco;
	int qtd;
	struct lista *ant;
	struct lista *prox;
};

void inserirProdutos(struct lista **produtos, struct lista *novo, int cod, float preco, int qtd){
	
	novo->cod = cod;
	novo->preco = preco;
	novo->qtd = qtd;
	
	novo->ant = NULL;
	
	if(*produtos == NULL){
		novo->prox = NULL;
		*produtos = novo;
	}
	
	else{
		novo->prox = *produtos;
		(*produtos)->ant = novo;
		*produtos = novo;
	}
}

void aplicarDesconto(struct lista **produtos, float desconto){
	
	struct lista *p;
	float pf;
	
	p = *produtos;
	
	while(p){
		pf = (p->preco*desconto)/100;
		p->preco = p->preco - pf;
		p = p->prox;		
	}
}

void mostrarLista(struct lista *produtos){
    struct lista *p;
    p = produtos;

    while(p){
        printf("\nCódigo do produto: %d\n",p->cod);
        printf("Quantidade: %d\n", p->qtd);
        printf("Preço: %.2lf\n", p->preco);
        p = p->prox;
        printf("\n\n");
    }
}

int main(){

	setlocale(LC_ALL, "Portuguese");
	struct lista *produtos = NULL, *novo;
	int op, cod, qtd, desconto;
	float preco;
	
	do{
		
		printf("[0] Sair\n");
		printf("[1] Inserir produto\n");
		printf("[2] Aplicar desconto\n");
		printf("[3] Mostrar lista\n");
		printf("Sua escolha: ");
		
		scanf("%d", &op);
		printf("\n");
		
		switch(op){
			case 1:
				
				printf("Digite o codigo do produto: ");
				scanf("%d", &cod);
				
				printf("Digite o valor do produto: ");
				scanf("%f", &preco);
				
				printf("Digite o quantidade no estoque: ");
				scanf("%d", &qtd);
				
				printf("\n");
				
				novo = (struct lista *) malloc(sizeof(struct lista));
				
				if(!novo) printf("Memória cheia!!");
				
				else inserirProdutos(&produtos, novo, cod, preco, qtd);
				break;
					
			case 2:
				printf("Digite a porcentagem a ser escontada nos produtos: ");
				scanf("%d", &desconto);
				aplicarDesconto(&produtos, desconto);
				mostrarLista(produtos);
				break;
				
			case 3:
				mostrarLista(produtos);
		}
	}while(op!=0);
	
return 0;
}
