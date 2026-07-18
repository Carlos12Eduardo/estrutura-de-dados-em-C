#include <stdio.h>
#include <stdlib.h>

/*
temos tr�s tipos de excls�es
1� n� sem filhos
2� n� com um filho
3� n� com dois filhos

n� 1� situa��o, para resolver precisamos apenas
colocar o ponteiro que armazena esse endere�o de mem�ria
apontar para NULL e excluir esse endere�o de mem�ria.

Na 2�situa��o, precisamos identificar qual filho n�o � nulo. 
Depois disso, quem armazena o endere�o do espa�o de mem�ria 
que ser� exclu�do deve apontar para o filho n�o nulo dele.

Na 3� situa��o, o comportamento ser� semelhante ao da situa��o 2
o que vai mudar � que o ficar� um n� sem raiz, para resolver isso,
temos que guardar o endere�o de mem�ria dele, percorrer o n� mais a direita 
do filho da esquerda e colocar ele para ser raiz desse n� que sobrou.
*/
typedef struct No{
	int dado;
	int fb;
	int alturaArvoreEsq;
	int alturaArvoreDir;
	struct No *esq;
	struct No *dir;
}No;

void atualizarFB(No *raiz);
No *rotacionarEsquerda(No *raiz);
No *rotacionarDireita(No *raiz);
No *rotacionarEsquerdaDireita(No *raiz);
No *rotacionarDireitaEsquerda(No *raiz);

