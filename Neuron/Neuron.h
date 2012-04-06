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
#include <random>
#include <cmath>

//TODO usunać
#include <iostream>

/**
 * Klasa Neuron odpowiada neuronowi w sieci neuronowej. Podana funkcja aktywacji jest klasą zawierającą metody: operator() za pomocą, której jest wyliczane pobudzenie neuronu oraz
 * deriterative(T x) pozwalającą na wyznaczenie pochodnej funkcji aktywacji w punkcie x (jest to niezbędne do realizacji procesu uczenia się sieci).
 * Współczynnik uczenia jest ustalony na sztywno na 0.7 (co z tym idzie aby sieć mogła się uczyć nie należy używać liczb całkowytych).
 */
template <class T, class ActivationFunction = StepActivationFunction<T>()> class Neuron : public Input<T>, public Output<T>
{
public:

  /**
   * Konstruktor domyślny z ustawieniem współczynnika uczenia z funkcją aktywacji, która jest funkcją skokową i skoku w punkcie 0. Współczynnik uczenie ustawiony jest na 0.7.
   * @param lf Współczynnik uczenia.
   */
  Neuron() : activate_function(ActivationFunction()), learn_factor(0.2)
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
   * @param fun Funkcja aktywacji.
   * 
   */
  Neuron(ActivationFunction fun) : activate_function(fun), learn_factor(0.7)
  {

  }

  /**
   * Konstruktor parametryczny z ustawieniem funkcji aktywacji i współczynnika uczenia.
   * @param fun Funkcja aktywacji.
   * @param  lf Współczynnik uczenia.
   * 
   */
  Neuron(ActivationFunction fun, T lf) : activate_function(fun), learn_factor(lf)
  {

  }

  virtual ~Neuron()
  {
    for (auto w : wages)
    {
      delete w;
    }
  }

  /**
   * Funkcja licząca wyjście neuronu w zależności od wejsć (suma ważone) a następnie przejście przez funkcję aktywacji.
   */
  void calculateOutput()
  {
    output = 0;
    typename std::list<Link<T>*>::iterator it = this->ins.begin();
    for (T* t : wages)
    {
      output += (*t) * (*it)->getValue();
      // Qstd::cout << "Waga: " << (*t) << " wartość:" << (*it)->getValue() << "\n";
      it++;
    }
    // Qstd::cout << output << "\n";
    this->input_value = activate_function(output);
    this->setValToAuts();
  }

  /**
   * Funkcja ucząca wg reguły delta. Stosowana tylko dla sieci jednowarstwowych i warstwy wyjściowej sieci wielowarstwowej.
   * @param answer Wymagana odpowiedź dla danego neuronu.
   */
  void learnDelta()
  {
    typename std::list<Link<T>*>::iterator it = this->ins.begin();
    for (auto w : wages)
    {
      *w = *w + learn_factor * (*it)->getValue() * (this->outs.front()->getAnswer()) * activate_function.deriterative(output);
      /*std::cout << learn_factor  <<"\n";**/
      //std::cout << (*it)->getValue()  << " wartość pobudzenia dla wagi" <<"\n";
      //std::cout << this->outs.front()->getAnswer() <<"odpowiedz ";
      // Qstd::cout << learn_factor * (*it)->getValue() * (this->outs.front()->getAnswer()) * activate_function.deriterative(output) << " zmiana wag ostatniego neuronu\n";

      it++;
    }
    checkWages();
  }

  /**
   * Funkcja propagująca błąd do głębszych warstw sieci.
   */
  void propagateAnswer()
  {
    //zbieranie błędu
    T error = 0;
    for (auto out : this->outs)
    {
      error += (out->getAnswer()) * activate_function.deriterative(output);
      //error += out->getAnswer();
    }
    typename std::list<T*>::iterator it = wages.begin();
    for (auto in : this->ins)
    {
      in->setAnswer(error * (**it));
      ++it;
    }
  }

  /**
   * Funkcja ucząca wg reguły Back Propagation dla warstw ukrytych.
   */
  void learnBP()
  {
    T delta = 0;
    for (auto out : this->outs)
    {
      delta += out->getAnswer() * activate_function.deriterative(output);
    }
    typename std::list<Link<T>*>::iterator it = this->ins.begin();
    for (auto w : wages)
    {
      *w = *w + learn_factor * (*it)->getValue() * (delta);
      // Qstd::cout << learn_factor * (*it)->getValue() * (delta) * activate_function.deriterative(output) << " zmiana wag neuronu\n";
      ++it;
    }
    checkWages();
  }

  void checkWages()
  {
    for (auto w : wages)
    {
      if (*w > 200)
      {
        *w = 200;
      }
      else if (*w < -200)
      {
        *w = -200;
      }
    }
  }

  /**
   * Funkcja ustawiająca połączenie wejściowe oraz dodające nową wagę.
   * @param link Połączenie do ododania.
   */
  void setLinkIn(Link<T>* link)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0);
    Output<T>::setLinkIn(link);
    wages.push_back(new T(dis(gen))); //TODO: początkowe wagi 0 lub losowe
  }

  //TODO usunąć
  /**
   * Wagi
   */
  void printWages()
  {
    for (auto w : wages)
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

