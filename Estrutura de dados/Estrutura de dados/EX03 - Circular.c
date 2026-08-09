#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tv
{
    char canal[20];
}CV;

typedef struct cell
{
    CV info;
    struct cell *next;
}CELULA;

void init(CELULA **lista)
{
    *lista = NULL;
}

CELULA* getnode()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

int empty(CELULA *lista)
{
    if(lista == NULL)
        return 1;
    return 0;
}

void freenode(CELULA *q)
{
    free(q);
}

void put_end(CELULA **lista, CV c)
{
    CELULA *q = getnode();

    if(q != NULL)
    {
        strcpy(q->info.canal, c.canal);
        if(empty(*lista))
        {
            q->next = q;
        }
        else
        {
            q->next = (*lista)->next; //LEMBRAR QUE É O PONTEIRO DO PROXIMO NÓ A FRENTE DO PRIMEIRO
            (*lista)->next = q;
        }
        *lista = q;
    }
}

void passar(CELULA *lista)
{
    CELULA *q;
    char op;

    if(!empty(lista))
    {
        q = lista->next;
        do
        {
            printf("%s\n", q->info.canal);
            q = q->next;
        printf("Deseja passar mais um canal(s-sim, n-nao): ");
        scanf(" %c", &op);  
        }while(op != 'n');
    }
}

CV inserir()
{
    CV c;
    printf("Insira o nome do canal: ");
    scanf("%[^\n]s", c.canal);
    fflush(stdin);

    return c;
}


void main()
{
    CELULA *lista;
    CV c;
    init(&lista);

    c = inserir();
    put_end(&lista, c);
    
    c = inserir();
    put_end(&lista, c);

    c = inserir();    
    put_end(&lista, c);

    passar(lista);

}




