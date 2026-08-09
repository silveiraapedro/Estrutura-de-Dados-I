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

int vetor_cheio(PILHA *p)
{
    if(p->topo == TAM)
    {
        return 1;
    }
    return 0;
}

int empilhar(PILHA *p, int elem)
{
    if(vetor_cheio(p))
    {
        printf("A lista esta cheia.\n");
        return 1;
    }

    p->topo++;
    p->vetor[p->topo] = elem;
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


int inverter(PILHA *p)
{
 PILHA aux;
 inicializar(&aux);
 int elem;

while(!lista_vazia(p))
{
    elem = desempilhar(p);
    printf("Elementos sendo transferidos: %d\n", elem);
    empilhar(&aux, elem);
}
}

void exibir(PILHA *p)
{
    PILHA aux;
    while(! lista_vazia(&p))
    {
        printf("Elementos: %d\n", desempilhar(&aux));
    }
}


int menu()
{
    int opc;

    printf("\n\nMENU:");
    printf("\n0 - Sair");
    printf("\n1 - Inserir elemento na pilha");
    printf("\n2 - Inverter pilha");
    printf("\n3 - Exibir elementos da pilha invertida");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opc);
    return opc;
}

void main()
{
    PILHA *p;
    int elem, opc;

    inicializar(&p);

    do
    {
    opc = menu();
    switch (opc)
    {
        case 1:
        printf("Insira o elemento: ");
        scanf("%d", &elem);
        empilhar(&p, elem);
        break;
    
        case 2:
        inverter(&p);
        break;

        case 3:
        exibir(&p);
        break;

    default:
    printf("opcao invalida.\n");
        break;
    }
}while(opc!=0);
}