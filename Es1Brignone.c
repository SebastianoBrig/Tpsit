#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int main()
{
    float r, nc=1;
    int n, i, m, k, g=0;
    int x[MAX];
    printf("inserisci r\n");
    scanf("%f", &r);
    printf("inserisci n\n");
    scanf("%d", &n);

    for(m=0; m < MAX; m++){
        x[m] = 0;
    }

    x[0]=1;

    for (i=1 ;i<1000; i++){
        g++;
        nc=nc*r;
        (int)nc;
        x[i]=nc;
        printf("%f\n", nc);
        if (nc>=n){
            break;
        }
    }

    for(k=0; k<g; k++){
        printf("x[%d] = %d \n",k, x[k]);
    }

    printf("la classe si e' ammalata in %d giorni", g);
    return 0;

}
