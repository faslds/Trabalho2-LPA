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

struct arvore *select(struct arvore *no, char filho)
{
	if (strcmp(filho, no->nome) == 0)
	{
		return no;
	}
	if(no!=NULL)
	{
		printf("\n%d", no->nome);
		preordem(no->mae);
		preordem(no->pai);
	}
}

void antepassados(struct arvore *pessoa, int k)
{
	//struct arvore *aux = pessoa; 
	if(pessoa!=NULL)
	{
		antepassados(pessoa->mae);
		antepassados(pessoa->pai);
		if(arvore->grau != k)
		{
		printf("\n%s", pessoa->nome);
		}
	}
}

void bracketing(struct arvore *pessoa)//a ordem de impressao eh semelhante a do pre ordem, porem contem os []´s necessarios.
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

void insert(struct arvore *no, char filho, char mae, char pai) //funcao para inserir pessoas na árvore
{
	struct arvore *aux = no;
	struct arvore *pont = NULL;
	
	pont = select(aux, filho);
	
	pont->mae = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh alocada para o novo no
	pont->pai = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh alocada para o pai tambem

	pont->mae->nome = mae;
	pont->mae->mae = NULL;
	pont->mae->pai = NULL;
	
	pont->pai->nome = pai;
	pont->pai->mae = NULL;
	pont->pai->pai = NULL;
	
}

int main()
{
	int n;
	char filho[40], pai[40], mae[40];
	printf("Ola, este programa ira montar uma arvore genealogica.\n");
	printf("Para inserir as pessoas, digite seus nomes, de 3 em 3, separados por espaço, na seguinte ordem: filho mae pai");
	printf("\nQuantas dessas tuplas (grupos de 3 nomes) voce quer entrar?");
	scanf("%d", &n);
	
}
