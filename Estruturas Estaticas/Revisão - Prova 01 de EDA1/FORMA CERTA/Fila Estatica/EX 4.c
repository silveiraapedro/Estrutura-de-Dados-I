#include <stdio.h>
#define TAM 10

typedef struct sFila
{
    int vetor[TAM];
    int inicio, fim;
}fila;

typedef struct sPilha
{
    int vetor[TAM];
    int topo;
}pilha;

void inicializarFila(fila *f)
{
    f->inicio = -1;
    f->fim = -1;
}

void inicializarPilha(pilha *p)
{
    p->topo = -1;
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

void enfileirar(fila *f, int elem)
{
    f->fim = (f->fim+1)%TAM;

    if(f->inicio == f->fim)
    {
        f->fim =f->fim-1;
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
    if(f->inicio != f->fim)
    {
        f->inicio = (f->inicio+1)%TAM;
        aux = f->vetor[f->inicio];
    }
    else
    {
        printf("ERRO - fILA VAZIA.\n");
    }
    return aux;
}

int empilhar(pilha *p, int elem)
{
    if(p->topo == TAM - 1)
    {
        printf("ERRO - cehia.\n");
        return 1;
    }

    p->topo = p->topo+1;
    p->vetor[p->topo] = elem;
    return 0;
}

int desempilhar(pilha *p)
{
    int aux;
    if(p->topo != -1)
    {
       aux = p->vetor[p->topo];
       p->topo = p->topo-1; 

    }
    else
    {
        printf("kdgkig");
    }
    return aux;
}

int comprimento(fila *f)
{
    int comprimento;
    return (f->fim-f->inicio+TAM)%TAM;
}

void inverter(fila *f, pilha *p)
{
    while(!vazia(f))
    {
        empilhar(p, desenfileirar(f));
    }

    while(p->topo != -1)
    {
        enfileirar(f, desempilhar(p));
    }
}

void apresentar(fila *f)
{
    int i;
    while(!vazia(f))
    {
        printf("Posicao[%d]: %d\n", i, desenfileirar(f));
        i++;
    }
}

void main()
{
    fila f;
    pilha p;

    inicializarFila(&f);
    inicializarPilha(&p);

    enfileirar(&f, 11);
    enfileirar(&f, 20);
    enfileirar(&f, 14);
    enfileirar(&f, 1);
    inverter(&f, &p);

    apresentar(&f);

}


