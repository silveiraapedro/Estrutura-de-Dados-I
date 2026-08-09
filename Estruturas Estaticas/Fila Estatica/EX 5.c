#include <stdio.h>
#define TAM 10

typedef struct sFila
{
    int itens[TAM];
    int inicio, fim;
}Fila;

void inicializar(Fila *f)
{
    f->inicio = TAM - 1;
    f->fim = TAM - 1;
}

int lista_cheia(Fila *f)
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

int inserir(Fila *f, int elem)
{
    f->fim = (f->fim + 1)% TAM;

    if(lista_cheia(f))
    {
        printf("ERRO - Lista cheia.\n");
        f->fim--;
        if(f->fim == -1)
        f->fim = TAM - 1;
        return 1;
    }
    f->itens[f->fim] = elem;

}

int retirar(Fila *f)
{
    int aux = 0;

    if(!lista_cheia(f))
    {
        if(f->inicio == TAM -1)
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
        aux = f->itens[f->inicio];
    }
    else
    {
        printf("ERRO - Vetor vazia.\n");
        return 1;
    }
    return aux;
}

void diferenca(Fila s, Fila f)
{
    int quant1 = 0, quant2 = 0;
    while(!lista_cheia(&f))
    {
        retirar(&f);
        quant1++;
    }

    while(!lista_cheia(&s))
    {
        retirar(&s);
        quant2++;
    }

    if(quant1 > quant2)
    {
        printf("A lista F é maior.\n");
    }
    else if(quant1 < quant2)
    {
        printf("A lista S é maior.\n");
    }

    else if(quant1 == quant2)
    {
        printf("As duas listas tem tamanho igual.\n");
    }

}

void main()
{
    Fila f;
    Fila s;


    inicializar(&f);
    inicializar(&s);

    inserir(&f, 99);
    inserir(&s, 8);
    inserir(&f, 10);
    inserir(&s, 15);
    inserir(&s, 8);

    diferenca(s,f);

}

