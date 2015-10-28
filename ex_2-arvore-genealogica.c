#include <stdio.h>
#include <stdlib.h>


struct arvore
{
	int grau;
	char nome[40];
	struct arvore *mae;
	struct arvore *pai;
};

void antepassados(struct arvore *pessoa, int k)
{
	struct arvore *aux = pessoa; 
	if(pessoa!=NULL)
	{
		posordem(pessoa->mae);
		posordem(pessoa->pai);
		if(arvore->grau != k)
		{
		printf("\n%s", pessoa->nome);
		}
	}
}


