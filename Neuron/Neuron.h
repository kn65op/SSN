/* 
 * File:   Neuron.h
 * Author: tomko
 *
 * Created on 15 marzec 2012, 16:24
 */

#ifndef NEURON_H
#define	NEURON_H

#include "Input.h"
#include "Output.h"

template <class T> class Neuron : public Input<T>, public Output<T>
{
public:
  Neuron( );
  Neuron(const Neuron& orig);
  virtual ~Neuron();
private:

};

#endif	/* NEURON_H */

