/* 
 * File:   Input.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:04
 */

#ifndef INPUT_H
#define	INPUT_H

template <class T> class Link;

#include <list>
/**
 * @class Klasa Input jest interfejsem wejścia do klasy Link.
 */
template <class T> class Input
{
public:
  virtual ~Input()
  {
    
  }
  /**
   * Funkcja zwracająca przechowywaną wartość do połączeń.
   * @return Przechowywana wartość.
   */
  virtual T getValue() const
  {
    return this->input_value;
  }
  /**
   * Funkcja dodająca połączenie do wejścia do połączenia.
   * @param link Dodawane połączenie.
   */
  void setLinkOut(Link<T>* link)
  {
    outs.push_back(link);
    link->setIn(this);
  }
protected:
  T input_value;
  std::list<Link<T>*> outs;
  /**
   * Wysłanie wartości przechowywanej w danym obiekcie do wszystkich podłączonych linków.
   */
  void setValToAuts() const
  {
    for (auto o: this->outs)
    {
      o->setValue(input_value);
    }
  }
};

#endif	/* INPUT_H */

