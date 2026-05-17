#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nom[50];
    char prenom[50];
    int age;
}Personne;
int main()
{
    Personne *tabP;
    int n ;
    printf("donner n: ");
    scanf("%d" , &n);
    tabP = malloc(n * sizeof(Personne));
    for(int i = 0 ; i < n ; i++)
    {
        printf("nom: ");
        scanf("%s" , tabP[i].nom);
        printf("prenom: ");
        scanf("%s" , tabP[i].prenom);
        printf("age: ");
        scanf("%d" , &tabP[i].age);
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("nom = %s\t" , tabP[i].nom);
        printf("prenom = %s\t" , tabP[i].prenom);
        printf("age = %d\n" , tabP[i].age);
    }


    int m;
    printf("donner m: ");
    scanf("%d" , &m);
    tabP = realloc(tabP , (n+m) * sizeof(Personne));
    for(int i = n ; i < n+m ; i++)
    {
        printf("nom: ");
        scanf("%s" , tabP[i].nom);
        printf("prenom: ");
        scanf("%s" , tabP[i].prenom);
        printf("age: ");
        scanf("%d" , &tabP[i].age);
    }
    for(int i = 0 ; i < (n+m) ; i++)
    {
        printf("nom = %s\t" , tabP[i].nom);
        printf("prenom = %s\t" , tabP[i].prenom);
        printf("age = %d\n" , tabP[i].age);
    }

    return 0;
}
