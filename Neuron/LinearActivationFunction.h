/* 
 * File:   LinearActivationFunction.h
 * Author: tomko
 *
 * Created on 19 marzec 2012, 16:25
 */

#ifndef LINEARACTIVATIONFUNCTION_H
#define	LINEARACTIVATIONFUNCTION_H

#include <cmath>

/**
 * Klasa przedstawiającą skokową funkcję aktywacji o określonym progu. Aktywacja następuje gdy dana wartość jest większa od wartości progu. Pochodną funkcji jest zookrąglona delta diraca.
 */
template <class T> class LinearActivationFunction
{
public:

  /**
   * Konstrutor domyślny ustawiający za wartość 0 (rzutowaną na dany typ)
   */
  LinearActivationFunction()
  {
  }


  /**
   * Funkcja sprawdzająca czy dana wartość jest większa od podanego progu.
   * @param x Sprawdzana wartość.
   * @return true jeśli sprawdzana waratość jest większa, false w przeciwnym wypadku.
   */
  double operator()(T x)
  {
    return x;
  }

  T deriterative(T x)
  {
    return x * (1-x);
  }
};


#endif	/* LINEARACTIVATIONFUNCTION_H */