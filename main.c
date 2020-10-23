#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
	int  num;
	char nome[20];
	char autore[20];
} canzone;

int main()
{
    canzone Playlist[MAX];
    FILE *ptr;
    int i;
    ptr=fopen ("playlist.csv", "rt");
    if (ptr){
            printf("file ok!");
            for (i=0;i<10;i++){}
             fgetc(ptr, "%d%s%s\n", &Playlist[i].num, &Playlist[i].nome, &Playlist[i].autore);
             printf("numero:%d nome:%s voto:%s\n", Playlist[i].num, Playlist[i].nome, Playlist[i].autore);
            }
            fclose(ptr);

    return 0;

}
