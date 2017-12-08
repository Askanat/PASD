# include "exparith_unary.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 



std :: string const sign_exp = "exp" ;

std :: string const sign_log = "log" ;



double Op_Unary :: eval ( Evaluation_Context & ec ) const { 
  return compute (argument->eval(ec))  ;
}


string Op_Unary :: toString () const { 
  return sign + "(" + this->argument->toString() + ")";
}


# define COMPUTE_UNARY( class , op )		\
  double class :: compute ( double x ) const {	\
    return op ( x ) ;				\
  }


COMPUTE_UNARY ( Exp , exp ) 
COMPUTE_UNARY ( Log, log ) 

