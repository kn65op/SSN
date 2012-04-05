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
  
  //brak możliwości kopiowania.
  NeuralNetwork(const NeuralNetwork& orig) = delete;
  
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
      std::list<Neuron<T, ActivationFunction>*> *tmp = new std::list<Neuron<T, ActivationFunction>*>;
      //dodanie neuronów
      for (int n = 0; n < neurons_count[j]; n++)
      {
        tmp->push_back(new Neuron<T, ActivationFunction>);
      }
      //zapisanie warstwy
      layers.push_back(tmp);
    }
    valid = true;
  }

  /**
   * Funkcja ustawiająca funkcję aktywacji.
   * @param activationfunction Ustawiana funkcja aktywacji.
   * @throw NeuralNetwork::WrongState W przypadku, gdy nie można zmienić funkcji aktywacji w tym moemencie,
   */
  void setActivationfunction(ActivationFunction activationfunction) throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    this->activationfunction = activationfunction;
  }

  /**
   * Ustawnienie liczby wejść.
   * @param entries_count Liczba wejść ile chcemy mieć w sieci.
   * @throw NeuralNetwork::WrongState W przypadku, gdy nie można zmienić w tym momencie liczby wejść
   */
  void setEntries(int entries_count) throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    this->entries_count = entries_count;
  }

  /**
   * Ustawnienie liczby wyjść.
   * @param exits_count Liczba wyjść ile chcemy mieć w sieci.
   * @throw NeuralNetwork::WrongState W przypadku, gdy nie można zmienić w tym momencie liczby wyjść
   */
  void setExits(int exits_count) throw (WrongState)
  {
    if (valid)
    {
      throw WrongState();
    }
    this->exits_count = exits_count;
  }

  /**
   * Ustawienie liczby neuronów w danej warstwie ukrytej. Neurony warstwy wyjściowej są ustawiane zgodnie z liczbą wyjść.
   * @param layer Warstwa, której liczbę neruonów chcemy ustawić.
   * @param neurons_count Liczba neuronów, które chcemy ustawić
   * @throw NeuralNetwork::WrongState Gdy nie można w danym momencie ustawić liczby neuronów
   * @throw NeuralNetwork::WrongArgument Gdy chcemy ustawić neurony dla warstwy, która nie istnieje.
   */
  void setNeurons(int layer, int neurons_count) throw (WrongState, WrongArgument)
  {
    if (valid)
    {
      throw WrongState();
    }
    if (layer > layers_count - 1)
    {
      throw WrongArgument("Network doesn't have such number of layers");
    }
    if (layer < 1)
    {
      throw WrongArgument("You cannot set layer 0 or negative");
    }
    this->neurons_count[layer - 1] = neurons_count;
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

  /**
   * Ustawnie liczby warstw. Ustawienie 1 oznacza, że sieć posiada tylko jedną warstwę. Wyższe wartości dodają warstwy ukryte. Maksymalna liczba warstw, które można ustawić to 3.
   * @param layers_count Liczba warstw, którą chcemy ustawić
   * @throw NeuralNetwork::WrongState Gdy w danym momencie nie można ustawić liczby warstw
   * @throw NeuralNetwork::WrongArgument Gdy liczba warstw jest nieprawidłowa (np. ujemna)
   */
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
    else if (layers_count < 1)
    {
      throw WrongArgument("Network should have at least one layer");
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
  //poprawność sieci
  bool valid;

  static int max_layers_count;

};

template <class T, class ActivationFunction> int NeuralNetwork<T, ActivationFunction> ::max_layers_count = 3;

#endif	/* NEURALNETWORK_H */

