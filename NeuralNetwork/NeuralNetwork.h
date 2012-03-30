/* 
 * File:   NeuralNetwork.h
 * Author: tomko
 *
 * Created on 30 marzec 2012, 19:02
 */

#ifndef NEURALNETWORK_H
#define	NEURALNETWORK_H

#include <Neuron.h>
#include <Entry.h>
#include <Exit.h>

#include <list>

/**
 * Klasa odwzorująca sieć neuronową.
 */
template <class T> class NeuralNetwork
{
public:

  NeuralNetwork()
  {
  }

  NeuralNetwork(const NeuralNetwork& orig)
  {
  }

  ~NeuralNetwork()
  {
  }
  
  
private:

  /**
   * Funkcja przetwarzająca daną warstwę.
   */
  void processLayer(std::list<Neuron<T >> &layer)
  {

  }
  //wejścia
  std::list<Entry<T>> entries;
  //wyjścia
  std::list<Exit<T>> exits;
  //warstwy neuronów (zawsze będzie 1 użyta).
  std::list<Neuron<T>> layer1;
  std::list<Neuron<T>> layer2;
  std::list<Neuron<T>> layer3;
  //dane dotyczące sieci
  int layers;
  int entries_count;
  int exits_count;
  int neurons_count_1;
  int neurons_count_2;
  int neurons_count_3;
};

#endif	/* NEURALNETWORK_H */

