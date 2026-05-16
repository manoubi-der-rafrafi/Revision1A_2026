#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
    gateau g;
    int i;
    int n;
    int num;
    char nom_fich[] = "gateaux.txt";

    printf("Combien de gateaux voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nSaisie du gateau numero %d\n", i + 1);
        saisir_gateau(&g);
        ajouter_gateau_ft(g, nom_fich);
    }

    printf("\nNombre total de gateaux dans le fichier : %d\n", nbre_gateaux_ft(nom_fich));

    printf("Donner le numero de la ligne a afficher : ");
    scanf("%d", &num);
    afficher_gateau(nom_fich, num);

    return 0;
}
