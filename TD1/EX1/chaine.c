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
	chaine ch;
	ch.taille = 0;
	ch.tab = NULL;
}

chaine chaine_creer_char(char* c)
{
	chaine ch;
	ch.taille = length(c);
	ch.tab = c;
	return chaine;
}

void chaine_detruire(chaine* ch)
{
	free(ch.taille);
	free(ch.tab);
	free(ch);
}

void chaine_afficher(FILE* f, chaine ch)
{
	fopen(f,"w");
	fputs(ch, f);
}

unsigned int chaine_extraire_taille(chaine ch)
{
	int taille = length(ch);
	return ch;
}


bool chaine_est_vide(chaine ch)
{
	if( 0 == length(ch)){
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
	strcat(ch1, ch2);
	return ch1;
}

char chaine_extraire_char_i(chaine ch, const unsigned int i)
{
	int j;
	if(length(ch.tab) >= i){
		for(j = 0; j<= i; j++){
			if (j == i){
				char c = ch.tab[i];
			}
		}
		return c;
	} else {
		exit(1);
	}
}

void chaine_modifier_char_i(chaine ch, const unsigned int i, const char c)
{
	int j;
	if(length(ch.tab) >= i){
		for(j = 0; j<= i; j++){
			if (j == i){
				ch.tab[i] = c;
			}
		}
	}
}

chaine chaine_copier(chaine ch1)
{
	chaine ch2;
	ch2.taille = ch1.taille;
	ch2.tab = ch1.tab;

	return ch2;
}

void chaine_en_minuscules(chaine ch)
{
	ch = tolower(ch);
	return ch;
}

void chaine_en_majuscules(chaine ch)
{
	ch = toupper(ch);
	return ch;
}

bool chaine_appartenir(const char c, chaine ch, int* i)
{
	int j;
	for(j = 0; j <= i; j++){
		if (ch.tab[j] == c){
			return 1;
		} else {
			return 0;
		}
	}
}

chaine chaine_lire(FILE* f, unsigned int taille)
{
	fopen(f,"r");
	char* ch;
	fgets(ch, taille, f);
	return ch;
}





