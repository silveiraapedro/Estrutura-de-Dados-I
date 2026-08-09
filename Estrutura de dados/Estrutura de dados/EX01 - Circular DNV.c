#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
}CELULA;

CELULA* getnode()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

int empty(CELULA *l)
{
    if(l == NULL)
        return 1;
    return 0;
}

void freenode(CELULA *q)
{
    free(q);
}

void init(CELULA **lista)
{
    *lista = NULL;
}

void put_end(CELULA **lista, int x)
{
    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        q->info = x;

        if(empty(*lista))
        {
            q->next = q;
        }
        else
        {
            q->next = (*lista)->next;
            (*lista)->next = q;
        }
        *lista = q;
    }
}

void remove_begin(CELULA **lista)
{
    CELULA *q;

    if(!empty(*lista))
    {
        q = *lista;
        if((*lista) == (*lista)->next)
        {
            freenode(*lista);
            *lista = NULL;
        }
        q = (*lista)->next;
        (*lista)->next = q->next;
        freenode(q);
    }
}

void listar(CELULA *lista)
{
    CELULA *q;

    if(!empty(lista))
    {
        q = lista->next;
        do
        {
            printf("%d\n", q->info);
            q = q->next;
        }while(q != lista->next);
    }
}

void main()
{
    CELULA *lista;

    init(&lista);
    put_end(&lista, 5);
    put_end(&lista, 10);
    put_end(&lista, 88);
    put_end(&lista, 60);
    remove_begin(&lista);
    listar(lista);
}
