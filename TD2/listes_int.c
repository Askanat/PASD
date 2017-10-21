#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "listes_int.h"


/*! \file listes_int.c

 * \brief La documentation pour les parties (types, variables, fonctions…) internes du module sont documentées ici.
 *
 * \copyright PASD
 * \version 2017
 */

/*! Un maillon est un pointeur sur (référence vers) une struct maillon_struct . */
typedef struct maillon_struct * maillon;
/*!
 * Structure servant à définir un élément de type int de la liste.
 * Cette structure n'est visible que depuis listes_int.c .
 * Les fonctions attenantes sont static pour être également masquées. */

struct maillon_struct {
  int val;
  maillon precedent;
  maillon suivant;
};
/*!
 * Création d'un maillon dont la valeur est _val .
 * suivant et precedent doivent pointer sur ce maillon.
 * \param _val valeur à stocker dans le maillon.
 * \return nouveau maillon stockant _val et bouclant sur lui-même.
 */
static maillon maillon_creer(int const _val) {
  maillon m = malloc(sizeof(struct maillon_struct));
  m->val = _val;
  m->precedent = m;
  m->suivant = m;
  return m;
}
/*!
 * Test pour savoir si le maillon est unique (bouclant sur lui-même et correspondant à une liste de taille 1).
 * \param m maillon à tester.
 */
static bool maillon_est_unique(maillon const m) {
  if(m->precedent == m && m->suivant == m){
    return true;
  }
  return false;
}
/*! 
 * Destruction de toute la liste chaînée.
 * \param m (pointeur sur un) maillon de la liste chaînée à détruire.
*/
static void maillon_detruire(maillon * const m) {
	free((*m)->val);
  	free(*m);
}
/*! 
 * Affichage d'un ensemble de maillon à partir d'un début et d'une fin.
 * Le résultat est de la forme \verbatim[ 1 2 3 ]\endverbatim sans saut de ligne.
 * \param f flux où imprimer.
 * \param m_debut premier maillon à imprimer. 
 * \param m_fin dernier maillon à imprimer. 
 */
static void maillon_afficher(FILE * const f, maillon const m_debut,maillon const m_fin) {
  maillon m = maillon_creer(0);
  m = m_debut;
  //  fprintf(f, "[%d]" , m_debut->val);
  // fprintf(f, "[%d]" , m_fin->val);
  while(m != m_fin){
    fprintf(f, "[%d]", m->val);
    m = m->suivant;
  }
   fprintf(f, "[%d]", m_fin->val);
}

/*!
 * Ajout d'un élément avant le maillon.
 * \param m maillon avant lequel on doit insérer.
 * \param _val valeur entière à insérer.
 */
static void maillon_ajouter_avant(maillon const m, int const _val) {
  maillon mc = maillon_creer(_val);
  mc->precedent = m->precedent;
  mc->suivant = m;
  m->precedent->suivant = mc;
  m->precedent = mc;
}

/*!
 * Ajout d'un élément après le maillon.
 * \param m maillon après lequel on doit insérer.
 * \param _val valeur entière à insérer.
 */
static void maillon_ajouter_apres(maillon const m, int const _val) {
  maillon mc = maillon_creer(_val);
  mc->precedent = m;
  mc->suivant = m->suivant;
  m->suivant->precedent = mc;
  m->suivant = mc;
}


/*! 
 * Suppression du maillon d'avant s'il existe (c.-à-d. si la liste correspondante ne contient qu'un maillon on ne fait rien).
 * \param m maillon avant lequel on doit supprimer.
 */
static void maillon_supprimer_avant(maillon const m) { //pas sur
  if(maillon_est_unique(m) == false){
    m->precedent->precedent->suivant = m;
    m->precedent= m->precedent->precedent;
    free(m->precedent);
  }
}


/*! suppression du maillon d'après s'il existe (c.-à-d. si la liste correspondante ne contient qu'un maillon on ne fait rien).
 * \param m maillon après lequel on doit supprimer.
*/
static void maillon_supprimer_apres(maillon const m) {
  if(maillon_est_unique(m) == false){
    m->suivant->suivant->precedent = m;
    m->suivant = m->suivant->suivant;
    free(m->suivant);
  }
}

