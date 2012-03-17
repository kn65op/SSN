/* 
 * File:   Output.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:11
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

/**
 * @class Klasa Output jest interfejsem wyjścia dla klasy Link.
 */
template <class T> class Output
{
public:
  virtual ~Output();
  /**
   * Funkcja przyjmująca wartość z łącza.
   * @param o Otrzymana wartość z łącza.
   */
  virtual void setValue(T o)
  {
    output_value = o;
  }
protected:
  T output_value;
};

#endif	/* OUTPUT_H */

