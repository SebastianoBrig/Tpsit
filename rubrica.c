#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 240

typedef struct s_contatto {
    int id;
    char nome[64];
    char numero[16];
}contatto;

typedef struct s_rubrica{
    int num_inseriti;
    contatto db[MAX];
}rubrica;

char *trova_numero_da_nome(rubrica *r, char *nome);
int inserisci(rubrica *r,char *nome, char *numero);
void stampa(rubrica *r);

int main()
{

    rubrica *r,d;
    char nomein[64];
    char numout[16];
    char name[64];
    char number[16];
    int op;
    char ind;
    bool mod=true;
    r=&d;
    r->num_inseriti=0;
    while (mod==true){
    do{
    printf("seleziona la funzione: \n 1.inserisci un numero \n 2.trova un contatto \n 3.stampa la rubrica\n");
    scanf("%d",&op);
    }while(op!=1 && op!=2 && op!=3);
        switch(op){
            case 1:
                printf("inserisci il nome: ");
                scanf("%s", name);
                printf("inserisci il numero: ");
                scanf("%s", number);
                inserisci(r,name,number);
                break;
            case 2:
                printf("inserisci il nome: ");
                scanf("%s", nomein);
                strcpy(numout,trova_numero_da_nome(r,nomein));
                if (numout!=NULL){
                printf("%s\n", numout);
                }
                break;
            case 3:
                stampa(r);
                break;

        }
        printf("premi '+' se vuoi apportare apportare ulteriori modifiche,altrimenti premi 'x': ");
        scanf(" %c", &ind);
        if (ind=='+'){
            mod=true;
        }
        else {
            mod=false;
        }


    }

    return 0;
}

void stampa(rubrica *r){
    int i;
    contatto *p;
    printf("\nStampa rubrica %d contatti\n", r->num_inseriti);
    for (i=0; i<MAX; i++){
        if (i==r->num_inseriti)
            break;
        p=&r->db[i];
        printf("%s, %s\n", p->nome, p->numero);

    }

}

char *trova_numero_da_nome(rubrica *r, char *nome){
    int i;
    contatto *p;
    for (i=0; i<MAX; i++) {
        if (i==r->num_inseriti)
            break;
        p=&r->db[i];

        if (strcmp(p->nome,nome)==0)
            return p->numero;
    }
    return NULL;

}


int inserisci(rubrica *r,char *nome, char *numero){
    contatto *p;
    if (r->num_inseriti == MAX){
        printf("rubrica piena");
        return -1;
    }
    p=&r->db[r->num_inseriti];

    strcpy(p->nome,nome);
    strcpy(p->numero,numero);
    p->id=r->num_inseriti;
    r->num_inseriti++;
    return 0;

}






