#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string.h>

typedef enum genre{PLATEAU, RPG, COOPERATIF, AMBIANCE, HASARD} genre_jeu;

struct jeu{
    char* nom;
    genre_jeu genre;
    int nbJoueurMin;
    int nbJoueurMax;
    int duree;
    struct jeu* suivant;
};

typedef struct jeu t_jeu;

struct ludotheque{
    int nb_entier;
    t_jeu* debut;
};

typedef struct ludotheque t_ludotheque;


#endif
