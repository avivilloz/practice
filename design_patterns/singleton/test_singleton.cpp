/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <iostream>
#include "singleton.hpp"
#include <vector>

using namespace design_pattern;

class X
{
public:
    void Init(int instance)
    {
        m_instance = instance;
    }

    void PrintInstance()
    {
        std::cout << m_instance << std::endl;
    }

private:
    int m_instance;

    friend class Singleton<X>;
    X() : m_instance(0)
    {
        std::cout << "X::X" << std::endl;
    }

    ~X()
    {
        std::cout << "X::~X" << std::endl;
    }
};

int main()
{
    std::vector<X*> xses;

    for (int i = 0; i < 20 ; ++i)
    {
        xses.push_back(Singleton<X>::GetInstance());
        xses[i]->Init(i);
        xses[i]->PrintInstance();
    }

    std::cout << "----------------------------------" << std::endl;

    for (int i = 0; i < 20 ; ++i)
    {
        xses[i]->PrintInstance();
        Singleton<X>::ReleaseInstance();
    }

    return 0;
}
