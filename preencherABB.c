#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No *esq;
	struct No *dir;	
}No;

void preOrdem(No *no){
	if(no == NULL)
		return;
	printf("%d ", no->dado);
	preOrdem(no->esq);
	preOrdem(no->dir);	
};

No *preencherABB(No *no, int dado){
	if(no == NULL){
		No *novo = (No*) malloc(sizeof(No*));
		novo->dado = dado;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}
	if(dado<no->dado)
		no->esq = preencherABB(no->esq,dado);
	else if(dado>no->dado)
		no->dir = preencherABB(no->dir,dado);
	else
		return no;
}

int main(){
	int escolha;
	No *raiz = NULL;
	while(1){
		printf("digite um numero que deseja adicionar: ");
		scanf("%d",&escolha);
		if(escolha == 0)
			break;
		raiz = preencherABB(raiz,escolha);
	};
	preOrdem(raiz);
	
return 0;
}
