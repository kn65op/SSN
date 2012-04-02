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
#include <Link.h>
#include <Helper.h>

#include <list>

/**
 * Klasa odwzorująca sieć neuronową.
 */
template <class T, class ActivationFunction> class NeuralNetwork
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
    //początkowe wartości
    exits_count = entries_count = 1;
    setLayersCount(1);
    setNeurons(1, 1);
  }

  ~NeuralNetwork()
  {
    clearNetwork();
  }

  /**
   * Funkcja zatrzymująca działanie sieci, dzięki czemu można zmienić parametry sieci.
   */
  void stop() throw (WrongState)
  {
    if (!valid)
    {
      throw WrongState();
    }
    clearNetwork();
    valid = false;
  }

  /**
   * Funkcja tworząca siec z podanych parametrów. Pozwala na wykorzystanie sieci.
   */
  void init() throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    //stworzenie wejsć
    for (int i = 0; i < entries_count; i++)
    {
      entries.push_back(new Entry<T > ());
    }
    //stworzenie wyjść
    for (int i = 0; i < exits_count; i++)
    {
      exits.push_back(new Exit<T > ());
    }
    //stworzenie warstw
    for (int j = 0; j < layers_count; j++)
    {
      layers.push_back(new std::list<Neuron<T, ActivationFunction>*>);
      //dodanie neuronów
    }
    //TODO: dopisać
    valid = true;
  }

  void setActivationfunction(ActivationFunction activationfunction) throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    this->activationfunction = activationfunction;
  }

  void setEntries(int entries_count) throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    this->entries_count = entries_count;
  }

  void setExits(int exits_count) throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    this->exits_count = exits_count;
  }

  void setNeurons(int layer, int neurons_count) throw (WrongArgument)
  {
    if (valid)
    {
      throw WrongState();
    }
    if (layer > layers_count)
    {
      throw WrongArgument("Network doesn't have such number of layers");
    }
    if (layer < 1)
    {
      throw WrongArgument("You cannot set layer 0 or negative");
    }
    //TODO: dopisać kod
  }

  void setInput() throw (WrongState)
  {
    if (!valid)
    {
      throw WrongState();
    }
    //TODO: dopisać
  }

  void calcOutput() throw (WrongState)
  {
    if (!valid)
    {
      throw WrongState();
    }
    //TODO: dopisać
  }

  void learn() throw (WrongState)
  {
    if (!valid)
    {
      throw WrongState();
    }
    //TODO: dopisać
  }

  void setLayersCount(int layers_count) throw (WrongState, WrongArgument)
  {
    if (valid)
    {
      throw WrongState();
    }
    if (layers_count > max_layers_count)
    {
      throw WrongArgument("Liczba warstw nie może być większa od ustalonej wartości: " + Helper::intToString(max_layers_count) + ".");
    }

    this->layers_count = layers_count;
    neurons_count.resize(layers_count);
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
  std::vector<std::list<Neuron<T, ActivationFunction >*>*> layers;
  //łącza
  std::list<Link<T>*> links;
  //dane dotyczące sieci
  int layers_count;
  int entries_count;
  int exits_count;
  std::vector<int> neurons_count;
  ActivationFunction activationfunction;
  bool valid;

  static int max_layers_count;

  NeuralNetwork(const NeuralNetwork& orig)
  {
  }

};

template <class T, class ActivationFunction> int NeuralNetwork<T, ActivationFunction> ::max_layers_count = 3;

#endif	/* NEURALNETWORK_H */

