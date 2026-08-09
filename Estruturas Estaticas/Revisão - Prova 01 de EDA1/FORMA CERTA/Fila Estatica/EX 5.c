#include <stdio.h>
#define TAM 10

typedef struct sFila1
{
    int vetor[TAM];
    int inicio, fim;
}fila1;

typedef struct sFila2
{
    int vetor[TAM];
    int inicio, fim;
}fila2;

void inicializar(fila1 *f)
{
    f->inicio = -1;
    f->fim = -1;
}

int vazia(fila1 *f)
{
    if(f->inicio == f->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheia(fila1 *f)
{
    if(f->inicio == f->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enfileirar(fila1 *f, int elem)
{
    f->fim = (f->fim+1)%TAM;

    if(cheia(f))
    {
        f->fim = f->fim-1;
        if(f->fim == -1)
        {
            f->fim = TAM-1;
        }
    }
    else
    {
        f->vetor[f->fim] = elem;
    }
}

int desenfileirar(fila1 *f)
{
    int aux =0;
    if(!vazia(f))
    {
        f->inicio = (f->inicio+1)%TAM;
        aux = f->vetor[f->inicio];
    }
    else
    {
        printf("ERRO - fila fazia.\n");
    }
    return aux;
}

int comprimento(fila1 *f)
{
    int comprimento;
    return comprimento = (f->fim-f->inicio+TAM)%TAM;
}

void main()
{
    fila1 f;
    fila2 p;

    inicializar(&f);
    inicializar(&p);

    enfileirar(&f, 10);
    enfileirar(&p, 5);
    enfileirar(&f, 10);
    enfileirar(&p, 10);
    enfileirar(&f, 10);
    enfileirar(&p, 10);

    if(comprimento(&f)> comprimento(&p))
    {
        printf("O comprimento da lista 1 e maior.\n");
    }
    else if(comprimento(&f) < comprimento(&p))
    {
        printf("O comprimento da lista 2 e maior.\n");
    }
    else if(comprimento(&f) == comprimento(&p))
    {
        printf("O comprimento das duas listas sao iguais.\n");
    }
    
    
    
}

