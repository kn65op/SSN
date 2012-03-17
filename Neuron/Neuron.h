/* 
 * File:   Neuron.h
 * Author: tomko
 *
 * Created on 15 marzec 2012, 16:24
 */

#ifndef NEURON_H
#define	NEURON_H

#include "Input.h"
#include "Output.h"

#include <list>

/**
 * Klasa Neuron odpowiada neuronowi w sieci neuronowej.
 */
template <class T> class Neuron : public Input<T>, public Output<T>
{
public:
  Neuron( );
  Neuron(const Neuron& orig);
  virtual ~Neuron();
  
  /**
   * Funkcja licząca wyjście neuronu w zależności od wejsć zgodnie ze wzorem f(E(xi, yi)).
   */
  void calculateOutput();
  /**
   * Funkcja ucząca.
   * @param answer Wymagana odpowiedź dla danego neuronu.
   */
  void learn(T answer);
private:
  T output;
  std::list<T*> wages;
};

#endif	/* NEURON_H */

