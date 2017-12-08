# ifndef __EXPARITH_BINARY_HPP_
# define __EXPARITH_BINARY_HPP_

/*!
 * \file 
 * This module provides the classes to represent binary arithmetical expressions.
 *
 * \pre For all method, no pointer should NULL
 *
 * \author PASD
 * \date 2016
 */

# include "exparith.hpp"


# undef NDEBUG
# include <assert.h>




/*! Symbol for operator \c + . */
extern std :: string const sign_add ; 
/*! Symbol for operator \c - (binary). */
extern std :: string const sign_sub ; 
/*! Symbol for operator\c * . */
extern std :: string const sign_mul ; 
/*! Symbol for operator \c ∕ . */
extern std :: string const sign_div ; 




/*! 
  * Class Op_Binary
  * Hérite de la Class Expr
  * Instancie les différents élément le composant via son constructeur
  * Composé des fonctions:  
  * -eval ()
  *    -Param: Evaluation_Context & ec
  * -toString ()
  * -get_sign ()
  * -compute ()
  *    -Pamam: double left, double right
*/
class Op_Binary : public Expr {
  /*! Stock symbol for operator */
  std :: string sign ;
  /*! Opérande gauche */
  Expr * left ; 
  /*! Opérande droite */
  Expr * right ;
public:
  // CONSTRUCTOR 
  Op_Binary ( priority_enum priority , 
	      std :: string sign , 
	      Expr * left , 
	      Expr * right ) 
    : Expr ( priority ) 
    , sign ( sign ) 
    , left ( left ) 
    , right ( right ) 
  {} ; 
  /*! Destructor. */
  ~ Op_Binary () {
    delete left ; 
    delete right ; 
  } ; 
  std :: string  toString () const ; 
  /*! Ensures that left is evaluated before right. */
  double eval ( Evaluation_Context & ec ) const ;
  /*! Récupère le signe */
  std :: string get_sign () const ; 
protected :
  /*! Calcul et Retourne la valeur de l'opération */
  virtual double compute ( double left ,
			   double right ) const = 0 ;
} ; 



//
// SAME
//
# define CLASS_OP_BINARY( name , priority, sign )	\
  class name : public Op_Binary {			\
  public:						\
  name ( Expr * exp1 ,					\
	 Expr * exp2 )					\
    : Op_Binary ( priority				\
		  , sign				\
		  , exp1				\
		  , exp2 ) {} ;				\
  /*! Destructor. */					\
  ~ name () {} ;					\
  protected :						\
  double compute ( double left ,			\
		   double right ) const ;		\
  } ; 


CLASS_OP_BINARY ( Add , priority_add_sub , sign_add )
CLASS_OP_BINARY ( Sub , priority_add_sub , sign_sub )
CLASS_OP_BINARY ( Mul , priority_mul_div , sign_mul )
CLASS_OP_BINARY ( Div , priority_mul_div , sign_div )



# endif



