/* 
 * File:   Exit.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:24
 */

#ifndef EXIT_H
#define	EXIT_H

#include "Output.h"


//TODO usunąć
#include <iostream>

/**
 * Klasa Exit odpowiada wyjściom z sieci neuronowej
 */
template <class T> class Exit : public Output<T>
{
public:

  virtual ~Exit()
  {

  }

  /**
   * Funkcja zwracająca wyjście.
   * @return Wyjście.
   */
  T getExit() const
  {
    //std::cout << this->ins.front()->getValue() << " exit\n";
    return this->ins.front()->getValue();
  }

  /**
   * Funkcja rozpoczynająca uczenienie z tego wyjścia sieci.
   * @param answer Żądana odpowiedź.
   */
  void learn(T answer) const
  {
    for (auto link : this->ins)
    {
      link->setAnswer(answer - this->ins.front()->getValue());
    }
  }
};

#endif	/* EXIT_H */

