#include "singleton.hpp"

template<class T>
T *Singleton<T>::ms_poInstance = NULL;

template<class T>
unsigned long int Singleton<T>::ms_nCounter = 0;

template<class T>
Singleton<T>::Singleton()
{}

template<class T>
Singleton<T>::~Singleton()
{}

template<class T>
T *Singleton<T>::GetInstance()
{
    // std::cout << "Get Instance" << std::endl;
    // mutex lock
    if (!ms_nCounter)
    {
        ms_poInstance = new T;
    }

    ++ms_nCounter;

    // std::cout << "Get Instance before return" << std::endl;
    return ms_poInstance;
}

template<class T>
void Singleton<T>::ReleaseInstance()
{
    // mutex lock
    --ms_nCounter;

    if (!ms_nCounter && NULL != ms_poInstance)
    {
        delete ms_poInstance;
    }
}