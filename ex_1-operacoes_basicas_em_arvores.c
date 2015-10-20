#include <stdio.h>

struct arvore
{
	int chave; //chave serve para o reconhecimento do item
	int dado; 
	struct arvore *esq; //cada strcut aponta para outras duas, uma a esquerda e outra a direita
	struct arvore *dir;
};

void createroot() //cria a raiz da arvore
{
	printf("Agora sera criada a raiz de sua arvore./nDigite o numero que ficara na raiz")
}

void insert(int n, struct arvore *a)
{
	int d, i=0;
	struct arvore *raiz, *p; //p ponteiro auxiliar
	while (i<n)
	{
		raiz=(struct *)malloc(sizeof(struct arvore)); //aloca dinamicamente somente o espaço para a raiz
		printf("Digite o numero na posição i:");
		scanf("%d", &d);
		if(i==0)
		{
			raiz->dado = d;
			raiz->chave = i;
			raiz->esq = NULL;
			raiz->dir = NULL;
		}
		else if (i != 0)
		{
		/*	if(d < raiz->dado && raiz esq == NULL)
			{
				p = (struct *)malloc(sizeof(struct arvore));
				p->dado = d;
				p->chave = i;
				p->esq = NULL;
				p->dir = NULL;
				raiz->esq = p;
			}
		*/
			//else if (d < raiz->dado && raiz != NULL)
			if (d < raiz->dado)
			{
				if (raiz->esq == NULL)
				{
					p = (struct *)malloc(sizeof(struct arvore));
					p->dado = d;
					p->chave = i;
					p->esq = NULL;
					p->dir = NULL;
					raiz->esq = p;
				}
				else if (raiz->esq != NULL)
				{
					p = raiz->esq;
					while (p->esq != NULL)
					{
						p = p->esq
					}
					//p = raiz->esq;
					p->esq = (struct *)malloc(sizeof(struct arvore));
					p = p->esq;
					p->dado = d;
					p->chave = i;
					p->esq = NULL;
					p->dir = NULL;
				}
			}
			else if (d >= raiz->dado)
			
		}
		
		i++;
	}
}


int main()
{
	int n;
	//struct arvore *raiz;
	printf("digite o numero que sera a raiz:")
	scanf("%d", &raiz->dado)
	
	insert(n, raiz);
	
	printf("Quantos numeros serao entrados?");
	scanf("%d", &n);
	while (n<1)
	{
		printf("Favor digitar um numero maior que 0.\n");//para que nao seja digitado um numero que de erro no programa
		scanf("%d", &n);
	}
	raiz=(struct *)malloc(sizeof(struct arvore)); //aloca dinamicamente somente a memoria necessaria
}
