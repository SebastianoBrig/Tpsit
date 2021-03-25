#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo *next;
}Nodo;

int is_empty(Nodo *head){
    if (head == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(Nodo **head, Nodo **tail, Nodo *element){
    if (*head==NULL){
        *head=element;
    }
    else{
        (*tail)->next=element;
    }
    *tail=element;
    element->next=NULL;
}

Nodo* dequeue(Nodo **head, Nodo **tail){
    Nodo *ret=*head;
    if (*head==NULL){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if (*head==NULL){
        *tail= NULL;
    }
    return ret;
}


int main()
{
    int n,val,i=0;
    Nodo *vout;
    vout = (Nodo*)malloc(sizeof(Nodo));
    Nodo *head=NULL;
    head = (Nodo*)malloc(sizeof(Nodo));
    Nodo *tail=NULL;
    tail = (Nodo*)malloc(sizeof(Nodo));
    Nodo *element;
    head = NULL;
    tail = NULL;
    printf("inserisci il numero di numeri: ");
    scanf("%d", &n);
    while (i<n){
        printf("inserisci il valore: ");
        scanf("%d", &val);
        Nodo *element = (Nodo*)malloc(sizeof(Nodo));
        element->valore=val;
        enqueue(&head,&tail,element);
        i++;
    }
    do {
        vout = dequeue(&head, &tail);
        printf("%d", vout->valore);
        free(vout);
    }while(is_empty(head)!=1);


}
