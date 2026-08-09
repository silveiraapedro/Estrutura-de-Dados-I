#include <stdio.h>
#define TAM 10

typedef struct sFila
{
    int vetor[TAM];
    int inicio, fim;
}fila;

void inicializar(fila *f)
{
    f->inicio = -1;
    f->fim = -1;
}

int lista_cheia(fila *f)
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

int lista_vazia(fila *f)
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

void enfileirar(fila *f, int elem)
{
    f->fim = (f->fim +1)%TAM;

    if(lista_cheia(f))
    {
        f->fim-1;
        if(f->fim == -1)
        {
            f->fim = TAM - 1;
        }
    }
    f->vetor[f->fim] = elem;
    
}

void desenfileirar(fila *f)
{
    int aux=0;
    if(!lista_vazia(f))
    {
       
        aux = f->vetor[f->inicio];
        f->inicio = (f->inicio+1)%TAM;
    }
    else
    {
        printf("ERRO - Fila vazia.\n");
    }
}

int comprimento(fila *f)
{
    int comprimento;
    return comprimento = (f->fim-f->inicio+TAM)%TAM;
}

void main()
{
    fila f;

    inicializar(&f);

    enfileirar(&f, 100);
    enfileirar(&f, 100);
    enfileirar(&f, 100);
    enfileirar(&f, 100);
    enfileirar(&f, 100);
    enfileirar(&f, 100);

    printf("O tamanho é: %d", comprimento(&f));
}

