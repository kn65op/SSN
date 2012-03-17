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

#include <iostream>
/**
 * Klasa Neuron odpowiada neuronowi w sieci neuronowej.
 */
template <class T> class Neuron : public Input<T>, public Output<T>
{
public:
  Neuron()
  {
    
  }
  Neuron(const Neuron& orig)
  {
    
  }
  virtual ~Neuron()
  {
    for (auto w: wages)
    {
      delete w;
    }
  }

  /**
   * Funkcja licząca wyjście neuronu w zależności od wejsć zgodnie ze wzorem f(E(xi, yi)).
   */
  void calculateOutput()
  {
    output = 0;
    typename std::list<Link<T>*>::iterator it = this->ins.begin();
    for (T* t : wages)
    {
     // std::cout << (*t) << " " << (*it)->getValue() << "\n";
      output += (*t) * (*it)->getValue();
      it++;
    }
    this->input_value = output;
    this->setValToAuts();
  }
  /**
   * Funkcja ucząca.
   * @param answer Wymagana odpowiedź dla danego neuronu.
   */
  void learn(T answer)
  {
    
  }
  /**
   * Funkcja ustawiająca połączenie wejściowe oraz dodające nową wagę.
   * @param link Połączenie do ododania.
   */
  void setLinkIn(Link<T>* link)
  {
    Output<T>::setLinkIn(link);
    wages.push_back(new T(1)); //TODO: początkowe wagi
  }
private:
  T output;
  std::list<T*> wages;
};

#endif	/* NEURON_H */

