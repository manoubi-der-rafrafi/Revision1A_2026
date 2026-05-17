#include"fonction.h"
#include <stdio.h>
#include <stdlib.h>

void saisirVoyageur(Voyageur *ptv)
{
    if (ptv == NULL)
    {
        return;
    }

    printf("Donner l'identifiant du voyageur : ");
    scanf("%s", ptv->id);

    printf("Donner le nom du voyageur : ");
    scanf("%s", ptv->nom);

    printf("Donner l'adresse du voyageur : ");
    scanf("%s", ptv->adresse);

    printf("Donner le nombre total de voyages : ");
    scanf("%d", &ptv->nbVoyages);
}

int nbVoyageurs(char nomFich[])
{
    Voyageur v;
    int nb = 0;
    FILE *fichier;
    fichier = fopen(nomFich , "rb");
    if(fichier != NULL)
    {
        while(fread(&v , sizeof(Voyageur) , 1 , fichier) != 0)
        {
            nb++;
        }
        fclose(fichier);
    }
    else
    {
        printf("probleme d'ouverture");
    }
    return nb ;
}
Voyageur *charger_donnees(char nomFich[], int *n)
{
    Voyageur *tab ;
    FILE *fichier;
    (*n) = nbVoyageurs(nomFich) ;
    tab =(Voyageur*) malloc((*n) * sizeof(Voyageur));
    fichier = fopen(nomFich , "rb");
    if(fichier != NULL && tab != NULL)
    {
        fread(tab , sizeof(Voyageur) , *n , fichier);
        fclose(fichier);
    }
    else
    {
        printf("probleme d'ouverture");
    }
    return tab ;
}
Voyageur *charger_donnees2(char nomFich[], int *n)
{
    Voyageur v;
    Voyageur *tab ;
    FILE *fichier;
    fichier = fopen(nomFich , "rb");
    (*n) = 0;
    if(fichier != NULL)
    {
        while(fread(&v , sizeof(Voyageur) , 1 , fichier ) != 0)
        {
            tab =(Voyageur*) realloc(tab ,((*n)+1) * sizeof(Voyageur));
            tab[*n] = v;
            (*n)++;
        }
        fclose(fichier);
    }
    else
    {
        printf("probleme d'ouverture");
    }
    return tab ;
}
void sauvegarder_donnees(char nomFich[], Voyageur *tab, int n)
{
    FILE *fichier;
    fichier = fopen(nomFich , "wb");
    if(fichier != NULL)
    {
        fwrite(tab , sizeof(Voyageur), n , fichier);
        fclose(fichier);
    }
    else
    {
        printf("probleme d'ouverture");
    }
}
int trouver(Voyageur *tab, char id[], int n)
{
    int i = 0 ;
    while(i<n && strcmp(tab[i].id , id) != 0)
    {
        i++;
    }
    if(i == n)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
Voyageur * ajouter (Voyageur v, Voyageur * tab, int * n)
{
    int pos = trouver(tab , v.id , *n) ;
    if(pos == -1)
    {
        tab = (Voyageur*) realloc(tab , ((*n)+1) * sizeof(Voyageur));
        tab[*n] = v;
        (*n)++;
    }
    else
    {
        printf("voyageur existe deja!!\n");
    }
    return tab;
}
void supprimer(Voyageur *tab, char id[], int *n)
{
    int i;
    int pos = trouver(tab , id , *n) ;
    if(pos != -1)
    {
        for(i = pos ; i < (*n)-1 ; i++)
        {
            tab[i] = tab[i+1];
        }
        (*n)--;
        tab =(Voyageur*) realloc(tab , (*n) * sizeof(Voyageur));
    }
    else
    {
        printf("voyageur n'existe pas deja!!\n");
    }
}
