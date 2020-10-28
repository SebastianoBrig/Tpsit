#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct s_canzone{
	int  num;
	char nome[20];
	char autore[20];
} canzone;

void Memorizzazione(canzone* Playlist, FILE* ptr);

int main()
{
    canzone Playlist[MAX];
    FILE *ptr;
    ptr=fopen("playlist.csv", "rt");
    if (ptr){
            printf("file ok!\n");
            Memorizzazione(Playlist,ptr);
            fclose(ptr);

    return 0;

    }
}
void Memorizzazione(canzone* Playlist, FILE* ptr){

            int i=0,k=0,w,j;
            char vet[MAX];
            fscanf(ptr, "%d,", &Playlist[i].num);

            for (i=0;fgets(vet,100,ptr)!=NULL;i++){

                for(w = 0; vet[w]!=','; w++){
                    Playlist[i].nome[w]=vet[w];
                    }
            Playlist[i].nome[w] = '\0';
            for(j = w+1; vet[j]!='\n'; j++){
            Playlist[i].autore[k]= vet[j];
            k++;
        }
        printf("%d\n", Playlist[i].num);
        printf("%s\n", Playlist[i].nome);
        printf("%s\n", Playlist[i].autore);

        fscanf(ptr, "%d,", &Playlist[i+1].num);
        k=0;

            }

        }

