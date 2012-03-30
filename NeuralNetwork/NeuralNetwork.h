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
#include <ActivationFunction.h>

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

  /**
   * Funkcja tworząca siec z podanych parametrów.
   */
  void init()
  {
    //TODO: dopisać
  }
  
  void setActivation_function(ActivationFunction<T> activation_function)
  {
    this->activation_function = activation_function;
  }

  void setEntries_count(int entries_count)
  {
    this->entries_count = entries_count;
  }

  void setExits_count(int exits_count)
  {
    this->exits_count = exits_count;
  }

  void setLayers(int layers)
  {
    this->layers = layers;
  }

  void setNeurons_count_1(int neurons_count_1)
  {
    this->neurons_count_1 = neurons_count_1;
  }

  void setNeurons_count_2(int neurons_count_2)
  {
    this->neurons_count_2 = neurons_count_2;
  }

  void setNeurons_count_3(int neurons_count_3)
  {
    this->neurons_count_3 = neurons_count_3;
  }

  void setInput()
  {
    //TODO: dopisać
  }
  
  void calcOutput()
  {
    //TODO: dopisać
  }
  
  void learn()
  {
    //TODO: dopisać
  }
private:

  /**
   * Funkcja przetwarzająca daną warstwę.
   * @param layer warstwa do przetworzenia.
   */
  void processLayer(std::list<Neuron<T >> &layer)
  {
    //TODO: dopisać   
  }
  /**
   * Funkcja czyszcząca sieć.
   */
  void clearNetwork()
  {
    //TODO: dopisać
  }
  //wejścia
  std::list<Entry<T >> entries;
  //wyjścia
  std::list<Exit<T >> exits;
  //warstwy neuronów (zawsze będzie 1 użyta).
  std::list<Neuron<T >> layer1;
  std::list<Neuron<T >> layer2;
  std::list<Neuron<T >> layer3;
  //dane dotyczące sieci
  int layers;
  int entries_count;
  int exits_count;
  int neurons_count_1;
  int neurons_count_2;
  int neurons_count_3;
  ActivationFunction<T> activation_function;
};

#endif	/* NEURALNETWORK_H */

