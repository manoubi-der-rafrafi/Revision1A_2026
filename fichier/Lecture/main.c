#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id ;
    char nom[40];
    int age;
}Etudiant;

int main()
{
    Etudiant e;
    /*****************TXT*****************/
    //1-ouverture
    FILE *fichier;
    fichier = fopen("etudiant.txt" , "r");
    //2-Lecture
    fscanf(fichier , "%d %s %d" , &e.id , e.nom , &e.age);
    //AFFICHAGE DES INFORMATIONS
    printf("txt: %d %s %d\n" , e.id , e.nom , e.age);
    fclose(fichier) ;

    /*****************bin*****************/
    //1-ouverture
    fichier = fopen("etudiant.txt" , "rb");
    //2-Lecture
    fread(&e , sizeof(Etudiant) , 1 , fichier);
    //AFFICHAGE DES INFORMATIONS
    printf("bin: %d %s %d" , e.id , e.nom , e.age);
    fclose(fichier) ;

    remove("etudiant.bin");
    rename("etudiant.txt" , "employe.txt");
    return 0;
}
