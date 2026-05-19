#include <stdio.h>
#include "fonction.h"

int main()
{
    liste tete = NULL;
    Patient p;
    int choix;
    int rdv;
    int sansRdv;
    char chemin[100] = "patients.txt";

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Saisir et ajouter un patient\n");
        printf("2. Afficher un patient\n");
        printf("3. Afficher les patients de la salle d'attente\n");
        printf("4. Compter les patients avec et sans rendez-vous\n");
        printf("5. Faire entrer un patient en consultation\n");
        printf("6. Sauvegarder les patients dans un fichier\n");
        printf("7. Recuperer les patients depuis un fichier\n");
        printf("0. Quitter\n");
        printf("Donner votre choix : ");
        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                saisirPatient(&p);
                tete = AjoutPatient(tete, p);
                break;

            case 2:
                saisirPatient(&p);
                afficherPatient(p);
                break;

            case 3:
                ConsulterSalleAttente(tete);
                break;

            case 4:
                RendezVous(tete, &rdv, &sansRdv);
                printf("Nombre de patients avec rendez-vous : %d\n", rdv);
                printf("Nombre de patients sans rendez-vous : %d\n", sansRdv);
                break;

            case 5:
                tete = SupprimePatient(tete);
                printf("Un patient est entre en consultation.\n");
                break;

            case 6:
                sauvegarderPatients(tete, chemin);
                printf("Sauvegarde terminee dans %s\n", chemin);
                break;

            case 7:
                tete = recupererListePatients(tete, chemin);
                printf("Recuperation terminee depuis %s\n", chemin);
                break;

            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    }
    while(choix != 0);

    return 0;
}
