#ifndef GUEST_H
#define GUEST_H
#include "person.h"
#include <string>
using namespace std;
class Guest : public Person
{
private:
    string name;
    string credit_card;
    int prepay;

public:
    void reserve_add();
    void reserve_modify();
    void reserve_del();
    void checkin_add();
    void checkin_modify();
    void checkin_del();
    void checkout();
};
#endif