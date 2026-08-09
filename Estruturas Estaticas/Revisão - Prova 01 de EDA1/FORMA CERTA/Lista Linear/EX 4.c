#include <stdio.h>
#define TAM 10

typedef struct sLista2
{
    int vetor[TAM];
    int n;
}L1;

typedef struct sLista1
{
    int vetor[TAM];
    int n;
}L2;

void inicializar(L1 *l1, L2 *l2)
{
    l1->n = -1;
    l2->n = -1;
}


int lista_cheia1(L1 *l1)
{
    if(l1->n+1 == TAM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_cheia2(L2 *l2)
{
    if(l2->n+1 == TAM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_lista1(L1 *l1, int pos, int elem)
{
    if(lista_cheia1(l1))
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }

    if(pos < 0 || pos > l1->n+1)
    {
        printf("ERRO - Posicao fora dos limites.\n");
        return 1;
    }

    for(int i = (l1->n+1); i>pos; i--)
    {
        l1->vetor[i] = l1->vetor[i-1];
    }
    l1->vetor[pos] = elem;
    l1->n = l1->n+1;
    return 0;
}

int inserir_lista2(L2 *l2, int pos, int elem)
{
    if(lista_cheia2(l2))
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }

    if(pos < 0 || pos > l2->n+1)
    {
        printf("ERRO - Posicao fora dos limites.\n");
        return 1;
    }

    for(int i = (l2->n+1); i>pos; i--)
    {
        l2->vetor[i] = l2->vetor[i-1];
    }
    l2->vetor[pos] = elem;
    l2->n = l2->n+1;
    return 1;
}

void concatenar(L1 *l1, L2 *l2)
{
        for(int i = 0; i<l1->n+1; i++)
        {
            l1->vetor[i] = l1->vetor[i] + l2->vetor[i];
            if(l2->vetor[i] == 0)
            {
                l2->n = l2->n+1;
            }
        }
 
   
}

void apresentar(L1 *l1)
{
    for(int i = 0;i<l1->n+1; i++)
    {
        printf("Posicao[%d]: %d\n", i, l1->vetor[i]);
    }
}

void main()
{
 L1 l1;
 L2 l2;

 inicializar(&l1, &l2);

 inserir_lista1(&l1, 0, 10);
 inserir_lista2(&l2, 0, 20);
 inserir_lista1(&l1, 1, 10);
 inserir_lista1(&l2, 1, 90);
 inserir_lista1(&l1, 2, 10);
 inserir_lista1(&l2, 1, 90);

 concatenar(&l1, &l2);
 apresentar(&l1);

}