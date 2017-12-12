# include <sstream>

# include "exparith.hpp"


# include <assert.h>
# define NDEBUG 1


using namespace std ; 



double Constant :: eval ( Evaluation_Context & ec ) const {
    return  value ;
}


string Constant :: toString () const {
    std::stringstream ss;
    ss << this->value;
    std::string chaine = ss.str();
    return chaine;
}

