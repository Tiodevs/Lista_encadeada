#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void inserir();
struct no * inserir_no(int);
struct no * pesquisar_no(int);

struct  no
{
    int n;
    struct no *p;
};

struct no * prim;

int main()
{
    prim = NULL;
    inserir();
    return 0;
};

void inserir(){
    int n;
    struct no * aux;
    printf("Informe o numero: ");
    scanf("%d", &n);
    aux = inserir_no(n);
    if (aux != NULL)
    {
        printf("Inserido com sucesso: %p", aux);
    } else {
        printf("Erro ao inserir");
    }   
};

struct no * inserir_no(int n)
{
    struct no * novo, * aux;
    novo = (struct no *)malloc(sizeof (struct no));
    if (novo != NULL)
    {
        novo->n = n;
        novo->p = NULL;
        if (prim == NULL)
        {
            prim = novo;
        }else{
            aux = prim;
            while (aux->p != NULL)
            {
                aux = aux->p;
                aux->p = novo;
            }
        }
        
    }
    
    return novo;
}

struct no * pesquisar_no(int n)
{
    struct no * aux;
    aux = prim;
    while (aux != NULL && aux->n != n )
    {
        aux = aux->p;
    }
    return aux;
}
