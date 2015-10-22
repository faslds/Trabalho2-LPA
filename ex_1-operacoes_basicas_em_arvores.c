#include <stdio.h>
#include <stdlib.h>

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
	
/*	if (aux == NULL)
	{
		novo = (struct arvore *)malloc(sizeof(struct arvore));
		novo->chave = c;
		novo->esq = NULL;
		novo->dir = NULL;
		aux = novo;
	}
	else
	{	
*/		while (aux != NULL)
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
			novo = (struct arvore *)malloc(sizeof(struct arvore));
			novo->chave = c;
			novo->esq = NULL;
			novo->dir = NULL;
			
		/*	if (pai == NULL)
			{
				no = novo; //aqui vai alterar o endereco da raiz ne? ai altera a raiz que eu declarei na main?
				return; //precisa? pra nao entrar nos outros casos aqui embaixo
			} */
			//else 
			if (pai->chave >= novo->chave)
			{
				pai->esq = novo;
			}
			else
			{ 
				pai->dir = novo;
			}
	}
//}

int removenum(struct arvore *no, int k)
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
	}
	
	if (aux == NULL)
	{
		printf("\nFavor entrar com um numero que esteja na sua arvore.");
		return;
	}	
	
	a = aux->dir;
	while (a != NULL && a->esq != NULL)
	{
		a = a->esq;
	}
	
	if (a != NULL)
	{
		a->esq = aux->esq;
		b = aux->dir;
	}
	else 
	{
		b = aux->esq;
	}
	if (pai->chave >= k)
	{
		pai->esq = b;
	}
	else
	{
		pai->dir = b;
	}
	free(aux);
	
	
}

void emordem(struct arvore*no) //vai passar por todas as chaves, em ordem crescente.
{
	if(no!=NULL)
	{
		emordem(no->esq);
		printf("\n%d", no->chave);
		emordem(no->dir);
	}
}

void preordem(struct arvore *no)
{
	if(no!=NULL)
	{
		printf("\n%d", no->chave);
		preordem(no->esq);
		preordem(no->dir);
	}
}

posordem(struct arvore*no)
{
	if(no!=NULL)
	{
		posordem(no->esq);
		posordem(no->dir);
		printf("\n%d", no->chave);
	}
}

void bracketing(struct arvore *no)
{
	if(no!=NULL)
	{
		printf("[%d", no->chave);
		bracketing(no->esq);
		printf("]");
		bracketing(no->dir);
		printf("]");
	}
	else 
	printf("[");
}


int main()
{
	int n, c, k, p, a, i=2;
	char r;
//	struct arvore *raiz = NULL;
	struct arvore * raiz = (struct arvore*) malloc(sizeof(struct arvore));
    raiz->esq = NULL;
    raiz->dir = NULL;
    printf("Ola, para comecar o programa, primeiro eh preciso criar sua arvore.\n");
	printf("Quantos numeros voce quer inserir?\n");
	scanf("%d", &n);
	printf("Digite o numero na posicao 1:(sera a sua raiz) ");
		scanf("%d", &raiz->chave);
	while (i <= n)
	{
		printf("Digite o numero na posicao %d: ", i);
		scanf("%d", &c);
		insert(raiz, c);
		i++;
	}
	
	while (p != 7)
	{
		printf("\n\nO que voce deseja fazer? Digite o numero correspondente!\n");
		printf("1 - Impressao Em Ordem\n2 - impressao Pre Ordem\n3 - Impressao Pos Ordem\n");
		printf("4 - Impressao em Labelled Bracketing\n5 - Inserir mais numeros\n6 - Remover numeros\n7 - Sair\n\n");
		scanf("%d", &p);
		if (p == 1)
		{
			printf("\nImpressao Em ordem:");
				emordem(raiz);
		}
		else if (p == 2)
		{
			printf("\nImpressao Pre ordem:");
				preordem(raiz);
		}
		else if (p == 3)
		{
			printf("\nImpressao Pos ordem:");
				posordem(raiz);
		}
		else if (p == 4)
		{
			printf("\nImpressao em labelled bracketing:");
				bracketing(raiz);
		}
		else if (p == 5)
		{
			printf("Qual numero voce quer inserir?");
			scanf("%d", &a);
			insert(raiz, a);
		}
		else if (p == 6)
		{
			printf("\nQual numero voce deseja remover?");
			scanf("%d", &k);
				removenum(raiz, k);
		}
		else if (p > 7)
		{
			printf("Favor entrar com uma das opcoes do menu.\n");
		}
	}
}
	
	
	

/*	printf("\nVoce deseja remover algum destes numeros? \n(Digite s para sim, ou n para nao)");
	r = getch();
	if (r==115);
	{
		while (r == 115)
		{
			printf("\nQual numero voce deseja remover?");
			scanf("%d", &k);
				removenum(raiz, k);
			printf("\nSua nova arvore esta abaixo:\n");
			printf("\n\nImpressao Em ordem:");
				emordem(raiz);
			printf("\n\nImpressao Pre ordem:");
				preordem(raiz);
			printf("\n\nImpressao Pos ordem:");
				posordem(raiz);
			printf("\n\nImpressao em labelled brackeing:");
				bracketing(raiz);
			printf("\nDeseja remover mais algum numero? \n(Digite s para sim, ou n para nao)");
			r = getch();
		}
	}

}
*/









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
