#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int pilha[TAM];
int posicaolivre = 0;

void adicionarElementoNaPilha(int informacao){
	if(posicaolivre == TAM){
		printf("Pilha cheia!\n");
		return;
	}
	pilha[posicaolivre] = informacao;
	posicaolivre++;
}

void removerElementoDaPilha(){
	if(posicaolivre == 0){
		printf("Pilha vazia!\n");
		return;
	}
	posicaolivre--;
	printf("elemento removido.\n");
}
void mostrarPilha(){
	int i = 0;
	if(posicaolivre == 0){
		printf("Pilha vazia!\n");
		return;
	}
	for(i=0;i<posicaolivre;i++){
		printf("o %d* elemento da pilha: %d\n",i+1,pilha[i]);
	}
	printf("fim da pilha.\n");
}
int main(){
	int i=0;
	for(i=0;i<TAM;i++){
		adicionarElementoNaPilha(i);
	}
	mostrarPilha();
	removerElementoDaPilha();
	mostrarPilha();
	system("pause");
return 0;
}
