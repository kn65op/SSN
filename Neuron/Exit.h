/* 
 * File:   Exit.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:24
 */

#ifndef EXIT_H
#define	EXIT_H

#include "Output.h"

/**
 * Klasa Exit odpowiada wyjściom z sieci neuronowej
 */
template <class T> class Exit: public Output<T>
{
public:
  Exit();
  Exit(const Exit& orig);
  virtual ~Exit();
  /**
   * Funkcja zwracająca wyjście.
   * @return Wyjście.
   */
  T getExit() const
  {
    return this->output_value;
  }
};

#endif	/* EXIT_H */

