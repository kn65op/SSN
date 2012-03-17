/* 
 * File:   Bias.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 14:36
 */

#ifndef BIAS_H
#define	BIAS_H

#include "Input.h"

/**
 * @class Klasa Bias odpowiada przesunięciu w sieciach neuronowych.
 */
template <class T> class Bias : public Input<T>
{
public:
  /**
   * Konstruktor ustawiający początkową wartość przesunięcia.
   * @param i Wartość przesunięcia.
   */
  Bias(T i): T(i)
  {
    
  }
  virtual ~Bias();
  /**
   * Ustawia wartość przesunięcia.
   * @param i Wartość przesunięcia.
   */
  void setBias(T i)
  {
    bias_value = i;
  }
private:
  T bias_value;
};

#endif	/* BIAS_H */

