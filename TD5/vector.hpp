# ifndef __VECTOR_HPP_
# define __VECTOR_HPP_

/* ! \file
 * \brief This module handles vector of floats. 
 * 
 * \author PASD
 * \date 2017
 */


# include <iostream>


/* ! 
 * This class records vector of floats.
 */
class Vector {

  /* ! Size of the vector. */
  unsigned int size ;

  /*! All the elements of the vector. */
  float * element ; 
 
public:
  
  /*! 
   * Construct a vector of size  \c _size of zeros.
   * /param _size size of the vector.
   */
  Vector ( unsigned int const _size ) 
    : size ( _size ) 
    , element ( new float [ _size ] ) {
  }
  
  /*! 
   * Copy constructor.
   * \param v Vector to copy.
   */
  Vector ( Vector const & v ) ; 
 
  /*! Destructor */
  ~Vector () ; 
 
  /*! To randomly set the values of the elements.
   * The size is not changed.
   */
  void init_alea () ; 

  /*! To access the size of the vector. */
  unsigned int get_size () const {
    return size ;
  } 

  /*! To access any individual value of the vector using the \c v[i] syntax.
   * \param i number of the coordinate to access. 
   * \pre i is a legal coordinate.
   * \return a direct reference to the coordinate
   */
  float & operator [] ( unsigned int const i ) ;
  
  /*! To access any individual value of the vector using the \c v[i] syntax (constant version). 
   * \param i number of the coordinate to access. 
   * \pre i is a legal coordinate.
   * \return a direct reference to the coordinate
   */
  float const & operator [] ( unsigned int const i ) const ; 

  /*! Affectation operator.
   * \param v Vector to copy the value of.
   * \return The vector itself.
   */
  Vector & operator = ( Vector const & v ) ; 

  /*! Compute the sum of two vectors.
   * \param v Vector to add the value of.
   * \pre this and v have the same size.
   * \return A new vector whose coordinates are the sum of the coordinate of this and v.
   */
  Vector operator + ( Vector const & v ) const ; 

  /*! Compute the difference of two vectors.
   * \param v Vector to subtract the value of.
   * \pre this and v have the same size.
   * \return A new vector whose coordinates are the subtractions of the coordinate of v from the ones of this.
   */
  Vector operator - ( Vector const & v ) const  ; 

  /*! Compute the product of the vector by a scalar a.
   * \param a Float to multiply by.
   * \return A new vector whose coordinates are the product of the coordinate of this and a.
   */
  Vector operator * ( float const a ) const ; 
 
  /*! Return the sum of the product component wise (a.k.a. scalar product)
   * \param v Vector to multiply by.
   * \pre this and v have the same.
   * \return The sum of the product of the coordinates of this and v;
   */
  float operator | ( Vector const & v ) const ; 
  
  /*! To test whether two vectors are equal.
   * \param v Vector to compare
   * \pre this and v have the same.
   * \return true if the two vectors are component-wise equal.
   */
  bool operator == ( Vector const & v ) const ; 
 

  friend Vector operator * ( float const a ,
			     Vector const & v ) ; 

  friend std :: ostream & operator << ( std :: ostream & ost ,
					Vector const & v ) ; 
 
} ; 



/*! Multiplication by a scalar function. 
 * \param a Float to multiply by.
 * \param v Vector to multiply.
 * \return A new vector whose coordinates are the product of the coordinates of v by a.
 */
Vector operator * ( float const a ,
		    Vector const & v ) ; 


/*! Print a string version of the vector to a stream. 
 * \param ost Output stream to write to.
 * \param v Vector to print.
 * \return The output stream.
 */
std :: ostream & operator << ( std :: ostream& ost ,
			       Vector const & v ) ; 



# endif
