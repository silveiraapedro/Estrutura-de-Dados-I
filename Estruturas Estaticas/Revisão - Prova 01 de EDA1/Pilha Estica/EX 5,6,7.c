#include <stdio.h>
#define TAM 10

typedef struct sPilha
{
    int vetor[TAM];
    int n;
}pilha;

void inicializar(pilha *p)
{
    p->n = -1;
}

int vazia(pilha *p)
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

int cheio(pilha *p)
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

int inserir(pilha *p, int elem)
{
    if(cheio(p))
    {
        printf("ERRO - lista cheia.\n");
        return 1;
    }
    
    p->n = p->n+1;
    p->vetor[p->n] = elem;
}

int remover(pilha *p)
{
    int aux=0;
    if(!vazia(p))
    {
        aux = p->vetor[p->n];
        p->n = p->n-1;
    }
    else
    {
        printf("Lista vazia.\n");
        return 1;
    }
    return aux;
}

pilha inverter(pilha p)
{
    pilha aux;

    inicializar(&aux);

    while(!vazia(&p))
    {
        inserir(&aux, remover(&p));
    }

    return aux;
}

void topo_pares(pilha *p)
{
    pilha par;
    pilha impar;
    int aux;

    inicializar(&par);
    inicializar(&impar);

    while(p->n > 0)
    {
        aux = remover(p);
        if(aux%2 == 0)
        {
            inserir(&par, aux);
        }
        else
        {
            inserir(&impar, aux);
        }
    }

    while(!vazia(&par))
    {
        inserir(p, remover(&par));
    }

    while(!vazia(&impar))
    {
        inserir(p, remover(&impar));
    }
}

void topo_pilha_inverter(pilha *p)
{
    pilha aux;
    int ultimo = 0, primeiro = 0;

    inicializar(&aux);

    ultimo = remover(p);

    while(!vazia(p))
    {
        inserir(&aux, remover(p));
    }

    primeiro = remover(&aux);

    inserir(p, ultimo);

    while(!vazia(&aux))
    {
        inserir(p, remover(&aux));
    }

    inserir(p, primeiro);

}


void imprimir(pilha p)
{
    int i=0;
    while(!vazia(&p))
    {
        printf("Posicao[%d]: %d\n", i, remover(&p));
        i++;
    }
}

int menu()
{
    int opc;

    printf("\n-------MENU-------\n");
    printf("1. Inserir elementos.\n");
    printf("2. Remover elemento.\n");
    printf("3. Inverter pilha.\n");
    printf("4. Valores pares no topo e impares no final.\n");
    printf("6. Apresentar elmeentos.\n");
    printf("0. Encerra programa.\n");
    printf("Insira a opcao: ");
    scanf("%d", &opc);

    return opc;
}

void main()
{
    pilha p;
    pilha aux;

    int opc, elem;
    inicializar(&p);

    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
        printf("Insira o elemento a ser adicionado: ");
        scanf("%d", &elem);
        inserir(&p, elem);
            break;
        
            case 2:
            remover(&p);
            break;

            case 3:
            aux = inverter(p);
            imprimir(aux);
            break;

            case 4:
            topo_pares(&p);
            imprimir(p);
            break;

            case 5:
            topo_pilha_inverter(&p);
            imprimir(p);
            break;

            case 6:
            imprimir(p);
            break;
        default:
            break;
        }
    } while (opc != 0);

}


void inserir_inicio(fila *f, int elem)
{
    
        if(f->inicio == 0)
        {
            f->inicio = TAM - 1;
        }
        else
        {
            f->inicio = (f->inicio)- 1;
        }
    }
    else
    {
        printf("erro ");

        return 1;
    }

    f->inicio[(f->inicio+1)%TAM] = elem;
    }

    void remover_fim(fila *f)
    {
        int aux = 0;

        if(!vazia(f))
        {
            if(f->fim == 0)
            {
                f->fim = TAM - 1;
            }
            else
            {
                f->fim = (f->fim) -1;
            }
        }
        else
        {
          fds
        }

        aux = f->vetor[(f->fim+1)%TAM] 
    }