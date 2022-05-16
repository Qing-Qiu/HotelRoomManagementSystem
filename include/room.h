#ifndef ROOM_H
#define ROOM_H
#include <string>
using namespace std;
class Room
{
private:
    string number;
    int type;
    int price;
    bool isReserved;
    bool isChecked;

    string guestName;
    string guestID;
    string bookTime;
    string checkinTime;
    string checkoutTime;

public:
    Room();
    Room(string num, int t, int p, bool r, bool c) : number(num), type(t), price(p), isReserved(r), isChecked(c){};

    friend void RoomInit(Room* room);
    friend class Admin;
    friend class Guest;
};
#endif