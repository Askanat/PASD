#include "chaine.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

/*!
 * \file chaine.c
 * \brief Les implémentations relatives à la manipulation des chaînes de caractères
 * \author PASD
 * \version 1.0
 * \date 2017
 *
 * La structure et toutes les fonctions de manipulation des chaines 
 *
 */

struct chaine {
  unsigned int taille;
  char* tab;
};

chaine chaine_creer_vide()
{
	chaine ch = (chaine)malloc(sizeof(struct chaine));
	ch->taille = 0;
	ch->tab = NULL;
	return ch;
}

chaine chaine_creer_char(char* c)
{
	chaine ch = (chaine)malloc(sizeof(struct chaine));
	ch->taille = strlen(c);
	ch->tab = c;
	return ch;
}

void chaine_detruire(chaine* ch)
{
	free(ch);
}

void chaine_afficher(FILE* f, chaine ch)
{
	fputs(ch->tab, f);
}

unsigned int chaine_extraire_taille(chaine ch)
{
	unsigned int taille = ch->taille;
	return taille;
}


bool chaine_est_vide(chaine ch)
{
	if( 0 == strlen(ch->tab)){
		return 1;
	} else {
		return 0;
	}
}

bool chaine_est_egal(chaine ch1, chaine ch2)
{
	if(ch1 == ch2){
		return 1;
	} else {
		return 0;
	}
}

void chaine_concatener(chaine ch1, chaine ch2)
{
	strcat(ch1->tab, ch2->tab);
	char concat = ch1->tab;
	return concat;
}

char chaine_extraire_char_i(chaine ch, const unsigned int i)
{
	unsigned int j;
	char c = "echec";
	if(strlen(ch->tab) != NULL){
		if(strlen(ch->tab) >= i){
			for(j = 0; j <= i; j++){
				if (j == i){
					c = ch->tab[i];
				}
			}
			return c;
		}
	} else {
		return c;
	}
}

void chaine_modifier_char_i(chaine ch, const unsigned int i, const char c)
{
	unsigned int j;
	if(strlen(ch->tab) != NULL){
		if(strlen(ch->tab) >= i){
			for(j = 0; j <= i; j++){
				if (j == i){
					ch->tab[i] = c;
				}
			}
		}
	}
}

chaine chaine_copier(chaine ch1)
{
	chaine ch2 = (chaine)malloc(sizeof(struct chaine));
	ch2->taille = ch1->taille;
	ch2->tab = ch1->tab;
	return ch2;
}

void chaine_en_minuscules(chaine ch)
{
	ch->tab = tolower(ch->tab);
	return ch;
}

void chaine_en_majuscules(chaine ch)
{
	ch->tab = toupper(ch->tab);
	return ch;
}

bool chaine_appartenir(const char c, chaine ch, int* i)
{
	unsigned int j, k = *i;
	for(j = 0; j <= k; j++){
		if (ch->tab[j] == c){
			return 1;
		} else {
			return 0;
		}
	}
}

chaine chaine_lire(FILE* f, unsigned int taille)
{
	chaine ch = (chaine)malloc(sizeof(struct chaine));
	ch->taille = taille;
	fgets(ch->tab, taille, f);
	return ch;
}





