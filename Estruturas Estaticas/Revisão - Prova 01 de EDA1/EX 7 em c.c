#include <stdio.h>
#define TAM 10

typedef struct sLista1
{
    int itens[TAM];
    int n;
}L1;

typedef struct sLista2
{
    int itens[TAM];
    int n;
}L2;

void inicializar(L1 *l1, L2 *l2)
{
    l1->n = -1;
    l2->n = -1;
}

int inserir_elemento(L1 *l1, int elem1)
{

    l1->n = l1->n+1;
 l1->itens[l1->n] = elem1;
 
 
}

void alterar(L1 *l1, L2 *l2)
{
    int k=0;
    for(int i = l1->n; i>=0; i--)
    {

        l2->itens[k++] = l1->itens[i];

    }
    l2->n = l1->n;
}

void apresentar(L2 *l2)
{
    for(int i = 0; i<l2->n+1; i++)
    {
        printf("Posicao[%d]: %d\n", i, l2->itens[i]);
    }
}

void main()
{

    L1 l1;
    L2 l2;
    inicializar(&l1, &l2);

    inserir_elemento(&l1, 8);
    inserir_elemento(&l1, 10);
    inserir_elemento(&l1, 88);
    inserir_elemento(&l1, 70);

    alterar(&l1, &l2);

    apresentar(&l2);

}

