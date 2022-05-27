#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "adminlist.h"
#include "roomlist.h"
#include "room.h"
class File
{
public:
    Adminlist get_admin_data();
    Roomlist get_room_data();
    void roomInit();
    void write(Roomlist &);
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
    char isBooked;
    char isChecked;
    string guestName;
    string guestID;
    string guestPhoneNum;
    string bookTime;
    string checkinTime;
    string checkoutTime;
    Roomlist roomlist;
    fin.open("../data/roomdata.txt");
    while (1)
    {
        fin >> number >> type >> price >> isBooked >> isChecked >> guestName >> guestID >> guestPhoneNum >> bookTime >> checkinTime >> checkoutTime;
        if (fin.eof())
            break;
        Room room;
        room.set_room(number, type, price, isBooked, isChecked, guestName, guestID, guestPhoneNum, bookTime, checkinTime, checkoutTime);
        roomlist.push_back(room);
    }
    fin.close();
    return roomlist;
}

void File::roomInit()
{
    ifstream fin;
    int number;
    string type;
    int price;
    char isBooked;
    char isChecked;
    string guestName;
    string guestID;
    string guestPhoneNum;
    string bookTime;
    string checkinTime;
    string checkoutTime;
    Roomlist roomlist;
    fin.open("../data/roominit.txt");
    while (1)
    {
        fin >> number >> type >> price >> isBooked >> isChecked >> guestName >> guestID >> guestPhoneNum >> bookTime >> checkinTime >> checkoutTime;
        Room room;
        room.set_room(number, type, price, isBooked, isChecked, guestName, guestID, guestPhoneNum, bookTime, checkinTime, checkoutTime);
        roomlist.push_back(room);
        if (fin.eof())
            break;
    }
    fin.close();
    write(roomlist);
    cout << "客房信息初始化成功！" << endl;
}

void File::write(Roomlist &roomlist)
{
    fstream file;
    file.open("../data/roomdata.txt", ios::out | ios::binary);
    file.close();
    ofstream fout;
    fout.open("../data/roomdata.txt");
    for (auto i = roomlist.begin(); i != roomlist.end(); i++)
    {
        Room room = *i;
        fout << room.get_number() << '\t' << room.get_type() << '\t' << room.get_price() << '\t'
             << (room.get_isBooked() ? "Y" : "N") << '\t' << (room.get_isChecked() ? "Y" : "N") << '\t'
             << room.get_guestName() << '\t' << room.get_guestID() << '\t' << room.get_guestPhoneNum() << '\t'
             << room.get_bookTime() << '\t' << room.get_checkinTime() << '\t' << room.get_checkoutTime() << endl;
    }
    fout.close();
}
#endif
