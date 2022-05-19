#ifndef GUEST_H
#define GUEST_H
#include "person.h"
#include <string>
using namespace std;
class Guest : public Person
{
private:
    string name;
    string id;
    int cost;

public:
    class Book
    {
    public:
        void add();
        void modify();
        void del();
    } book;
    class Checkin
    {
    public:
        void add();
        void modify();
        void del();
    } checkin;
    class Checkout
    {
    public:
        void checkout();
    } checkout;
};

void Guest::Book::add()
{

}

void Guest::Book::modify()
{

}

void Guest::Book::del()
{

}

void Guest::Checkin::add()
{

}

void Guest::Checkin::modify()
{

}

void Guest::Checkin::del()
{
    
}

void Guest::Checkout::checkout()
{

}

#endif