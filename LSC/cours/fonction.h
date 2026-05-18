#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct cellule cellule ;

struct cellule
{
    int val;
    cellule* suiv;
};

typedef cellule* liste;

liste AjoutDebut(liste l , int val);
liste ajoutFin(liste l , int val) ;
liste supprimerDebut(liste l );
liste supprimerFin(liste l );
void afficherListe(liste l);
#endif // FONCTION_H_INCLUDED
