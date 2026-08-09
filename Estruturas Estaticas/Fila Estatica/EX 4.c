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

int implementar(Fila *f, int elem)
{
    if(f->fim == (TAM - 1))
    {
        f->fim = 0;
    }
    else
    {
        (f->fim)++;
    }

    if(lista_vazia(f))
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
    if(!lista_vazia(f))
    {
       if(f->inicio == TAM - 1)
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
        printf("ERRO - Lista cheia.\n");
        return 1;
    }

    return aux;

}

void inverter(Fila *f)
{
    Fila s;
    int quant= 0;
    int aux[TAM];

    inicializar(&s);

    while(!lista_vazia(f))
    {
        aux[quant++] = retirar(f);  
    }

    for(int i = f->fim ; i>=0; i--)
    {
        implementar(&s, aux[i]);
        printf("Elemento: %d\n", aux[i]);
    }
}

void main()
{
    Fila f;

    inicializar(&f);

    implementar(&f, 8);
    implementar(&f, 90);
    implementar(&f, 10);
    inverter(&f);

}
