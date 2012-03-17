/* 
 * File:   Entry.cpp
 * Author: tomko
 * 
 * Created on 17 marzec 2012, 12:23
 */

#include "Entry.h"

template <class T> Entry<T>::Entry()
{
}

template <class T> Entry<T>::Entry(const Entry& orig)
{
}

template <class T> Entry<T>::~Entry()
{
}

template <class T> T Entry<T>::getValue()
{
  return value;
}