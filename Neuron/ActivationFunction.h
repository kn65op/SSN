/* 
 * File:   ActivationFunction.h
 * Author: tomko
 *
 * Created on 30 marzec 2012, 19:46
 */

#ifndef ACTIVATIONFUNCTION_H
#define	ACTIVATIONFUNCTION_H

template <class T> class ActivationFunction
{
public:
  /**
   * Funkcja sprawdzająca czy dana wartość jest większa od podanego progu.
   * @param x Sprawdzana wartość.
   * @return true jeśli sprawdzana waratość jest większa, false w przeciwnym wypadku.
   */
  T operator()(T x) const = 0;

  /**
   * Funkcja licząca pochodną funkcji skokowej (jako cos(x) w zakresie 0 do 1)
   * @param x
   * @return 
   */
  T deriterative(T x) const = 0;
};

#endif	/* ACTIVATIONFUNCTION_H */

