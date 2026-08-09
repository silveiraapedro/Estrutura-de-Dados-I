#include <stdio.h>
#define TAM 10

typedef struct sLista{
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
    printf("Esta cheia.\n");
    return 1;
}
else 
{
    return 0;
}

}

int lista_vazia(LISTA *L)
{
if(L->n == -1)
{
    printf("Lista esta vazia.\n");
    return 1;
}
else
{
    return 0;
}
}

int inserir_elemento(LISTA *L, int pos, int v)
{
   int i;  
 
   if(lista_cheia(L))
   {
    printf("A lista ja esta cheia.\n");
    return 1;
   }

   if(pos < 0 || pos > L->n+1) // Condição pra se caso a posição seja maior do que a que tenha na fila
   {
    printf("A posicao esta fora dos limites da array.\n");
    return 1;
   }

   for(i = (L->n+1); i > pos; i--)
   {
    L->valor[i] = L->valor[i-1];
   }

   L->valor[pos] = v; // Insere o elemento na posição buscada dentro do for
   L->n = L->n+1;    // E logo em seguida ja aloca espaço na proxima posição
   return 0;
}

int remover_elemento(LISTA *L, int pos)
{
    int i;
    if(pos < 0 || pos > L->n+1)
    {
     printf("A posicao esta fora dos limites da array.\n");
     return 1;
    }

  for(i = pos; i < (L->n); i++)
  {
    L->valor[i] = L->valor[i+1]; /// Vai adicionar uma posição recebendo o proximo
  }

  L->n = L->n-1; // Remove
  return 0;

}

int acessar_elemento(LISTA *L, int pos)
{
    if(pos < 0 || pos > L->n+1)
    {
     printf("A posicao esta fora dos limites da array.\n");
     return 1;
    }

    return L->valor[pos]; 
}

int procurar_elemento(LISTA *L, char val_b)
{
    int elem = -1; 
    int i = 0;

    while(i<(L->n))
    {
        if(val_b == L->valor[i])
        {
            elem = i;
            break;
        }
        i++;
    }
    return elem;

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
    int v, pos, op, elem;
    char val_b;
inicializar(&lista);

printf("1. inserir elemento no vetor em posicao especifica.\n");
printf("4. mostrar vetor.\n");
printf("2. remover elemento de posicao especifica.\n");
printf("5. acessar elemento em posicao especifica.\n");
printf("3. procurar elemento.\n");
do
{
    printf("Insira a opção: ");
    scanf("%d", &op);
   switch (op)
   {

   case 1:
   printf("Insira a posicao: ");
   scanf("%d", &pos);
   printf("Insira o elemento: ");
   scanf("%d", &v);
   inserir_elemento(&lista, pos, v);
    break;
   
    case 2:
    printf("Insira a posicao: ");
    scanf("%d", &pos);
    remover_elemento(&lista, pos);
    break;

    case 3:
    printf("Insira o elemento a procurar: ");
    scanf(" %c", &val_b);
    elem = procurar_elemento(&lista, val_b);
    printf("Posicao: %d", elem);
    break;

    case 4:
    mostrar_vetor(&lista);
    break;

    case 5:
    acessar_elemento(&lista, pos);
    break;

   }
} while (op != 0);
}