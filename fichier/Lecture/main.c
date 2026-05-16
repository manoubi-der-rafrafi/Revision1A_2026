#include <stdio.h>
#include <stdlib.h>

/*
    Projet : Lecture
    Objectif :
    - lire les informations d'un etudiant depuis un fichier texte ;
    - effectuer ensuite une lecture en mode binaire ;
    - illustrer la suppression et le renommage d'un fichier.


*/

typedef struct
{
    int id ;
    char nom[40];
    int age;
}Etudiant;

int main()
{
    Etudiant e;

    /***************** Lecture du fichier texte *****************/
    // 1. Ouvrir le fichier texte contenant les donnees de l'etudiant.
    FILE *fichier;
    fichier = fopen("etudiant.txt" , "r");

    // 2. Lire les champs dans l'ordre : id, nom, age.
    fscanf(fichier , "%d %s %d" , &e.id , e.nom , &e.age);

    // 3. Afficher les informations recuperees depuis le fichier texte.
    printf("txt: %d %s %d\n" , e.id , e.nom , e.age);
    fclose(fichier) ;

    /***************** Lecture en mode binaire *****************/
    // 1. Ouvrir un fichier en mode binaire.
    // Dans le code actuel, le nom utilise est "etudiant.txt".
    fichier = fopen("etudiant.txt" , "rb");

    // 2. Lire directement une structure Etudiant avec fread.
    fread(&e , sizeof(Etudiant) , 1 , fichier);

    // 3. Afficher le contenu lu en mode binaire.
    printf("bin: %d %s %d" , e.id , e.nom , e.age);
    fclose(fichier) ;

    // Supprimer le fichier binaire, puis renommer le fichier texte.
    remove("etudiant.bin");
    rename("etudiant.txt" , "employe.txt");

    return 0;
}
