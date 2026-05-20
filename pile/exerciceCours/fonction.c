#include <stdio.h>
#include <stdlib.h>
#include"fonction.h"


pile Empiler(pile p , char car)
{
    cellule *nouv;
    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->ch = car;
    nouv->suiv = p;
    p = nouv;
    return p;
}
pile depiler(pile p)
{
    if(p!=NULL)
    {
        cellule* Q;
        Q = p;
        p = p->suiv;
        free(Q);
    }
    return p;
}
int bien_paranthesee( char *expr)
{
    pile p ;
    p=NULL ;
    for(int i = 0 ; i< strlen(expr) ; i++)
    {
        p = Empiler(p , expr[i]);
    }


    //DEPLI
    int nbrPF = 0 , nbrPO = 0;
    while(p != NULL)
    {
        if(p->ch == '(')
        {
            nbrPO++;
        }
        else if (p->ch == ')')
        {
            nbrPF++;
        }
        p = depiler(p);
    }
    if(nbrPF == nbrPO)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
