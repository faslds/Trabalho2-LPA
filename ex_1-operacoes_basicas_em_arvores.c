#include <stdio.h>
#include <stdlib.h>

struct arvore
{
	int chave; //chave serve para o reconhecimento do item
	struct arvore *esq; //cada strcut aponta para outras duas, uma a esquerda e outra a direita
	struct arvore *dir;
};

void insert(struct arvore *no, int c) //funcao para inserir numeros
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
				if (aux->chave >= c) // aqui ele checa por onde percorrer, mantendo a arvore ordenada
				{
					aux = aux->esq;
				}
				else 
				{
					aux = aux->dir;
				}
			}
			novo = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh locada para o novo no
			novo->chave = c;
			novo->esq = NULL;
			novo->dir = NULL;
			
		/*	if (pai == NULL)
			{
				no = novo; //aqui vai alterar o endereco da raiz ne? ai altera a raiz que eu declarei na main?
				return; //precisa? pra nao entrar nos outros casos aqui embaixo
			} */
			//else 
			if (pai->chave >= novo->chave) //aqui checa onde colocar o novo no para manter a ordenacao
			{
				pai->esq = novo;
			}
			else
			{ 
				pai->dir = novo;
			}
	}
//}

int removenum(struct arvore *no, int k) //funcao para remover numeros
{
	struct arvore *aux = no;
	struct arvore *pai = NULL;
	struct arvore *a = NULL;
	struct arvore *b = NULL;
	while (aux != NULL && aux->chave != k) //aqui localiza o item a ser removida=o
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
	
	if (aux == NULL) //caso o item a ser removido nao exista, imprime uma mensagem de erro
	{
		printf("\nFavor entrar com um numero que esteja na sua arvore."); 
		return; //sai da funcao
	}	
	
	a = aux->dir;
	while (a != NULL && a->esq != NULL) //aqui seleciona parte para remontar a arvore e manter a ordenacao
	{
		a = a->esq; //procura todos a esquerda, pois serao menores que o item a ser removido
	}
	
	if (a != NULL) //dois casos para fazera remocao, dependendo se a chegou a NULL ou nao.
	{
		a->esq = aux->esq;
		b = aux->dir;
	}
	else 
	{
		b = aux->esq;
	}
	if (pai->chave >= k) //escolhe onde remontar a arvore e manter a ordenacao.
	{
		pai->esq = b;
	}
	else
	{
		pai->dir = b;
	}
	free(aux);//libera a memoria
}

//foi feita uma funcao para remover a raiz, devido a particularidade dessa situacao
/* a ideia eh fazer com que o numero a direita da raiz a ser removida seja a nova raiz, 
entao percorre e acha-se o menor numero do lado direito da arvore para a sua esquerda
toda a parte esquerda da arvore, pois ha a garantia de que toda essa parte sera menor 
que o numero selecionado (o numero selecionado eh "o menor dos maiores que a raiz". */
struct arvore *removeroot(struct arvore *no, int k, int *newroot)
{
	struct arvore *aux = no;
	struct arvore *pai = NULL;
	struct arvore *a = NULL; /*os ponteiros a, b, c servem para armazenar os enderecos, que serao necessarios
para a remontagem da arvore, portanto eles ficam fixos durante a execucao da funcao*/
	struct arvore *b = NULL;
	struct arvore *c = NULL;
	pai = aux->dir;
	a = aux->esq;
	b = no;
	c = aux->dir;
	while (aux->esq != NULL) //encontra o "menor dos maiores que a raiz"
	{
		aux = pai->esq;
		pai = aux;
	}
	//printf("%d", aux->chave);
	aux->esq = a; //coloca a parte da esquerda da raiz a esquerda do "menor dos maiores"
	//no = c;
	*newroot = c->chave; //"rastreia" qual eh a nova raiz, para uma possivel nova remocao no futuro
	free(b); //libera a memoria
	return c; //retorna o endereco da nova raiz, para ser passado ao ponteiro raiz na funcao main
}

void emordem(struct arvore*no) //vai passar por todas as chaves, em ordem crescente, e imprimir elas.
{
	if(no!=NULL)
	{
		emordem(no->esq);
		printf("\n%d", no->chave);
		emordem(no->dir);
	}
}

void preordem(struct arvore *no) //imprime em "niveis" 
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

void bracketing(struct arvore *no)//a ordem de impressao eh semelhante a do pre ordem, porem contem os []´s necessarios.
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
	int n, c, k, escolha, a, root, i=2;
	char r;
//	struct arvore *raiz = NULL;
	struct arvore * raiz = (struct arvore*) malloc(sizeof(struct arvore)); // a raiz eh alocada e feita na funcao main
    raiz->esq = NULL;
    raiz->dir = NULL;
    printf("Ola, para comecar o programa, primeiro eh preciso criar sua arvore.\n");
	printf("Quantos numeros voce quer inserir?\n");
	scanf("%d", &n);
	printf("Digite o numero na posicao 1:(sera a sua raiz) ");
		scanf("%d", &raiz->chave); //adiciona a chave na raiz
	root = raiz->chave; //"marca" a raiz, para saber quando eh necessario remover a raiz ou um outro numero qualquer
	while (i <= n)//preenche a arvore
	{
		printf("Digite o numero na posicao %d: ", i);
		scanf("%d", &c);
		insert(raiz, c);
		i++;
	}
	
	while (escolha != 7) //repete o menu ate que seja escolhida a opcao "sair"
	{
		printf("\n\nO que voce deseja fazer? Digite o numero correspondente!\n");
		printf("1 - Impressao Em Ordem\n2 - Impressao Pre Ordem\n3 - Impressao Pos Ordem\n");
		printf("4 - Impressao em Labelled Bracketing\n5 - Inserir mais numeros\n6 - Remover numeros\n7 - Sair\n\n");
		scanf("%d", &escolha);
		if (escolha > 7) //caso seja escolhida uma opcao fora do menu, uma mensagem de erro eh impressa
		{
			printf("Favor entrar com uma das opcoes do menu.\n");
		}
		else
		{
			switch(escolha)
			{
			case 1:
				printf("\nImpressao Em ordem:");
				emordem(raiz);
				break;
			
			case 2:
				printf("\nImpressao Pre ordem:");
				preordem(raiz);
				break;
			
			case 3:
				printf("\nImpressao Pos ordem:");
				posordem(raiz);
				break;
			
			case 4:
				printf("\nImpressao em labelled bracketing:");
				bracketing(raiz);
				break;
			
			case 5:
				printf("Qual numero voce quer inserir?");
				scanf("%d", &a);
				insert(raiz, a);
				break;
			
			case 6:
				printf("\nQual numero voce deseja remover?");
				scanf("%d", &k);
				if (k != root)//escolhe se vai chamar a funcao pra remover a raiz ou um outro numero qualquer
				{
					removenum(raiz, k);
				}
				else
				{
					raiz = removeroot(raiz, k, &root);
				}
				break;
			}
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
