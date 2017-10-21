#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#undef NDEBUG

#include "arbres.h"

/*!
 * \file
 * \brief
 * Les implémentations des deux structures arbre (cf arbres.h) et noeud
 * cette dernière est cachée et permet de construire effectivement l'arbre binaire
 * les fonctions associées à noeud sont donc "static"
 * \copyright PASD
 * \version 2017 
 */

typedef struct noeud_struct* noeud ;

struct noeud_struct {
  void* val;
  noeud f_g;
  noeud f_d;
}; 


struct arbre_struct {
  noeud racine;
  void(*copier)(void *val, void** pt);
  void(*detruire)(void** pt);
  int(*comparer)(void *val1, void *val2);
}; 


/*!
 * Création d'un noeud
 * \param val la valeur affectée à ce noeud à partir d'une copie
 * \param copier fonction pour copier les valeurs au sein d'un noeud
 * \return un noeud feuille initialisé à val
 */
static noeud noeud_creer(void* val, void(*copier)(void *val, void** pt))
{
  if (val == NULL){
    noeud n = (noeud)malloc(sizeof(struct noeud_struct));
    n->val = &val;
    n->f_g = n;
    n->f_d = n;
    copier(val,n);
    return n;
  }
  return NULL ;
}


/*!
 * Destruction d'un noeud et de tous les noeuds se trouvant en dessous. 
 * \param n_pt le noeud départ de la destruction (remis à NULL à la fin)
 * \param detruire la fonction permettant de détruire la valeur au sein du noeud
 */
static void noeud_detruire_recursivement(noeud* n_pt, void(*detruire)(void** pt)) {
  if ((*n_pt) != NULL){
    if ((*n_pt)->f_d != NULL || (*n_pt)->f_g != NULL){
      detruire((*n_pt)->f_d);
      detruire((*n_pt)->f_g);
    }
    detruire(n_pt);
  }
}


/*!
 * Détruit un noeud sans détruire les noeuds se trouvant en dessous.
 * Il faut donc assurer la structure de l'arbre binaire de recherche après la suppression.
 * \param n_pt noeud à détruire car il contient la valeur à supprimer
 * \param detruire la fonction permettant de détruire une valeur au sein d'un noeud
 */
static void noeud_detruire_simple(noeud* const n_pt, void(* detruire)(void** pt ))
{
  detruire(n_pt);
}

/*! 
 * affichage selon le parcours prefixe à partir d'un noeud donné
 * \param n le noeud débutant l'affichage
 * \param f le flux de sortie
 * \param afficher la fonction permettant d'afficher la valeur au sein d'un noeud
 */
static void noeud_afficher_prefixe(noeud n, FILE* f, void(* afficher)(void* val, FILE* f))
{
  (* afficher)(n->val,f);
  if(n->f_g != NULL){
    noeud_afficher_prefixe(n->f_g, f, afficher);
  }
  if(n->f_d !=NULL){
    noeud_afficher_prefixe(n->f_d, f, afficher);
  }
}

/*! 
 * affichage selon le parcours infixe à partir d'un noeud donné
 * \param n le noeud débutant l'affichage
 * \param f le flux de sortie
 * \param afficher la fonction permettant d'afficher la valeur au sein d'un noeud
 */
static void noeud_afficher_infixe(noeud n, FILE * f, void(* afficher)(void* val, FILE * f))
{
  if(n->f_g != NULL){
    noeud_afficher_infixe(n->f_g, f, afficher);
  }
  (* afficher)(n->val,f);
  if(n->f_d !=NULL){
    noeud_afficher_infixe(n->f_d, f, afficher);
  }
}

/*! 
 * affichage selon le parcours postfixe à partir d'un noeud donné
 * \param n le noeud débutant l'affichage
 * \param f le flux de sortie
 * \param afficher la fonction permettant d'afficher la valeur au sein d'un noeud
 */
static void noeud_afficher_postfixe(noeud n, FILE * f, void(* afficher)(void* val, FILE * f))
{
  if(n->f_g != NULL){
    noeud_afficher_postfixe(n->f_g, f, afficher);
  }
  if(n->f_d !=NULL){
    noeud_afficher_postfixe(n->f_d, f, afficher);
  }
  (* afficher)(n->val,f);
}

/*!
 * 1+le nombre de noeud en dessous du noeud donné
 * \param n le noeud de départ
 * \return le nombre de noeuds à partir de n
 */
