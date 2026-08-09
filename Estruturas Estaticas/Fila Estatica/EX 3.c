#include <stdio.h>
#define TAM 10

typedef struct sFila
{
    int itens[TAM];
    int inicio, fim;
}Fila;

void inicializar(Fila *f)
{
    f->inicio = TAM -1;
    f->fim = TAM -1;
}

int lista_vazia(Fila *f)
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

int implementacao(Fila *f, int elem)
{
    f->fim = (f->fim + 1) % TAM;

    if(lista_vazia(f)) /// mesma coisa pros mesmo casos
    {
        printf("ERRO - Lista cheia.\n");
        f->fim--;
        if(f->fim = -1)
        {
            f->fim = TAM -1;
        }
        return 1;
    }
    f->itens[f->fim] = elem;
}

int desemplementacao(Fila *f)
{
    int aux = 0;

    if(!lista_vazia(f))
    {
        if(f->inicio == TAM -1)
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
    }
    else
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }
    aux = f->itens[f->inicio];
    return aux;

}

int apresentar(Fila f) /// nesse caso nao usaremos o pontero por estarmos manipulando valores somente dentro
                       /// da função
{
    int quant = 0;

    while(!lista_vazia(&f))
    {
        desemplementacao(&f);
        quant++;
    }
    return quant;
}

void main()
{
    Fila f;
    int quant;

    inicializar(&f);

    implementacao(&f, 6);
    implementacao(&f, 8);
    implementacao(&f, 10);
    implementacao(&f, 80);
    quant = apresentar(f);
    printf("A quantidade de elementos é: %d", quant);
}
