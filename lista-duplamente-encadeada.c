#include <stdio.h>
#include <stdlib.h>

typedef struct SFila{
	int dado;
    struct SFila *back;
	struct SFila *next;
}Fila;

Fila *fila = NULL;
Fila *inicio = NULL;
Fila *ultimo = NULL;
Fila *penultimo = NULL;

Fila * novoElemento(int informacao){
    Fila *novo = (Fila*) malloc(sizeof(Fila));
	if(!novo){
		printf("memoria insuficiente.\n");
		return NULL;
	}
	novo->dado = informacao;
	novo->back = NULL;
    novo->next = NULL;
    return novo;
}

void mostrarFila(){
	ultimo = fila;
	if(fila == NULL){
		printf("fila esta vazia.\n");
		return;
	}
	do{
		printf("dado: %d \n",ultimo->dado);
		ultimo = ultimo->next;
	}while(ultimo != NULL);
	printf("fim da fila.\n");
}
void adicionarElementoNoFim(int informacao){
	ultimo = fila;
	novo = (Fila*) malloc(sizeof(Fila));
	if(!novo){
		printf("memoria insuficiente.\n");
		return;
	}
	novo->dado = informacao;
	novo->next = NULL;
	if(fila == NULL){
		fila = novo;	
	}
	else{
		while(ultimo->next != NULL){
			ultimo = ultimo->next;
		}
		ultimo->next = novo;
	}
	printf("elemento adicionado.\n");
}
void adicionarElementoNoMeio(int informacao, int localizar){
	Fila *procurado = fila;
	novo = (Fila*) malloc(sizeof(Fila));
	if(!novo){
		printf("memoria insuficiente.\n");
		return;
	}
	novo->dado = informacao;
	novo->next = NULL;
	while(procurado != NULL){
		if(procurado->dado == localizar){
			novo->next = procurado->next;
			procurado->next = novo;
			printf("elemento adicionado.\n");
			return;
		}
		procurado = procurado->next;
	}
	printf("valor nao localizado.\n");
}
void adicionarElementoNoInicio(int informacao){
	inicio = fila;
	novo = (Fila*) malloc(sizeof(Fila));
	if(!novo){
		printf("memoria insuficiente.\n");
		return;
	}
	novo->dado = informacao;
	novo->next = NULL;
	if(fila == NULL){
		fila = novo;	
	}
	else{
		novo->next = inicio;
		fila = novo;
	}
	printf("elemento adicionado.\n");
}
Fila *removerElementoNoInicio(){
	inicio = fila;
	Fila *elementoRemovido;
	if(fila == NULL){
		printf("Sem elementos para remover no inicio.\n");
		return NULL;
	}else{
		fila = fila->next;
		elementoRemovido = (Fila*) malloc(sizeof(Fila));
		*elementoRemovido = *inicio;
		free(inicio);
		return elementoRemovido;	
	}
	
}
Fila *removerElementoNoFim(){
	Fila *elementoRemovido = NULL;
	if(fila == NULL){
		printf("sem elementos para remover no fim!\n");
		return NULL;
	}else{
		elementoRemovido = (Fila*) malloc(sizeof(Fila));
		ultimo = fila;
		if(ultimo->next == NULL){
			*elementoRemovido = *ultimo;
			free(ultimo);
			fila = NULL;
			return elementoRemovido;
		}
		while(ultimo->next != NULL){
			penultimo = ultimo;
			ultimo = ultimo->next;
		}
		*elementoRemovido = *ultimo;
		free(ultimo);
		penultimo->next = NULL;
		return elementoRemovido;
	}

	
}

int main(){
	int i=0;
	for(i=0;i<10;i++){
		adicionarElementoNoFim(i);
	}
	mostrarFila();
	adicionarElementoNoInicio(20);
	adicionarElementoNoMeio(11111,9);
	adicionarElementoNoFim(123);
	adicionarElementoNoFim(124);
	mostrarFila();
	while(removerElementoNoFim()){
		printf("elemento removido\n");
	}
	mostrarFila();
	system("pause");
return 0;
}
