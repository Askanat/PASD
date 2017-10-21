# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <assert.h>
# include <ctype.h>

# undef NDEBUG

# include "arbre.h"
# include "chaine.h"
# include "xml.h"


struct balise_struct {
  enum { ouvrante , fermante } type; 
  chaine nom; 
}; 




balise balise_creer(char const * st){
  return NULL;
}


void balise_detruire(balise* x){
}

bool balise_est_ouvrante(balise x){ 
  assert(x != NULL ); 
  return(x -> type==ouvrante ); 
}

bool balise_est_fermante(balise x){ 
  assert(x != NULL ); 
  return(x -> type==fermante ); 
}

void balise_afficher (balise x, FILE* f) {
  chaine_afficher(f,x->nom);
}

/*! Les 4 fonctions ci-dessous sont usuels maintenant pour la manipulation d'un arbre de balises 
 * Elles sont "static" quand elles sont utiles à la création de l'arbre et "non static" sinon
 */
/*!
 * Pour copier une balise et utiliser la généricité des arbres
 * \param val la balise initiale
 * \param la location de la copie
 */
static void copier_balise(void* val, void** ptr){
}

void afficher_balise(void* val, FILE* f){
}

/*!
 * Pour détruire une balise et utiliser la généricité des arbres
 * \param ptr la location de la balise à détruire
 */
static void detruire_balise(void** ptr){
}

bool est_egal_balise(void* val1, void* val2){
  return false;
}


/*!
 * Pour supprimer les espaces d'une chaine de caractères
 * \param st la chaine (au sens C) cible
 * \return une chaine (au sens C) sans espace
 */
static char* trim (char* st) {
  return NULL; 
}

arbre xml_construction_arbre(char* source){
  return NULL; 
}

