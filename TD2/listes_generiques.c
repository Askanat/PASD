#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "listes_generiques.h"

/*! \file listes_generiques.c
 * \brief L'implémentation des fonctions
 * Les définitions des fonctions sont identiques à celles de liste des entiers.
 * Mais certaines nécessitent un paramètre supplémentaire la fonction copier 
 * afficher ou detruire qui permettent de rendre générique la liste.
 * Pour l'essentiel il s'agit de reprendre les fonctions pour les listes 
 * d'entiers et de les adapter à la généricité .
 *
 * \copyright PASD
 * \version 2017
 */

typedef struct maillon_struct * maillon;

struct maillon_struct {
};


static maillon maillon_creer(void * val, void(*copier)(void* val, void** pt)) {
	maillon m = (maillon)malloc(sizeof(struct maillon_struct));
	copier(val,&(m->val));
	m->precedent = m;
	m->suivant = m;
}


static bool maillon_est_unique(maillon m){
}


static void maillon_detruire(maillon* m, void(* detruire)(void** pt)) {
	detruire(&(m->val));
	m->precedent = NULL;
	m->suivant = NULL;
	free(*m);
}


static void maillon_afficher(FILE* f, maillon m_debut, maillon m_fin, void(* afficher )(FILE *f, void* val)) {
}


static void maillon_ajouter_avant(maillon m, void* _val, void(*copier)(void* val, void** pt)) {
}


static void maillon_ajouter_apres(maillon m, void * _val, void(*copier)(void* val, void** pt)) {
}


static void maillon_supprimer_avant(maillon m, void(*detruire)(void** pt)) {
}


static void maillon_supprimer_apres(maillon m, void(*detruire)(void** pt)) {
}


/*!
 * la structure définit 3 champs supplémentaires qui sont des pointeurs sur fonction
*/
struct liste_struct {
};


liste liste_creer(void(*_copier)(void* val, void** pt),
		    void(*_afficher)(FILE *f, void* val),
		    void(* _detruire )(void** pt)) {
}


void liste_detruire(liste* l){
}


void liste_insertion_debut(liste l, void* val){
}


void liste_insertion_fin(liste l, void* val){
}


void liste_insertion_avant(liste l, void* val){
}


void liste_insertion_apres(liste l, void* val){
}


void liste_suppression_debut(liste l){
}


void liste_suppression_fin(liste l){
}


void liste_suppression_avant(liste l){
}


void liste_suppression_apres(liste l){
}


void liste_affichage(FILE* f,liste l){
}


void liste_decalage(liste l,int n){
}


void * liste_valeur_tete(liste l){
}



void * liste_valeur_courant(liste l){
}


bool liste_est_tete(liste l){
}



void liste_courant_init(liste l){
}


void liste_courant_suivant(liste l){
}


