#include <stdio.h>
#include <string.h>
#define TAM 10

typedef struct sPilha
{
    char vetor[TAM];
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

int inserir(pilha *p, char elem[])
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

int palindromo(pilha *p, char palavra[])
{
    int tam = 0;

    printf("Insira a palavra: ");
    scanf("%[^\n]s", palavra);

    tam = strlen(palavra);
    for(int i = 0; i<tam;i++)
    {
        inserir(p, palavra[i]);
    }
    
 int i = 0;
    while(!lista_vazia(p))
    {
        
        if(palavra[i] != remover(p))
        {
            printf("Nao e um palindromo.\n");
            return 1;
        }
        else
        {
            printf("E um palindromo.\n");
            return 0;
        }
        i++;
    }


}

void main()
{
    pilha p;
    char palavra[20];

    inicializar(&p);

    palindromo(&p, palavra);
}

