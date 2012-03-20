/* 
 * File:   StepActivationFunction.h
 * Author: tomko
 *
 * Created on 19 marzec 2012, 16:25
 */

#ifndef STEPACTIVATIONFUNCTION_H
#define	STEPACTIVATIONFUNCTION_H

/**
 * Klasa przedstawiającą skokową funkcję aktywacji o określonym progu. Aktywacja następuje gdy dana wartość jest większa od wartości progu.
 */
template <class T> class StepActivationFunction
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
   * @return true jeśli sprawdzana waratość jest większa, false w przeciwnym wypadku.
   */
  bool operator()(T x)
  {
    return x > threshold;
  }
};


#endif	/* STEPACTIVATIONFUNCTION_H */