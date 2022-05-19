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

    friend void RoomInit(Room *room);
    friend class Admin;
    friend class Guest;
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
#endif