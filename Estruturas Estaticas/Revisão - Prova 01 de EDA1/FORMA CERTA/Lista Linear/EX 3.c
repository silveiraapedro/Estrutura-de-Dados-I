#include <stdio.h>
#define TAM 10

typedef struct sLista
{
    float vetor[TAM];
    int n;
}lista;

void inicializar(lista *l)
{
    l->n = -1;
}

int lista_cheia(lista *l)
{
    if(l->n+1 == TAM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_vazia(lista *l)
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

int inserir(lista *l, float elem, int pos)
{
    float temp;
    if(lista_cheia(l))
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }

    if(pos < 0 || pos > l->n+1)
    {
        printf("ERRO - Fora dos limites da array.\n");
        return 1;
    }

    for(int i = (l->n+1); i>pos; i--)
    {
        l->vetor[i] = l->vetor[i-1];
    }
    l->vetor[pos] = elem;
    l->n = l->n+1;

 
    for(int i = 0; i<l->n+1; i++)
    {
        for(int j = i; j<l->n + 1 ; j++)
        {
            if(l->vetor[i] > l->vetor[j])
            {
                temp = l->vetor[i];
                l->vetor[i] = l->vetor[j];
                l->vetor[j] = temp;
            }
        }
    }

    return 0;
}

void ordenar(lista *l)
{

}

int remover(lista *l, int pos)
{
    int aux;
    if(lista_vazia(l))
    {
        printf("ERRO - A lista esta vazia.\n");
        return 1;
    }
    if(pos < 0 || pos > l->n)
    {
        printf("ERRO - Fora dos limites da array.\n");
        return 1;
    }

    for(int i = 0; i<pos; i++)
    {
        l->vetor[i] = l->vetor[i+1];
    }

    aux = l->vetor[pos];
    l->n = l->n-1;

    return 0;
}

void apresentar(lista *l)
{
    for(int i = 0; i<l->n+1; i++)
    {
        printf("Posicao[%d]: %0.2f\n", i, l->vetor[i]);
    }
}

void main()
{
    lista l;

    inicializar(&l);

    inserir(&l, 1, 0);
    inserir(&l, 5, 1);
    inserir(&l, 9, 2);
    inserir(&l, 10, 3);
    ordenar(&l);

    apresentar(&l);
}


