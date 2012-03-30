/* 
 * File:   StepActivationFunction.h
 * Author: tomko
 *
 * Created on 19 marzec 2012, 16:25
 */

#ifndef STEPACTIVATIONFUNCTION_H
#define	STEPACTIVATIONFUNCTION_H

#include <cmath>

#include "ActivationFunction.h"

/**
 * Klasa przedstawiającą skokową funkcję aktywacji o określonym progu. Aktywacja następuje gdy dana wartość jest większa od wartości progu. Pochodną funkcji jest zookrąglona delta diraca.
 */
template <class T> class StepActivationFunction : public ActivationFunction<T>
{
  T threshold;
public:

  /**
   * Konstrutor domyślny ustawiający za wartość 0 (rzutowaną na dany typ)
   */
  StepActivationFunction()
  {
    threshold = 0;
  }

  /**
   * Konstruktor z parametrem progu.
   * @param i Próg jaki chcemy ustawić.
   */
  StepActivationFunction(T i)
  {
    threshold = i;
  }

  /**
   * Funkcja sprawdzająca czy dana wartość jest większa od podanego progu.
   * @param x Sprawdzana wartość.
   * @return 1 jeśli sprawdzana waratość jest większa, 0 w przeciwnym wypadku.
   */
  T operator()(T x)
  {
    return x > threshold;
  }

  /**
   * Funkcja licząca pochodną funkcji skokowej (jako cos(x) w zakresie 0 do 1)
   * @param x
   * @return 
   */
  T deriterative(T x)
  {
    if (x > threshold + 1)
    {
      return std::cos(1);
    }
    if (x > threshold - 1)
    {
      return std::cos(-1);
    }
    else
    {
      return std::cos(x - threshold);
    }
  }
};


#endif	/* STEPACTIVATIONFUNCTION_H */