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
    int prepay;

public:
};
#endif