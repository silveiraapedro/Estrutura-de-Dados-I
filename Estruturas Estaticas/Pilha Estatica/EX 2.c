#include <stdio.h>
#define TAM 10

typedef struct nPilha
{
    int vetor[TAM];
    int topo;

}PILHA_N;

typedef struct pPilha
{
    int vetor[TAM];
    int topo;

}PILHA_P;

void inicializar(PILHA_N *n, PILHA_P *p)
{
   n->topo = -1;
   p->topo = -1;
}

int lista_vazia(PILHA_N *n, PILHA_P *p)
{
   if(n->topo == -1 || p->topo == -1)
   {
    return 1;
   }
   return 0;
}

int lista_cheia(PILHA_N *n, PILHA_P *p)
{
    if(n->topo == TAM-1 && p->topo == TAM-1)
    {
        return 1;
    }
    return 0;
}

int inserir(PILHA_N *n, PILHA_P *p, int elem)
{
    int aux1, aux2;

    if(lista_cheia(n, p))
    {
        printf("Lista esta cheia.\n");
        return 1;
    }

    if(elem > 0)
    {
        p->topo++;
       p->vetor[p->topo] = elem;
    }

    else if(elem < 0)
    {
        n->topo++;
       n->vetor[n->topo] = elem;
       
    }

    else if(elem == 0)
    {
       if(lista_vazia(n, p))
       {
        printf("Uma das lista esta vazia.\n");
        return 1;
       }

       aux1 = p->vetor[p->topo];
       p->topo--;

       aux2 = n->vetor[n->topo];
       n->topo--;

       printf("Os numeros excluidos foram:\n Lista N: %d\n Lista P: %d\n", aux1, aux2);
    }
}

int menu()
{
    int opc;

    printf("\n----|Menu|----\n");
    printf("1. Inserir elemento, se for negativo sera inserido na pilha P, se for negativo na pilha N, e 0 excluira das duas lista.\n");
    printf("2. Vizualizar o vetor.\n");
    printf("Insira a opcao: ");
    scanf("%d", &opc);

    return opc;

}

void main()
{
   PILHA_N n;
   PILHA_P p;
int elem, opc;
   
   inicializar(&n, &p);
   do
   {
      opc = menu();
      switch (opc)
      {
         case 1:
         printf("Insira o numero a ser adicionado: ");
         scanf("%d", &elem);
         inserir(&n, &p, elem);
         break;
     
         default:
         printf("Opcao inexistente.\n");
         break;
      }
   } while (opc != 0);
   
  

}