# ifndef __HEAP_HPP_
# define __HEAP_HPP_

/*!
 * \file
 * \brief This module provide a generic (template) heap.
 *
 * \author PASD
 * \date 2017
 */

# include <iostream>


# undef NDEBUG 
# include <assert.h>



// Pre-declaration to be able to declare operator <<
template <class Element>
class Heap;


// Pre-declaration to declare friend after
template <class Element>
std :: ostream & operator <<(std :: ostream & out, Heap <Element> const & h);


/*!
 * \brief This class implements a generic heap.
 *
 * It uses a binary tree such that the value held in any node is greater (or equal) to the value in its sons.
 *
 * \pre \c Element must be comparable: operators < and <= must be defined.
 *
 * Implementation: 
 * \li the tree is folded into an array.
 * \li reference / pointers are used to store elements (i.e. no copy is made)
 */
template <class Element>
class Heap {

public :

  /*! Maximal capacity of the heap. */ 
  const unsigned int capacity;

private :

  /*! Nature of the nodes: pointers to elements.
   * The number of elements is \c capacity. */
  typedef Element* Node;
  
  /*! Pointer to array of size capacity. 
    The array holds the values. */
  Node* const elements;

  /*! Number of values in the heap.
   * It is always at most the capacity. */
  unsigned int nb_elem;

  /*! To compare two elements (less than).
   * \param pos_1 position of the left node.
   * \param pos_2 position of the right node.
   * \pre \c  pos_1 and \c pos_2 are legal positions.
   * \return true iff the node at \c pos_1 has a value LESSER THAN the one at node \c pos_2 ). 
   */
  bool lt(unsigned int const pos_1, unsigned int const pos_2) const {
    if (pos_1 < pos_2){
      return (true);
    }
    return (false);
  }
  
  /*! To compare two elements (less or equal).
   * \param pos_1 position of the left node.
   * \param pos_2 position of the right node.
   * \pre \c  pos_1 and \c pos_2 are legal positions.
   * \return true iff the node at \c pos_1 has a value LESSER than or EQUAL to the one at node \c pos_2) */
  bool le(unsigned int const pos_1, unsigned int const pos_2) const {
    if (pos_1 <= pos_2){
      return (true);
    }
    return (false);
  }
  /*!
   * To compute the index of the left son.
   * \param i position of the node.
   * \pre \c i is a legal position
   * \post returns a legal position.
   * \return the index (in the array) of the left son of the node (indicated by index i). 
   */
  unsigned int get_pos_left_son(unsigned int i) const {
    return (2*i+1); 
  };
  
  /*!
   * To compute the index of the left son.
   * \param i position of the node.
   * \pre \c i is a legal position
   * \post returns a legal position.
   * \return the index (in the array) of the right son of the node (indicated by index i). 
   */
  unsigned int get_pos_right_son(const unsigned int i) const {
    return (2*i+2); 
  };
  
  /*!
   * To compute the index of the father.
   * \param i position of the node.
   * \pre \c i is a legal position.
   * \post returns a legal position.
   * \return the index (in the array) of the right son of the node (indicated by index i), except for the root (it returns 0). 
   */
  unsigned int get_pos_father(const unsigned int i) const {
    if (i == 0) {
      return 0;
    }
    return((i-1)/2); 
  };
  
  /*!
   * Exchange two elements in the array. 
   * \param pos_a position of one node.
   * \param pos_b position of other node.
   * \pre \c pos_a and \c pos_b are legal positions.
   */
  void swap(const unsigned int pos_a, const unsigned int pos_b) {
    Element *t = elements[pos_a];
    elements[pos_a] = elements[pos_b];
    elements[pos_b] = t;
  }
  
  /*!
   * To check the validity of the head.
   * \return true iff the heap is correct (each father less than or equal to sons).
   * This should to be used in asserts.
   */
  bool is_valid () const;

  /*! 
   * Swap the node pos down throughout the heap till consistency is restored.
   * \param pos position of the node to lower
   * \pre pos is a valid location.
   * \post The heap is valid.
   */
  void lower(unsigned pos);

  /*! 
   * Swap the node pos up throughout the heap till consistency is restored.
   * \pre pos is a valid location.
   * \post The heap is valid.
   */
  void raise(unsigned pos);

  
public :

  
  //
  //  CONSTRUCTOR
  //

  /*! Build an empty heap with given capacity. */
  Heap(unsigned int _capacity)
    : capacity(_capacity)
    , elements(new Node [ _capacity ])
    , nb_elem(0) 
  {
    assert(is_valid ());
  };

  
  //
  //  DESTRUCTOR
  //

  /*! Release the array. */
  ~Heap () {
    for(unsigned int i = 0; i<nb_elem; i++){
      free(elements[i]);
    }
  }

  
  //
  //  PUBLIC METHODS
  //

  /*!
   * To test the emptyness of the heap. 
   * \return true iff the heap is empty 
   */
  bool is_empty () const {
    if (nb_elem == 0){
      return (true);
    }
    else{
      return (false);
    }
  }
  
  /*! 
   * Remove and return the root of the heap.
   * The heap is re equilibrated by putting the last element at the root and lowering it.
   * \pre The heap is valid.
   * \post The heap is valid.
   * \return the minimum of the heap.
   */
  Element & pop();

  /*!
   * Add a value at the bottom of the tree (first empty cell) and swap it up (raise).
   * \param v value to add.
   * \pre The heap is valid.
   * \post The heap is valid.
   */
  void push(Element & v);

  
  //
  //  FRIENDS
  //

  friend std :: ostream & operator << <Element>(std :: ostream &, Heap const &);
  
};



//
// TEMPLATE 
// => METHODS MUST BE HERE 
//


template <class Element>
bool Heap <Element> :: is_valid () const {
  for (unsigned int i = nb_elem; i>0 ; i--){
    if ((le(get_pos_father(i),i)) == false ){
      return false;
    }
  }
  return true;
}


template <class Element>
void Heap <Element> :: lower(unsigned int pos) {
  while( is_valid() != true ){
    if (le(get_pos_left_son(pos), get_pos_right_son(pos))){
      swap(pos, get_pos_left_son(pos));
    }
    else{
      swap(pos, get_pos_right_son(pos));
    }
  }
}
  /*!
   * Add a value at the bottom of the tree (first empty cell) and swap it up (raise).
   * \param v value to add.
   * \pre The heap is valid.
   * \post The heap is valid.
   */

template <class Element>
void Heap <Element> :: push(Element & v) {
  elements[nb_elem+1] = &v;
  raise(nb_elem+1);
}


template <class Element>
void Heap <Element> :: raise(unsigned int pos) {
  while( is_valid() != true ){
    swap(pos, get_pos_father(pos));
  }
}


  /*! 
   * Remove and return the root of the heap.
   * The heap is re equilibrated by putting the last element at the root and lowering it.
   * \pre The heap is valid.
   * \post The heap is valid.
   * \return the minimum of the heap.
   */
template <class Element>
Element & Heap <Element> :: pop() {
  /*Element *buffer= elements[0];
  swap(0, nb_elem);
  elements[nb_elem]= 0;
  nb_elem--;
  lower(0);
  return *buffer;
  */
  
}


/*! Print the heap on the \c ostream as an array with the format:
 * \verbatim [ e0 , e1 , ... , en ] \endverbatim 
 * \param out \c ostream to output to.
 * \param h Heap to output
 * \return the ostream
 */
template <class Element> std :: ostream & operator <<(std :: ostream & out, Heap<Element> const & h) {
  return out;
}


# endif
