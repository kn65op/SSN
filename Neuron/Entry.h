/* 
 * File:   Entry.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:23
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include "Input.h"

template <class T> class Entry: public Input<T>
{
public:
  Entry();
  Entry(const Entry& orig);
  virtual ~Entry();
private:

};

#endif	/* ENTRY_H */

