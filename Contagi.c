#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
typedef struct s_regione{
    char orario[MAX];
    char stato[MAX];
    char codice[MAX];
    char nome[MAX];
    int lat;
    int LOng;
    int ric;
    int ti;
    int to;
    int id;
    int pos;
    int vpos;
    int npos;
    int dime;
    int dec;
    int sosp;
    int scree;
    int tc;
    int tam;
    int ct;
}regione;
void totRic(regione *regioni, int i);
void top3Max(regione *regioni, int i);
void top3Min(regione *regioni, int i);
int main()
{
    regione *regioni ;
    FILE *ptr;
    FILE *fp;
    char *token;
    char vet[MAX];
    int i=0;
    int nv=0;
    const char *ch = ",";
    int c,count=0;
    fp=fopen("data.csv", "r");
    if (fp){
        for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n')
        count++;
        }
    }
    fclose(fp);
    regioni = (regione *) malloc(sizeof(regione) * count);
    ptr=fopen("data.csv", "r");
    if (ptr!=NULL){
            printf("file ok!\n");
            while (fgets(vet,MAX,ptr)){
            if (nv!=0){

            strcpy(regioni[i].orario, strtok(vet, ch));

            strcpy(regioni[i].stato, strtok(NULL, ch));

            strcpy(regioni[i].codice, strtok(NULL, ch));

            strcpy(regioni[i].nome, strtok(NULL, ch));

             token = strtok(NULL, ch);
            regioni[i].lat = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].LOng = atoi(token);

            token = strtok(NULL, ch);
            regioni[i].ric = atoi(token);

            token = strtok(NULL, ch);
            regioni[i].ti = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].to = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].id = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].pos = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].vpos = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].npos = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].dime = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].dec = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].sosp = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].scree = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].tc = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].tam = atoi(token);

             token = strtok(NULL, ch);
            regioni[i].ct = atoi(token);

            i++;
            }
            nv++;
            }
            top3Max(regioni,i);
            top3Min(regioni,i);
            totRic(regioni,i);

    }

    else {
        printf("errore sul file!");
    }
    free(regioni);
    return 0;
}

void top3Max(regione *regioni, int i){
        int max3=0;
        int max2=0;
        int max1=0;
        int k=0;
        char regioneMax3[4096];
        char regioneMax2[4096];
        char regioneMax1[4096];
        for(k=1;k<i;k++){
            if ((regioni[k].ti)>max3){
                    if(regioni[k].ti>max2){
                            if(regioni[k].ti>max1){
                                strcpy(regioneMax1,regioni[k].nome);
                                max1=regioni[k].ti;
                            }
                            else{
                                strcpy(regioneMax2,regioni[k].nome);
                                max2=regioni[k].ti;
                            }
                    }
                    else {
                            strcpy(regioneMax3,regioni[k].nome);
                            max3=regioni[k].ti;
                    }

            }
        }
        printf("maggiori\n");
        printf("1: %s ", regioneMax1);
        printf("2: %s ", regioneMax2);
        printf("3: %s\n ", regioneMax3);


}

void top3Min(regione *regioni, int i){
        int min1=10000;
        int min2=10000;
        int min3=10000;
        int k=0;
        char regioneMin3[4096];
        char regioneMin2[4096];
        char regioneMin1[4096];
        for(k=1;k<i;k++){
            if (regioni[k].ti<min3){
                    if(regioni[k].ti<min2){
                            if(regioni[k].ti<min1){
                                strcpy(regioneMin1,regioni[k].nome);
                                min1=regioni[k].ti;
                            }
                            else{
                                strcpy(regioneMin2,regioni[k].nome);
                                min2=regioni[k].ti;
                            }
                    }
                    else {
                            strcpy(regioneMin3,regioni[k].nome);
                            min3=regioni[k].ti;
                    }

            }
        }
        printf("minori\n");
        printf("1: %s ", regioneMin1);
        printf("2: %s ", regioneMin2);
        printf("3: %s \n", regioneMin3);



}

void totRic(regione *regioni, int i){
    int k=1;
    int cr=0;
    while(k<i){
        cr=cr+regioni[k].ti;
        k++;
    }
    printf("casi totali terapia intensiva: %d",cr);

}
