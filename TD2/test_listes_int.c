#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "listes_int.h"

/*! \file test_listes_int.c
 * \brief Les fonctions de tests pour valider la liste d'entiers
 *
 * \copyright PASD
 * \version 2017
 */

void test1(FILE* f_out)
{
  fprintf(f_out,"-----------------test1------------------\n");
  liste l = liste_creer();
  liste_insertion_debut(l,1);
  liste_affichage(f_out,l);
  fprintf(f_out,"\n");
  liste_detruire(&l);
}

void test2(FILE* f_out)
{
  fprintf(f_out,"-----------------test2------------------\n");
  liste l = liste_creer();
  liste_insertion_fin(l,3);
  liste_affichage(f_out,l);
  fprintf(f_out,"\n");
  liste_detruire(&l);
}

void test3(FILE* f_out)
{
  fprintf(f_out,"-----------------test3------------------\n");
  liste l = liste_creer();
  liste_insertion_debut(l,1);
  liste_insertion_debut(l,2);
  liste_insertion_fin(l,3);
  liste_insertion_fin(l,4);    
  liste_courant_init(l);
  liste_insertion_apres(l,10);
  liste_affichage(f_out,l);
  fprintf(f_out,"\n");
  liste_detruire(&l);
}

void test4(FILE* f_out)
{
  fprintf(f_out,"-----------------test4------------------\n");
  
  FILE* f_in = fopen("test_listes_int_in.txt","r");
  
  liste l = liste_creer();
  int a;
  fscanf(f_in,"%d",&a);
  liste_insertion_debut(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_fin(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_fin(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_fin(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_fin(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_debut(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_debut(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_debut(l,a);
  liste_suppression_debut(l);
  liste_suppression_debut(l);
  liste_suppression_fin(l);
  fscanf(f_in,"%d",&a);
  liste_courant_init(l);
  liste_courant_suivant(l);
  liste_insertion_avant(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_avant(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_apres(l,a);
  fscanf(f_in,"%d",&a);
  liste_insertion_apres(l,a);
  liste_courant_suivant(l);
  liste_suppression_avant(l);
  liste_suppression_apres(l);
  liste_suppression_avant(l);
  liste_suppression_apres(l);
  liste_affichage(f_out,l);
  fprintf(f_out,"\n");
  liste_courant_init(l);
  while(!liste_est_fin(l)) {
    if (liste_est_tete(l))
      fprintf(f_out,"tete : %d\n",liste_valeur_courant(l));
    else
      fprintf(f_out,"courant : %d\n",liste_valeur_courant(l));
    liste_courant_suivant(l);
  }
  fprintf(f_out,"pied : %d\n",liste_valeur_courant(l));
  
  
  fclose(f_in);
  liste_detruire(&l);
}

void test5(FILE* f_out)
{
  fprintf(f_out,"-----------------test5------------------\n");
  
  FILE* f_in = fopen("test_listes_int_in.txt","r");
  
  liste l = liste_creer();

  int a;
  fscanf(f_in,"%d",&a);
  liste_insertion_debut(l,a);
  fscanf(f_in,"%d",&a);
  liste_courant_init(l);
  do {
    liste_insertion_avant(l,a);
    fscanf(f_in,"%d",&a);
  }  while (!feof(f_in)) ;
  
  liste_affichage(f_out,l);
  fprintf(f_out,"\n");
  liste_detruire(&l);
  fclose(f_in);
  
}

int main (void)
{

  FILE* f_out = fopen("test_listes_int_out.txt","w");
  test1(f_out);
  test2(f_out);
  test3(f_out);
  test4(f_out);
  test5(f_out);
  fclose(f_out);


  return 0 ;
}
