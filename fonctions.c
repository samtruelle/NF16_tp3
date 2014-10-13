#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_ludotheque* creer_ludotheque(){
    t_ludotheque* ludo;
    ludo = malloc(sizeof(t_ludotheque));
    ludo->nb_entier = 0;
    ludo->debut = NULL;

    return ludo;
}

t_jeu* creer_jeu(char * nom, int nbJoueurMin, int nbJoueurMax, int duree,genre_jeu genre){
        t_jeu * jeu;
        jeu = malloc(sizeof(t_jeu));
        jeu->nom = nom;
        jeu->nbJoueurMin = nbJoueurMin;
        jeu->nbJoueurMax = nbJoueurMax;
        jeu->duree = duree;
        jeu->genre = genre;
        jeu->suivant = NULL;

        return jeu;
}


int ajouter_jeu(t_ludotheque * ludo,t_jeu * j){}

void afficher_ludotheque(t_ludotheque* ludo){}

int retirer_jeu(t_ludotheque* ludo, char* nom){}

void supprimer_ludotheque(t_ludotheque* ludo){}

t_ludotheque* requete_jeu(t_ludotheque* ludo, genre_jeu genre, int nbJoueurs, int duree){}

t_ludotheque* fusion(t_ludotheque* ludo1, t_ludotheque* ludo2){}
