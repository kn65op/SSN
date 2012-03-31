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

  class WrongArgument
  {
  public:

    WrongArgument(std::string m) : message(m)
    {
    }

    std::string GetMessage() const
    {
      return message;
    }
    

  private:
    std::string message;
  };

  class WrongState
  {
    
  };
  NeuralNetwork()
  {
    valid = false;
  }
  
  ~NeuralNetwork()
  {
    clearNetwork();
  }

  /**
   * Funkcja zatrzymująca działanie sieci, dzięki czemu można zmienić parametry sieci.
   */
  void stop() throw(WrongState)
  {
    if (!valid)
    {
      throw WrongState;
    }
    clearNetwork();
  }

  /**
   * Funkcja tworząca siec z podanych parametrów. Pozwala na wykorzystanie sieci.
   */
  void init()
  {
    if (valid)
    {
      throw WrongState;
    }
    for (int i = 0; i < entries_count; i++)
    {
      entries.push_back(new Entry<T > ());
    }
    for (int i = 0; i < exits_count; i++)
    {
      exits.push_back(new Exit<T > ());
    }
    for (int j = 0; j < layers_count; j++)
    {
      layers.push_back(new std::list<Neron<T>*>())
    }
    //TODO: dopisać
  }

  void setActivation_function(ActivationFunction<T> activation_function)
  {
    if (valid)
    {
      throw WrongState;
    }
    this->activation_function = activation_function;
  }

  void setEntries(int entries_count)
  {
    if (valid)
    {
      throw WrongState;
    }
    this->entries_count = entries_count;
  }

  void setExits(int exits_count)
  {
    if (valid)
    {
      throw WrongState;
    }
    this->exits_count = exits_count;
  }

  void setNeurons(int layer, int neurons_count) throw (WrongArgument)
  {
    if (valid)
    {
      throw WrongState;
    }
    if (layer > layers_count)
    {
      throw WrongArgument("Network doesn't have such number of layers");
    }
    if (layer < 1)
    {
      throw WrongArgument("You cannot set layer 0 or negative");
    }
    //this->neurons_count_1 = neurons_count_1;
    //TODO: dopisać kod
  }

  void setInput()
  {
    if (!valid)
    {
      throw WrongState;
    }
    //TODO: dopisać
  }

  void calcOutput()
  {
    if (!valid)
    {
      throw WrongState;
    }
    //TODO: dopisać
  }

  void learn()
  {
    if (!valid)
    {
      throw WrongState;
    }
    //TODO: dopisać
  }

  void setLayers_count(int layers_count)
  {
    if (valid)
    {
      throw WrongState;
    }
    this->layers_count = layers_count;

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
    for (auto tmp : entries)
    {
      delete tmp;
    }
    for (auto tmp : exits)
    {
      delete tmp;
    }
    for (auto tmp : layers)
    {
      for (auto n : *tmp)
      {
        delete n;
      }
      delete tmp;
    }
    for (auto tmp : links)
    {
      delete tmp;
    }
    entries.clear();
    exits.clear();
    layers.clear();
    links.clear();
    //TODO: dopisać
  }
  //wejścia
  std::list<Entry<T >*> entries;
  //wyjścia
  std::list<Exit<T >*> exits;
  //warstwy neuronów (zawsze będzie 1 użyta).
  std::vector<std::list<Neuron<T >*>*> layers;
  //łącza
  std::list<Link<T>*> links;
  //dane dotyczące sieci
  int layers_count;
  int entries_count;
  int exits_count;
  std::vector<int> neurons_count;
  ActivationFunction<T> activation_function;
  bool valid;
  
  NeuralNetwork(const NeuralNetwork& orig)
  {
  }

};

#endif	/* NEURALNETWORK_H */

