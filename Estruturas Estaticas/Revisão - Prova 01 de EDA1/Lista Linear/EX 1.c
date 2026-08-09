#include <stdio.h>
#define TAM 10

typedef struct sLista
{
    int vetor[TAM];
    int n;
}lista;

void inicializar(lista *l)
{
    l->n = -1;
}

int vazia(lista *)
{
    if(l->n == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheia(lista *l)
{
    if(l->n+1 == TAM)
    {
        return 1
    }
    else
    {
        return 0;
    }
}

int inserir(lista *l, int pos, int elem)
{
    if(cheia(l))
    {
        printf("ERRO - lista cheia.\n");
        return 1;
    }
    if(pos < 0 || pos > l->n+1)
    {
        printf("ERRO - fora dos limites da array.\n");
        return 1;
    }

    for(int i = (l->n+1); i>pos; i--)
    {
        l->vetor[i] = l->vetor[i-1];
    }

    l->vetor[pos] = elem;
    l->n = l->n+1;
    return 0;
}

int remover(lista *l, int pos)
{
    if(vazia(l))
    {
        printf("ERRO - Lista vazia.\n");
        return 1;
    }
    if(pos < 0 || pos > l->n+1)
    {
        printf("ERRO - fora do limite de array.\n");
        return 1;
    }

    for(int i = pos; i<(l->n); i++)
    {
        l->vetor[i] = l->vetor[i+1];
    }

    aux = l->vetor[pos];
    l->n = l->n-1;
    return aux;
}



void buscar(lista *l, pos)
{
    if(vazia(l))
    {
        printf("ERRO - lista vazia.\n");
        return 1;
    }

    return l->vetor[pos];
    printf("O elemento na posicao é: %d\n", elem);
}

void procurar(lista *l, int elem)
{
    int elem = -1;
    int i = 0;
    if(vazia(l))
    {
        printf("ERRO - lista vazia.\n");
        return 1;
    }

    while(i<l->n+1)
    {
        if(l->vetor[i] == elem)
        printf("O numero esta na posicao: %d\n", i);
        i = elem; 
        break;
    i++;
    }
}

void apresentar(lista *l)
{
    for(int i = 0; i<l->n+1; i++)
    {
        printf("Posicao[%d]: %d\n", i, l->vetor[i]);
    }
}





