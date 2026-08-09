#include <stdio.h>
#define TAM 10

typedef struct sFila
{
    int itens[TAM];
    int inicio, fim;
}Fila;

void inicializar(Fila *f)
{
    f->inicio = TAM - 1;
    f->fim = TAM - 1;
}

int lista_cheia(Fila *f)
{
    if(f->inicio == f->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(Fila *f, int elem)
{
    f->fim = (f->fim + 1) % TAM;

    if(lista_cheia(f))
    {
        printf("Lista cheia.\n");
        f->fim--;
        if(f->fim == -1)
        f->fim = TAM - 1;
        return 1;
    }
    f->itens[f->fim] = elem;
    return 0;
}

int retirar(Fila *f)
{
    int aux = 0;
    if(!lista_cheia(f))
    {
        if(f->inicio == TAM - 1 )
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
        aux = f->itens[f->inicio];
        return aux;
    }

    else
    {
        printf("ERRO - Lista vazia;\n");
        return 0;
    }
}

void maior_menor(Fila f)
{
    int aux[TAM], cont = 0;
    int maior = aux[0], menor = aux[0];
    if(lista_cheia(&f))
    {
        printf("ERRO - Lista vazia.\n");
    }

    while(!lista_cheia(&f))
    {
        aux[cont++] = retirar(&f);
    }
    
    for(int i = 1; i<cont; i++)
    {
        if(aux[i] > maior)
        {
            maior = aux[i];
        }
        else if(aux[i] < menor)
        {
            menor = aux[i];
        }
    }

    printf("O maior elemento é: %d\n", maior);
    printf("O menor elemento é: %d\n", menor);

}

void realizar_media(Fila f)
{
    int aux[TAM]; 
    int quant = 0, total = 0;
    float media;
    if(lista_cheia(&f))
    {
        printf("ERRO - Lista vazia.\n");
    }

    while(!lista_cheia(&f))
    {
        aux[quant++] = retirar(&f);
    }

    for(int i = 0; i<quant; i++)
    {
        total += aux[i];
    }
    
    media = total / quant;
    printf("A media de numeros é: %0.2f\n", media);
}


void main()
{
    Fila f;
    float media;
    inicializar(&f);

    inserir(&f, 610);
    inserir(&f, 9);
    inserir(&f, 15);
    inserir(&f, 88);
    inserir(&f, 8);

    maior_menor(f);
    realizar_media(f);

}


