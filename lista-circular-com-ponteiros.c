#include <stdio.h>
#include <stdlib.h>

typedef struct SLista {
  int dado;
  struct SLista * next;
} TLista;
 
 //Sentinela
TLista * lista = NULL;

void adicionar(int posicao, int informacao){

  TLista * anterior;
  TLista * novo;
  int cont;

  novo = (TLista*) malloc(sizeof(TLista));
  novo->dado = informacao;
  novo->next = NULL;

  if (lista == NULL){
    lista = novo;
    novo->next = novo;
  }
  else{ 
    anterior = lista;
    if (posicao == 1){
    	while(anterior->next != lista){
    		anterior = anterior->next;
		}
		novo->next = anterior->next;
		anterior->next = novo;
		lista = novo;
	  return;
    }
    for (cont = 2; cont < posicao && anterior->next != NULL; cont++){
      anterior = anterior->next;
    }
    novo->next = anterior->next;
    anterior->next = novo;
    }
}


void remover(int posicao){
  TLista * destroyer;
  TLista * anterior = lista;

  if (posicao == 1){
    destroyer = lista;
    if(destroyer->next == lista){
    	lista = NULL;
	}else{
      while(anterior->next != lista){
        anterior = anterior->next;
	  }
	  lista = lista->next;
	  anterior->next = lista;	
	}
  }else{
    for (int cont = 2; cont < posicao; cont++){
      anterior = anterior->next;
    }

    destroyer = anterior->next;
    anterior->next = destroyer->next;
  }

  free(destroyer);
}

void listar(){
  TLista * ultimo;
  printf("\n\nListando\n\n");
  ultimo = lista;
  do{
    printf("%d ",ultimo->dado);	
    ultimo = ultimo->next;
  }while(ultimo != lista);
}

int main(int argc, char** argv) {

  int i = 0;
  int leitura,posicao;


  while (1){
    printf("Informe a posicao e o valor: ");
    scanf("%d %d",&posicao,&leitura);
    if (leitura == 0)
      break;
    
    adicionar(posicao,leitura);
  }

  listar();
 
  printf("\nQual posicao deseja remover: ");
  scanf("%d",&posicao);
  remover(posicao);
  listar();
  

  return (EXIT_SUCCESS);
}
