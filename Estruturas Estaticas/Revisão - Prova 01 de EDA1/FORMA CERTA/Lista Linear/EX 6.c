#include <stdio.h>
#define TAM 10

typedef struct sLista1
{
    int vetor[TAM];
    int n;
}L1;

typedef struct sLista2
{
    int vetor[TAM];
    int n;
}L2;

void inicializar(L1 *l1)
{
    l1->n = -1;
}

int lista_vazia(L1 *l1)
{
    if(l1->n == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_cheia(L1 *l1)
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

int inserir(L1 *l1, int pos, int elem)
{
    if(lista_cheia(l1))
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }
    if(pos < 0 || pos > l1->n+1)
    {
        printf("ERRO - fora dos limites.\n");
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

int enfileirar(L1 *l1, int elem)
{
    l1->n = l1->n+1;
    l1->vetor[l1->n] = elem;
    
}

int desenfileirar(L1 *l1)
{
    int aux;

    aux = l1->vetor[l1->n];
    l1->n = l1->n-1;
    return aux;
}

int buscar(L1 *l1, int pos)
{
   elem = l1->vetor[pos];
   return elem;

}

void inverter(L1 *l1, L2 *l2)
{
    while(!lista_vazia(l1))
    {
        enfileirar(l2, desenfileirar(l1));
    }

    for(int i = l1->n; i>=0; i--)
    {
        enfileirar(l2, buscar(l1, i));
    }
}

void apresentar(L2 *l2)
{
    for(int i = 0; i<l2->n+1; i++)
    {
        printf("Posicao[%d]: %d\n", i, l2->vetor[i]);
    }
}

void main()
{
    L1 l1;
    L2 l2;

    inicializar(&l1);
    inicializar(&l2);

    inserir(&l1, 0, 10);
    inserir(&l1, 1, 1);
    inserir(&l1, 2, 3);
    inserir(&l1, 3, 9);

    inverter(&l1, &l2);
    apresentar(&l2);

}

