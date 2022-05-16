#ifndef ITERATOR_H
#define ITERATOR_H
#include "listnode.h"
#include "list.h"
template <typename T>
class List;
template <typename T>
class Iterator
{
public:
    Iterator() : now(nullptr) {}
    T &operator*();
    Iterator &operator++(int);
    Iterator &operator++();
    bool operator==(const Iterator &);
    bool operator!=(const Iterator &);
    friend class List<T>;

private:
    Listnode<T> *now;
};

template <typename T>
T &Iterator<T>::operator*()
{
    return now->val;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++(int)
{
    Iterator it = *this;
    ++(*this);
    return it;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    now = now->next;
    return *this;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T> &tmp)
{
    if (now == tmp.now)
        return true;
    else
        return false;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T> &tmp)
{
    if (now != tmp.now)
        return true;
    else
        return false;
}
#endif
