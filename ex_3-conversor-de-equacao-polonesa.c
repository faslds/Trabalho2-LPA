//pos ordem pra polonesa inversa

#include <stdio.h>
#include <stdlib.h>

struct arvore
{
	char entrada[1];
	struct arvore *esq;
	struct arvoer *dir;
};

posordem(struct arvore *no)
{
	if(no!=NULL)
	{
		posordem(no->esq);
		posordem(no->dir);
		printf("%s", no->entrada);
	}
}

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

void insertnum(struct arvore *no, char *k, int n) 
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
	int i = 1, j, k;
	char entrada[1], equacao[30];
	printf("Ola! Este programa ira converter uma entrada em notacao polonesa para a notacao polonesa reversa (RPN) e infixa.\n");
	printf("Digite sua equacao em notacao polonesa (separe os simbolos e numeros todos por um 'espaco'):");
	scanf("%s", entrada);
	//strcpy(equacao, entrada);
	equacao[0] = entrada[0];
	while(equacao[i] == 42 || equacao[i] == 43 || equacao[i] == 45 || equacao[i] == 47)
	{
		scanf("%s", entrada);
		//strcpy(equacao, entrada);
		equacao[i] = entrada[0];
		i++;	
	}
	k = i + 1;
	for (j = 0; j < k; j++)
	{
		scanf("%s", entrada);
		equacao[k+j] = entrada[0];
	}
	
	printf("\na sua equecao eh %s\n", equacao);
	printf("\nPolonesa reversa:\n");
	//posordem
}
