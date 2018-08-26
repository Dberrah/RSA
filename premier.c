#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "premier.h"

void pythagore()
{
    int k = 0, space = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nNombres Premiers de Pythagore.\n\n");
    printf("Entrez un nombre k tel que 4k+1 : ");
    scanf("%d",&k);
    printf("4*%d+1 = %d\n", k, 4*k+1);
    printf("4k+1 est un nombre de Pythagore possiblement Premier.\n");
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

void mersenne()
{
    int n = 0, space = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nNombres Premiers de Mersenne.\n\n");
    printf("Entrez un nombre n tel que (2^n)+1 : ");
    scanf("%d",&n);
    printf("(2^%d)+1 = %d\n", n, (int) pow(2,n)+1);
    printf("(2^n)+1 est un nombre de Mersenne possiblement Premier.\n");
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

void fermat2()
{
    int n = 0, space = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nNombres Premiers de Fermat.\n\n");
    printf("Entrez un nombre n tel que (2^(2^n))+1 : ");
    scanf("%d",&n);
    printf("(2^(2^%d))+1 = %d\n", n, (int) pow(2,pow(2,n))+1);
    printf("(2^(2^n))+1 est un nombre de Fermat possiblement Premier.\n");
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}


