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

//TODO usunąć
#include <iostream>

/**
 * Klasa Link odpowiada połączaniu między neuronami oraz między neuronami i wejściem/wyjściem.
 */
template <class T> class Link
{
public:
  /**
   * Konstruktor domyślny.
   */
  Link()
  {
    
  }
  Link(const Link& orig) = delete;
  virtual ~Link()
  {
    
  }
  
  /**
   * Funkcja zwracająca wartość aktualnie przetrzymywana na połączeniu.
   * @return Wartość przyjęta ostatnio na wejściu do połączenia.
   */
  T getValue() const
  {
    //std::cout << value << " get value\n";
    return value;
  }
  /**
   * Funckja pobierająca wartość z wejścia do połączenia i zapisująca wartość w połączeniu.
   * @param Wartość, która będzie dostępna na wyjściu z połączenia.
   */
  void setValue(const T v)
  {
    value = v;
    //std::cout << value << " set value\n";
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
  /**
   * Pobranie odpowiedzi z linku.
   * @return Zapisana odpowiedź.
   */
  T getAnswer() const
  {
    return answer;
  }
  /**
   * Zapisanie odpowiedzi do linku.
   * @param answer Przekazywana odpowiedź.
   */
  void setAnswer(T answer)
  {
    this->answer = answer;
  }

private:
  Input<T>* in;
  Output<T>* out;
  T value;
  T answer;
};

#endif	/* LINK_H */

