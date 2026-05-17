#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *tab; //tableau dynamique
    int n;
    printf("donner n: ");
    scanf("%d" , &n);
    tab = malloc(n * sizeof(int));
    for(int i =0 ; i< n ; i++)
    {
        printf("donner int: ");
        scanf("%d" , &tab[i]);
    }

    for(int i =0 ; i< n ; i++)
    {
        printf("%d\n" , tab[i]);
    }
    //REALLOC
    n = n + 2;
    tab = realloc(tab ,n * sizeof(int) );
    for(int i = n -2 ; i < n ; i++)
    {
        printf("donner int: ");
        scanf("%d" , &tab[i]);
    }
    for(int i =0 ; i< n ; i++)
    {
        printf("%d\n" , tab[i]);
    }
    return 0;

}
