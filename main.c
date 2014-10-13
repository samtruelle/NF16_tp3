#include "fonctions.h"
#include "structures.h"
#include "fonctions.c"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    t_ludotheque ludo1;
    t_jeu jeu1;

    if (!(ludo1 = creer_ludotheque())){printf("shit happens");}
    if (!(jeu1 = creer_jeu("monopoly",2,8,60,1))){printf("shit happens");}

    return 0;
}
