#include <stdio.h>
#include <stdlib.h>

#define TAM 10


int lista[TAM];
int posicaolivre = 0;

void adicionarElemento(int informacao){
	if(posicaolivre == TAM){
		printf("Lista Cheia!\n");
	}
	else{
		lista[posicaolivre] = informacao;
		posicaolivre++;
		printf("elemento %d foi adicionado.\n",informacao);
	}
}

void removerElemento(){
	int i=0;
	if(posicaolivre == 0){
		printf("Lista Vazia.\n");
	}else{
		posicaolivre--;
		for(i=0;i<posicaolivre;i++){
			lista[i] = lista[i+1];
		}
		printf("elemento revomido.\n");
	}
}

void mostrarLista(){
	int i=0;
	if(posicaolivre == 0){
		printf("Lista vazia!\n");
		return;
	}
	for(i=0; i<posicaolivre; i++){
		printf("o %d* elemento e: %d\n ", i+1, lista[i]);
	}
	printf("fim da lista\n");
}




int main(){
	int i =0;
	for(i=0;i<TAM;i++){
		adicionarElemento(i);
	}	
	
	adicionarElemento(20);
	mostrarLista();
	removerElemento();
	removerElemento();
	removerElemento();
	removerElemento();
	mostrarLista();
	
return 0;
}
