/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <iostream>
#include <map>

class LRUCache
{
public:
    LRUCache(int capacity);
    LRUCache(const LRUCache& other);
    LRUCache &operator=(const LRUCache& other);

    void Put(int key, int value);
    int Get(int key);

private:
    struct Element
    {
        int m_key;
        int m_value;
        Element *m_next;
        Element *m_prev;

        Element() : m_key(0), m_value(0), m_next(NULL), m_prev(NULL) {}
    };

    int m_capacity;
    int m_size;
    Element *m_LRU;
    Element *m_MRU;

    std::map<int, Element> m_cache;
};


LRUCache::LRUCache(int capacity) :
    m_capacity(capacity),
    m_size(0),
    m_LRU(NULL),
    m_MRU(NULL),
    m_cache()
{}

LRUCache::LRUCache(const LRUCache& other) :
    m_capacity(other.m_capacity),
    m_size(other.m_size),
    m_LRU(other.m_LRU),
    m_MRU(other.m_MRU),
    m_cache(other.m_cache)
{}

LRUCache &LRUCache::operator=(const LRUCache& other)
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_LRU = other.m_LRU;
    m_MRU = other.m_MRU;
    m_cache = other.m_cache;

    return *this;
}

void LRUCache::Put(int key, int value)
{
    Element *e = NULL;

    std::map<int, Element>::iterator it = m_cache.find(key);
    if (it != m_cache.end())
    {
        e = &it->second;

        if (e->m_prev && e->m_next)
        {
            e->m_prev->m_next = e->m_next; 
            e->m_next->m_prev = e->m_prev;
        }
        else if (e->m_prev)
        {
            e->m_prev->m_next = e->m_next;
            m_LRU = e->m_prev;
        }
        else if (e->m_next)
        {
            e->m_next->m_prev = e->m_prev;
        }
    }
    else
    {
        if (m_size == m_capacity && m_capacity > 1)
        {
            int eraseKey = m_LRU->m_key;
            m_LRU = m_LRU->m_prev;
            m_LRU->m_next = NULL;
            m_cache.erase(eraseKey);
            --m_size;
        }

        ++m_size;

        m_cache[key].m_key = key;
        e = &m_cache[key];

        if (!m_LRU)
        {
            m_LRU = e;
        }
    }

    e->m_value = value;

    if (m_MRU != e)
    {
        e->m_next = m_MRU;
        e->m_prev = NULL;
        if (m_MRU)
        {
            m_MRU->m_prev = e;
        }
        m_MRU = e;
    }
}

int LRUCache::Get(int key)
{
    Element *e = NULL;

    std::map<int, Element>::iterator it = m_cache.find(key);
    if (it != m_cache.end())
    {
        e = &it->second;

        if (e->m_prev && e->m_next)
        {
            e->m_prev->m_next = e->m_next; 
            e->m_next->m_prev = e->m_prev;
        }
        else if (e->m_prev)
        {
            e->m_prev->m_next = e->m_next;
            m_LRU = e->m_prev;
        }
        else if (e->m_next)
        {
            e->m_next->m_prev = e->m_prev;
        }
    }
    else
    {
        return -1;
    }

    if (m_MRU != e)
    {
        e->m_next = m_MRU;
        e->m_prev = NULL;
        if (m_MRU)
        {
            m_MRU->m_prev = e;
        }
        m_MRU = e;
    }

    return e->m_value;
}

int main()
{

    return 0;
}