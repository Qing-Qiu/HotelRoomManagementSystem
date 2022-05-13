#ifndef list
#define list
#include "listnode.h"
#include <iostream>
#include "iterator.h"
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
    void erase(const int ,const T &);
    iterator<T> begin()
    {
        iterator it;
        it.now = head->next;
        return it;
    }
    iterator<T> end(){
        iterator it;
        it.now = tail->prev;
        return it;
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
void List<T>::insert(const int, const T &)
{
}

template <typename T>
void List<T>::erase(const int, const T &)
{
}
template <typename T>
const List<T> &List<T>::operator=(const List<T> &)
{
}
template <typename T>
const T &List<T>::operator[](const int index)
{
    
}

template <typename T>
void List<T>::display()
{
    std::cout << head->next->val << std::endl;
}
#endif