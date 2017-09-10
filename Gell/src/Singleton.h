/*
 * Singleton.h
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
public:
   static Singleton* instance() {
      static Singleton inst;
      return &inst;
   }
private:
  Singleton() {}
};

#endif /* SINGLETON_H_ */
