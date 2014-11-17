#ifndef FONCTIONS_H
#define FOCNTIONS_H

#include "structures.h"

t_ludotheque* creer_ludotheque();

t_jeu* creer_jeu(char * nom, int nbJoueurMin, int nbJoueurMax, int duree,genre_jeu genre);

int ajouter_jeu(t_ludotheque * ludo,t_jeu * j);

void afficher_ludotheque(t_ludotheque* ludo);

int retirer_jeu(t_ludotheque* ludo, char* nom);

void supprimer_ludotheque(t_ludotheque* ludo);

t_ludotheque* requete_jeu(t_ludotheque* ludo, genre_jeu genre, int nbJoueurs, int duree);

t_ludotheque* fusion(t_ludotheque* ludo1, t_ludotheque* ludo2);

//char *concat(const char *s1, const char *s2);

//void afficher_tab(char ** tab,int li);



#endif
