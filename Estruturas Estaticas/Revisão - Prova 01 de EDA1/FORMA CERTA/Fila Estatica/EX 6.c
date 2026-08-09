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

int vazia(fila *f)
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

int cheia(fila *f)
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
    f->fim = (f->fim+1)%TAM;

    if(cheia(f))
    {
        f->fim = f->fim-1;
        if(f->fim == -1)
        {
            f->fim = TAM -1;
        }
    }
    else
    {
        f->vetor[f->fim] = elem;
    }
}

int desenfileirar(fila *f)
{
    int aux = 0;
    if(!vazia(f))
    {
        f->inicio = (f->inicio+1)%TAM;
        aux = f->vetor[f->inicio];
    }
    else
    {
        printf("ERRO - fila vazia.\n");
    }
    return aux;
}

int maior(fila f)
{
    int elem;
    int maior = 0;
        while(!vazia(&f))
        {
            elem = desenfileirar(&f);
            if(elem > maior)
            {
                maior = elem;
            }
        }
    return maior;
}

int menor(fila f)
{
    int elem;
    int menor;
    while(!vazia(&f))
    {
        elem = desenfileirar(&f);
        if(elem < menor)
        {
            menor = elem;
        }
    }
    return menor;
}

int comprimento(fila *f)
{
    int comprimento;
    return comprimento = (f->fim-f->inicio+TAM)%TAM;
}

float media(fila f)
{
    int total = 0;
    int elem;
    float media;
    while(!vazia(&f))
    {
        elem = desenfileirar(&f);
        total += elem;
    }
    return total;
}





void main()
{
    fila f;

    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 188);
    enfileirar(&f, 1);
    enfileirar(&f, 20);
    enfileirar(&f, 9);
    enfileirar(&f, 10);

    printf("O maior elemento e: %d\n", maior(f));
    printf("O menor elemento e: %d\n", menor(f));
    printf("A media e: %.2f\n", media(f)/comprimento(&f));

}


