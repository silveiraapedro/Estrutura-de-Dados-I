#include <stdio.h>
#include <string.h>
#define TAM 50

typedef struct sLista
{
    char nome[TAM][50]; 
    char cpf[TAM][15];
    char id[TAM][20];
    int sit[TAM];
    int n; 

}LISTA;

void inicializar(LISTA *L)
{
   L->n = -1;
} 

int lista_cheia(LISTA *L)
{
   if(L->n == TAM)
   {
    printf("A lista esta cheia.\n");
    return 1;
   }
   else
   { 
    return 0;
   } 

}


int adicionar_tenda(LISTA *L, char name, char cp, int prod)
{
  int i= L->n;
  char op;

  if(lista_cheia(L))
  {
   printf("A lista de tendas esta cheia.\n");
   return 1;
  }
  
  do
  {
   strcpy(L->nome[i], name);
   strcpy(L->cpf[i], cp);

   if(prod == 1)
   {
    strcpy(L->id[i], "Bebida");
   }
  else if(prod == 2)
   {
    strcpy (L->id[i], "Lanches");
   }
  else if (prod == 3)
   {
    strcpy(L->id[i], "Artigos em geral");
   }
   
   L->sit[i] = 1;
   L->n++;
   printf("Deseja inserir mais um cliente(s/S ou n/N)? ");
   scanf(" %c", &op);
  }while (op != 's' && op != 'S');
   return 0;
}

void mostrar_vetor(LISTA *L)
{
 int i;

 for(i=0; i< (L->n+1); i++)
 {
    printf("Barraca[%d]\n", i);
    printf("Nome: %s\n", L->nome[i]);
    printf("CPF: %s\n", L->cpf[i]);
    printf("ID: %s\n", L->id[i]);
 }

}


int main()
{
LISTA lista;

 char name[50], cp[15];
 int prod;

 inicializar(&lista);

printf("Insira o nome do comprador: ");
scanf(" %s", name);
printf("Insira o cpf do comprador: ");
scanf(" %s", cp);
printf("Insira o produto que sera vendido: ");
scanf("%d", &prod);
 adicionar_tenda(&lista, name, cp, prod);
 printf("Chamando mostrar_vetor...\n");
 mostrar_vetor(&lista);

 return 0;
}