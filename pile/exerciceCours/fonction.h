#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct cellule cellule ;
struct cellule
{
    char ch;
    cellule* suiv;
};
typedef cellule* pile;

pile Empiler(pile p , char car);
pile depiler(pile p);
int bien_paranthesee( char *expr);


#endif // FONCTION_H_INCLUDED
