#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

void saisirPatient(Patient *p)
{
    printf("Donner le nom du patient : ");
    scanf("%49s", p->nom);

    printf("Donner le prenom du patient : ");
    scanf("%49s", p->prenom);

    printf("Donner le rendez-vous (0 ou 1) : ");
    scanf("%d", &p->rdv);
}
void afficherPatient(Patient p)
{
    printf("nom: %s" , p.nom);
    printf("nom: %s" , p.prenom);
    printf("nom: %d" , p.rdv);
}
liste AjoutPatient(liste tete, Patient p)
{
    cellule* nouv;
    nouv =(cellule*) malloc(sizeof(cellule));
    nouv->p = p ;
    nouv->suiv = NULL ;

    if(tete == NULL)
    {
        tete = nouv;
    }
    else
    {
        cellule* parc;
        parc = tete;
        while(parc->suiv != NULL)
        {
            parc = parc->suiv;
        }

        // mert2aked eli parc tponty 3la ekher ellement
        parc->suiv = nouv;

    }
    return tete ;
}
void RendezVous(liste tete, int *rdv, int *sansRdv)
{
    cellule* parc;
    parc = tete;
    (*rdv) = 0;
    (*sansRdv) = 0;
    while(parc != NULL)
    {
        if(parc->p.rdv == 0)
        {
            (*sansRdv)++;
        }
        else
        {
            (*rdv)++;
        }
        parc = parc->suiv ;
    }
}
liste SupprimePatient(liste tete)
{
    int rdv,sansRdv;
    if(tete != NULL)
    {
        RendezVous(tete , &rdv , &sansRdv);
        if(rdv == 0)
        {
            //SPPURIMER TETE
            cellule* Q;
            Q = tete;
            tete = tete->suiv;
            free(Q);

        }
        else
        {
            //supprimer milieu
            if(tete->p.rdv == 1)
            {
                //Supprimer tete
                 cellule* Q;
                Q = tete;
                tete = tete->suiv;
                free(Q);
            }
            else
            {
                cellule* parc;
                cellule* pred;
                parc = tete->suiv ;
                pred =tete;
                while(parc != NULL && parc->p.rdv != 1)
                {
                    parc = parc->suiv;
                    pred = pred->suiv;
                }
                if(parc != NULL)
                {
                    pred->suiv = parc->suiv ;
                    free(parc) ;
                }
            }
        }
    }
    return tete ;
}
void ConsulterSalleAttente(liste tete)
{
    cellule *parc;
    parc= tete;
    while(parc != NULL)
    {
        if(parc->p.rdv == 1)
        {
            afficherPatient(parc->p);
        }
        parc = parc->suiv;
    }
    parc= tete;
    while(parc != NULL)
    {
        if(parc->p.rdv == 0)
        {
            afficherPatient(parc->p);
        }
        parc = parc->suiv;
    }
}
void sauvegarderPatients(liste tete, char *chemin)
{
    FILE *fichier ;
    fichier = fopen(chemin , "w");
    if(fichier != NULL)
    {
        cellule *parc;
        parc = tete;
        while(parc != NULL)
        {
            //sauvgarde dans le fichier

            fprintf(fichier ,"%s %s %d\n" , parc->p.nom , parc->p.prenom , parc->p.rdv);
            parc = parc->suiv;
        }
        fclose(fichier);
    }
    else
    {
        printf("probleme d'ouverture!!\n");
    }
}
liste recupererListePatients(liste tete, char *chemin)
{
    FILE *fichier;
    fichier = fopen(chemin , "r");
    Patient p ;
    if(fichier != NULL)
    {
        while(fscanf(fichier , "%s %s %d\n" , p.nom , p.prenom , &p.rdv ) != EOF)
        {
            tete = AjoutPatient(tete , p) ;
        }
        fclose(fichier);
    }
    else
    {
        printf("probleme d'ouverture!!\n");
    }
    return tete;
}
