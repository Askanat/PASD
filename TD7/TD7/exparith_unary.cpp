# include "exparith_unary.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 



std :: string const sign_exp = "exp" ;

std :: string const sign_log = "log" ;



double Op_Unary :: eval ( Evaluation_Context & ec ) const { 
  return NAN ;
}


string Op_Unary :: toString () const { 
  return * ( string * ) NULL ;
}


# define COMPUTE_UNARY( class , op )		\
  double class :: compute ( double x ) const {	\
    return op ( x ) ;				\
  }


COMPUTE_UNARY ( Exp , exp ) 
COMPUTE_UNARY ( Log, log ) 

