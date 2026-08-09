#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int info;
    struct cell *esq;
    struct cell *dir;
}NO;

void init(NO **arvore)
{
    *arvore = NULL;
}

void put(NO** arvore, int x)
{
    NO *new;
    
    if(*arvore == NULL)
    {
    new = (NO*) malloc(sizeof(NO));
    if(new != NULL)
    {
        new->info = x;
        new->esq = NULL;
        new->dir = NULL;
        *arvore = new;

    }
    }
    else if(x < (*arvore)->info )
    {
        put(&(*arvore)->esq, x);
    }
    else if(x > (*arvore)->info)
    {
        put(&(*arvore)->dir, x);
    }

}

int number_of_no(NO *arvore)
{
    if(arvore == NULL)
    {
        return 0;
    }
    else
    {
        return arvore->info + number_of_no(arvore->dir) + number_of_no(arvore->esq);
    }
}

int number_of_tree(NO *arvore)
{
    if(arvore == NULL)
    {
        return 0;
    }
    else if(arvore->dir == NULL && arvore->esq == NULL)
    {
        return 1;
    }
    else
    {
       return number_of_tree(arvore->dir) + number_of_tree(arvore->esq);
    }
    
}

int altura(NO *arvore)
{
    int direita, esquerda;
    if(arvore == NULL)
    {
        return -1;
    }
    else
    {
        direita = altura(arvore->dir);
        esquerda = altura(arvore->esq);
        if(direita> esquerda)
        {
            return 1 + direita;
        }
        else
        {
            return 1 + esquerda;
        }
        
    }
}

void main()
{
    NO *arvore;

    init(&arvore);

    put(&arvore, 8);
    put(&arvore, 5);
    put(&arvore, 17);
    put(&arvore, 9);
    put(&arvore, 4);
    put(&arvore, 1);
    put(&arvore, 10);

    printf("%d\n",number_of_no(arvore));
    printf("%d\n", number_of_tree(arvore));
    printf("%d\n", altura(arvore));


}


