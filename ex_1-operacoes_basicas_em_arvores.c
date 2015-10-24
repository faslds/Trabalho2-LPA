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
		while (aux != NULL)
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
		if (pai->chave >= novo->chave) //aqui checa onde colocar o novo no para manter a ordenacao
		{
			pai->esq = novo;
		}
		else
		{ 
			pai->dir = novo;
		}
}


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
struct arvore *removeroot(struct arvore *no, int k)
{
	struct arvore *aux = no;
	struct arvore *pai = NULL;
	struct arvore *a = NULL; /*os ponteiros a, b, c servem para armazenar os enderecos, que serao necessarios
para a remontagem da arvore, portanto eles ficam fixos durante a execucao da funcao*/
	struct arvore *b = NULL;
	struct arvore *c = NULL;
	if (aux->dir == NULL)
	{
		return aux->esq;
		free(aux);
	}
	else if (aux->esq == NULL)
	{
		return aux->dir;
		free(aux);
	}
	else
	{
		pai = aux->dir;
		a = aux->esq;
		b = no;
		c = aux->dir;
		while (aux->esq != NULL) //encontra o "menor dos maiores que a raiz"
		{
			aux = pai->esq;
			pai = aux;
		}
		aux->esq = a; //coloca a parte da esquerda da raiz a esquerda do "menor dos maiores"
		free(b); //libera a memoria
		return c; //retorna o endereco da nova raiz, para ser passado ao ponteiro raiz na funcao main
	}
}

int search(struct arvore *no, int k)
{
	struct arvore *aux = no;
	if (aux->chave == k)
	{
		printf("O numero %d existe na ABB!", k);
		return 0;
	}
	while (aux != NULL)
	{
		if (aux->chave < k)
		{
			aux=aux->dir;
		}
		else if (aux->chave > k)
		{
			aux=aux->esq;
		}
		else
		{
			return 1;
		}
	}
	return -1;
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
	int a, c, k, n, escolha, busca, root, i=2;
	char r;
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
	
	while (escolha != 8) //repete o menu ate que seja escolhida a opcao "sair"
	{
		printf("\n\nO que voce deseja fazer? Digite o numero correspondente!\n");
		printf("1 - Buscar um numero\n2 - Impressao Em Ordem\n3 - Impressao Pre Ordem\n4 - Impressao Pos Ordem\n");
		printf("5 - Impressao em Labelled Bracketing\n6 - Inserir mais numeros\n7 - Remover numeros\n8 - Sair\n\n");
		scanf("%d", &escolha);
		if (escolha > 8) //caso seja escolhida uma opcao fora do menu, uma mensagem de erro eh impressa
		{
			printf("Favor entrar com uma das opcoes do menu.\n");
		}
		else
		{
			switch(escolha)
			{
			case 1:
				printf("\nQual numero voce quer buscar?\n");
				scanf("%d", &busca);
				if (search(raiz, busca) == 1)
				printf("\nO numero %d existe na ABB!", busca);
				else if (search(raiz, busca) == -1)
				printf("\nO numero %d nao existe na ABB!", busca);
				break;
				
			case 2:
				printf("\nImpressao Em ordem:");
				emordem(raiz);
				break;
			
			case 3:
				printf("\nImpressao Pre ordem:");
				preordem(raiz);
				break;
			
			case 4:
				printf("\nImpressao Pos ordem:");
				posordem(raiz);
				break;
			
			case 5:
				printf("\nImpressao em labelled bracketing:");
				bracketing(raiz);
				break;
			
			case 6:
				printf("Qual numero voce quer inserir?");
				scanf("%d", &a);
				insert(raiz, a);
				break;
			
			case 7:
				printf("\nQual numero voce deseja remover?");
				scanf("%d", &k);
				if (k != root)//escolhe se vai chamar a funcao pra remover a raiz ou um outro numero qualquer
				{
					removenum(raiz, k);
				}
				else
				{
					raiz = removeroot(raiz, k);
					root = raiz->chave; //"rastreia" qual eh a nova raiz, para uma possivel nova remocao no futuro
				}
				break;
			}
		}
	}
}
