#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
typedef struct nodo{
    int valore;
    struct nodo *next;
}Nodo;

int is_empty(Nodo *head){
    if (head == NULL){
        return 1;
        printf("ohya");
    }
    else {
        return 0;
    }
}

void push(Nodo **head, Nodo *elemento){
    if (is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }
    else {
        elemento->next = *head;
        *head = elemento;
    }

}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if (*head == NULL){
        printf("GAA");
        return NULL;
    }
    else{
        *head = ret->next;
    }
    return ret;
}

int main()
{
    int val;
    Nodo *head=NULL;
    head = (Nodo*)malloc(sizeof(Nodo));
    Nodo *elemento;
    Nodo *vout;
    vout = (Nodo*)malloc(sizeof(Nodo));
    int n;
    printf("inserisci il numero di numeri ");
    scanf("%d", &n);
    for (int k=0; k<n;k++){
        printf("si");
        scanf("%d", &val);
        elemento = (Nodo*)malloc(sizeof(Nodo));
        elemento->valore=val;
        push(&head,elemento);
    }

    do{
        vout = pop(&head);
        printf("%d", vout->valore);
        free(vout);
    }while(is_empty(head)!=1);

    return 0;
}
