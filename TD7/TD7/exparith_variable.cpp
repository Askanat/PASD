# include "exparith_variable.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 


std :: string const sign_set = ":=" ; 


double Variable :: eval ( Evaluation_Context & ec ) const{ 
  return NAN ;
}


string Variable :: toString () const { 
  return * ( string * ) NULL ;
} 


double Set :: eval ( Evaluation_Context & ec ) const { 
  return NAN ;
}


string Set :: toString () const { 
  return * ( string * ) NULL ;
}

