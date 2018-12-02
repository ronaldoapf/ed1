#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
	int cod;
	double preco;
	int qtd;
	struct no *prox;
};

struct no *produtos = NULL;

void inserirProduto(struct no *novo, int codigo, double preco, int qtd){

    novo->cod = codigo;
    novo->preco = preco;
    novo->qtd = qtd;

    if(produtos == NULL){
        novo->prox = NULL;
    }

    else{
        novo->prox = produtos;
    }
    produtos = novo;
    printf("\n");
}

void verificarProdutos(){
    struct no *p;
    p = produtos;

    while(p){
        printf("\nCódigo do produto: %d\n",p->cod);
        printf("Quantidade: %d\n", p->qtd);
        printf("Preço: %.2lf\n", p->preco);
        p = p->prox;
        printf("\n\n");
    }
}

void ajustarPrecos(int ajuste){

    struct no *p;
    double pf;

    p = produtos;

    while(p!=NULL){
        pf = (p->preco*ajuste)/100;
        p->preco = p->preco - pf;
        p = p->prox;
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int op, x, cod, qtd, porcentagem;
    double preco;
	struct no *novo;

	do{

        printf("[1] Cadastrar novo produto\n");
        printf("[2] Verificar produtos cadastrados\n");
        printf("[3] Ajustar preço dos produtos\n");
        printf("Sua escolha: ");

        scanf("%d", &op);

        printf("\n\n");

        switch(op){

            case 0:
                printf("Valeu Falou!\n\n");
                break;

            case 1:
                printf("Digite o número do novo produto: ");
                scanf("%d", &cod);

                printf("Digite o preço do produto: ");
                scanf("%lf", &preco);

                printf("Digite a quantidade em estoque: ");
                scanf("%d", &qtd);

                novo = (struct no *) malloc(sizeof(struct no));

                if(!novo) printf("Memória cheia!\n");

                else inserirProduto(novo, cod, preco, qtd);
                break;

            case 2:
                verificarProdutos();
                break;

            case 3:
                printf("Digite a porcentagem a ser ajustada: ");
                scanf("%d", &porcentagem);

                ajustarPrecos(porcentagem);
        }

	}while(op!=0);

return 0;
}
