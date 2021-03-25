#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

void push(Nodo *primo, int x){
    Nodo *vet=primo;
    while(vet->next!=NULL){
        vet=vet->next;
    }
    vet->next=(Nodo*)malloc(sizeof(Nodo));
    vet->next->val=x;
    vet->next->next=NULL;
}

int main()
{
    Nodo *primo;
    primo = (Nodo*)malloc(sizeof(Nodo));
    primo->val=1;
    primo->next=NULL;
    push(primo, 2);
    push(primo, 3);
    Nodo *vet;

    vet=primo;
    while(vet!=NULL){
        printf("il valore e': %d", vet->val);
        vet=vet->next;

    }
    return 0;
}
