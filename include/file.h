#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "adminlist.h"
#include "admin.h"
class File
{
public:
    Adminlist get_admin_data();
};

Adminlist File::get_admin_data()
{
    ifstream fin;
    string user, pwd;
    Adminlist adminlist;
    fin.open("../data/admindata.txt");
    for (int i = 1; i <= 10; i++) {
        fin >> user >> pwd;
        Admin admin;
        admin.set_username(user);
        admin.set_password(pwd);
        adminlist.push_back(admin);
    }
    fin.close();
    return adminlist;
}
#endif