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
    Etudiant e; e.id=10 ; strcpy(e.nom , "manoubi") ; e.age = 20;
    //txt
    //1-OUVERTURE du Fichier
    FILE *fichier ; //variable de manipulation
    fichier = fopen("etudiant.txt" , "a");

    //2-ECRITURE du fichier TXT
    fprintf(fichier , "%d %s %d" , e.id , e.nom , e.age);
    //3-fermuture du fichier
    fclose(fichier) ;


    //bin
    fichier = fopen("etudiant.bin" , "wb");
    //2-ECRITURE du fichier bin
    fwrite(&e , sizeof(Etudiant) , 1 , fichier);
    //3-fermuture di fichier
    fclose(fichier) ;
    return 0;
}
