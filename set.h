#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>
#include "node1.h"

using namespace main_savitch_5;

class set
{
public:
  typedef node::value_type value_type;
  typedef std::size_t size_type;

  set();
// postcondition: empty set has been created
	//efficiency:O(1)

  ~set();
// postcondition: set has been deallocated
   //efficiency:O(n)
  
  set (const set& source);
  // postcondition: a copy of source has been created
  //efficiency:O(n)

  set& operator = (const set& source);
  // postcondition: 
  //efficiency:O(2n)
  
  void insert (const value_type& entry);
  // postcondition: entry is in the set
  //efficiency:O(n)

  void remove (const value_type& entry);
   // postcondition: entry is not in the set
   //efficiency:O(n)

  size_type size() const;
// postcondition: number of elements in the set has been returned
  //efficiency:O(1)

  bool contains (const value_type& entry) const;
// postcondition: whether entry is in the set has been returned
  //efficiency:O(n)

  friend set set_union (const set& s1, const set& s2);
  //postcondition: union of s1 & s2 has been returned
    //efficiency:O(2n^2)

  friend set set_intersection (const set& s1, const set& s2);
  // postcondition: intersection of s1 & s2 has been returned
    //efficiency:O(n^3)

  friend set set_difference (const set& s1, const set& s2);
// postcondition: difference of s1 - s2 has been returned
    //efficiency:O(n^3)

  friend bool is_subset (const set& s1, const set& s2);
// postcondition: returned whether s1 is a subset of s2
	  //efficiency:O(n^2)

  friend bool operator == (const set& s1, const set& s2);
  // postcondition: returned whether s1 & s2 are equal
	  //efficiency:O(n^2)
  friend std::ostream& operator << (std::ostream& output, const set& s);
// postcondition: s has been displayed on output
	  //efficiency:O(n)
private:
  node* head;
  size_type used;

};


#endif