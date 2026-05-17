#ifndef FONCTION_H
#define FONCTION_H

typedef struct
{
    char id[50];
    char nom[50];
    char adresse[50];
    int nbVoyages;
} Voyageur;


int nbVoyageurs(char nomFich[]);
void saisirVoyageur(Voyageur *ptv);
Voyageur *charger_donnees(char nomFich[], int *n);
void sauvegarder_donnees(char nomFich[], Voyageur *tab, int n);
int trouver(Voyageur *tab, char id[], int n);
Voyageur *ajouter(Voyageur v, Voyageur *tab, int *n);
void supprimer(Voyageur *tab, char id[], int *n);
void liberer(Voyageur *tab);

#endif
