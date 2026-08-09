#include <stdio.h>
#include <string.h>
#define TAM 50

typedef struct sPilha
{
    char vetor[TAM];    
    int topo;
}PILHA;

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int lista_vazia(PILHA *p)
{
    if(p->topo == -1)
    {
        return 1;
    }
    return 0;
}

int lista_cheia(PILHA *p)
{
    if(p->topo ==   TAM)
    {
        return 1;
    }
    return 0;
}

int empilhar(PILHA *p, char valor)
{
    if(lista_cheia(p))
    {
        printf("A lista esta cheia.\n");
        return 1;
    }

    p->topo++;
    p->vetor[p->topo] = valor;
    return 0;
}

int desempilhar(PILHA *p)
{
    int aux;
   if(lista_vazia(p))
   {
    printf("A lista esta vazia.\n");
    return 1;
   }
   aux = p->vetor[p->topo];
   p->topo--;
   return aux;
}

void ler(PILHA *p, char palavra[])
{
    int tampalavra, i;  

    tampalavra = strlen(palavra);

    for(i=0; i<tampalavra; i++)
    {
        empilhar(p, palavra[i]);
    }

    for(i=0; i<tampalavra; i++)
    {
        if(palavra[i] != desempilhar(p))
        {
            printf("Nao e um.\n");
            return 1;
        }
    }

    printf("E um palindromo.\n");
    
}

void main()
{
    PILHA p;

    char palavra[TAM];

    inicializar(&p);

    printf("Insira a palavra: ");
    scanf("%s", palavra);
    ler(&p, palavra);
}