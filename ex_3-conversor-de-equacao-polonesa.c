//pos ordem pra polonesa inversa

#include <stdio.h>
#include <stdlib.h>

struct arvore
{
	char entrada[1];
	struct arvore *esq;
	struct arvoer *dir;
};

void insertsign(struct arvore *no, char *k)
{
	struct arvore *aux = no;
	struct arvore *novo = (struct arvore *)malloc(sizeof(struct arvore));
	novo->esq;
	novo->dir;
	strcpy(novo->entrada, k);
	while (aux->esq != NULL)
	{
		aux = aux->esq;
	}
	aux->esq = novo;
}

void insertnum(struct arvore *no, char *k, int n) //passar os numeros ao contrario e ir so colocando a direita
{
	struct arvore *aux = no;
	struct arvore *novo = (struct arvore *)malloc(sizeof(struct arvore));
	novo->esq;
	novo->dir;
	strcpy(novo->entrada, k);
	if (n == 1)
	{
		while (aux->esq != NULL)
		{
			aux = aux->esq;
		}
		aux->esq = novo;
	}
	else if (n == 2)
	{
			while (aux->esq != NULL)
		{
			aux = aux->esq;
		}
		aux->dir = novo;
	}
	else if (n > 2)
	{
		while (no->dir == NULL)
		{
			if (aux->esq->esq != NULL && aux->esq->dir != NULL && aux->dir == NULL)
			{
				aux->dir = novo;
			}
			else 
			aux = aux->esq;
		}
	}
}

/*
void create(struct arvore *no, int k)
{	
	int n=1, k = k+4;
	char insert[1];
	printf("Digite sua operacao, separando-a por espacos:\n");
	while (n <= k)
	{
		scanf("%s", insert);
		while (no->entrada == 42 || no->entrada == 43 || no->entrada == 45 || no->entrada == 47)
		{
			struct arvore *novo = (struct arvore *)malloc(sizeof(struct arvore));
			novo->esq;
			novo->dir;
			no->esq = novo;
			novo->entrada = insert;
		}
		while (insert >= 48 && insert <= 57)
		{
			struct arvore *novo = (struct arvore *)malloc(sizeof(struct arvore));
			novo->esq;
			novo->dir;
			no->dir = novo;
			novo->entrada = insert;
		}
	}
	
}
*/

int main()
{
	char teste[1];
	printf("digite:");
	scanf("%s", teste);
	printf("o que voce digitou: %s", teste);
	printf("Digite sua operacao, separando-a por espacos:\n");
	while (n <= k)
}
