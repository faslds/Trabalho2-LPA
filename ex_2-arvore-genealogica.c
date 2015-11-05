#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore //cada struct representará uma pessoa da arvore 
{
	int grau; //cada pessoa possui um grau
	char nome[40]; //o nome da pessoa eh armazenado em uma string
	struct arvore *mae; //cada strcut aponta para outras duas, uma a esquerda e outra a direita
	struct arvore *pai;
};

/* a funcao select eh utilizada em varias partes do programa, ela eh capaz
de localizar um nome da arvore e retornar o seu endereco, fazendo parte da 
solucao do exercicio em diversos momentos*/
struct arvore *select(struct arvore *no, char *filho)
{
	struct arvore *end = (struct arvore *)-2; /*end eh usado como marcador, caso ele seja mantido inalterado, 
	o nome fornecido nao existe na arvore*/
	if (no != NULL)
	{
		if (strcmp(filho, no->nome) == 0) /*strcmp retornara 0 caso os nomes sejam iguais, o que significa 
		que o nome foi encontrado. Entao o endereco eh retornado*/
		{
			end = no;
		}
		if (end == -2)
		{
			end = select(no->mae, filho); /*eh feita com uso da recursao, pois eh necessario percorrer a arvore toda, 
			comparando cada nome com o nome fornecido*/
		}
		if (end == -2)
		{
			end = (select(no->pai, filho));
		}
	}
	return (end);	
}

/* por meio de uma estrutura recursiva, essa funcao considera o endereco passado (que foi encontrado
com a funcao select) uma subraiz da arvore, e imprime tudo que esta depois e ligado a ele, assim todos
os antepassados deste individuo sao impressos */
void antepassados(struct arvore *pessoa, char *filho)
{
	if(pessoa!=NULL) 
	{
		if (strcmp(pessoa->nome, filho) != 0) // evita que o nome dado seja impresso tambem
		{
			printf("\n%s", pessoa->nome);
		}
		antepassados(pessoa->mae, filho);
		antepassados(pessoa->pai, filho);
	}
}

void bracketing(struct arvore *pessoa)//a ordem de impressao eh semelhante a do pre ordem, porem contem os []´s necessarios.
{
	if(pessoa!=NULL)
	{
		printf("[%s", pessoa->nome);
		bracketing(pessoa->mae);
		printf("]");
		bracketing(pessoa->pai);
		printf("]");
	}
	else 
	printf("[");
}

void insert(struct arvore *no, char *filho, char *mae, char *pai) //funcao para inserir pessoas na árvore
{
	struct arvore *aux = no;
	struct arvore *pont = NULL;
	
	pont = select(aux, filho);
	//printf("pos select: %s", pont->nome);
	pont->mae = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh alocada para o novo no
	pont->pai = (struct arvore *)malloc(sizeof(struct arvore)); // memoria eh alocada para o pai tambem

	strcpy(pont->mae->nome, mae); //copia o nome fornecido para a mae na sua devida struct
	pont->mae->mae = NULL;//aterra
	pont->mae->pai = NULL;
	pont->mae->grau = pont->grau+1;//o grau desta pessoa eh 1 maior que o anterior
	
	strcpy(pont->pai->nome, pai); //copia o nome do pai na sua devida struct
	pont->pai->mae = NULL;//aterra
	pont->pai->pai = NULL;
	pont->pai->grau = pont->grau+1; //o grau desta pessoa eh 1 maior que o anterior
}

/*Esta funcao usa a funcao select para encontrar os dois nomes fornecidos. Tendo seus enderecos
eh possivel saber o grau desta determinada pessoa. Sendo assim, o grau de parentesco eh facilmente obtido
subtraindo o grau dos dois nomes fornecidos. Como eh utilizado o primeiro nome como uma subraiz 
(semelhante a funcao 'antepassdos') para achar o segundo nome, caso essas duas pessoas nao sejam da mesma
familia, essa condicao sera reconhecida e o programa dira que o grau eh 0 <zero>. */
void parentesco(struct arvore *raiz, char *no1, char *no2)
{
	struct arvore *a = select(raiz, no1);
	struct arvore *b = select(a, no2);
	int grau;
	if(a == -2)
	{
		printf("\n%s e %s nao possuem garu de parentesco (grau = 0)\n", no1, no2);
	}
	else if (b == -2)
	{
		printf("\n%s e %s nao possuem garu de parentesco (grau = 0)\n", no1, no2);
	}
	else
	{
		grau = b->grau - a->grau;
		printf("\nO grau de parentesco entre %s e %s eh %d\n", no1, no2, grau);
	}
}
/* Essa funcao utiliza o grau de cada pessoa e percorre a arvore. Como todas as pessoas
de uma mesma geracao possuem o mesmo grau, basta checar se o grau dessa pessoa eh igual ao 
da geracao em questao. Se for, essa pessoa pertence a essa geracao. Essa funcao foi feita
recursiva para que ela possa percorrer a arvore toda para buscar todas as pessoas de uma 
possivel geracao */
void geracao(struct arvore *no, int k)
{
	if(no!=NULL)
	{
		geracao(no->mae, k);
		if(no->grau == k)
		{
			printf(" %s ", no->nome);
		}
		geracao(no->pai, k);
	}
}

