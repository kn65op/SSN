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
#include "StepActivationFunction.h"

#include <list>

#include <iostream>
/**
 * Klasa Neuron odpowiada neuronowi w sieci neuronowej. Podana funkcja aktywacji jest klasą zawierającą metody: operator() za pomocą, której jest wyliczane pobudzenie neuronu [nieaktualne]oraz
 * deriterative(T x) pozwalającą na wyznaczenie pochodnej funkcji aktywacji w punkcie x (jest to niezbędne do realizacji procesu uczenia się sieci)[/nieaktualne].
 * Współczynnik uczenia jest ustalony na sztywno na 0.7 (co z tym idzie aby sieć mogła się uczyć nie należy używać liczb całkowytych).
 */
template <class T, class ActivationFunction = StepActivationFunction<T>()> class Neuron : public Input<T>, public Output<T>
{
public:
  /**
   * Konstruktor domyślny z ustawieniem współczynnika uczenia z funkcją aktywacji, która jest funkcją skokową i skoku w punkcie 0. Współczynnik uczenie ustawiony jest na 0.7.
   * @param lf Współczynnik uczenia.
   */
  Neuron() : activate_function(ActivationFunction()), learn_factor(0.7)
  {
    
  }
  /**
   * Konstruktor parametryczny z ustawieniem współczynnika uczenia  oraz z funkcją aktywacji, która jest funkcją skokową i skoku w punkcie 0.
   * @param lf Współczynnik uczenia.
   */
  Neuron(T lf) : activate_function(ActivationFunction()), learn_factor(lf)
  {
    
  }
  /**
   * Konstruktor parametryczny z ustawieniem funkcji aktywacji. Jako współczynnik uczenia ustawione jest 0.7.
   * @param fun
   * 
   */
  Neuron(ActivationFunction fun) : activate_function(fun), learn_factor(0.7)
  {
    
  }
  /**
   * Konstruktor parametryczny z ustawieniem funkcji aktywacji i współczynnika uczenia.
   * @param fun
   * 
   */
  Neuron(ActivationFunction fun, T lf) : activate_function(fun), learn_factor(lf)
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
      output += (*t) * (*it)->getValue();
      //std::cout << "Waga: " << (*t) << " wartość:" << (*it)->getValue() << " ";
      it++;
    }
    //std::cout << output << "\n";
    this->input_value = activate_function(output);
    this->setValToAuts();
  }
  /**
   * Funkcja ucząca wg reguły delta. Stosowana tylko dla sieci jednowarstwowych.
   * @param answer Wymagana odpowiedź dla danego neuronu.
   */
  void learnDelta(T answer)
  {
    typename std::list<Link<T>*>::iterator it = this->ins.begin();
    for (auto w: wages)
    {
      *w = *w + learn_factor * (*it)->getValue() * (answer - this->input_value);
      /*std::cout << learn_factor  <<"\n";
      std::cout << (*it)->getValue()  <<"\n";
      std::cout << (answer - output) <<"\n";
      std::cout << learn_factor * (*it)->getValue() * (answer - output) <<"\n\n";*/
    }
  }
  /**
   * Funkcja ustawiająca połączenie wejściowe oraz dodające nową wagę.
   * @param link Połączenie do ododania.
   */
  void setLinkIn(Link<T>* link)
  {
    Output<T>::setLinkIn(link);
    wages.push_back(new T(1)); //TODO: początkowe wagi 0 lub losowe
  }
  /***/
  void printWages()
  {
    for (auto w: wages)
    {
      std::cout << *w << " ";
    }
    std::cout << "that was wages!\n";
  }
private:
  T output;
  std::list<T*> wages; //THINK: Może zmienić na samo T
  ActivationFunction activate_function;
  T learn_factor;
};

#endif	/* NEURON_H */

