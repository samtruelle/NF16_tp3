#include "fonctions.h"
#include "structures.h"
#include "fonctions.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    t_ludotheque* ludo1, *ludo2,*ludo3;
    t_jeu* jeu1;
    int choix = 0,genre_TMP, nbmin_tmp, nbmax_tmp, duree_tmp;
    char * nom_TMP;
    printf("\t\t\t\t TP3 NF16\n\nHenry Clement\nReymondet Samuel\n\n");
    while (choix != 6){
        choix = 0;
        while(choix!=1 && choix!=2 && choix !=3 && choix!=4 && choix !=5 && choix!=6){
            printf("\n 1 : Creer ludo \n 2 : Afficher ludo \n 3 : Ajouter un jeu dans ludo \n 4 : Recherche dans ludo \n 5 : Fusion \n 6 : Quitter \n \n");
            scanf("%d",&choix);
            switch(choix){
                case 1:{
                    printf("creation d'une ludotheque vide\nLudo 1, Ludo 2 ou Ludo 3 ? Attention, si une ludotheque existe deja et que vous voulez la recreer, celle-ci sera ecrasee. Tapez 4 pour annuler.\n");
                    int a=0;
                    while (a!=1 && a!=2 && a!=3 && a!=4)
                        scanf("%d",&a);
                    if (a==1)
                        ludo1 = creer_ludotheque();
                    if (a==2)
                        ludo2 = creer_ludotheque();
                    if (a==3)
                        ludo3 = creer_ludotheque();
                    if (a==4)
                        break;
                    printf("\n\n");
                    break;
                }

                case 2:{
                    printf("Affichage de ludotheque \nLudo1, Ludo2 ou Ludo3 ? Attention, vous devez avoir cree la ludotheque auparavant. Tapez 4 pour annuler.\n");
                    int a=0;
                    while (a!=1 && a!=2 && a!=3 && a!=4)
                        scanf("%d",&a);
                    if (a==1)
                        afficher_ludotheque(ludo1);
                    if (a==2)
                        afficher_ludotheque(ludo2);
                    if (a==3)
                        afficher_ludotheque(ludo3);
                    if (a==4)
                        break;

                    printf("\n\n");
                    break;
                }

                case 3:{
                    printf("\ncreation d'un jeu, saisissez ses caracteritiques\t");

                    nom_TMP=malloc(40*sizeof(char));
                    printf("Nom : \t");
                    scanf("%s",nom_TMP);
                    do{
                        printf("\nGenre : \n0 : plateau\n1 : RPG\n2 : cooperatif\n3 : ambiance\n4 : hasard\n");
                        scanf("%d",&genre_TMP);
                    }while(genre_TMP > 4 || genre_TMP < 0);
                    do{
                        printf("\nNombre de joueurs minimum : \t");
                        scanf("%d",&nbmin_tmp);
                    } while (nbmin_tmp < 0);
                    do{
                        printf("\nNombre de joueurs max :\t");
                        scanf("%d",&nbmax_tmp);
                    } while(nbmax_tmp<nbmin_tmp);
                    do{
                        printf("\nDuree moyenne d'une partie : \t");
                        scanf("%d",&duree_tmp);
                    } while(duree_tmp < 0);
                    jeu1 = creer_jeu(nom_TMP,nbmin_tmp,nbmax_tmp,duree_tmp,genre_TMP);
                    printf("Dans quelle ludotheque voulez-vous ajouter ce jeu ? 1,2,3 ? Attention, vous devez avoir creer la ludotheque auparavant. Tapez 4 pour annuler\n");
                    int a=0;
                    while (a!=1 && a!=2 && a!=3 && a!=4)
                        scanf("%d",&a);
                    if (a==1)
                        ajouter_jeu(ludo1,jeu1);
                    if (a==2)
                        ajouter_jeu(ludo2,jeu1);
                    if (a==3)
                        ajouter_jeu(ludo2,jeu1);
                    if (a==4)
                        break;
                    printf("\n\n");
                    break;
                }

                case 4:{
                    printf("\nRecherche d'un jeu : \n saisissez vos criteres (-1 si critere non voulu) : \n");
                    do{
                        printf("\nGenre : \n0 : plateau\n1 : RPG\n2 : cooperatif\n3 : ambiance\n4 : hasard\n");
                        scanf("%d",&genre_TMP);
                    }while(genre_TMP > 4 || genre_TMP < -1);
                    do{														//on utilise la variable nbmin pour le nombre de joueur effectif #alarache
                        printf("\nNombre de joueurs minimum : \t");
                        scanf("%d",&nbmin_tmp);
                    } while (nbmin_tmp < -1);

                    do{
                        printf("\nDuree moyenne d'une partie : \t");
                        scanf("%d",&duree_tmp);
                    } while(duree_tmp < -1);

                    printf("Dans quelle ludotheque voulez-vous ajouter ce jeu ? 1,2,3 ? Attention, vous devez avoir creer la ludotheque auparavant. Tapez 4 pour annuler\n");
                    int a=0;
                    while (a!=1 && a!=2 && a!=3 && a!=4)
                        scanf("%d",&a);
                    if (a==1)
                        afficher_ludotheque(requete_jeu(ludo1,genre_TMP,nbmin_tmp,duree_tmp));
                    if (a==2)
                        afficher_ludotheque(requete_jeu(ludo2,genre_TMP,nbmin_tmp,duree_tmp));
                    if (a==3)
                        afficher_ludotheque(requete_jeu(ludo3,genre_TMP,nbmin_tmp,duree_tmp));
                    if (a==4)
                        break;
                    printf("\n\n");
                    
                    break;
                }

                case 5:{
                    printf("\nQuelles sont les ludotheques que vous voulez fusionner ? Donnez leurs 2 numeros. Tapez 4 pour annuler.\nAttention les ludotheques doivent exister !!\n");
                    int a=0,b=0;
                    while (a!=1 && a!=2 && a!=3 && a!=4){
                        printf("Rentrez le Numero de la premiere ludotheque : ");
                        scanf("%d",&a);
                    }
                    while ((b==a) || (b!=1 && b!= 2 && b!=3 && b!=4)){
                        printf("\nRentrez le Numero de la seconde bibliotheque : ");
                        scanf("%d",&b);
                    }
                    if ((a==1 && b==2) || (a==2 && b==1)){
                        printf("Premiere ludotheque :\n");
                        afficher_ludotheque(ludo1);
                        printf("\nDeuxieme ludotheque :\n");
                        afficher_ludotheque(ludo2);
                        printf("\n\n Fusion des deux ludotheques : \n");
                        afficher_ludotheque(fusion(ludo1,ludo2));
                    }
                    if ((a==2 && b==3) || (a==3 && b==2)){
                        printf("Première ludotheque :\n");
                        afficher_ludotheque(ludo2);
                        printf("\nDeuxième ludotheque :\n");
                        afficher_ludotheque(ludo3);
                        afficher_ludotheque(fusion(ludo2,ludo3));
                    }
                    if ((a==1 && b==3) || (a==3 && b==1)){
                        printf("Première ludotheque :\n");
                        afficher_ludotheque(ludo1);
                        printf("\nDeuxième ludotheque :\n");
                        afficher_ludotheque(ludo3);
                        afficher_ludotheque(fusion(ludo1,ludo3));
                    }
                    if (a==4 || b==4)
                        break;
                    printf("\n\n");
                    break;
                }

                case 6:{
                    printf("Bye\n");
                    exit(0);
                }
            }
        }
    }
    free(jeu1);
	free(nom_TMP);
    supprimer_ludotheque(ludo1);
    supprimer_ludotheque(ludo2);
    supprimer_ludotheque(ludo3);
    return 0;
}

