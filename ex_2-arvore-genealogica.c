#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore
{
	int grau;
	char nome[40];
	struct arvore *mae;
	struct arvore *pai;
};


struct arvore *select(struct arvore *no, char *filho)
{
	struct arvore *end = (struct arvore *)-2;
	if (no != NULL)
	{
		if (strcmp(filho, no->nome) == 0)
		{
			end = no;
		//	printf("\nachou %s", no->nome);
		}
		//printf("\n%s", no->nome);
		if (end == -2)
		{
			end = select(no->mae, filho);
		}
		if (end == -2)
		{
			end = (select(no->pai, filho));
		}
	}
	return (end);	
}

void antepassados(struct arvore *pessoa, char *filho)//, int k)
{
	//struct arvore *aux = pessoa; 
	if(pessoa!=NULL) 
	{
		if (strcmp(pessoa->nome, filho) != 0)
		{
			printf("\n%s", pessoa->nome);
		}
		antepassados(pessoa->mae, filho);
		antepassados(pessoa->pai, filho);
		//if(pessoa->grau != k)
		//{
		//}
	}
}

void bracketing(struct arvore *pessoa)//a ordem de impressao eh semelhante a do pre ordem, porem contem os []´s necessarios.
{
	if(pessoa!=NULL)
	{
		printf("[%s", pessoa->nome);
		bracketing(pessoa->mae);
		printf("]");
		bracketing(pessoa->pai);
		printf("]");
	}
	else 
	printf("[");
}

void insert(struct arvore *no, char *filho, char *mae, char *pai) //funcao para inserir pessoas na árvore
{
	struct arvore *aux = no;
	struct arvore *pont = NULL;
	
	pont = select(aux, filho);
	//printf("pos select: %s", pont->nome);
	pont->mae = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh alocada para o novo no
	pont->pai = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh alocada para o pai tambem

	strcpy(pont->mae->nome, mae);
	pont->mae->mae = NULL;
	pont->mae->pai = NULL;
	pont->mae->grau = pont->grau+1;
	
	strcpy(pont->pai->nome, pai);
	pont->pai->mae = NULL;
	pont->pai->pai = NULL;
	pont->pai->grau = pont->grau+1;
}

void parentesco(struct arvore *raiz, char *no1, char *no2)
{
	struct arvore *a = select(raiz, no1);
	struct arvore *b = select(a, no2);
	int grau;
	if(a == -2)
	{
		printf("\n%s e %s nao possuem garu de parentesco (grau = 0)\n", no1, no2);
	}
	else if (b == -2)
	{
		printf("\n%s e %s nao possuem garu de parentesco (grau = 0)\n", no1, no2);
	}
	else
	{
		grau = b->grau - a->grau;
		printf("\nO grau de parentesco entre %s e %s eh %d\n", no1, no2, grau);
	}
}

int main()
{
	struct arvore *raiz = NULL;
	int n, i=2, escolha;
	char filho[40], pai[40], mae[40], ind[40];
	printf("Ola, este programa ira montar uma arvore genealogica.\n");
	printf("Para inserir as pessoas, digite seus nomes, de 3 em 3, separados por espaco, na seguinte ordem: 'filho mae pai'");
	printf("\nQuantas dessas tuplas (grupos de 3 nomes) voce quer entrar?");
	scanf("%d", &n);
	printf("Digite a tupla 1 (a arvore toda sera feita a partir deste filho):\n");
	scanf("%s", filho);
	scanf("%s", mae);
	scanf("%s", pai);
	raiz = (struct arvore *)malloc(sizeof(struct arvore));
	raiz->grau = 0;
	strcpy(raiz->nome, filho);
	raiz->mae = NULL;
	raiz->pai = NULL;
	//printf("%s %s %s\n", filho, mae, pai);
	insert(raiz, filho, mae, pai);
	while (i <= n)
	{
		printf("Digite a tupla %d:\n", i);
		scanf("%s", filho);
		scanf("%s", mae);
		scanf("%s", pai);
		insert(raiz, filho, mae, pai);
		i++;
	}
	while (escolha != 6)
	{
	printf("\nO que voce deseja fazer? Digite o numero correspondente!\n");
	printf("1 - Imprimir membros da arvore por geracao\n2 - Imprimir os antepassados de um individuo\n");
	printf("3 - Impressao da arvore em 'labelled bracketing'\n4 - Calcular o grau de parentesco entre 2 membros\n5 - Inserir mais individuos\n6 - Sair\n\n");
	scanf("%d", &escolha);
	if (escolha > 6) //caso seja escolhida uma opcao fora do menu, uma mensagem de erro eh impressa
		{
			printf("Favor entrar com uma das opcoes do menu.\n");
		}
	else 
	{
		switch(escolha)
		{
			case 1:
				break;
			case 2:
				printf("\nVoce quer os antepassados de qual individuo?\n ");
				scanf("%s", ind);
				printf("Os antepassados de %s sao:\n", ind);
				antepassados(select(raiz, ind), ind);
				printf("\n");
				break;
			case 3:
				printf("\nImpresao em bracketing:\n");
				bracketing(raiz);
				break;
			case 4:
				printf("\nVoce quer o grau de parentesco entre quais pessoas?\nOBS:Digite o nome do mais novo e depois o do mais velho, separados por 'espaco'\n");
				scanf("%s", ind);
				scanf("%s", filho);
				parentesco(raiz, ind, filho);
				break;
			case 5:
				printf("\nDigite a tupla que voce deseja inserir: \n");
				scanf("%s", filho);
				scanf("%s", mae);
				scanf("%s", pai);
				insert(raiz, filho, mae, pai);
		}
	}
	
	}
}
