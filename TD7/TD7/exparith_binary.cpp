# include "exparith_binary.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 


std :: string const sign_add = "+" ; 
std :: string const sign_sub = "-" ; 
std :: string const sign_mul = "*" ; 
std :: string const sign_div = "/" ; 



double Op_Binary :: eval ( Evaluation_Context & ec ) const { 
	double g = left->eval(ec);
	double d = right->eval(ec);
  return compute (g,d) ;
}


string Op_Binary :: toString () const { 
  return  this->left->toString ()+" "+ this->sign +" "+ this->right->toString()  ;
}


# define COMPUTE_BINARY( class , op )				\
    double class :: compute ( double left ,			\
    double right ) const {	\
    return left op right;						\
  }

COMPUTE_BINARY ( Add , + )
COMPUTE_BINARY ( Sub , - )
COMPUTE_BINARY ( Mul , * )
COMPUTE_BINARY ( Div , / )


