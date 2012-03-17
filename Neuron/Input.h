/* 
 * File:   Input.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:04
 */

#ifndef INPUT_H
#define	INPUT_H

template <class T> class Input
{
public:
  virtual ~Input();
  virtual T getValue() = 0;
private:

};

#endif	/* INPUT_H */

