#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

void afficherVoyageurs(Voyageur *tab, int n)
{
    int i;

    if (n == 0)
    {
        printf("\nAucun voyageur disponible.\n");
        return;
    }

    printf("\nListe des voyageurs :\n");
    for (i = 0; i < n; i++)
    {
        printf("\nVoyageur %d\n", i + 1);
        printf("Identifiant : %s\n", tab[i].id);
        printf("Nom         : %s\n", tab[i].nom);
        printf("Adresse     : %s\n", tab[i].adresse);
        printf("Nb voyages  : %d\n", tab[i].nbVoyages);
    }
}

int main()
{
    int choix;
    int n = 0;
    int pos;
    char id[50];
    char nomFich[] = "voyageurs.dat";
    Voyageur v;
    Voyageur *tab = charger_donnees(nomFich, &n);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Ajouter un voyageur\n");
        printf("2. Rechercher un voyageur\n");
        printf("3. Supprimer un voyageur\n");
        printf("4. Afficher tous les voyageurs\n");
        printf("5. Sauvegarder les donnees\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            saisirVoyageur(&v);
            tab = ajouter(v, tab, &n);
            printf("Operation terminee.\n");
            break;

        case 2:
            printf("Donner l'identifiant a rechercher : ");
            scanf(" %49[^\n]", id);
            pos = trouver(tab, id, n);
            if (pos == -1)
            {
                printf("Voyageur introuvable.\n");
            }
            else
            {
                printf("Voyageur trouve :\n");
                printf("Identifiant : %s\n", tab[pos].id);
                printf("Nom         : %s\n", tab[pos].nom);
                printf("Adresse     : %s\n", tab[pos].adresse);
                printf("Nb voyages  : %d\n", tab[pos].nbVoyages);
            }
            break;

        case 3:
            printf("Donner l'identifiant a supprimer : ");
            scanf(" %49[^\n]", id);
            supprimer(tab, id, &n);
            break;

        case 4:
            afficherVoyageurs(tab, n);
            break;

        case 5:
            sauvegarder_donnees(nomFich, tab, n);
            printf("Sauvegarde terminee.\n");
            break;

        case 0:
            sauvegarder_donnees(nomFich, tab, n);
            liberer(tab);
            printf("Donnees sauvegardees. Fin du programme.\n");
            break;

        default:
            printf("Choix invalide.\n");
        }
    }
    while (choix != 0);

    return 0;
}
void liberer(Voyageur *tab)
{
    free(tab);
}
