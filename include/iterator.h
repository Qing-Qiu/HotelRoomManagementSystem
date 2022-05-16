#ifndef ITERATOR_H
#define ITERATOR_H
#include "listnode.h"
#include "list.h"
#include "const_iterator.h"
template <typename T>
class List;
template <typename T>
class Iterator : public IteratorC<T>
{
public:
    Iterator(){}
    T &operator*();
    Iterator &operator++(int);
    Iterator &operator++();
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
#endif
