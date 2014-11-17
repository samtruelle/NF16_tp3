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

/*int tri_alpha(char * str1, char * str2)
	{
		int i; str1_len = size(str1); str2_len = size(str2); 
	}*/

int ajouter_jeu(t_ludotheque * ludo,t_jeu * j){
	t_jeu * iter;
	//t_jeu * tmp = malloc(sizeof(t_jeu));
    //memcpy(tmp, j, sizeof(t_jeu));
	iter = ludo->debut;

	if(ludo->debut == NULL){                    								//liste vide
		ludo->debut = j;
		//tmp->suivant = NULL;
		ludo->nb_entier++;
		return 1;
	}
	else if(strcmp(j->nom,iter->nom)<0) 																													//nom de j avant nom de l'élément, j placé avant
		{
			j->suivant = ludo->debut;
			ludo->debut = j;
			ludo->nb_entier++;
			return 1;
		}																		//liste de plusieurs éléments
	else {
		while (iter->suivant != NULL && strcmp(j->nom,iter->suivant->nom)>0)
		{
			/*if(){
				j->suivant = iter->suivant;
				iter->suivant = j;
				//free(iter);
				ludo->nb_entier++;
				//return 1;
				break;
			//}*/
			iter = iter->suivant;
		}
		if(iter->suivant == NULL){
			iter->suivant = j;
			j->suivant = NULL;
			ludo->nb_entier++;
			return 1;
		}
		else {
			j->suivant = iter->suivant;
			iter->suivant = j;
			ludo->nb_entier++;
			return 1;
		}
		return 0;
	}
	
}

void afficher_ludotheque(t_ludotheque* ludo){
	
	t_jeu * iter;
	iter = ludo->debut;

	if(iter == NULL){ printf("Liste vide"); return;}

	printf("|Nom    |Type      |Nombre de joueur|Durée moyenne |\n");
	/*if(iter->suivant == NULL){
		printf("|%s      |%d     |%d-%d    |%d'    |\n",iter->nom,iter->genre,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree);
	}
	else{
		while(iter->suivant != NULL){
			printf("|%s      |%d      |%d-%d    |%d'    |\n",iter->nom,iter->genre,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree);
			iter = iter->suivant;		
			}

			//printf("|%s      |%d     |%d-%d    |%d'    |\n",iter->suivant->nom,iter->suivant->genre,iter->suivant->nbJoueurMin,iter->suivant->nbJoueurMax,iter->suivant->duree);

		}
	printf("%d\n",ludo->nb_entier);*/

	int i;
	for(i=0;i<ludo->nb_entier;i++){
		printf("|%s      |%d      |%d-%d    |%d'    |\n",iter->nom,iter->genre,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree);
			iter = iter->suivant;	
	}

}
	/*char** affichage;
	int i;
	t_jeu * iter;

	affichage[0][0] = 'nom';
	affichage[0][1] = 'Type';
	affichage[0][2] = 'Nombre de joueur';
	affichage[0][3] = 'Durée moyenne';

	
	iter = malloc(sizeof(t_jeu));
	iter = ludo->debut;
	char * str_Min_player;
	char * str_Max_player;
	char * str_duree;
	char * str_nb_jeu;
	
	while (iter->suivant != NULL)
	{ 
	
		affichage[i][0] = iter->nom;
		affichage[i][1] = iter->genre;
		sprintf(str_Min_player,"%d",iter->nbJoueurMin);
		sprintf(str_Max_player,"%d",iter->nbJoueurMax);
		affichage[i][2] = concat(concat(str_Min_player,'-'),str_Max_player);
		sprintf(str_duree,"%d",iter->duree);
		affichage[i][3] = concat(str_duree,"\'");

		iter = iter->suivant;
		i++;
	}

	sprintf(str_nb_jeu,"%d",ludo->nb_entier);
	affichage[i+1][1] = str_nb_jeu;
}*/

int retirer_jeu(t_ludotheque* ludo, char* nom){
	t_jeu * current;
	t_jeu * prev; 
	t_jeu * tmp;

	prev = ludo->debut;
	current = ludo->debut->suivant;
	
	if(prev == NULL){														//liste vide
		return 0;
	}
	else if(current == NULL){   											//1 seul élément dans la liste
		if(strcmp(prev->nom,nom) == 0){										// nom match
			tmp = prev;
			free(tmp);
			return 1;
		}
		else {return 0;}													// nom match pas

	}
	else {
		while (current != NULL && prev != NULL && strcmp(current->nom, nom) != 0){
			//if(strcmp(current->nom, nom) == 0){
			//	t_jeu * tmp = prev;
			//	prev->suivant = current->suivant;
			//	free(tmp);
				//break;
			//	return 1;
			//}
			prev = current;
			current = current->suivant;
			//prev = prev->suivant;
		}

		if(prev->suivant->nom == nom){
			tmp = current;
			prev->suivant = tmp->suivant;
			ludo->nb_entier--;
			free(tmp);
			return 1;
		}
		else{
			return 0;		
		}
	}
}
	
void supprimer_ludotheque(t_ludotheque* ludo){

   t_jeu* tmp;

   while (ludo->debut != NULL)
    {
       tmp = ludo->debut;
       ludo->debut = ludo->debut->suivant;
       free(tmp);
    }

    ludo->debut = NULL;
}

