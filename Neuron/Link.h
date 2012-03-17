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
  Link()
  {
    
  }
  Link(Input<T>)
  {
    
  }
  Link(const Link& orig)
  {
    
  }
  virtual ~Link()
  {
    
  }
  
  /**
   * Funkcja zwracająca wartość aktualnie przetrzymywana na połączeniu.
   * @return Wartość przyjęta ostatnio na wejściu do połączenia.
   */
  T getValue() const
  {
    return value;
  }
  /**
   * Funckja pobierająca wartość z wejścia do połączenia i zapisująca wartość w połączeniu.
   * @param Wartość, która będzie dostępna na wyjściu z połączenia.
   */
  void setValue(const T v)
  {
    value = v;
  }
  
  /**
   * Funkcja ustawiająca wejście do linku.
   * @param i Ustawiane wejście.
   */
  void setIn(Input<T>* i)
  {
    in = i;
  }
  /**
   * Funkcja ustawiająca wyjście z linku.
   * @param out Ustawiane wyjście.
   */
  void setOut(Output<T>* o)
  {
    out = o;
  }
  
private:
  Input<T>* in;
  Output<T>* out;
  T value;
};

#endif	/* LINK_H */

