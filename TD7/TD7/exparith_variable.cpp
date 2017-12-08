# include "exparith_variable.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 


std :: string const sign_set = ":=" ; 


double Variable :: eval ( Evaluation_Context & ec ) const { 
  return ec.get_value(this->id) ;
}


string Variable :: toString () const { 
  return this->id ;
} 


double Set :: eval ( Evaluation_Context & ec ) const { 
	double val =  value->eval(ec);
    ec.valuate(variable->get_id(),val);
    return val;
}


string Set :: toString () const { 
  return "( "+this->variable->toString()+ " := " + this->value->toString() + " )";
}

