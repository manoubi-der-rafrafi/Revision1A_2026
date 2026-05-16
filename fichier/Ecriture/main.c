#include <stdio.h>
#include <stdlib.h>

/*
    Projet : Ecriture
    Objectif :
    - creer une structure Etudiant ;
    - enregistrer ses donnees dans un fichier texte ;
    - enregistrer la meme structure dans un fichier binaire.


*/

typedef struct
{
    int id ;
    char nom[40];
    int age;
}Etudiant;


int main()
{
    // Initialisation d'un etudiant qui sera ecrit dans les deux fichiers.
    Etudiant e; e.id=10 ; strcpy(e.nom , "manoubi") ; e.age = 20;

    /***************** Ecriture dans un fichier texte *****************/
    // 1. Ouvrir le fichier texte en mode ajout.
    FILE *fichier ; // variable de manipulation du fichier
    fichier = fopen("etudiant.txt" , "a");

    // 2. Ecrire les informations de l'etudiant sous forme texte.
    fprintf(fichier , "%d %s %d" , e.id , e.nom , e.age);

    // 3. Fermer le fichier apres l'ecriture.
    fclose(fichier) ;


    /***************** Ecriture dans un fichier binaire *****************/
    // 1. Ouvrir le fichier binaire en mode ecriture.
    fichier = fopen("etudiant.bin" , "wb");

    // 2. Ecrire toute la structure Etudiant dans le fichier.
    fwrite(&e , sizeof(Etudiant) , 1 , fichier);

    // 3. Fermer le fichier binaire.
    fclose(fichier) ;

    return 0;
}