int main()
{
	struct arvore *raiz = NULL;
	int n, i=2, j=0, escolha;
	char filho[40], pai[40], mae[40], ind[40];
	printf("Ola, este programa ira montar uma arvore genealogica.\n");
	printf("Para inserir as pessoas, digite seus nomes, de 3 em 3, separados por espaco, na seguinte ordem: 'filho mae pai' e depois teclar 'Enter'");
	printf("\nQuantas dessas tuplas (grupos de 3 nomes) voce quer entrar?");
	scanf("%d", &n);
	while (n <= 0) //evita que seja entrado um numero que de erro no programa
	{
		printf("Favor digitar um numero maior do que 0");
		scanf("%d", &n);
	}
	printf("Digite a tupla 1 (a arvore toda sera feita a partir deste filho):\n");
	scanf("%s", filho);
	scanf("%s", mae);
	scanf("%s", pai);
	raiz = (struct arvore *)malloc(sizeof(struct arvore));
	raiz->grau = 0; // a raiz recebe grau 0
	strcpy(raiz->nome, filho);//a raiz eh criada e feita na funcao main
	raiz->mae = NULL;// a raiz eh aterrada
	raiz->pai = NULL;
	insert(raiz, filho, mae, pai); //insere os pais da raiz
	while (i <= n) //faz a leitura insercao do resto das tuplas
	{
		printf("Digite a tupla %d:\n", i);
		scanf("%s", filho);
		scanf("%s", mae);
		scanf("%s", pai);
		insert(raiz, filho, mae, pai);
		i++;
	}
	while (escolha != 6)//repete o menu ate que seja escolhida a opcao "sair"
	{
	printf("\nO que voce deseja fazer? Digite o numero correspondente!\n");
	printf("1 - Imprimir membros da arvore por geracao\n2 - Imprimir os antepassados de um individuo\n");
	printf("3 - Impressao da arvore em 'labelled bracketing'\n4 - Calcular o grau de parentesco entre 2 membros\n5 - Inserir mais individuos\n6 - Sair\n\n");
	scanf("%d", &escolha);
	if (escolha > 6) //caso seja escolhida uma opcao fora do menu, uma mensagem de erro eh impressa
		{
			printf("Favor entrar com uma das opcoes do menu.\n");
		}
	else 
	{
		switch(escolha) //o menu foi feito usando switch-case
		{
			case 1:
				j = 0;
				while (j <= n)
				{
					printf("\nGeracao %d:", j);
					geracao(raiz, j);
					printf("\n");
					j++;
				}
				break;
			case 2:
				printf("\nVoce quer os antepassados de qual individuo?\n ");
				scanf("%s", ind);
				printf("Os antepassados de %s sao:\n", ind);
				antepassados(select(raiz, ind), ind);
				printf("\n");
				break;
			case 3:
				printf("\nImpresao em bracketing:\n");
				bracketing(raiz);
				printf("\n");
				break;
			case 4:
				printf("\nVoce quer o grau de parentesco entre quais pessoas?\nOBS:Digite o nome do mais novo e depois o do mais velho, separados por 'espaco'\n");
				scanf("%s", ind);
				scanf("%s", filho);
				parentesco(raiz, ind, filho);
				break;
			case 5:
				printf("\nDigite a tupla que voce deseja inserir: \n");
				scanf("%s", filho);
				scanf("%s", mae);
				scanf("%s", pai);
				insert(raiz, filho, mae, pai);
				n++;
				break;
		}
	}
	
	}
}
