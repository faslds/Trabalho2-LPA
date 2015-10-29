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
	struct arvore *end = (struct arvore *)-1;
	if (strcmp(filho, no->nome) == 0)
	{
		end = no;
		printf("\nachou %s", no->nome);
	}
	printf("\n%s", no->nome);
	if (end == -1)
	{
		end = select(no->mae, filho);
		if (end == -1)
		{
			end = (select(no->pai, filho));
		}
	}
	
	return (end);
}

void antepassados(struct arvore *pessoa, int k)
{
	//struct arvore *aux = pessoa; 
	if(pessoa!=NULL)
	{
		antepassados(pessoa->mae, k);
		antepassados(pessoa->pai, k);
		if(pessoa->grau != k)
		{
		printf("\n%s", pessoa->nome);
		}
	}
}

void bracketing(struct arvore *pessoa)//a ordem de impressao eh semelhante a do pre ordem, porem contem os []�s necessarios.
{
	if(pessoa!=NULL)
	{
		printf("[%d", pessoa->nome);
		bracketing(pessoa->mae);
		printf("]");
		bracketing(pessoa->pai);
		printf("]");
	}
	else 
	printf("[");
}

void insert(struct arvore *no, char *filho, char *mae, char *pai) //funcao para inserir pessoas na �rvore
{
	struct arvore *aux = no;
	struct arvore *pont = NULL;
	
	pont = select(aux, filho);
	printf("pos select: %s", pont->nome);
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

int main()
{
	struct arvore *raiz = NULL;
	int n, i=2;
	char filho[40], pai[40], mae[40];
	printf("Ola, este programa ira montar uma arvore genealogica.\n");
	printf("Para inserir as pessoas, digite seus nomes, de 3 em 3, separados por espa�o, na seguinte ordem: 'filho mae pai'");
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
}
