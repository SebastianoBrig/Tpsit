#include <stdio.h>
#include <string.h>

#define MAX 200
int main () {

    char stin[MAX], stout[MAX], v, c, np;
    int nn=1, i, j, t, op, ls, l, n=0, z, ind;

;    for(int i = 0; i < MAX; i++) {
  stin[i] = 0;
}
    for(int j = 0; j < MAX; j++) {
  stout[j] = 0;
}

    printf ("premi '1' per effettuare l'encoding o '2' per effettuare il decoding\n");
     scanf ("%d", &op);
     if (op==1){
         printf("inserisci una stringa\n");
            scanf("%s", stin);
            ls=strlen(stin);
            for (t=0; t<=ls; t++) {

            if (stin[t]==stin[t+1]){
                nn++;
            }
            else {
                    printf("%d", nn);
                    printf("%c",stin[t]);
                    nn=1;
            }
        }
     }
     else {
            printf("inserisci una stringa\n");
            scanf("%s", stin);
            ls=strlen(stin);
            for (z=0; z<ls; z++) {
            if (stin[z]>= '0' && stin[z]<= '9'){

                n=n*10 + stin[z] -'0';

            }
            else {

            for (l=0; l<n; l++){
                printf("%c", stin[z]);
            }
            n=0;
            }

         }

   }
   return 0;
}



