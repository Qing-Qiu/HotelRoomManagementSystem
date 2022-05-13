#include "listnode.h"
template <typename T>
class iterator
{
private:
    Listnode<T> *now;

public:
    iterator() : now(NULL) {}
    const T &operator*() const;
    iterator &operator++(int);
    iterator &operator++();
    bool operator==(const iterator &);
    bool operator!=(const iterator &);
    friend class Listnode<T>;
};

template <typename T>
const T &iterator<T>::operator*() const
{
    return now->val;
}

template <typename T>
iterator<T> &iterator<T>::operator++(int)
{
    iterator it = *this;
    ++(*this);
    return it;
}

template <typename T>
iterator<T> &iterator<T>::operator++()
{
    now = now->next;
    return *this;
}

template <typename T>
bool iterator<T>::operator==(const iterator<T> &tmp)
{
    if (now == tmp.now)
        return true;
    else
        return false;
}

template <typename T>
bool iterator<T>::operator!=(const iterator<T> &)
{
    if (now != tmp.now)
        return true;
    else
        return false;
}
