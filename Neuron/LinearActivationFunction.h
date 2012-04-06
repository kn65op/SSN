/* 
 * File:   LinearActivationFunction.h
 * Author: tomko
 *
 * Created on 19 marzec 2012, 16:25
 */

#ifndef LINEARACTIVATIONFUNCTION_H
#define	LINEARACTIVATIONFUNCTION_H

#include <cmath>

#include "ActivationFunction.h"
/**
 * Klasa przedstawiającą skokową funkcję aktywacji o kształcie sigmoidy parametryzowana wartością określającą w jakim zakresie jest największa zmiana wartości.
 */
template <class T> class LinearActivationFunction
{
public:

  /**
   * Konstrutor domyślny ustawiający za parametr wartość 1.
   */
  LinearActivationFunction() : parameter(1)
  {
  }
  
  /**
   * Konstrutor domyślny ustawiający żądany parametr.
   */
  LinearActivationFunction(double p) : parameter(p)
  {
  }

  /**
   * Funkcja licząca wartość sigmoidy.
   * @param x Sprawdzana wartość.
   * @return Wyliczona wartość dla sigmoidy
   */
  T operator()(T x)
  {
    return 1 / (1 + pow(M_E, -parameter * x));
  }

  /**
   * Funkcja licząca pochodną
   * @param x Wartość dla której liczymy pochodną.
   * @return Obliczona pochodna.
   */
  T deriterative(T x)
  {
    return x * (1 - x);
  }
  
  /**
   * Funkcja ustawiająca paramtr sigmoidy,
   * @param parameter Parametr.
   */
  void setParameter(double parameter)
  {
    this->parameter = parameter;
  }


private:
  double parameter;
};


#endif	/* LINEARACTIVATIONFUNCTION_H */