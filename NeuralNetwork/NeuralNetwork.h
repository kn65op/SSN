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
#include <Bias.h>

#include <list>

/**
 * Klasa odwzorująca sieć neuronową. Najpierw należy ustawić parametry sieci, a następnie uruchomić sieć. Jeśli wystąpi konieczność zmiany parametrów to należy zatrzymać sieć.
 */
template <class T, class ActivationFunction> class NeuralNetwork
{
public:

  /**
   * Klasa wyjątku w sytuacji, gdy podany argument do funkcji jest niezgodny z aktualnie ustawionymi parametrami sieci (np. ustawienie ilości nuronów w 3 warstwie, jeśli sieć posiada 2 warstwy)
   */
  class WrongArgument
  {
  public:

    /**
     * Konstrutkor z ustawieniem wiadomości.
     * @param m Wiadomość do ustawienia.
     */
    WrongArgument(std::string m) : message(m)
    {
    }

    /**
     * Pobranie wiadomości przekazywanej przez wyjątek.
     * @return Wiadomość przekazana przez wyjątek.
     */
    std::string GetMessage() const
    {
      return message;
    }


  private:
    std::string message;
  };

  /**
   * Klasa wyjątku w sytuacji, gdy próbujemy operować na sieci w sytuacji gdy jest to niemożliwe (np. zmienić parametry w momencie gdy sieć działa).
   */
  class WrongState
  {
  };

  /**
   * Kontruktor domyślny, tworzy prostą sieć z jednym wejściem i jednym wyjściem.
   */
  NeuralNetwork()
  {
    valid = false;
    //początkowe wartości
    exits_count = entries_count = 1;
    setLayersCount(1);
    setEntries(1);
    setExits(1);
  }

  /**
   * Destruktor, czyści sieć.
   */
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
    //zapisanie liczby wyjść jako liczby neuronów ostatniej warstwy
    neurons_count[layers_count - 1] = exits_count;
    //stworzenie wejsć
    for (int i = 0; i < entries_count; ++i)
    {
      entries.push_back(new Entry<T > ());
    }
    //stworzenie wyjść
    for (int i = 0; i < exits_count; ++i)
    {
      exits.push_back(new Exit<T > ());
    }
    //stworzenie warstw i biasów
    layers.reserve(layers_count);
    for (int j = 0; j < layers_count; ++j)
    {
      std::list<Neuron<T, ActivationFunction>*> *tmp = new std::list<Neuron<T, ActivationFunction>*>;
      //dodanie neuronów
      for (int n = 0; n < neurons_count[j]; ++n)
      {
        tmp->push_back(new Neuron<T, ActivationFunction>);
      }
      //zapisanie warstwy
      layers.push_back(tmp);
      biases.push_back(new Bias<T > (1));
    }
    //tworzenie linków, inaczej się tworzy dla warstw ukrytych, a inaczej dla braku warstw ukryty, layers_count == 1 oznacza, że brak warstw ukrytych
    int links_count = 0;
    Link<T>* tmp;

    //połączenie wejść z pierwszą warstwą
    for (auto n : *(layers[0])) // n -wskaźnik do listy z warstwą 1 
    {
      for (auto e : entries) // e - wskaźnik do wejścia
      {
        tmp = new Link<T > ();
        e->setLinkOut(tmp);
        n->setLinkIn(tmp);
        links.push_back(tmp);
      }
      //dodanie bias
      tmp = new Link<T > ();
      biases[0]->setLinkOut(tmp);
      n->setLinkIn(tmp);
      links.push_back(tmp);
    }

    //połączenie kolejnych warstw
    for (int i = 1; i < layers_count; ++i)
    {
      for (auto n2 : *(layers[i])) // n2 - wskaźnik do neuronu warstwy wyższej
      {
        for (auto n1 : *(layers[i - 1])) // n1 - wskaźnik do neuronu warstwy niższej
        {
          tmp = new Link<T > ();
          n1->setLinkOut(tmp);
          n2->setLinkIn(tmp);
          links.push_back(tmp);
        }
        //dodanie bias
        tmp = new Link<T > ();
        biases[i]->setLinkOut(tmp);
        n2->setLinkIn(tmp);
        links.push_back(tmp);
      }
    }

    //połączenie wartswy wyjściowej z wyjściami
    typename std::list<Neuron<T, ActivationFunction>*>::iterator it = layers[layers_count - 1]->begin();
    for (auto e : exits) //e - wskaźnik do wyjścia
    {
      tmp = new Link<T > ();
      (*it)->setLinkOut(tmp);
      e->setLinkIn(tmp);
      links.push_back(tmp);
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

  /**
   * Funkcja ustawiająca wejście. Przyjmuje jako argumenty dwa iteratory, do pierwszego elementu wejścia oraz do pierwszego za ostatnim elementem wejścia. Jeśli liczba elementów wejściowych jest
   * dłuższa niż liczba wejść, to elementy po skończeniu wejścia są ignorowane.
   * @param start Interator wskazujący na pierwszy element.
   * @param end Iterator wskazujący na element za ostatnim
   * @throw NeuralNetwork::WrognState W przypadku, gdy nie można ustawić wejścia
   * @throw NeuralNetwork::WrognArgument W przypadku, gdy zostanie podanych za mało elementów wejściowych.
   */
  template <class InputIterator> void setInput(InputIterator start, InputIterator end) throw (WrongState, WrongArgument)
  {
    if (!valid)
    {
      throw WrongState();
    }
    for (auto e : entries) //e - wskaźnik  na wejście
    {
      e->setEntry(*start);
      start++;
      if (start == end)
      {
        throw (WrongArgument("Size of input is smaller then input of network"));
      }
    }
  }

  /**
   * Funkcja licząca odpowiedź sieci na zadane wcześniej wejście.
   * @throw NeuralNetwork::WrongState W przypadku, gdy nie można wyliczyć odpowiedzi
   * @return Wektor wartości wyjściowych.
   */
  std::vector<T> calcOutput() throw (WrongState)
  {
    if (!valid)
    {
      throw WrongState();
    }
    for (auto b : biases) // b - wskaźnik do biasu
    {
      b->sendBiasToLinks();
    }
    for (auto l : layers) //l - wskaźnik na listę neuronów
    {
      for (auto a : *l) //a -  wskaźnik  na neuron
      {
        a->calculateOutput();
      }
    }
    std::vector<T> tmp(exits_count);
    int i = 0;
    for (auto e : exits) // e - wksaźnik na Exit
    {
      tmp[i++] = e->getExit();
    }
    return tmp;
  }

  /**
   * Funkcja ucząca sieć. Jako argumenty podawana jest odpowiedź oczekiwana w postaci pary iteratorów: pierwszy i pierwszy za ostatnim.
   * Jeśli podana odpowiedź jest większa niż ilość wyjść, to ostatnie elementy odpowiedzi są ignorowane.
   * @param start Iterator do pierwszego składnika odpowiedzi.
   * @param end Iterator do pierwszego elementu za ostatnim składnikiem odpowiedzi.
   * @throw NeuralNetwork::WrongState W przypadku, gdy nie jest możliwe w danenym momencie uczenie sieci.
   * @throw NeuralNetwork::WrongArgument W przypadku, gdy podana odpowiedź jest za mała.
   */
  template <class InputIterator> void learn(InputIterator start, InputIterator end) throw (WrongState, WrongArgument)
  {
    if (!valid)
    {
      throw WrongState();
    }
    //przekazanie odpowiedzi na wyjścia.
    for (auto e : exits) //e - wskaźnik do exit
    {
      if (start == end)
      {
        throw (WrongArgument("Size of the answer is too small."));
      }
      e->learn(*(start++));
    }
    //przekazywanie odpowiedzi do warst ukrytych (jeśli są)
    for (int i = layers_count - 1; i != 0; --i)
    {
      for (auto n : *(layers[i])) //n - wskaźnik do neuronu
      {
        n->propagateAnswer();
      }
    }
    //uczenie warstwy najwyższej
    for (auto n : *(layers[layers_count - 1])) // n - wskaźnik do neuronu
    {
      n->learnDelta();
    }
    //uczenie niższych warstw
    for (int i = layers_count - 2; i >= 0; --i)
    {
      for (auto n : *(layers[i])) //n - wskaźnik do neuronu
      {
        n->learnBP();
      }
    }
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
   * Funkcja przetwarzająca daną warstwę. Na razie nieużywane.
   * @param layer warstwa do przetworzenia.
   */
  void processLayer(std::list<Neuron<T >> &layer)
  {
    //LATER: dopisać   
  }

  /**
   * Funkcja czyszcząca sieć.
   */
  void clearNetwork()
  {
    //    std::cout << entries.size() << " " << exits.size() << " " << layers.size() << " " << links.size() << " \n";
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
  }
  //wejścia
  std::list<Entry<T >*> entries;
  //wyjścia
  std::list<Exit<T >*> exits;
  //warstwy neuronów (zawsze będzie 1 użyta).
  std::vector<std::list<Neuron<T, ActivationFunction >*>*> layers;
  //bias
  std::vector<Bias<T>*> biases;
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

