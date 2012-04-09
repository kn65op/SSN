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
 * Odpowiada przesunięciu w sieciach neuronowych. Po podłączeniu linku należy przekazać wartość do łącz lub użyć metody setBiasAndSend(T).
 */
template <class T> class Bias : public Input<T>
{
public:

  /**
   * Konstruktor ustawiający początkową wartość przesunięcia. Po podłączeniu linku należy przekazać wartość do łącz lub użyć metody setBias(T).
   * @param i Wartość przesunięcia.
   */
  Bias(T i) : bias_value(i)
  {

  }

  virtual ~Bias()
  {

  }

  /**
   * Ustawia wartość przesunięcia i nie wysyła jej do łącz.
   * @param i Wartość przesunięcia.
   */
  void setBias(T i)
  {
    bias_value = i;
  }

  /**
   * Ustawia wartość przesunięcia i wysyła ją do łącz.
   * @param i Wartość przesunięcia.
   */
  void setBiasAndSend(T i)
  {
    setBias(i);
    sendBiasToLinks();
  }

  /**
   * Wysyła wartość przesunięcia do łącz.
   */
  void sendBiasToLinks()
  {
    this->input_value = bias_value;
    this->setValToAuts();
  }
private:
  T bias_value;
};

#endif	/* BIAS_H */

