#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct cellule cellule;

typedef struct
{
    char nom[50];
    char prenom[50];
    int rdv;
}Patient;

struct cellule
{
    Patient p;
    cellule* suiv;
};

typedef cellule* liste;

void saisirPatient(Patient *p);
void afficherPatient(Patient p);
liste AjoutPatient(liste tete, Patient p);
void RendezVous(liste tete, int *rdv, int *sansRdv);
liste SupprimePatient(liste tete);
void ConsulterSalleAttente(liste tete);
void sauvegarderPatients(liste tete, char *chemin);
liste recupererListePatients(liste tete, char *chemin);

#endif // FONCTION_H_INCLUDED
