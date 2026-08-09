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

int vazia(lista *l)
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
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(lista *l, int pos, int elem)
{
    int temp;
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

    for(int i = 0;i< l->n+1; i++)
    {
        if(l->vetor[i] > l->vetor[i+1])
        {
            temp = l->vetor[i];
            l->vetor[i] = l->vetor[i+1];
            l->vetor[i+1] = temp;
        }
    }
    return 0;
}

int remover(lista *l, int elem)
{
    int i = 0;
    int aux;
    if(vazia(l))
    {
        printf("ERRO - lista vazia.\n");
        return 1;
    }

    while(i<l->n+1)
    {
        if(elem == l->vetor[i])
        {
            aux = l->vetor[i];
            l->vetor[i] = l->vetor[i+1];
            break;
        }
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

void main()
{
    lista l;

    inicializar(&l);

    inserir(&l, 0, 8);
    inserir(&l, 1, 5);
    inserir(&l, 2, 9);
    inserir(&l, 3, 7);

    apresentar(&l);

    remover(&l, 5);

    printf("\n");

    inserir(&l, 3, 10);

    apresentar(&l);
}


