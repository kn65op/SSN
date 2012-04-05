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
 * Klasa Entry odpowiada wejściom do sieci neuronowej.
 */
template <class T> class Entry: public Input<T>
{
public:
  virtual ~Entry()
  {
    
  }
  /**
   * Ustawia wejście na podaną wartość.
   * @param entry Żądana wartość.
   */
  void setEntry(T entry)
  {
    this->input_value = entry;
    this->setValToAuts();
  }
};

#endif	/* ENTRY_H */

