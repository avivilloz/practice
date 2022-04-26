#ifndef SINGLETON_HPP
#define SINGLETON_HPP

namespace design_pattern
{

template<class T>
class Singleton
{
public:
    static T *GetInstance();
    static void ReleaseInstance();

private:
    static T *ms_poInstance;
    static unsigned long int ms_nCounter;

    Singleton();
    ~Singleton();
};

#include "singleton_impl.hpp"

}


#endif // SINGLETON_HPP