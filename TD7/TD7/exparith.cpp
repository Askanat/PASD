# include <sstream>

# include "exparith.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 



double Constant :: eval ( Evaluation_Context & ec ) const{ 
  return NAN ;
}


string Constant :: toString () const { 
  return * ( string * ) NULL ;
}

