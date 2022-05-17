#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "iterator.h"
#include "const_iterator.h"
template <typename T>
class IteratorC;
template <typename T>
class Iterator;
template <typename T>
class List
{
public:
    List();
    ~List();
    List(const List<T> &);
    const T &front();
    const T &back();
    int size();
    bool empty();
    void push_front(const T &);
    void push_back(const T &);
    void pop_front();
    void pop_back();
    void clear();
    void insert(Iterator<T>, const T &);
    void remove(const T &);
    IteratorC<T> begin() const
    {
        IteratorC<T> it;
        it.now = head->next;
        return it;
    }
    IteratorC<T> end() const
    {
        IteratorC<T> it;
        it.now = tail;
        return it;
    }
    Iterator<T> begin()
    {
        Iterator<T> it;
        it.now = head->next;
        return it;
    }
    Iterator<T> end()
    {
        Iterator<T> it;
        it.now = tail;
        return it;
    }
    Iterator<T> erase(Iterator<T> it)
    {
        if (!empty() && it != end())
        {
            Listnode<T> *tmp = it.now;
            Listnode<T> *p = tmp;
            tmp->prev->next = tmp->next;
            tmp = tmp->next;
            delete p;
            Iterator<T> res;
            res.now = tmp;
            len--;
            return res;
        }
    }
    const List<T> &operator=(const List<T> &);
    const T &operator[](const int);
    void display();

private:
    int len;
    Listnode<T> *head;
    Listnode<T> *tail;
};

template <typename T>
List<T>::List() : head(new Listnode<T>()), tail(new Listnode<T>()), len(0)
{
    tail->prev = head;
    head->next = tail;
}

template <typename T>
List<T>::List(const List<T> &rhs) : head(new Listnode<T>()), tail(new Listnode<T>()), len(0)
{
    tail->prev = head;
    head->next = tail;
    for (IteratorC<T> it = rhs.begin(); it != rhs.end(); ++it)
        push_back(*it);
}

template <typename T>
List<T>::~List()
{
    clear();
    delete head;
    delete tail;
}

template <typename T>
const T &List<T>::front()
{
    if (!empty())
        return head->next->val;
}

template <typename T>
const T &List<T>::back()
{
    if (!empty())
        return tail->prev->val;
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
void List<T>::push_front(const T &elem)
{
    Listnode<T> *tmp = new Listnode<T>(elem);
    tmp->prev = head;
    head->next->prev = tmp;
    tmp->next = head->next;
    head->next = tmp;
    len++;
}

template <typename T>
void List<T>::push_back(const T &elem)
{
    Listnode<T> *tmp = new Listnode<T>(elem);
    tmp->next = tail;
    tail->prev->next = tmp;
    tmp->prev = tail->prev;
    tail->prev = tmp;
    len++;
}

template <typename T>
void List<T>::pop_front()
{
    if (empty())
        return;
    Listnode<T> *tmp = head->next;
    tmp->next->prev = head;
    head->next = tmp->next;
    delete tmp;
    len--;
}

template <typename T>
void List<T>::pop_back()
{
    if (empty())
        return;
    Listnode<T> *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    delete tmp;
    len--;
}

template <typename T>
void List<T>::clear()
{
    while (!empty())
        pop_back();
}

template <typename T>
void List<T>::insert(Iterator<T> it, const T &elem)
{
    Listnode<T> *tmp = it->now;
    Listnode<T> *p = new Listnode<T>(elem);
    tmp->prev->next = p;
    p->next = tmp;
    p->prev = tmp->prev;
    tmp->prev = p;
    len++;
}

template <typename T>
void List<T>::remove(const T &elem)
{
    if (empty())
        return;
    Listnode<T> *tmp = head->next;
    while (tmp != tail)
    {
        if (tmp->val == elem)
        {
            Listnode<T> *p = tmp;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp = tmp->next;
            delete p;
            p = nullptr;
            len--;
        }
        else
            tmp = tmp->next;
    }
}

template <typename T>
const List<T> &List<T>::operator=(const List<T> &rhs)
{
    if (this == &rhs)
        return *this;
    clear();
    for (IteratorC<T> it = rhs.begin(); it != rhs.end(); ++it)
        push_back(*it);
    return *this;
}
template <typename T>
const T &List<T>::operator[](const int index)
{
    if (index <= len)
    {
        Iterator<T> it = begin();
        int cnt = index;
        while (cnt--)
        {
            if (cnt == 0)
                break;
            it++;
        }
        return *it;
    }
}

template <typename T>
void List<T>::display()
{
    std::cout << *begin() << endl;
    for (IteratorC<T> it = begin(); it != end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

#endif