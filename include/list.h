#ifndef list
#define list
#include "listnode.h"
template <typename T>
class List
{
public:
    List();
    ~List();
    const T &front();
    const T &back();
    int size();
    bool empty();
    void push_front(const T &);
    void push_back(const T &);
    void pop_front();
    void pop_back();
    void clear();
    void insert(const int, const T &);
    void erase(const T &);
    const List<T> &operator=(const List<T> &);
    const T &operator[](const int);

private:
    int len;
    Listnode<T> *head;
    Listnode<T> *tail;
};

template <typename T>
List<T>::List()
{
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
const T &List<T>::front()
{
}

template <typename T>
const T &List<T>::back()
{
}

template <typename T>
int List<T>::size()
{
    return len;
}

template <typename T>
bool List<T>::empty()
{
    if (len == 0)
        return true;
    else
        return false;
}

template <typename T>
void List<T>::push_front(const T &a)
{
}

template <typename T>
void List<T>::push_back(const T &a)
{
}

template <typename T>
void List<T>::pop_front()
{
}

template <typename T>
void List<T>::pop_back()
{
}

template <typename T>
void List<T>::clear()
{
}

template <typename T>
void List<T>::insert(const int, const T &)
{
}

template <typename T>
void List<T>::erase(const T &)
{
}
template <typename T>
const List<T> &List<T>::operator=(const List<T> &)
{
}
template <typename T>
const T &List<T>::operator[](const int)
{
}

#endif