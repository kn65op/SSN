/* 
 * File:   Output.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 12:11
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

template <class T> class Output
{
public:
  virtual ~Output();
  virtual void setValue(T) = 0;
private:

};

#endif	/* OUTPUT_H */

