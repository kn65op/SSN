/* 
 * File:   Input.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:04
 */

#ifndef INPUT_H
#define	INPUT_H

/**
 * @class Klasa Input jest interfejsem wejścia do klasy Link.
 */
template <class T> class Input
{
public:
  virtual ~Input();
  /**
   * Funkcja zwracająca przechowywaną wartość do połączeń.
   * @return Przechowywana wartość.
   */
  virtual T getValue() const
  {
    return input_value;
  }
protected:
  T input_value;
};

#endif	/* INPUT_H */

