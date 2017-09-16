/*
 * Singleton.h
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_
#include "Common.h"

template <typename T> class Singleton
{
	private:
		Singleton(const Singleton<T> &);
		Singleton& operator=(const Singleton<T> &);

	protected:
        static T* msSingleton;

    public:
        Singleton( void )
    	{
            assert( !msSingleton );
        }
        ~Singleton( void )
        {  assert( msSingleton );  msSingleton = 0;  }
        static T& GetSingleton( void )
		{	assert( msSingleton );  return ( *msSingleton ); }
        static T* GetSingletonPtr( void )
		{ return msSingleton; }
};

#endif /* SINGLETON_H_ */
