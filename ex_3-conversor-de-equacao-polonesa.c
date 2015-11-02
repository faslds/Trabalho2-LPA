//pos ordem pra polonesa inversa

#include <stdio.h>
#include <stdlib.h>

struct arvore
{
	char entrada[1];
	struct arvore *esq;
	struct arvoer *dir;
};

void emordem(struct arvore*no)
{
	if(no!=NULL)
	{
		if (no->entrada <= 48 && no->entrada >=57)
		printf("(");
		emordem(no->esq);
		printf("%s", no->entrada); //aqui voce faz o que quiser quando tiver no no. imprimir chave, ou qualquer outra coisa
		emordem(no->dir);
		printf(")");
	}
}

posordem(struct arvore *lista)
{
	if(lista != NULL)
	{
		posordem(lista->esq);
		posordem(lista->dir);
		printf(" %s", lista->entrada);
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

void insertnum(struct arvore *no, char *k, int n, int i) 
{
	int count = 1;
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
		while (count < i)
		{
			aux = aux->esq;
			count++;
		}
		aux->dir = novo;
	}
	else if (n > 2)
	{
		while (no->dir == NULL)
		{
			//a = aux->esq;
			if (aux->esq->esq != NULL && aux->esq->dir != NULL && aux->dir == NULL)
			{
				aux->dir = novo;
				//printf("ultimo numero inserido!");
			}
			else 
			aux = aux->esq;
			//printf("\npassou no else\n");
		}
	}
	//printf("\nn eh %d\n", n);
}

int main()
{
	struct arvore *raiz = NULL;
	int i = 1, j = 1, k;
	char a[1], b[1];
	printf("Ola! Este programa ira converter uma entrada em notacao polonesa para a notacao polonesa reversa (RPN) e infixa.\n");
	printf("Digite sua equacao em notacao polonesa\n(separe os simbolos e numeros todos por um 'espaco' e depois tecle 'Enter'):\n");
	raiz = (struct arvore *)malloc(sizeof(struct arvore));
	raiz->esq = NULL;
	raiz->dir = NULL;
	scanf("%s", a);
	strcpy(raiz->entrada, a);
	scanf("%s", a);
	while(a[0] == 42 || a[0] == 43 || a[0] == 45 || a[0] == 47)
	{
		insertsign(raiz, a);
		scanf("%s", a);
		i++;	
	} 
	insertnum(raiz, a, j, i);
	for (j = 2; j < i + 2; j++)
	{
		scanf("%s", a);
		//printf("\n\n2i: %d \n", i);
		insertnum(raiz, a, j, i);
	}
	//printf("\naqui\n");
	printf("\nPolonesa reversa:\n");
	posordem(raiz);
	printf("\nem ordem:\n");	
	emordem(raiz);
}