t_ludotheque* requete_jeu(t_ludotheque* ludo, genre_jeu genre, int nbJoueurs, int duree){
	t_ludotheque* echantillon = creer_ludotheque();
	t_jeu * iter = ludo->debut;

	while(iter){

		if(genre == -1){
			if (duree == -1){
				if(nbJoueurs == -1){
			 		return echantillon;
				}
				else{
					if(nbJoueurs <= iter->nbJoueurMax && nbJoueurs >= iter->nbJoueurMin){
						ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));
					}
				}
			}
			else{
				if(nbJoueurs == -1 && duree < 1.1*iter->duree && duree > 0.9*iter->duree){
					ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));
				}
				else{
					if(duree < 1.1*iter->duree && duree < 0.9*iter->duree && nbJoueurs <= iter->nbJoueurMax && nbJoueurs >= iter->nbJoueurMin){
						ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));
					}
				}
			}
		}
		else{
			if (duree == -1)
			{
				if(nbJoueurs == -1 && genre == iter->genre){
					ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));				
				}
				else{
					if(genre == iter->genre && nbJoueurs <= iter->nbJoueurMax && nbJoueurs >= iter->nbJoueurMin){
						ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));
					}
				}	
			}
			else{
				if(nbJoueurs == -1 && genre == iter->genre && duree < 1.1*iter->duree && duree > 0.9*iter->duree){
					ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));
				}
				else{
					if(genre == iter->genre && duree < 1.1*iter->duree && duree > 0.9*iter->duree && nbJoueurs <= iter->nbJoueurMax && nbJoueurs >= iter->nbJoueurMin){
						ajouter_jeu(echantillon,creer_jeu(iter->nom,iter->nbJoueurMin,iter->nbJoueurMax,iter->duree,iter->genre));
					}
				}
			}
		}

		iter = iter->suivant;
	}
	return echantillon;

}

t_ludotheque* fusion(t_ludotheque* ludo1, t_ludotheque* ludo2){
    t_ludotheque* liste_fusion = creer_ludotheque();
    t_jeu* iter1 = ludo1->debut, *iter2 = ludo2->debut;
    int i;
    //t_jeu * jeu, *tmp=ludo1->debut;
    //t_ludotheque** tail = &liste_fusion;
    //t_jeu* tail = &liste_fusion

   while (iter1 && iter2){
        if (strcmp(iter1->nom,iter2->nom) < 0) {
            //*tail = ludo1;
            ajouter_jeu(liste_fusion,creer_jeu(iter1->nom,iter1->nbJoueurMin,iter1->nbJoueurMax,iter1->duree,iter1->genre));
            iter1 = iter1->suivant;
        } else /*if(strcmp(iter1->nom,iter2->nom) > 0*/{
            ajouter_jeu(liste_fusion,creer_jeu(iter2->nom,iter2->nbJoueurMin,iter2->nbJoueurMax,iter1->duree,iter2->genre));
            iter2 = iter2->suivant;
        }

        //tail = &((*tail)->suivant);
    }

   while(iter1){
   		ajouter_jeu(liste_fusion,creer_jeu(iter1->nom,iter1->nbJoueurMin,iter1->nbJoueurMax,iter1->duree,iter1->genre));
        iter1 = iter1->suivant;	
   }

   while(iter2){
   		ajouter_jeu(liste_fusion,creer_jeu(iter2->nom,iter2->nbJoueurMin,iter2->nbJoueurMax,iter2->duree,iter2->genre));
            iter2 = iter2->suivant;
   }

    //iter1 = iter1 ? iter1->suivant : iter2->suivant;
    return liste_fusion;

    /*for(i=0;i<ludo1->nb_entier + ludo2->nb_entier;i++){
		if (strcmp(iter1->nom,iter2->nom) < 0) {
            //*tail = ludo1;
            ajouter_jeu(liste_fusion,creer_jeu(iter1->nom,iter1->nbJoueurMin,iter1->nbJoueurMax,iter1->genre,iter1->duree));
            if(iter1->suivant == NULL){ 		
    			iter2 = iter2->suivant;
    		}
    		else {
    			iter1 = iter1 ->suivant;
    		}

        } else if(strcmp(iter1->nom,iter2->nom) > 0{
            ajouter_jeu(liste_fusion,creer_jeu(iter2->nom,iter2->nbJoueurMin,iter2->nbJoueurMax,iter2->genre,iter2->duree));         
       		if(iter2->suivant == NULL){
    			iter1 = iter1->suivant;
    		}
    		else {
    			iter2 = iter2->suivant;
        	}
        }
    }
    return liste_fusion;*/
}
/*
char *concat(const char *s1, const char *s2) {
    char *res = malloc(strlen(s1) + strlen(s2) + 1);
    if (res) {
        strcpy(res, s1);
        strcat(res, s2);
    }
    return res;
}


void afficher_tab(char ** tab,int taille){
	int i,j;
 
    for (i = 0 ; i < taille ; i++)
    {
    	for(j = 0;j< 4;j++){
    		printf("%s\t", tab[i][j]);	
    	}
    	printf("\n");
    	j = 0;      
    }
}*/
