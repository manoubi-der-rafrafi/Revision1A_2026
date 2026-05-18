#include"fonction.h"
#include <stdio.h>
#include <stdlib.h>
liste AjoutDebut(liste l , int v)
{
    cellule* nouv;
    nouv =(cellule*) malloc(sizeof(cellule));
    nouv->val = v;
    nouv->suiv = l;
    l = nouv;
    return l ;
}
liste ajoutFin(liste l , int v)
{
    cellule* nouv;
    nouv =(cellule*) malloc(sizeof(cellule));
    nouv->val = v;
    nouv->suiv = NULL ;
    if(l == NULL)
    {
        l = nouv;
    }
    else
    {

        cellule* parc;
        parc = l;
        while(parc->suiv!= NULL)
        {
            parc = parc->suiv ;
        }
        parc->suiv = nouv;
    }
    return l;

}
liste supprimerDebut(liste l)
{
    if(l != NULL)
    {
        cellule* Q;
        Q=l;
        l = l->suiv;
        free(Q);
    }
    return l;
}
liste supprimerFin(liste l)
{
    cellule *Q;
    if(l == NULL)
    {
        printf("liste vide");
    }
    else if (l->suiv == NULL)
    {
        free(l);
        l = NULL ;
    }
    else
    {
        cellule *parc , *pred;
        parc = l->suiv;
        pred = l ;
        while(parc->suiv != NULL)
        {
            parc = parc->suiv;
            pred = pred->suiv;
        }
        pred->suiv = NULL;
        free(parc);
    }
    return l;
}
void afficherListe(liste l)
{
    cellule *parc;
    parc = l;
    while(parc != NULL)
    {
        printf("val= %d" , parc->val);
        parc = parc->suiv;
    }
}
