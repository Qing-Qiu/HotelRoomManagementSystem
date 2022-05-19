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
    void write(Roomlist);
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
    fin.open("../data/roomdata.txt"); // stringstream
    while (1)
    {
        string s;
        // stringstream ss;
        fin >> number >> type >> price >> status;
        if (fin.eof())
            break;
        Room room;
        room.set_room(number, type, price, status);
        roomlist.push_back(room);
    }
    fin.close();
    return roomlist;
}

void File::write(Roomlist roomlist)
{
    fstream file;
    file.open("../data/tmp.txt", ios::out | ios::binary);
    ofstream fout;
    fout.open("../data/tmp.txt");
    for (auto i = roomlist.begin(); i != roomlist.end(); i++)
    {
        Room room = *i;
        fout << room.get_number() << '\t' << room.get_type() << '\t' << room.get_price() << '\t';
        fout << (room.get_isBooked() ? "B" : "A") << '\t' << (room.get_isChecked() ? "C" : "B") << '\t';
        fout << room.get_guestName() << '\t' << room.get_guestID() << '\t';
        fout << room.get_bookTime() << '\t' << room.get_checkinTime() << '\t' << room.get_checkoutTime() << endl;
    }
    fout.close();
}
#endif
