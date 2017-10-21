#include "chaine.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

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
  chaine c = (chaine)malloc(sizeof(struct chaine));
  c->taille = 0;
  c->tab = NULL;
  return c;
}

chaine chaine_creer_char(char* c)
{
  chaine ch = (chaine)malloc(sizeof(struct chaine));
  ch->taille = strlen(&c);
  ch->tab = c;
  return ch;
}

void chaine_detruire(chaine* ch)
{
  ch->tab = NULL;
  ch->taille = 0;
  free((*ch)->tab);
  free(ch);
}

void chaine_afficher(FILE* f, chaine ch)
{
  fprintf(f, "%s\n", ch->tab);
}

unsigned int chaine_extraire_taille(chaine ch)
{
  unsigned int taille = ch->taille;
  return taille;
}


bool chaine_est_vide(chaine ch)
{
  if (ch->tab == NULL && ch->taille == 0){
    return true;
  }
  else {
    return false;
  }
}

bool chaine_est_egal(chaine ch1, chaine ch2)
{
  if (ch1->taille == ch2->taille && ch1->tab == ch2->tab){
    return true;
  }
  else {
    return false;
  }
}

void chaine_concatener(chaine ch1, chaine ch2)
{
  unsigned int i;
  char* concat = malloc(sizeof(ch1->tab));
  for(i=0; i < ch1->taille ; i++){
    concat[i] = ch1->tab[i];
  }
  
  free(ch1->tab);
  ch1->tab = (char*)malloc((ch1->taille + ch2->taille) * sizeof(char));

  for(i = 0; i < ch1->taille ; i++){
    ch1->tab[i] =  concat[i];
  }
  for(i = 0; i < ch1->taille ; i++){
    ch1->tab[i] =  ch2->tab[i];
  }
  
  free(concat);
}

char chaine_extraire_char_i(chaine ch, const unsigned int i)
{
  char c [1] = "";
  if(ch->taille >= i){
    c[0] = ch->tab[i];
    return c[0];
  }
  return c[0];
}

void chaine_modifier_char_i(chaine ch, const unsigned int i, const char c)
{
  unsigned int j;
  char* modif = (char*)malloc(sizeof(char)*ch->taille);
  if(ch->taille >= i){
    for(j=0; j <= ch->taille; j++){
      if (j == i){
        modif[j] = c;
      } else {
        modif[j] = ch->tab[j];
      }
    }
    ch->tab = modif;
    free(modif);
  }
}

chaine chaine_copier(chaine ch1)
{
  chaine ch2 = (chaine)malloc(sizeof(struct chaine));
  char* copie = ch1->tab;
  ch2->taille = ch1->taille;
  ch2->tab = copie;
  return ch2;
}

void chaine_en_minuscules(chaine ch)
{
  int i;
  for(i=0; ch->tab[i] != '\0'; i++){
    ch->tab[i] = tolower(ch->tab[i]);
  }
}

void chaine_en_majuscules(chaine ch)
{
  int i;
  for(i=0; ch->tab[i] != '\0'; i++){
    ch->tab[i] = toupper(ch->tab[i]);
  }
}

bool chaine_appartenir(const char c, chaine ch, int* i)
{
  unsigned int j, k = *i;
  for(j = 0; j <= k; j++){
    if (ch->tab[j] == c){
      return true;
    }
  }
  return false;
}

chaine chaine_lire(FILE* f, unsigned int taille)
{
  chaine ch = (chaine)malloc(sizeof(struct chaine));
  ch->taille = taille;
  fgets(ch->tab, taille, f);
  return ch;
}





