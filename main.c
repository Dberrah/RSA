#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"
#include "test.h"
#include "attaques.h"
#include "premier.h"

//-------------------------- TO DO --------------------------

// - Ajoutez les tests de primalités avec chrono
// - Ajoutez les attaques sur RSA avec chrono

//-------------------------- TO DO --------------------------

int main()
{
    int menu = 0, menu1 = 0, menu2 = 0, menu3 = 0;

    while(menu!=4) //MENU
    {
        system("cls");
        //system("clear");
        printf("--- Chiffrement RSA ---\n\n");
        printf("1 : Tests de primalites\n");
        printf("2 : Nombres Premiers Particuliers\n");
        printf("3 : RSA\n");
        printf("4 : Quitter\n");
        printf("\nEntree = ");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            system("cls");
            //system("clear");
            printf("--- Chiffrement RSA ---\n\n");
            printf("1 : Test de Fermat\n");
            printf("2 : Test de Solovay-Strassen\n");
            printf("3 : Test de Miller-Rabin\n");
            printf("4 : Retour\n");
            printf("\nEntree = ");
            scanf("%d", &menu1);
            switch(menu1)
            {
            case 1: //
                fermat();
                break;

            case 2: //
                solovay();
                break;

            case 3: //
                miller();
                break;

            default:
                break;
            }
            break;

        case 2:
            system("cls");
            //system("clear");
            printf("--- Chiffrement RSA ---\n\n");
            printf("1 : Nombres Premiers de Pythagore\n");
            printf("2 : Nombres Premiers de Mersenne\n");
            printf("3 : Nombres Premiers de Fermat\n");
            printf("4 : Retour\n");
            printf("\nEntree = ");
            scanf("%d", &menu2);
            switch(menu2)
            {
            case 1: //
                pythagore();
                break;

            case 2: //
                mersenne();
                break;

            case 3: //
                fermat2();
                break;

            default:
                break;
            }
            break;
        case 3:
            system("cls");
            //system("clear");
            printf("--- Chiffrement RSA ---\n\n");
            printf("1 : Generer des cles\n");
            printf("2 : Chiffrer un message\n");
            printf("3 : Dechiffrer un message\n");
            printf("4 : Retour\n");
            printf("\nEntree = ");
            scanf("%d", &menu3);
            switch(menu3)
            {
            case 1: //GENEREATION DES CLES
                rsa();
                break;

            case 2: //CHIFFREMENT
                chiffre();
                break;

            case 3: //DECHIFFREMENT
                dechiffre();
                break;

            default:
                break;
            }
            break;
        }
    }
    printf("Merci de votre visite ! A bientot !");
    return 0;
}

