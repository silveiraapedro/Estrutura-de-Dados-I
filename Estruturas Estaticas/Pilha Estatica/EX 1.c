#include <stdio.h>
#define TAM 10

typedef struct sPilha
{
int vetor[TAM];
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
    if(p->topo == TAM-1)
    {
        return 1;
    }
    return 0;
}

int insetir_elementos(PILHA *p, int elem)
{
    int aux;

    if(lista_cheia(p))
    {
        printf("A lista esta cheia.\n");
        return 1;
    }

    if((elem % 2) == 0) 
    {
        p->topo++;
        p->vetor[p->topo] = elem;
    }
    else
    {
        if(lista_vazia(p))
        {
            printf("A lista ainda esta vazia.\n");
            return 1;
        }
        aux = p->vetor[p->topo];
        p->topo--;
        printf("O numero excluido foi: %d", aux);
    }
    return 0;
} 

int desempilhar(PILHA *p)
{
    int aux;
  if(lista_vazia(p))
  {
    printf("Lista vazia.\n");
    return 1;
  }

   aux = p->vetor[p->topo];
   p->topo--;
   return aux;

}

void exibir_vetor(PILHA p)
{
 while(!lista_vazia(&p))
 {
    printf("Elemento: %d\n", desempilhar(&p));
 }
}

int menu()
{
    int opc;

    printf("\n----|Menu|----\n");
    printf("1. Inserir elemento, se for par sera inserido, se for par vai ser excluido.\n");
    printf("2. Vizualizar o vetor.\n");
    printf("Insira a opcao: ");
    scanf("%d", &opc);

    return opc;

}

void main()
{
    PILHA p;
    int elem, opc;

 inicializar(&p);

 do
 {
    opc = menu();
    switch (opc)
    {
       case 1:
       printf("Insira o numero a ser adicionado: ");
       scanf("%d", &elem);
       insetir_elementos(&p, elem);
       break;
    
       case 2:
       exibir_vetor(p);
       break;
   
       default:
       printf("Opcao inexistente.\n");
       break;
    }
 } while (opc != 0);
 

}