#include <stdio.h>
#include <string.h>
#define TAM 10

typedef struct sBicicleta
{
    char cor[20];
    int quant_marcha;
}Bicicleta;

typedef struct sFila
{
    Bicicleta itens[TAM];
    int inicio, fim;
}Fila;

void inicializar(Fila *f)
{
    f->inicio = -1;
    f->fim = -1;
}

int fila_vazia(Fila *f)
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

int fila_cheia(Fila *f)
{
    if((f->inicio +1)%TAM == f->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enfileirar(Fila *f, Bicicleta b)
{

    f->fim = (f->fim + 1)%TAM;
    if(fila_cheia(f))
    {
        f->fim = f->fim--;
        if(f->fim == -1)
        {
            f->fim = TAM - 1;
        }
    }
    else
    {
        strcpy(f->itens[f->fim].cor, b.cor);
        f->itens[f->fim].quant_marcha =  b.quant_marcha;
    }
}

Bicicleta inserir()
{
    Bicicleta b;

    printf("Insira a cor da bicicleta: ");
    scanf("%[^\n]s", b.cor);
    fflush(stdin);

    printf("Insira a quantidade de marchas: ");
    scanf("%d", &b.quant_marcha);
    fflush(stdin);

    return b;
}

Bicicleta desenfileirar(Fila *f)
{
    Bicicleta b;

    if(!fila_vazia(f))
    {
        f->inicio = (f->inicio + 1)%TAM;
        strcpy(b.cor, f->itens[f->inicio].cor);
        b.quant_marcha = f->itens[f->inicio].quant_marcha;
    }
    else
    {
        printf("dkjgfgifd");
    }
    return b;
}

void main()
{
    Fila f;
    Bicicleta byke;

    inicializar(&f);

    byke = inserir(&f);
    enfileirar(&f, byke);

    printf("Cor: %s marchar: %d",
         f.itens[f.fim].cor,
         f.itens[f.fim].quant_marcha);

    byke = desenfileirar(&f);
    printf("\nCor: %s marchar: %d", 
        byke.cor,
        byke.quant_marcha);
}

