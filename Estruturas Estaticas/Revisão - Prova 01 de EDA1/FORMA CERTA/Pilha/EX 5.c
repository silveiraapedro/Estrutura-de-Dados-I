#include <stdio.h>
#define TAM 10

typedef struct sPilha
{
    int vetor[TAM];
    int n;
}pilha;

void inicializar(pilha *p)
{
    p->n = -1;
}

int lista_vazia(pilha *p)
{
    if(p->n == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_cheia(pilha *p)
{
    if(p->n == TAM -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(pilha *p, int elem)
{
    if(lista_cheia(p))
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }
    p->n = p->n+1;
    p->vetor[p->n] = elem;
    return 0;
}

int remover(pilha *p)
{
    int aux;
    if(!lista_vazia(p))
    {
        aux = p->vetor[p->n];
        p->n = p->n-1;
    }
    else
    {
        printf("ERRO - Lista vazia.\n");
        return 1;
    }
    return aux;
}

void inverter(pilha *p)
{
    int quant = 0;
    pilha aux;

    inicializar(&aux);

    while(!lista_vazia(p))
    {
      inserir(&aux, remover(p));
      quant++;
    }

    for(int i = 0; i<quant; i++)
    {
        printf("Posicao[%d]: %d\n", i, aux.vetor[i]);
    }
}


void main()
{
    pilha p;

    inicializar(&p);

    inserir(&p, 10);
    inserir(&p, 6);
    inserir(&p, 90);
    inserir(&p, 1);

    inverter(&p);

}