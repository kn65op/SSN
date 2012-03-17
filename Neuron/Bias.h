/* 
 * File:   Bias.h
 * Author: tomko
 *
 * Created on 17 marzec 2012, 14:36
 */

#ifndef BIAS_H
#define	BIAS_H

#include "Input.h"

/**
 * @class Klasa Bias odpowiada przesunięciu w sieciach neuronowych.
 */
template <class T> class Bias : public Input<T>
{
public:
  virtual ~Bias();
private:

};

#endif	/* BIAS_H */

