#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include<string>
using namespace std;
class Admin : public Person
{
    private:
        string username;
        string password;
    public:
        bool login();
        void modify_price();
};

bool Admin::login()
{
    return true;
}
#endif