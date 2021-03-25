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

void push(Nodo **head, Nodo *elemento){
    if (is_empty(*head)){
        *head = elemento
        elemento->next = NULL;
    }
    else {
        elemento->next = *head;
        *head = elemento;
    }

}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if (is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    return ret;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
