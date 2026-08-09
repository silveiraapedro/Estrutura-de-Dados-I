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

int vetor_cheio(LISTA *L)
{
    if(L->n+1 == TAM)
    {
        printf("vetor cheio.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_elemento(LISTA *L)
{
 int i;
    if(vetor_cheio(L))
    {
        printf("vetor ceheio.\n");
        return 1;
    }
    for(i= 0; i<TAM; i++)
    printf("Insira o elemento[%d]: ", i+1);
    scanf("%d", &L->valor[i]);
    return 0;
}

void remover_valor(LISTA *L, int elem)
{
  L->valor[elem] = L->valor[L->n+1];
  L->n = L->n-1;

}


void main()
{
LISTA *lista;

int op, elem;

inicializar(&lista);
printf("1. adicionar.\n");
printf("2. remover valor.\n");
printf("3. mostrar vetor.\n");
do
{
    printf("Insria a opcao: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
    
        inserir_elemento(&lista);
        break;
    
    case 2:
    printf("Insria o elemento: ");
    scanf("%d", &elem);
    remover_valor(&lista, elem);
        break;

        case 3:
        mostrar_vetor(&lista);
        break;
    }
} while (op != 0);
}