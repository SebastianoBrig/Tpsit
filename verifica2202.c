#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    char seme;
    int valore;
    struct nodo *next;
}Nodo;

int is_empty(Nodo *head){       //funzione che controlla che la coda sia vuota
    if (head == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(Nodo **head, Nodo **tail, Nodo *element){      //fuznione che inserisce un elemento in coda, all'ultimo posto
    if (*head==NULL){
        *head=element;
    }
    else{
        (*tail)->next=element;
    }
    *tail=element;
    element->next=NULL;
}

Nodo* dequeue(Nodo **head, Nodo **tail){            //funzione che rimuova il primo elemento della coda
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

bool fineTurno(Nodo **head, Nodo** tail){       //funzione per controllare se tutte le carte rimanenti sono rosse
    bool ris=true;
    Nodo *ret=*head;                            //ret punta alla stessa cosa di head
    while(ret->next!=NULL){                     //ciclo tutto il mazzo
        if(ret->seme=='P' || ret->seme== 'F'){  //se trovo una carta nera il risultato viene messo a false
            ris=false;
        }
        ret=ret->next;
    }
    return ris;
}


int main()
{
    int i=0;
    char c;
    Nodo *vout;
    vout = (Nodo*)malloc(sizeof(Nodo));
    Nodo *head=NULL;
    head = (Nodo*)malloc(sizeof(Nodo));
    Nodo *tail=NULL;
    tail = (Nodo*)malloc(sizeof(Nodo));
    Nodo *element;
    head = NULL;
    tail = NULL;
    for (int k=0; k<4; k++){        //riempo il mazzo di carte in ordine non casuale
    if (k==0){                      //in questo for determino il seme
        c='C';
    }
    if (k==1){
        c='Q';
    }
    if (k==2){
        c='P';
    }
    if (k==3){
        c='F';
    }
        for (i=1; i<14; i++){   //in quest'altro for metto nel mazzo tutte le 13 carte dello stesso seme determinato in precedenza
            Nodo *element = (Nodo*)malloc(sizeof(Nodo));
            element->valore=i;
            element->seme = c;
            enqueue(&head, &tail, element);
        }
    }
    while(fineTurno(&head,&tail)==false){ //ogni giro del while equivale a un turno di gioco
        vout = dequeue(&head, &tail);           //il while cicla finchè la funzione che controlla che tutte le carte siano rosse è falsa
        if (vout->seme=='P' || vout->seme=='F'){ //se il colore della carta estratta è nero viene scartata
            printf("scartata\n");
        }
        else {
            enqueue(&head,&tail,vout);          //se no viene reintrodotta in cima al mazzo
            printf("in cima\n");
        }
    }
    do {                                        //stampa di tutte le carte rimanenti nel mazzo
        vout = dequeue(&head, &tail);
        printf("%d", vout->valore);
        printf("%c\n", vout->seme);
        free(vout);
    }while(is_empty(head)!=1);                  //finchè la coda non è vuota


    return 0;
}
