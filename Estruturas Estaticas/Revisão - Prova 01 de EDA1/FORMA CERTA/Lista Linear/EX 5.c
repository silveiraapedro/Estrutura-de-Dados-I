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

typedef struct sLista3
{
    int vetor[TAM];
    int n;
}L3;

void inicializar(L1 *l1, L2 *l2, L3 *l3)
{
    l1->n = -1;
    l2->n = -1;
    l3->n = -1;
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

void inserir(L1 *l1, int elem)
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



void listar(L1 *l1, L2 *l2, L3 *l3)
{
    while(!lista_vazia(l1) && !lista_vazia(l2))
    {
        inserir(l3, desenfileirar(l1));
        inserir(l3, desenfileirar(l2));
    }
}

void apresentar(L3 *l3)
{
    for(int i = 0; i<l3->n+1; i++)
    {
        printf("Posicao[%d]: %d\n", i, l3->vetor[i]);
    }
}


void main()
{
 L1 l1;
 L2 l2;
 L3 l3;

 inicializar(&l1, &l2,&l3);
 
 inserir_lista1(&l1, 0, 5);
 inserir_lista1(&l2, 0, 2);
 inserir_lista1(&l1, 1, 7);
 inserir_lista1(&l2, 1, 6);

 listar(&l1, &l2, &l3);


 apresentar(&l3);
}
