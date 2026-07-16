#include <stdio.h>
#include <stdlib.h>

typedef struct SFila
{
    int dado;
    struct SFila *back;
    struct SFila *next;
} Fila;

Fila *fila = NULL;
Fila *inicio = NULL;
Fila *ultimo = NULL;
Fila *penultimo = NULL;

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

void mostrarFila(Fila **inicioDaFila)
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

Fila *removerElementoNoInicio()
{
    inicio = fila;
    Fila *elementoRemovido;
    if (fila == NULL)
    {
        printf("Sem elementos para remover no inicio.\n");
        return NULL;
    }
    else
    {
        fila = fila->next;
        elementoRemovido = (Fila *)malloc(sizeof(Fila));
        *elementoRemovido = *inicio;
        free(inicio);
        return elementoRemovido;
    }
}
Fila *removerElementoNoFim()
{
    Fila *elementoRemovido = NULL;
    if (fila == NULL)
    {
        printf("sem elementos para remover no fim!\n");
        return NULL;
    }
    else
    {
        elementoRemovido = (Fila *)malloc(sizeof(Fila));
        ultimo = fila;
        if (ultimo->next == NULL)
        {
            *elementoRemovido = *ultimo;
            free(ultimo);
            fila = NULL;
            return elementoRemovido;
        }
        while (ultimo->next != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->next;
        }
        *elementoRemovido = *ultimo;
        free(ultimo);
        penultimo->next = NULL;
        return elementoRemovido;
    }
}

int main()
{
    Fila *inicioDaFila = NULL;
    Fila *fimDaFila = NULL;
    // inicioDaFila = novoElemento(20);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        adicionarElementoNoFim(&inicioDaFila, &fimDaFila, i);
    }
    // adicionarElementoNoFim(&inicioDaFila, &fimDaFila, 1);
    // adicionarElementoNoFim(&inicioDaFila, &fimDaFila, 2);
    // adicionarElementoNoFim(&inicioDaFila, &fimDaFila, 3);
    mostrarFila(inicioDaFila);
    adicionarElementoNoInicio(&inicioDaFila, 20);
    adicionarElementoNoMeio(&inicioDaFila, &fimDaFila, 1111, 5);
    adicionarElementoNoMeio(&inicioDaFila, &fimDaFila, 2222, 9);
    // adicionarElementoNoFim(fimDaFila, 123);
    // adicionarElementoNoFim(fimDaFila, 124);
    // mostrarFila(inicioDaFila);
    // while (removerElementoNoFim())
    // {
    //     printf("elemento removido\n");
    // }
    mostrarFila(inicioDaFila);
    system("pause");
    return 0;
}