/*! 
 * Structure pour la liste en étendant la structure maillon. 
 * Quand la liste est vide, il n'y a pas de liste circulaire (et les pointeurs concernés valent NULL). 
*/

struct liste_struct {
  unsigned int taille;
  maillon tete;
  maillon courant;
};


liste liste_creer(void) {
  liste l = malloc(sizeof(struct liste_struct));
  l->taille = 0;
  l->tete = NULL;
  l->courant = NULL;
  return l;
}

bool liste_est_vide(liste const l) {
  if(l->taille == 0 && l->tete == NULL && l->courant == NULL){
    return true;
  }
  else{
    return false;
  }
}

void liste_detruire(liste * const l) {
  free(*l);
}


/*!
 * Pour ajouter une valeur à une liste vide.
 * fonction facultative mais qui peut aider
 * \param l liste où ajouter.
 * \param val valeur entière à jouter.
 */
//static void liste_ajouter_a_vide(liste const l, int const val) {}


/*! 
 * Pour enlever la dernière valeur. 
 * fonction facultative mais qui peut aider
 * \param l liste où enlever
 */
//static void liste_enlever_dernier(liste const l) {}

void liste_insertion_debut(liste const l, int const val) {
  maillon mc = maillon_creer(val);
  if(liste_est_vide(l)){
    l->tete = mc;
  }
  else{
    maillon_ajouter_avant(l->tete, val);
    l->tete = l->tete->precedent;
  }
}


void liste_insertion_fin(liste const l, int const val) {
  maillon mc = maillon_creer(val);
  if(liste_est_vide(l)){
    l->tete = mc;
  }
  else{
    maillon_ajouter_avant(l->tete, val);
  }
}


void liste_insertion_apres(liste const l, int const val) {
  maillon_ajouter_apres(l->courant, val);
}


void liste_insertion_avant(liste const l, int const val) {
  if(l->tete == l->courant){
    maillon_ajouter_avant(l->courant, val);
    l->tete = l->tete->precedent;
  }
}


void liste_suppression_debut(liste const l) {
  if(liste_est_vide(l) == false){
    l->tete = l->tete->suivant;
    maillon_supprimer_avant(l->tete);
  }
}


void liste_suppression_fin(liste const l) { 
  if(liste_est_vide(l) == false){
    maillon_supprimer_avant(l->tete);
  }
}


void liste_suppression_avant(liste const l) {
  if(liste_est_vide(l) == false){
    if(maillon_est_unique(l->courant) == false ){
      if(l->tete == l->courant->precedent){
	l->tete = l->tete->suivant;
      }
      maillon_supprimer_avant(l->courant);
    }
  }
}


void liste_suppression_apres(liste const l) { // manque un truc
  if(liste_est_vide(l) == false){
    if (maillon_est_unique(l->courant) == false){
      if(l->tete == l->courant->suivant){
	l->tete = l->tete->suivant;
      }
      maillon_supprimer_apres(l->courant);
    }
  }
}


void liste_affichage(FILE * const f, liste const l) {
  
    maillon_afficher(f, l->tete, l->tete->precedent);
}

void liste_courant_init(liste const l) {
  l->courant = l->tete;
}


void liste_courant_suivant(liste const l) {
  l->courant = l->courant->suivant;
}


void liste_decalage(liste const l, int n) {
  if(n > 0){
    while(n != 0){
      l->courant = l->courant->suivant;
      n++;
    }
  }
  else{
    while (n != 0){
      l->courant = l->courant->precedent;
      n--;
    }
  }
}


int liste_taille(liste const l) {
  return l->taille;
}


int liste_valeur_tete(liste const l) {
  return l->tete->val;
}


int liste_valeur_courant(liste const l) {
  return l->courant->val;
}


bool liste_est_tete(liste const l) {
  if( l->courant == l->tete){
    return true;
  }
  else{
    return false;
  }
}


bool liste_est_fin (liste const l) {
  if( l->courant->suivant == l->tete){
    return true;
  }
  else{
    return false;
  }
}
