#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "adminlist.h"
#include "admin.h"
#include "roomlist.h"
#include "room.h"
class File
{
public:
    Adminlist get_admin_data();
    Roomlist get_room_data();
};

Adminlist File::get_admin_data()
{
    ifstream fin;
    string user, pwd;
    Adminlist adminlist;
    fin.open("../data/admindata.txt");
    for (int i = 1; i <= 10; i++)
    {
        fin >> user >> pwd;
        Admin admin;
        admin.set_username(user);
        admin.set_password(pwd);
        adminlist.push_back(admin);
    }
    fin.close();
    return adminlist;
}

Roomlist File::get_room_data()
{
    ifstream fin;
    int number;
    string type;
    int price;
    char status;
    Roomlist roomlist;
    fin.open("../data/roomdata.txt");
    while (!fin.eof())
    {
        fin >> number >> type >> price >> status;
        Room room;
        room.set_room(number, type, price, status);
        roomlist.push_back(room);
    }
    fin.close();
    return roomlist;
}

#endif