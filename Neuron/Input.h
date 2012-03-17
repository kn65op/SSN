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
  virtual T getValue() = 0;
private:

};

#endif	/* INPUT_H */

