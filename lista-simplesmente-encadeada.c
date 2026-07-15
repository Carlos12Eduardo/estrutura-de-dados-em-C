#include <stdio.h>
#include <stdlib.h>

typedef struct SFila
{
    int dado;
    struct SFila *next;
} Fila;

Fila *novo = NULL;
Fila *fila = NULL;
Fila *inicio = NULL;
Fila *ultimo = NULL;

void listarFila()
{
    ultimo = fila;
    int i = 1;
    if (fila == NULL)
    {
        printf("fila esta vazia.\n");
        return;
    }
    do
    {
        printf("%d - elemento: %d \n", i++, ultimo->dado);
        ultimo = ultimo->next;
    } while (ultimo != NULL);
    printf("fim da fila.\n");
}

void adicionarElementoNaFila(int informacao)
{
    ultimo = fila;
    novo = (Fila *)malloc(sizeof(Fila));
    if (!novo)
    {
        printf("memoria insuficiente.\n");
        return;
    }
    novo->dado = informacao;
    novo->next = NULL;
    if (fila == NULL)
    {
        fila = novo;
    }
    else
    {
        while (ultimo->next != NULL)
        {
            ultimo = ultimo->next;
        }
        ultimo->next = novo;
    }
    printf("elemento adicionado.\n");
}
void removerElementoDaFila()
{
    inicio = fila;
    if (fila == NULL)
    {
        printf("Fila vazia.\n");
        return;
    }
    inicio = fila->next;
    free(fila);
    fila = inicio;
    printf("Elemento removido.\n");
}

void menu()
{
    unsigned short int escolha = 0;
    int valor = 0;
    do
    {
        printf("1- adicionar elemento\n");
        printf("2- remover elemento\n");
        printf("3- listar elementos da fila\n");
        printf("0-sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &escolha);
        switch (escolha)
        {

        case 1:
            printf("digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            adicionarElementoNaFila(valor);
            break;
        case 2:
            removerElementoDaFila();
            break;
        case 3:
            listarFila();
            system("pause");
            break;
        default:
            printf("opcao invalida! tente outra: ");
        }
        system("cls");
    } while (escolha != 0);
}
int main()
{
    menu();
    system("pause");
    return 0;
}
