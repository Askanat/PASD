# include "exparith_binary.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 


std :: string const sign_add = "+" ; 
std :: string const sign_sub = "-" ; 
std :: string const sign_mul = "*" ; 
std :: string const sign_div = "/" ; 



double Op_Binary :: eval ( Evaluation_Context & ec ) const { 
  return NAN ;
}


string Op_Binary :: toString () const { 
  return * ( string * ) NULL ;
}


# define COMPUTE_BINARY( class , op )				\
    double class :: compute ( double left ,			\
    double right ) const {					\
    return NAN ;						\
  }

COMPUTE_BINARY ( Add , + )
COMPUTE_BINARY ( Sub , - )
COMPUTE_BINARY ( Mul , * )
COMPUTE_BINARY ( Div , / )


