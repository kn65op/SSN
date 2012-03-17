/* 
 * File:   Neuron.cpp
 * Author: tomko
 * 
 * Created on 15 marzec 2012, 16:24
 */

#include "Neuron.h"

#include "Link.h"

template <class T> Neuron<T>::Neuron()
{
}

template <class T> Neuron<T>::Neuron(const Neuron& orig)
{
}

template <class T> Neuron<T>::~Neuron()
{
}

template <class T> void Neuron<T>::calculateOutput()
{
  output = 0;
  typename std::list<Link<T>*>::iterator it = this->ins.begin();
  for (T t : wages)
  {
    output += wages * it->getValue();
    it++;
  }
}