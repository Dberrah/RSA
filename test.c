#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "test.h"

void fermat()
{
    int space = 0, x = 0, a = 1, b = 1, c = 1, d = 1, i = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nTest de primalite Fermat\n\n");
    printf("Entrez un nombre x a tester : ");
    scanf("%d",&x);
    for(i=0;i<x-1;i++)
    {
        a = (a*2)%x;
        b = (b*3)%x;
        c = (c*5)%x;
        d = (d*7)%x;
    }
    if ((1==a)&&(1==b)&&(1==c)&&(1==d))
    {
        printf("1=2^x-1=3^x-1=5^x-1=7^x-1 [mod x] est vrai \n\nDonc x = %d est un nombre probablement premier.\n\n",x);
    }
    else
    {
        printf("1=2^x-1=3^x-1=5^x-1=7^x-1 [mod x] est faux \n\nDonc x = %d n'est pas un nombre premier.\n\n",x);
    }
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

void solovay()
{
    int space = 0, i = 0, y = 0, a = 0, an = 1, anmod = 1, n = 0, k = 0, tableau[50], e = 0, x = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nTest de primalite Solovay-Strassen\n\n");
    printf("Entrez un nombre n a tester : ");
    scanf("%d",&n);
    printf("Entrez un nombre k corresepondant au nombre de fois que le test va etre lance : ");
    scanf("%d",&k);
    srand(time(NULL));
    for (i=0;i<50;i++)
    {
        tableau[i] = 0;
    }
    decompose(n, tableau);
    for(y=0;y<k;y++)
    {
        a = 0;
        an = 1;
        anmod = 1;
        while ((a==0)||(a==1))
        {
            a =(rand())%n;
        }
        for(i=0;i<50;i++)
        {
            if (tableau[i]!=0)
            {
                an = an*symbole(a,tableau[i]);
            }
        }
        for(i=0;i<((n-1)/2);i++)
        {
            anmod = (anmod*a)%n;
        }
        x = an+n;
        if ((x==0)||(x%n!=anmod))
        {
            e = 1;
        }
    }
    if (e == 1)
    {
        printf("\nn = %d n'est pas premier.\n", n);
    }
    if (e == 0)
    {
        printf("\nn = %d est probablement premier si k est assez grand.\n", n);
    }
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

void miller()
{
    int space = 0, a = 0, s = 0, d = 0, n = 1, k = 0, e = 0, i = 0;
    system("cls");
    //system("clear");
    printf("--- Chiffrement RSA ---\n\nTest de primalite Miller-Rabin\n\n");
    printf("n est un nombre a tester tel que n = (2^s)*d+1 \n");
    printf("Entrez un nombre s : ");
    scanf("%d",&s);
    printf("Entrez un nombre d : ");
    scanf("%d",&d);
    for(i=0;i<s;i++)
    {
        n = n*2;
    }
    n = n*d+1;
    printf("(2^s)*d+1 = %d\n", n);
    printf("Entrez un nombre k corresepondant au nombre de fois que le test va etre lance : ");
    scanf("%d",&k);
    srand(time(NULL));
    for(i=0;i<k;i++)
    {
        a = 0;
        while ((a==0)||(a==1))
        {
            a = (rand())%(n-1);
        }
        if (temoinmiller(a,s,d))
        {
            e = 1;
        }
    }
    if (e == 1)
    {
        printf("\nn = %d n'est pas premier.\n", n);
    }
    if (e == 0)
    {
        printf("\nn = %d est probablement premier si k est assez grand.\n", n);
    }
    do
    {
        printf("Entrez le nombre 1 pour revenir au menu. ");
        scanf("%d", &space);
    }while(space!=1);
}

int symbole(int n, int p)
{
	if(n%p==0) {
		return 0;
	}
	if((n%p)!=0) {
		if (residu(p,n)==1) {
			return 1;
		}
	}
	return -1;
}

int residu(int p, int n)
{
	int i;
	for(i=0;i<(p*p);i++) {
		if(((i*i)%p)==n) {
			return 1;
		}
	}
	return 0;
}

void decompose(int n, int *tableau)
{
    int k = 2, y = 0;
    while (n!=1)
    {
        k = 2;
        while (n%k!=0)
        {
            k++;
        }
        n = n/k;
        tableau[y] = k;
        y++;
    }
}

int temoinmiller(int a, int s, int d)
{
    int n = 1, i = 0, x = 1;
    for(i=0;i<s;i++)
    {
        n = n*2;
    }
    n = n*d+1;
    for(i=0;i<d;i++)
    {
        x = x*a%n;
    }
    x = x+n%n;
    if ((x==1)||(x==(n-1)))
    {
        return(0);
    }
    while (s>1)
    {
        x = x*x%n;
        x = x+n%n;
        if (x==(n-1))
        {
            return(0);
        }
        s--;
    }
    return(1);
}

