#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int info;
    struct cell *next;
}CELULA;

void init(CELULA **lista)
{
    *lista = NULL;
}

CELULA* getnode()
{
    return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    free(q);
}

int empty(CELULA *lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    return 0;
}

void put_lista(CELULA **lista, int x)
{
    CELULA *aux;

    aux = getnode();
    if(aux != NULL)
    {
        aux->info = x;
        aux->next = *lista;
        *lista = aux; 
    }
    else
    {
        exit(1);
    }
}

int calc_compri(CELULA *lista)
{
    if(empty(lista))
    {
        return 0;
    }
    else
    {
        return(calc_compri(lista->next)+1);
    }
}

int soma(CELULA *lista)
{
    if(empty(lista))
    {
        return 0;
    }
    else
    {
        return lista->info + soma(lista->next);
    }
}

int multi(CELULA *lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    else
    {
        return lista->info * multi(lista->next);
    }
}

int impar(CELULA *lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    else
    {
        if(lista->info % 2 == 1)
        {
            printf("%d\n", lista->info);
        }
        return impar(lista->next);
    }
}

int pares(CELULA *lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    else
    {
        
        if(lista->info % 2 == 0)
        {
            printf("%d\n", lista->info);
        }
        return pares(lista->next);
        
    }

}





void main()
{
    CELULA *lista;

    init(&lista);
    put_lista(&lista, 5);
    put_lista(&lista, 10);
    put_lista(&lista, 54);
    put_lista(&lista, 1);

    printf("%d\n", calc_compri(lista));
    printf("%d\n", soma(lista));
    printf("%d\n", multi(lista));
    impar(lista);
    pares(lista);
}
