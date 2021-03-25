#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct s_Post{
    char mese[MAX];
    int giorno;
    int id;
    int like;
}Post;

int main()
{
    Post *ArrPost;
    FILE *ptr;
    FILE *fp;
    char c;
    int count=0;
    int nv=0;
    int i=0;
    int k=0;
    int nlike=0;
    int npost=0;
    char *token;
    char MesIn[MAX];
    const char *ch = ",";
    char vet[MAX];
    fp=fopen("instagram.csv", "r");
    if (fp){
        for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n')
        count = count + 1;
        }
    }
    fclose(fp);
    ArrPost = (Post *) malloc(sizeof(Post) * count);
    ptr=fopen("instagram.csv", "r");
    if (ptr){
            printf("file ok!\n");
            while (fgets(vet,MAX,ptr)){
                if (nv!=0){

                    strcpy(ArrPost[i].mese, strtok(vet, ch));

                    token = strtok(NULL, ch);
                    ArrPost[i].giorno = atoi(token);

                    token = strtok(NULL, ch);
                    ArrPost[i].id = atoi(token);

                    token = strtok(NULL, ch);
                    ArrPost[i].like = atoi(token);

                    i++;
                }
            nv++;
            }
            printf("inserisci un mese: ");
            scanf("%s", MesIn);
            for (k=0;k<(count-1);k++){
                if(strcmp(ArrPost[k].mese,MesIn)==0){
                    npost++;
                    nlike=nlike+ArrPost[k].like;
                }
            }
            printf("npost: %d\n", npost);
            printf("nlike: %d", nlike);


    }
    free(ArrPost);
}
