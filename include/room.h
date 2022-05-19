#ifndef ROOM_H
#define ROOM_H
#include "roomlist.h"
#include <string>
using namespace std;
class Room
{
private:
    int number;
    string type;
    int price;
    bool isBooked;
    bool isChecked;

    string guestName;
    string guestID;
    string bookTime;
    string checkinTime;
    string checkoutTime;

public:
    Room(){};
    Room(int num, string t, int p, bool r, bool c) : number(num), type(t), price(p), isBooked(r), isChecked(c){};
    void set_room(int, string, int, char);

    int get_number();
    string get_type();
    int get_price();
    bool get_isBooked();
    bool get_isChecked();
    string get_guestName();
    string get_guestID();
    string get_bookTime();
    string get_checkinTime();
    string get_checkoutTime();
//可能都是不需要的
    void set_number(int);
    void set_type(string);
    void set_price(int);
    void set_isBooked(bool);
    void set_isChecked(bool);
    void set_guestName(string);
    void set_guestID(string);
    void set_bookTime(string);
    void set_checkinTime(string);
    void set_checkoutTime(string);

    friend void RoomInit(Room *room);
    friend class Admin;
    friend class Book;
    friend class Checkin;
    friend class Checkout;
};

void Room::set_room(int num, string t, int p, char status)
{
    number = num;
    type = t;
    price = p;
    isBooked = false;
    isChecked = false;
    if (status == 'B' || status == 'b')
        isBooked = true;
    if (status == 'C' || status == 'c')
        isChecked = true;
}

int Room::get_number()
{
    return number;
}
string Room::get_type()
{
    return type;
}
int Room::get_price()
{
    return price;
}
bool Room::get_isBooked()
{
    return isBooked;
}
bool Room::get_isChecked()
{
    return isChecked;
}
string Room::get_guestName()
{
    return guestName;
}
string Room::get_guestID()
{
    return guestID;
}
string Room::get_bookTime()
{
    return bookTime;
}
string Room::get_checkinTime()
{
    return checkinTime;
}
string Room::get_checkoutTime()
{
    return checkoutTime;
}

void Room::set_number(int n)
{
    number = n;
}
void Room::set_type(string s)
{
    type = s;
}
void Room::set_price(int p)
{
    price = p;
}
void Room::set_isBooked(bool f)
{
    isBooked = f;
}
void Room::set_isChecked(bool f)
{
    isChecked = f;
}
void Room::set_guestName(string s)
{
    guestName = s;
}
void Room::set_guestID(string s)
{
    guestID = s;
}
void Room::set_bookTime(string s)
{
    bookTime = s;
}
void Room::set_checkinTime(string s)
{
    checkinTime = s;
}
void Room::set_checkoutTime(string s)
{
    checkoutTime =s;
}
#endif