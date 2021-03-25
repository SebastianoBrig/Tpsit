#include <stdio.h>
#include <stdlib.h>

typedef struct El
{
int valore;
struct El* next;
}Nodo;

void push(Nodo *primo, int x){
    Nodo *vet=primo;
    while(vet->next!=NULL){
        vet=vet->next;
    }
    vet->next=(Nodo*)malloc(sizeof(Nodo));
    vet->next->valore=x;
    vet->next->next=NULL;
    }
void stampaLista(Nodo *primo){
    Nodo *vet=primo;
    while (vet!=NULL){
    printf("%d - %p \n",vet->valore, vet->next);
    vet=vet->next; /* fa puntare l al nodo successivo */
    }
    printf("\n");

}

int main()
{
int n;
Nodo* primo;
primo=NULL;/* metto l'head uguale uguale quindi la lista non presenta elementi */
do
{
printf("Inserisci un naturale o -1 per terminare\n");
scanf("%d",&n);
    if (n>=0){
        if (primo==NULL){
        primo = (Nodo*) malloc(sizeof(Nodo));
        primo->valore = n;
        primo->next = NULL;
        }
    else{
    push(primo,n);
    }
    }
/* imposta il puntatore al nodo successivo (che non esiste) a NULL */
} while (n>=0);
stampaLista(primo);
return 0;

}
