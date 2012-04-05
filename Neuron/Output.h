/* 
 * File:   Output.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:11
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

template <class T> class Link;
#include <list>

/**
 * Klasa Output jest interfejsem wyjścia dla klasy Link.
 */
template <class T> class Output
{

public:
  virtual ~Output()
  {
    
  }
  /**
   * Funkcja przyjmująca wartość z łącza.
   * @param o Otrzymana wartość z łącza.
   */
//  virtual void setValue(T o)
//  {
//    output_value = o;
//  }
  /**
   * Funkcja dodająca połączenie do wyjścia z połączenia.
   * @param link Dodawane połączenie.
   */
  void setLinkIn(Link<T>* link)
  {
    ins.push_back(link);
    link->setOut(this);
  }
protected:
  //T output_value;
  std::list<Link<T>*> ins;
};

#endif	/* OUTPUT_H */

