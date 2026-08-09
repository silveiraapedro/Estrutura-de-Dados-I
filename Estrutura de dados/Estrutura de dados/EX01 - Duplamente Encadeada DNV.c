#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *esq, *dir;
}CELULA;

void init(CELULA **lista)
{
    *lista = NULL;
}

int empty(CELULA *l)
{
    if(l == NULL)
        return 1;
    return 0;    
}

CELULA* getnode()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    free(q);
}

void put_begin(CELULA **lista, int x)
{
    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        q->info = x;
        q->dir = NULL;
        q->esq = NULL;
        if(!empty(*lista))
        {
            (*lista)->esq = q;
            q->dir = *lista;
        }
        *lista = q;
    }
}

void put_end(CELULA **lista, int x)
{
    CELULA *q, *aux;

    q = getnode();
    if(q != NULL)
    {
        q->info = x;
        q->dir = NULL;
        q->esq = NULL;
        if(!empty(*lista))
        {
            aux = *lista;
            while(aux->dir != NULL)
            {
                aux = aux->dir;
            }
            q->esq = aux;
            aux->dir = q;
            
        }
        else
        {
            *lista = q;
        }
        
    }
}

void remover_inicio(CELULA **lista)
{
    CELULA *q;

    if(!empty(*lista))
    {
        q = *lista;
        *lista = (*lista)->dir;
        if(*lista != NULL)
        {
             (*lista)->esq = NULL;
        }
       
        freenode(q);
    }
}

CELULA* pesquisar(CELULA *lista, int x)
{
    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q != NULL)
        {
            if(q->info == x)
            {
                return q;
            }
            q = q->dir;
        }
    }
}

void remover_valor(CELULA **lista, int x)
{
    CELULA *q, *aux;

    if((q = pesquisar(*lista, x)) != NULL)
    {
        
        if(*lista == q)
        {
            remover_inicio(*lista);
        }
        else
        {
            (q->esq)->dir = q->dir;
            if(q->dir != NULL)
            {
                (q->dir)->esq = q->esq;
            }
            
            freenode(q);

        } 
    }
}

void listar(CELULA *lista)
{
    CELULA *q;
    if(!empty(lista))
    {
        q = lista;
        while(q != NULL)
        {
            printf("%d\n", q->info);
            q = q->dir;
        }
    }
}

void main()
{
    CELULA *lista;

    init(&lista);
    put_begin(&lista, 8);
    put_begin(&lista, 9);
    put_end(&lista, 7);
    remover_valor(&lista, 8);
    remover_inicio(&lista);

    listar(lista);


}

