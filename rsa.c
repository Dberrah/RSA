#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"

void rsa() //GENERATION DES CLES
{
    int p, q, pgcd1 = 0, e = 0, space = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nGeneration des cles.\n\n");
    printf("Entrez un nombre premier p : ");
    scanf("%d",&p);
    printf("Entrez un nombre premier q : ");
    scanf("%d",&q);
    int n = p*q;
    printf("\nn = %d", n);
    int phiden = (p-1)*(q-1); //Demontrer Phiden dans le rapport
    printf("\n\nphi de n = %d", phiden);
    while(pgcd1 != 1)
    {
        if((p<e)&&(q<e)&&(e<phiden))
        {
            pgcd1 = pgcd(e,phiden);
            if(pgcd1 != 1)
            {
                e++;
            }
        }
        else
        {
            e++;
        }
    }
    printf("\n\nCle publique (%d,%d)", e, n);
    int d = aee(e,phiden);
    printf("\n\nCle privee (%d,%d)", (d+phiden)%phiden, n);
    printf("\n\nN'oubliez pas vos cles pour pouvoir chiffrer vos messages !\n");
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

void chiffre() //CHIFFREMENT
{
    int e, n, i, y, ascii, crypt;
    char msg[100];
    system("cls");
    //system("clear");
    int space = 0;
    printf("--- Chiffrement RSA ---\n\nChiffrement d'un message.\n\n");
    printf("Entrez votre cle publique (e, n)\n");
    printf("e = ");
    scanf("%d", &e);
    printf("n = ");
    scanf("%d", &n);
    printf("\nEntrez un message a chiffrer\n");
    printf("message a chiffrer = ");
    scanf("%s", msg);
    int taille = strlen(msg);
    printf("\nmot chiffre = |");
    for(i=0;i<taille;i++)
    {
        ascii =(int) msg[i];
        crypt = 1;
        for(y=0;y<e;y++)
        {
            crypt = (crypt*ascii)%n;
        }
        printf("%d|", crypt);
    }
    printf("\n\nN'oubliez pas d'enregistrer votre message chiffre !\n");
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

void dechiffre() //DECHIFFREMENT
{
    int d, n, y, ascii, taille, cpt, crypt;
    int msg;
    system("cls");
    //system("clear");
    int space = 0;
    printf("--- Chiffrement RSA ---\n\nDechiffrement d'un message.\n\n");
    printf("Entrez votre cle privee (d, n)\n");
    printf("d = ");
    scanf("%d", &d);
    printf("n = ");
    scanf("%d", &n);
    printf("Entre la taille du message a dechiffre (nombre de lettres) ");
    scanf("%d", &taille);
    printf("\nEntrez un message a dechiffrer (lettre chiffre par lettre chiffre)\n");
    for(cpt=0;cpt<taille;cpt++)
    {
        printf("lettre a dechiffrer = ");
        scanf("%d", &msg);
        ascii = msg;
        crypt = 1;
        for(y=0;y<d;y++)
        {
            crypt = (crypt*ascii)%n;
        }
        char decrypt =(char) crypt;
        printf("lettre dechiffre = %c\n", decrypt);
    }
    printf("\n\n");
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}


int pgcd(int a, int b) //PGCD
{
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}

int aee(int a, int b) //ALGO EUCLIDE ETENDU
{
    int r1=a, r2=b, u1=1, u2=0, v1=0, v2=1, q, rs ,us, vs;

    while(r2!=0)
    {
        q=r1/r2;
        rs=r1;
        us=u1;
        vs=v1;
        r1=r2;
        u1=u2;
        v1=v2;
        r2=rs-(q*r2);
        u2=us-(q*u2);
        v2=vs-(q*v2);
    }
    return u1;
}
