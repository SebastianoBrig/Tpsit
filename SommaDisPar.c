#include <stdio.h>
#include <stdlib.h>
#define max 100


int sommaDis(int *vet, int n){
int k,sd=0;
for (k=1;k<n;k=k+2){
    sd=sd+vet[k];
}
return sd;
}

int sommaPar(int *vet, int n){
int k,sp=0;
for (k=0;k<n;k=k+2){
    sp=sp+vet[k];
}
return sp;
}

int main()
{
    int vet[100];
    int i,n,sd,sp;
    do{
        printf("inserisci la lunghezzza del vettore: ");
        scanf("%d",&n);
    }while(n<=0 || n>100);
        printf("inserisci le variabili nel vettore (una per volta)\n");
    for (i=0;i<n;i++){
        scanf("%d", &vet[i]);
    }
    sd=sommaDis(vet,n);
    sp=sommaPar(vet,n);
    printf("somme delle posizioni dispari: %d\n", sd);
    printf("somme delle posizioni pari: %d", sp);

    return 0;
}
