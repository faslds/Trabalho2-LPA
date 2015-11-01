//pos ordem pra polonesa inversa

#include <stdio.h>
#include <stdlib.h>

struct arvore
{
	char entrada[1];
	struct arvore *esq;
	struct arvoer *dir;
};

posordem(struct arvore *lista)
{
	if(lista != NULL)
	{
		posordem(lista->esq);
		posordem(lista->dir);
		printf("%s", lista->entrada);
	}
}

void insertsign(struct arvore *no, char *k)
{
	struct arvore *aux = no;
	struct arvore *novo = (struct arvore *)malloc(sizeof(struct arvore));
	novo->esq = NULL;
	novo->dir = NULL;
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
	struct arvore *a = NULL;
	struct arvore *novo = (struct arvore *)malloc(sizeof(struct arvore));
	novo->esq = NULL;
	novo->dir = NULL;
	strcpy(novo->entrada, k);
	//printf("\n\naqui!\n\n");
	if (n == 1)
	{
		
		while (aux->esq != NULL)
		{
			aux = aux->esq;
			//printf("\n\naqui2!\n\n");
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
		while (aux->dir == NULL)
		{
			//a = aux->esq;
			if (aux->esq->esq != NULL && aux->esq->dir != NULL && aux->dir == NULL)
			{
				aux->dir = novo;
				printf("ultimo numero inserido!");
			}
			else 
			aux = aux->esq;
			printf("\npassou no else\n");
		}
	}
	printf("\nn eh %d\n", n);
}

int main()
{
	struct arvore *raiz = NULL;
	int i = 1, j = 1, k;
	char a[1];//, equacao[30];
	printf("Ola! Este programa ira converter uma entrada em notacao polonesa para a notacao polonesa reversa (RPN) e infixa.\n");
	printf("Digite sua equacao em notacao polonesa\n(separe os simbolos e numeros todos por um 'espaco'):");
	scanf("%s", a);
	//strcpy(equacao, entrada);
	raiz = (struct arvore *)malloc(sizeof(struct arvore));
	raiz->esq = NULL;
	raiz->dir = NULL;
	strcpy(raiz->entrada, a);
	scanf("%s", a);
	while(a[0] == 42 || a[0] == 43 || a[0] == 45 || a[0] == 47)
	{
		insertsign(raiz, a);
		scanf("%s", a);
		//strcpy(equacao, entrada);
		i++;	
	} 
	//printf("\n\nfoi\n\n");
	k = i + 2;
	//printf("\n\nk: %d \n", k);
	insertnum(raiz, a, j);
	//printf("\n\nfoi2\n\n");
	for (j = 2; j < i + 2; j++)
	{
	//	printf("\n\nk: %d \n", k);
		scanf("%s", a);
	printf("\n\n2i: %d \n", i);
	//	printf("\naqui%d\n", j);
		insertnum(raiz, a, j);
	//	printf("\n\n3k: %d \n", k);
	//	printf("passou");
	//	printf("j: %d, k: %d", j, k);
	}
	printf("\naqui\n");
	printf("\nPolonesa reversa:\n");
	posordem(raiz);
}
