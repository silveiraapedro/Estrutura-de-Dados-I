#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct r
{
    char title[50], type[20], name[50];

}recipe;

typedef struct cell
{
    recipe info;
    struct cell *next;
}CELULA;

CELULA* init(CELULA *lista)
{
    lista = NULL;
    return lista;
}

CELULA* getnode()
{
    return (CELULA*) malloc(sizeof(CELULA));
}

int empty(CELULA *lista)
{
    if(lista == NULL)
        return 1;
    return 0;
}

void freenode(CELULA *q)
{
    free(q);
}

recipe register_recipe()
{
    recipe r;
    int opc;

    printf("Insira o titulo da receira: ");
    scanf("%[^\n]s", r.title);
    fflush(stdin);

    printf("Insira qual é o tipo da comida(1 - doce, 2 - salgado): ");
    scanf("%d", &opc);
    fflush(stdin);

    switch(opc)
    {
        case 1: 
        strcpy(r.type, "Doce");
        break;

        case 2:
        strcpy(r.type, "Salgado");
        break;
    }

    printf("Insira o nome da pessoa que fez a receita: ");
    scanf("%[^\n]s", r.name);
    fflush(stdin);

    return r;
}

CELULA* put_in_order(CELULA *lista, recipe r)
{
    CELULA *atual = lista;
    CELULA *anterior = NULL;
    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        strcpy(q->info.title, r.title);
        strcpy(q->info.type, r.type);
        strcpy(q->info.name, r.name);
        q->next = NULL;

        while(atual != NULL && strcmp(atual->info.title, r.title) < 0)
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

    else
    {
        printf("meigeigmdigm.\n");
        return NULL;
    }

}

void listar(CELULA *lista)
{
    CELULA *q = lista;

    if(!empty(lista))
    {
        while(q != NULL)
        {
        printf("%s\n", q->info.title);
        printf("%s\n", q->info.type);
        printf("%s\n", q->info.name);
        q = q->next;
        }

    }
}

CELULA* remove_begin(CELULA *lista)
{
    CELULA *q;

    q = lista;
    if(!empty(lista))
    {
        
        lista = q->next;
        freenode(q);
        return lista;
    }
}

CELULA* pesquisar(CELULA *lista, char x[20])
{
    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q != NULL)
        {
            if(strcmp(q->info.title, x) == 0)
            {
                return q;
            }
            q = q->next;
        }
    }
}

CELULA* remover_valor(CELULA *lista, char x[20])
{
    CELULA *q, *aux;

    if((q = pesquisar(lista, x))!= NULL)
    {
        if(lista == q)
        {
            lista = remove_begin(lista);
        }
        else
        {
            aux = lista;
            while(aux->next != q)
            {
                aux = aux->next;
            }
            aux->next = q->next;
            freenode(q);
        }
        return lista;
    }
    else
    {
        return NULL;
    }
}



void main()
{
    CELULA *lista;
    recipe r;

    lista = init(lista);
    r = register_recipe();
    lista = put_in_order(lista, r);
    r = register_recipe();
    lista = put_in_order(lista, r);
    r = register_recipe();
    lista = put_in_order(lista, r);
    listar(lista);
    lista = remove_begin(lista);
    listar(lista);
    lista = remover_valor(lista, "b");
    listar(lista);

}