int noeud_taille(noeud n) {
  if (n->f_g == NULL && n->f_d == NULL){
    return 1;
  }
  else{
    if(n->f_g == NULL){
      return 1 + noeud_taille(n->f_d);
    }
    if(n->f_d == NULL){
      return 1 + noeud_taille(n->f_g);
    }
    if(n->f_g != NULL && n->f_d != NULL){
      return 1 + noeud_taille(n->f_g) + noeud_taille(n->f_d);
    }
  }
}


arbre arbre_creer(void(* copier)(void* val, void** pt), void(* detruire)(void** pt), int(* comparer)(void *val1, void * val2))
{
  arbre a = (arbre)malloc(sizeof(struct arbre_struct));
  a->racine = NULL;
  a->copier = copier;
  a->comparer = comparer;
  a->detruire = detruire;
  return a;
}


void arbre_detruire(arbre* a ) {
  noeud_detruire_recursivement((*a)->racine,detruire((*a)->racine));
}

/*!
 * A compléter
 */

static noeud* arbre_chercher_position(arbre a, void* val)
{
  noeud* n = &(a->racine);
  while ((*n) != NULL) {
    int comp = a->comparer(val,(*n)->val);
    if (comp<=-1) 
      n = &((*n)->f_g);
    else if (comp>=1) 
      n = &((*n)->f_d);
    else 
      return n;
  }
  return n;
}



void arbre_insertion(arbre a, void *val )
{
  noeud* n = arbre_chercher_position(a, val);
  if((comparer(val, (*n)->val) != NULL)){
    (*n)->f_d = noeud_creer(val, a->copier); 
  }
  else {
    if((comparer(val, (*n)->val)<= -1)){
      (*n)->f_d = noeud_creer(val, a->copier);
    }
    else
      printf(" La valeur est deja dans l'arbre");
  }
}


void arbre_afficher_prefixe(arbre a, FILE * f, void(* afficher)(void * val, FILE * f))
{  
 noeud_afficher_postfixe(a->racine, f, afficher);
}

void arbre_afficher_infixe(arbre a, FILE * f, void(* afficher)(void* val, FILE* f))
{
  noeud_afficher_postfixe(a->racine, f, afficher);
}

void arbre_afficher_postfixe(arbre a, FILE * f, void(* afficher)(void* val, FILE* f))
{
  noeud_afficher_postfixe(a->racine, f, afficher);
}


bool arbre_est_vide(arbre a)
{
  if(a->racine == NULL){
    return true;
  }
  else{
    return false;
  }
}



int arbre_taille(arbre a)
{
  return noeud_taille(a->racine);
}



void* arbre_rechercher(arbre a, void* val)
{
  noeud* n =  &(noeud_creer(val,(val,&(n->val))));
  n = arbre_chercher_position(a, val);
}


void arbre_supprimer(arbre a, void* val)
{
  noeud* n = arbre_chercher_position(a, val);
  if(((*n)->f_g == NULL) && ((*n)->f_d == NULL)){ //feuille
    supprimer_noeud_simple(&(*n), a->detruire);
      }
  if(((*n)->f_g == NULL) && ((*n)->f_d != NULL)){ //un enfant droit
    (*n)->val = (*n)->f_d->val; 
    (*n)->f_d = (*n)->f_d->f_d;
    (*n)->f_g = NULL;
    noeud_detruire_simple((*n)->f_d), a->detruire);
  }
  if(((*n)->f_g != NULL) && ((*n)->f_d == NULL)){ //un enfant gauche
    (*n)->val = (*n)->f_g->val; 
    (*n)->f_d = NULL;
    (*n)->f_g = (*n)->f_g->f_g;
    noeud_detruire_simple((*n)->f_d, a->detruire);
  }
  if(((*n)->f_g != NULL) && ((*n)->f_d != NULL)){ //deux enfants
    if (((*n)->f_d->f_g) != NULL){// si il y a un fils gauche du fils droit du noeud 
      (*n)->val = (*n)->f_d->f_g->val;// on copie la valeur 
      arbre_supprimer(a, (*n)->f_d->f_g->val); //on rec pour eviter de tout remettre
    }
    else{// il y a deux enfant mais l'enfant de droite n'a pas d'enfant de gauche
      (*n)->val = (*n)->f_d->val; 
      (*n)->f_d = (*n)->f_d->f_d;
      (*n)->f_g = NULL;
      noeud_detruire_simple((*n)->f_d, a->detruire);
      
    }
  }
}


