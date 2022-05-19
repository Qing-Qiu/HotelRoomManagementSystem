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
    Iterator() {}
    T &operator*();
    const T &operator*() const;
    Iterator &operator++();
    Iterator operator++(int);
    Iterator &operator--();
    Iterator operator--(int);
    friend class List<T>;
};

template <typename T>
T &Iterator<T>::operator*()
{
    return IteratorC<T>::now->val;
}

template <typename T>
const T &Iterator<T>::operator*() const
{
    return IteratorC<T>::operator*();
}

template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    IteratorC<T>::now = IteratorC<T>::now->next;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator it = *this;
    ++(*this);
    return it;
}

template <typename T>
Iterator<T> &Iterator<T>::operator--()
{
    IteratorC<T>::now = IteratorC<T>::now->prev;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator it = *this;
    --(*this);
    return it;
}
#endif
