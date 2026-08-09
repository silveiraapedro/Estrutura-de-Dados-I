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

int pilha_vazia(PILHA *p)
{
    if(p->topo == -1)
    {
        return 1;
    }

    return 0;
}

int pilha_cheia(PILHA *p)
{
    if(p->topo == TAM-1 )
    {
        return 1;
    }
    return 0;
}


int empilhar(PILHA *p, int elem)
{
    if(pilha_cheia(p))
    {
        printf("ERRO - Lista cheia.\n");
        return 1;
    }

    p->topo++;
    p->vetor[p->topo] = elem;
    return 0;
}

int desempilhar(PILHA *p)
{
    int aux;
    if(pilha_vazia(p))
    {
        printf("Lista esta vazia.\n");
        return 1;
    }
    
    aux = p->vetor[p->topo];
    p->topo--;
    return aux;

}


int alterar(PILHA *p)
{
    int n;

    if(pilha_vazia(p))
    {
        printf("Vai da nao ta vazia.\n");
        return 1;
    }

    PILHA aux;
    inicializar(&aux);

    n = p->vetor[0]; /// armazeno o primeiro valor nessa variavel

   for(int i=0; i<p->topo; i++)
   {
    empilhar(&aux, p->vetor[i]);
   }

   inicializar(p);
   while(!pilha_vazia(&aux))
   {
    empilhar(p, desempilhar(&aux));
   }

   empilhar(p, n);
   return 0;
}

void exibir(PILHA *p)
{
    while(!pilha_vazia(p))
    {
        printf("Elementos: %d\n", desempilhar(p));
    }
}

int menu()
{
    int opc;

    printf("\n\nMENU:");
    printf("\n0 - Sair");
    printf("\n1 - Inserir elemento na pilha");
    printf("\n2 - Alternar pilha");
    printf("\n3 - Exibir elementos da pilha");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opc);
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
    printf("Insira elemento: ");
    scanf("%d", &elem);
    empilhar(&p, elem);
    break;

    case 2:
    alterar(&p);
    break;

    case 3:
    exibir(&p);
    break;

    default:
    printf("naooidkgfo\n");
    break;
}
} while (opc != 0);
}

