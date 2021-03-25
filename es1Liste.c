#include <stdio.h>
#include <stdlib.h>

struct El
{
int valore;
struct El* next;
};

int main()
{
int n;
struct El* lista;
struct El* l;
lista=NULL; /* metto l'head uguale uguale quindi la lista non presenta elementi */

do
{
printf("Inserisci un naturale o -1 per terminare\n");
scanf("%d",&n);
if (n>=0)
{
if (lista==NULL) /* se la lista non presenta ancora nessun elemento */
{
/* Crea l'head */

lista = (struct El*) malloc(sizeof(struct El));

l = lista;
}
else /* Se la lista presente già 1 o + elementi */
{
/* Crea un altro elemento nella lista */

l->next = (struct El*) malloc(sizeof(struct El));

l = l->next;
}
l->valore = n; /* imposta il valore del nodo appena creato a n*/
l->next = NULL; /* imposta il puntatore al nodo successivo (che non esiste) a NULL */
}
} while (n>=0);

l=lista; /* fa puntare l all'head della lista */
printf("numeri inseriti: ");
while (l!=NULL)
{
printf("%d - %p \n",l->valore, l->next);
l=l->next; /* fa puntare l al nodo successivo */
}
printf("\n");
return 0;
}
