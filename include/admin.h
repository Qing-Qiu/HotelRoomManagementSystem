#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "adminlist.h"
#include <string>
#include <iostream>
using namespace std;
class Admin : public Person
{
private:
    string username;
    string password;

public:
    void set_username(string);
    void set_password(string);
    string get_username();
    string get_password();
};

void Admin::set_username(string user)
{
    username = user;
}

void Admin::set_password(string pwd)
{
    password = pwd;
}

string Admin::get_username()
{
    return username;
}

string Admin::get_password()
{
    return password;
}
#endif