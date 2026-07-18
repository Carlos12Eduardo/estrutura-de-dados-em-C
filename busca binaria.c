#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No *esq;
	struct No *dir;
}No;

No *buscaBinaria(No *no, int chave){
	No *encontrado = NULL;
	if(no == NULL)
        return NULL;
    if(chave > no->dado){
    	encontrado = buscaBinaria(no->dir,chave);
    	return encontrado;
	}
	else if(chave < no->dado){
    	encontrado = buscaBinaria(no->esq,chave);
    	return encontrado;
	}else{
		return no;
	}
	return NULL;
}

void preOrdem(No *no){
	if(no == NULL){
		return;
	}
	printf("%d ",no->dado);
	preOrdem(no->esq);
	preOrdem(no->dir);
}

void ordem(No *no){
	if(no == NULL){
		return;
	}
	ordem(no->esq);
	printf("%d ",no->dado);
	ordem(no->dir);
}


int main(){
	No *raiz = (No*) malloc(sizeof(No));raiz->dado = 8;raiz->esq = raiz->dir = NULL;
	No *no1 = (No*) malloc(sizeof(No));no1->dado = 5;no1->esq = no1->dir = NULL;
	No *no2 = (No*) malloc(sizeof(No));no2->dado = 10;no2->esq = no2->dir = NULL;
	No *no3 = (No*) malloc(sizeof(No));no3->dado = 3;no3->esq = no3->dir = NULL;
	No *no4 = (No*) malloc(sizeof(No));no4->dado = 6;no4->esq = no4->dir = NULL;
	
    raiz->esq = no1;
    raiz->dir = no2;
    no1->esq = no3;
    no1->dir = no4;
    No *resultado = buscaBinaria(raiz,15);
    if(resultado != NULL)
        printf("valor encontrado.");
    else
        printf("valor nao encontrado.");
        
    preOrdem(raiz);    
	return 0;
}
