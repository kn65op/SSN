/* 
 * File:   Link.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:15
 */

#ifndef LINK_H
#define	LINK_H

#include "Input.h"
#include "Output.h"

/**
 * @class Klasa Link odpowiada połączaniu między neuronami oraz między neuronami i wejściem/wyjściem.
 */
template <class T> class Link
{
public:
  Link();
  Link(const Link& orig);
  virtual ~Link();
  
  T getValue();
  void setValue(T);
private:
  Input<T> in;
  Output<T> out;
};

#endif	/* LINK_H */

