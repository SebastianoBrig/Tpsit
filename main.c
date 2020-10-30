#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    FILE *ptr;
    int ac=0;
    int gc=0;
    int tc=0;
    int cc=0;
    int c;
    if((ptr=fopen("rna.txt", "r"))==NULL) {
		printf("Errore nell'apertura del file'");
		return 1;
	}

    do {
        //prelevo un carattere e controllo se e' uguale a uno dei caratteri da contare;
		c=fgetc(ptr);
		if (c=='a'){
            ac++;
		}
		if (c=='g'){
            gc++;
		}
		if (c=='c'){
            cc++;
		}
		if (c=='t'){
            tc++;
		}
	} while(c!=EOF);
	printf("a: %d\n", ac);
	printf("g: %d\n", gc);
	printf("c: %d\n", cc);
	printf("t: %d\n", tc);
	fclose(ptr);
	//stampo i contatori;

	return 0;


}
