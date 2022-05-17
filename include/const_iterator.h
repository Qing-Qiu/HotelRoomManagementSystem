#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H
#include "list.h"
template <typename T>
class List;
template <typename T>
class IteratorC
{
public:
    IteratorC() : now(nullptr) {}
    const T &operator*() const;
    IteratorC operator++(int);
    IteratorC &operator++();
    bool operator==(const IteratorC &);
    bool operator!=(const IteratorC &);
    friend class List<T>;

protected:
    Listnode<T> *now;
};

template <typename T>
const T &IteratorC<T>::operator*() const
{
    return now->val;
}

template <typename T>
IteratorC<T> IteratorC<T>::operator++(int)
{
    IteratorC it = *this;
    ++(*this);
    return it;
}

template <typename T>
IteratorC<T> &IteratorC<T>::operator++()
{
    now = now->next;
    return *this;
}

template <typename T>
bool IteratorC<T>::operator==(const IteratorC<T> &tmp)
{
    if (now == tmp.now)
        return true;
    else
        return false;
}

template <typename T>
bool IteratorC<T>::operator!=(const IteratorC<T> &tmp)
{
    if (now != tmp.now)
        return true;
    else
        return false;
}
#endif