#include <stdio.h>
#include <stdlib.h>

typedef struct SFila
{
    int dado;
    struct SFila *back;
    struct SFila *next;
} Fila;

Fila *novoElemento(int informacao)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    if (!novo)
    {
        printf("memoria insuficiente.\n");
        return NULL;
    }
    novo->dado = informacao;
    novo->back = NULL;
    novo->next = NULL;
    return novo;
}

void mostrarFilaSentidoLR(Fila **inicioDaFila)
{
    Fila *ultimo = *inicioDaFila;
    int i = 1;
    if (*inicioDaFila == NULL)
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
void mostrarFilaSentidoRL(Fila **fimDaFila)
{
    Fila *inicio = *fimDaFila;
    int i = 1;
    if (*fimDaFila == NULL)
    {
        printf("fila esta vazia.\n");
        return;
    }
    do
    {
        printf("%d - elemento: %d \n", i++, inicio->dado);
        inicio = inicio->back;
    } while (inicio != NULL);
    printf("fim da fila.\n");
}

void mostrarFila(Fila **inicioDaFila, Fila **fimDaFila, char *sentido)
{
    if (sentido == "LR")
    {
        printf("listando do inicio ao fim\n");
        mostrarFilaSentidoLR(inicioDaFila);
    }
    else if (sentido == "RL")
    {
        printf("listando do fim ao inicio\n");
        mostrarFilaSentidoRL(fimDaFila);
    }
    else
    {
        printf("sentido de impressao nao reconhecido. O campo de sentido aceita os modos: \n LR - Left -> right \n RL - right -> left");
        printf("listando com o padrao LR");
        mostrarFilaSentidoLR(inicioDaFila);
    }
}

void adicionarElementoNoFim(Fila **inicioDaFila, Fila **fimDaFila, int informacao)
{
    Fila *novo = novoElemento(informacao);
    if (!novo)
    {
        printf("memoria insuficiente.\n");
        return;
    }
    if (*inicioDaFila == NULL)
    {
        *inicioDaFila = *fimDaFila = novo;
        printf("primeiro elemento adicionado");
        return;
    }

    (*fimDaFila)->next = novo;
    novo->back = *fimDaFila;
    *fimDaFila = novo;
    printf("elemento adicionado.\n");
}

void adicionarElementoNoMeio(Fila **inicioDaFila, Fila **fimDaFila, int informacao, int localizar)
{
    Fila *procurado = *inicioDaFila;
    Fila *novo = novoElemento(informacao);
    if (!novo)
    {
        printf("memoria insuficiente.\n");
        return;
    }
    while (procurado != NULL)
    {
        if (procurado->dado == localizar)
        {
            if (procurado->next == NULL)
            {
                adicionarElementoNoFim(inicioDaFila, fimDaFila, informacao);
                return;
            }
            novo->next = procurado->next;
            novo->back = procurado;
            procurado->next->back = novo;
            procurado->next = novo;

            printf("elemento adicionado.\n");
            return;
        }
        procurado = procurado->next;
    }
    printf("valor nao localizado.\n");
}

void adicionarElementoNoInicio(Fila **inicioDaFila, int informacao)
{
    Fila *novo = novoElemento(informacao);
    if (!novo)
    {
        printf("memoria insuficiente.\n");
        return;
    }
    if (*inicioDaFila == NULL)
    {
        *inicioDaFila = novo;
    }
    else
    {
        novo->next = *inicioDaFila;
        *inicioDaFila = novo;
    }
    printf("elemento adicionado.\n");
}

Fila *removerElementoNoInicio(Fila **inicioDaFila)
{
    Fila *inicio = *inicioDaFila;
    Fila *elementoRemovido;
    if (*inicioDaFila == NULL)
    {
        printf("Sem elementos para remover no inicio.\n");
        return NULL;
    }
    else
    {
        *inicioDaFila = (*inicioDaFila)->next;
        (*inicioDaFila)->back = NULL;
        elementoRemovido = (Fila *)malloc(sizeof(Fila));
        *elementoRemovido = *inicio;
        free(inicio);
        return elementoRemovido;
    }
}

Fila *removerElementoNoFim(Fila **fimDaFila)
{
    Fila *ultimo = *fimDaFila;
    Fila *elementoRemovido = NULL;
    if (*fimDaFila == NULL)
    {
        printf("sem elementos para remover no fim!\n");
        return NULL;
    }
    else
    {
        elementoRemovido = (Fila *)malloc(sizeof(Fila));
        *fimDaFila = (*fimDaFila)->back;
        (*fimDaFila)->next = NULL;
        *elementoRemovido = *ultimo;
        free(ultimo);
        return elementoRemovido;
    }
}

int main()
{
    Fila *inicioDaFila = NULL;
    Fila *fimDaFila = NULL;
    adicionarElementoNoInicio(&inicioDaFila, 2);
    // adicionarElementoNoInicio(&inicioDaFila, 1);
    mostrarFila(&inicioDaFila, &fimDaFila, "LR");
    mostrarFila(&inicioDaFila, &fimDaFila, "RL");
    system("pause");
    return 0;
}