void preOrdem(No *no){
	if(no == NULL){
		return;
	}
	printf("%d ",no->dado);
	printf(" fb do no %d: %d \n", no->dado, no->fb);
	printf("filho(s) da esquerda de %d: \n", no->dado);
	preOrdem(no->esq);
	printf("filho(s) da direita de %d: \n", no->dado);
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


No *criarNo(int dado){
	No *novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->fb = 0;
	novo->alturaArvoreEsq = 0;
	novo->alturaArvoreDir = 0;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;	
}

No *adicionarNo(No *raiz, int dado){
	if(raiz == NULL){
		return criarNo(dado);
	}
	
	if(dado < raiz->dado){
		raiz->esq = adicionarNo(raiz->esq, dado);
	}else if(dado > raiz->dado){
		raiz->dir = adicionarNo(raiz->dir, dado);
	}else{
		printf("valor ja existe!\n");
		return raiz;	
	}
	atualizarFB(raiz);
	if(raiz->fb == -2 && raiz->dir->fb == -1){
		printf("\n\n raiz %d \n\nrotacionar esquerda",raiz->dado);
		return rotacionarEsquerda(raiz);
	}
	if(raiz->fb == 2 && raiz->esq->fb == 1){
		printf("\n\n raiz %d \n\nrotacionar direita",raiz->dado);
		return rotacionarDireita(raiz);
	}
	if(raiz->fb == 2 && raiz->esq->fb == -1){
		printf("\n\n raiz %d \n\nrotacionar esquerda-direita \n\n",raiz->dado);
		return rotacionarEsquerdaDireita(raiz);
	}
	if(raiz->fb == -2 && raiz->dir->fb == 1){
		printf("\n\n raiz %d \n\nrotacionar direita-esquerda \n\n",raiz->dado);
		return rotacionarDireitaEsquerda(raiz);
	}
	
	return raiz;
}


void atualizarFB(No *raiz){
	if(raiz == NULL){
		return;
	}
	atualizarFB(raiz->esq);
	atualizarFB(raiz->dir);
	if(raiz->esq == NULL && raiz->dir == NULL){
		raiz->alturaArvoreEsq = 0;
		raiz->alturaArvoreDir = 0;
	}else if(raiz->esq == NULL && raiz->dir != NULL){
		raiz->alturaArvoreEsq = 0;
		if(raiz->dir->alturaArvoreEsq > raiz->dir->alturaArvoreDir){
			raiz->alturaArvoreDir = raiz->dir->alturaArvoreEsq + 1;	
		}else{
			raiz->alturaArvoreDir = raiz->dir->alturaArvoreDir + 1;
		}
	}else if(raiz->esq != NULL && raiz->dir == NULL){
		raiz->alturaArvoreDir = 0;
		if(raiz->esq->alturaArvoreEsq > raiz->esq->alturaArvoreDir){
			raiz->alturaArvoreEsq = raiz->esq->alturaArvoreEsq + 1;
		}else{
			raiz->alturaArvoreEsq = raiz->esq->alturaArvoreDir + 1;	
		}
		
		
	}else{
		if(raiz->esq->alturaArvoreEsq > raiz->esq->alturaArvoreDir){
			raiz->alturaArvoreEsq = raiz->esq->alturaArvoreEsq + 1;	
		}else{
			raiz->alturaArvoreEsq = raiz->esq->alturaArvoreDir + 1;	
		}
		if(raiz->dir->alturaArvoreEsq > raiz->dir->alturaArvoreDir){
			raiz->alturaArvoreDir = raiz->esq->alturaArvoreEsq + 1;	
		}else{
			raiz->alturaArvoreDir = raiz->dir->alturaArvoreDir + 1;	
		}
		
	}
	raiz->fb = raiz->alturaArvoreEsq - raiz->alturaArvoreDir; 
//	printf("\n\n");
//	printf("raiz : %d ", raiz->dado);
//	printf("altura arvore esquerda : %d ", raiz->alturaArvoreEsq);
//	printf("altura arvore direita : %d \n\n", raiz->alturaArvoreDir);
}

No *rotacionarEsquerda(No *raiz){
	No *temp = raiz;
	raiz = raiz->dir;
	temp->dir = raiz->esq;
	raiz->esq = temp;
	return raiz;
}

No *rotacionarDireita(No *raiz){
	No *temp = raiz;
	raiz = raiz->esq;
	temp->esq = raiz->dir;
	raiz->dir = temp;
	return raiz;
}

No *rotacionarEsquerdaDireita(No *raiz){
	No *temp = raiz->esq;
	raiz->esq = rotacionarEsquerda(temp);
	return rotacionarDireita(raiz);
}

No *rotacionarDireitaEsquerda(No *raiz){
	No *temp = raiz->dir;
	raiz->dir = rotacionarDireita(temp);
	return rotacionarEsquerda(raiz);
}

void atualizarNo(No *no,int valorQueDesejaAtualizar, int valorNovo){
	if(no == NULL)
		return;
	if(no->dado == valorQueDesejaAtualizar){
		no->dado = valorNovo;
	}
	atualizarNo(no->esq,valorQueDesejaAtualizar,valorNovo);
	atualizarNo(no->dir,valorQueDesejaAtualizar,valorNovo);
}

No *excluirNo(No *no, int dadoASerExcluido){
	if(no == NULL)
		return NULL;
	if(no->dado == dadoASerExcluido){
		No *destroyer = no;	
		if(no->esq == NULL && no->dir == NULL){
			no = NULL;
		}else if(no->esq != NULL && no->dir == NULL){
			no = no->esq;
		}else if(no->esq == NULL && no->dir!=NULL){
			no = no->dir;
		}else if(no->esq != NULL && no->dir != NULL){
			no = no->esq;
			No *temp = no;
			while(temp->dir!=NULL){
				temp = temp->dir;
			}
			temp->dir = destroyer->dir;
		}
		free(destroyer);
		return no;
	}
	no->esq = excluirNo(no->esq,dadoASerExcluido);
	no->dir = excluirNo(no->dir,dadoASerExcluido);
	return no;
}

int main(){
	No *raiz = NULL;
	int leitura;
//	raiz = adicionarNo(raiz,3);
//	raiz = adicionarNo(raiz,2);
//	raiz = adicionarNo(raiz,1);
//	raiz = adicionarNo(raiz,4);
//	raiz = adicionarNo(raiz,5);
//	raiz = adicionarNo(raiz,6);
//	raiz = adicionarNo(raiz,7);
//	
	
//	raiz = adicionarNo(raiz,1);
//	raiz = adicionarNo(raiz,3);
//	raiz = adicionarNo(raiz,2);
//	preOrdem(raiz);
	while(1){
		printf("digite o valor do no que deseja inserir: ");
		scanf("%d", &leitura);
		if(leitura == 0)
			break;
		raiz = adicionarNo(raiz,leitura);
	}
	
	printf("\n\ndepois de atualizar os fb\n\n");
	atualizarFB(raiz);
	printf("\n");
	preOrdem(raiz);
	printf("imprimindo em Ordem: \n");
	ordem(raiz);
	
	
	
	return 0;
}
