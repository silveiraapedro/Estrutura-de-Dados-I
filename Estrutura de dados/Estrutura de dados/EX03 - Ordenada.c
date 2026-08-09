#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct r
{
    char nome[30], ingredients[50];
}RECIPE;


typedef struct cell
{
    RECIPE info;
    struct cell *next;
}CELULA;

CELULA* init(CELULA *lista)
{
    lista = NULL;
    return lista;
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

CELULA* getnode()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

RECIPE inserir()
{
    RECIPE r;

    printf("Insira o nome: ");
    scanf("%[^\n]s", r.nome);
    fflush(stdin);

    printf("Insira os porras: ");
    scanf("%[^\n]s", r.ingredients);
    fflush(stdin);

    return r;
}


CELULA* put_in_order(CELULA *lista, RECIPE r)
{
    CELULA *q;
    CELULA *atual = lista;
    CELULA *anterior = NULL;

    q=getnode();
    if(q != NULL)
    {
        strcpy(q->info.nome, r.nome);
        strcpy(q->info.ingredients, r.ingredients);
        q->next = NULL;
        
        while(atual != NULL && strcmp(atual->info.nome, r.nome)< 0)
        {
            anterior = atual;
            atual = atual->next;
        }

        if(atual == lista)
        {
            q->next = lista;
            lista = q;
        }

        else
        {
            anterior->next = q;
            q->next = atual;
        }

        return lista;
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
            printf("%s\n", q->info.nome);
            printf("%s\n", q->info.ingredients);
            q = q->next;
        }
    }
}

void main()
{
    CELULA *l;
    RECIPE r;

    l = init(l);
    r = inserir();
    l = put_in_order(l, r);
    r = inserir();
    l = put_in_order(l, r);
    r = inserir();
    l = put_in_order(l, r);
    listar(l);
}
