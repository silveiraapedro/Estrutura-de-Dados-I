#include <stdio.h>
#define TAM 10

typedef struct sLista
{
    char valor[TAM];
    int n;
}LISTA;

void inicializar(LISTA *L)
{
    L->n = -1;
}

int lista_cheia(LISTA *L)
{
    if(L->n+1 == TAM)
    {
        printf("vETOR CHEIO.\n");
        return 1;
    }
    else 
    {
        return 0;
    }
}

int adicionar_fim(LISTA *L, int elem)
{

   if(lista_cheia(L))
   {
    printf("O vetor esta cheio.\n");
    return 1;
   }

    L->valor[L->n+1] = elem;
   L->n = L->n+1;
   return 0;
}

int remover_fim(LISTA *L)
{
  L->valor[L->n] = L->valor[L->n+1];
  L->n = L->n-1;

}

void mostrar_vetor(LISTA *L)
{
    int i;

    for(i = 0; i < (L->n+1); i++)
    {
        printf("[%d] - Numero: %d\n", i+1, L->valor[i]);
    }
}

void main()
{
LISTA *lista;

int elem, op;

inicializar(&lista);
printf("1. adicionar no fim.\n");
printf("2. remover no fim.\n");
printf("3. mostrar vetor.\n");
do
{
    printf("Insira a opcao: ");
    scanf("%d", &op);
    switch (op)
    {
        case 1:
        printf("Insira o elemento a adicionar: ");
        scanf("%d", &elem);
        adicionar_fim(&lista, elem);
        break;
    
        case 2:
        remover_fim(&lista);
        break;

        case 3:
        mostrar_vetor(&lista); 
        break;
    }

} while(op != 0);

}