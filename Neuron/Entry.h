/* 
 * File:   Entry.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:23
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include "Input.h"

/**
 * @class Klasa Entry odpowiada wejściom do sieci neuronowej.
 */
template <class T> class Entry: public Input<T>
{
public:
  Entry();
  Entry(const Entry& orig);
  virtual ~Entry();
  /**
   * Ustawia wejście na podaną wartość.
   * @param entry Żądana wartość.
   */
  void setEntry(T entry)
  {
    input_value = entry;
  }
};

#endif	/* ENTRY_H */

