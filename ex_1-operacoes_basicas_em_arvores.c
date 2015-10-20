#include <stdio.h>

struct arvore
{
	int chave; //chave serve para o reconhecimento do item
	struct arvore *esq; //cada strcut aponta para outras duas, uma a esquerda e outra a direita
	struct arvore *dir;
};

void insert(struct arvore *no, int c)
{
	struct arvore *aux = no;
	struct arvore *pai = NULL;
	struct arvore *novo = NULL;	
		while (aux != NULL)
		{
			pai = aux;
			if (aux->chave >= c)
			{
				aux = aux->esq;
			}
			else 
			{
				aux = aux->dir;
			}
		}
		novo = (struct *)malloc(sizeof(struct arvore));
		novo->chave = c;
		novo->esq = NULL;
		novo->dir = NULL;
		
		if (pai == NULL)
		{
			no = novo; //aqui vai alterar o endereco da raiz ne? ai altera a raiz que eu declarei na main?
			return; //precisa? pra nao entrar nos outros casos aqui embaixo
		}
		else if (pai->chave >= novo->chave)
		{
			pai->esq = novo;
		}
		else
		{ 
			pai->dir = novo;
		}
		
}

int remove (struct arvore *no, int k)
{
	struct arvore *aux = no;
	struct arvore *pai = NULL;
	struct arvore *a = NULL;
	struct arvore *b = NULL;
	while (aux != NULL && aux->chave != k)
	{
		pai = aux;
		if (aux->chave >= k)
		{
			aux = aux->esq;
		}
		else 
		{
			aux = aux->dir;
		}
	return -1;
	}
	
	a = aux->dir;
	while (a != NULL && a->esq != NULL)
	{
		a = a->esq
	}
	
	if (a != NULL)
	
	
}

int main()
{
	int n, c, i=1;
	struct arvore *raiz = NULL;
	printf("Quantos números serão inseridos?\n");
	scanf("%d", &n);
	while (i <= n)
	{
		printf("\nDigite o numero na posicao i: ");
		scanf("%d", &c);
		insert(raiz, c);
		i++;
	}
	
}










/*void createroot() //cria a raiz da arvore
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
			//raiz->dado = d;
			raiz->chave = d;
			raiz->esq = NULL;
			raiz->dir = NULL;
		}
		else if (i != 0)
		{
			if(d < raiz->dado && raiz esq == NULL)
			{
				p = (struct *)malloc(sizeof(struct arvore));
				p->dado = d;
				p->chave = i;
				p->esq = NULL;
				p->dir = NULL;
				raiz->esq = p;
			}
		
			//else if (d < raiz->dado && raiz != NULL)
			if (d < raiz->chave)
			{
				if (raiz->esq == NULL)
				{
					p = (struct *)malloc(sizeof(struct arvore));
					//p->dado = d;
					p->chave = d;
					p->esq = NULL;
					p->dir = NULL;
					raiz->esq = p;
				}
				else if (raiz->esq != NULL && d <  )
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
			{
				
			}
			
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
*/
