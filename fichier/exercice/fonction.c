#include "fonction.h"

void saisir_gateau(gateau *g)
{
    printf("Donner le type du gateau : ");
    scanf("%d", &g->type);

    printf("Donner le nombre d'ingredients : ");
    scanf("%d", &g->nbr_ing);

    printf("Donner le prix du gateau : ");
    scanf("%f", &g->prix);
}
void ajouter_gateau_ft(gateau g, char nom_fich[])
{
    FILE *fichier ;
    fichier = fopen(nom_fich , "a");
    if(fichier != NULL)
    {
        fprintf(fichier , "%d %d %f\n" , g.nbr_ing , g.type , g.prix);
    }
    else
    {
        printf("probleme d'ouverture");
    }
}
int nbre_gateaux_ft(char nom_fich[])
{
    int nbr = 0 ;
    gateau g;
    FILE *fichier ;
    fichier = fopen(nom_fich , "r");
    if(fichier != NULL)
    {
        while(fscanf(fichier , "%d %d %f\n" , &g.nbr_ing , &g.type , &g.prix) != EOF)
        {
            nbr++;
        }
    }
    else
    {
        printf("probleme d'ouverture");
    }
    return nbr ;
}
void afficher_gateau(char nom_fich[], int num)
{
    int nbr = 1;
    gateau g;
    FILE *fichier ;
    fichier = fopen(nom_fich , "r");
    if(fichier != NULL)
    {
        while(fscanf(fichier , "%d %d %f\n" , &g.nbr_ing , &g.type , &g.prix) != EOF && nbr != num)
        {
            nbr++;
        }
        if(nbr == num)
        {
            printf("gateaux: %d %d %f\n" , g.nbr_ing , g.type , g.prix);
        }
        else
        {
            printf("gateaux non disponible!!\n");
        }
    }
    else
    {
        printf("probleme d'ouverture");
    }
}
