#ifndef PERSON_H
#define PERSON_H
#include "room.h"
#include "roomlist.h"
#include "list.h"
#include "iterator.h"
#include "const_iterator.h"
#include <windows.h>
#include <iomanip>
class Room;
class Roomlist;
class Person
{
public:
    virtual void view(Roomlist) = 0;
    virtual ~Person() {}
    void sort_by_time(Roomlist &);
    void sort_by_num(Roomlist &);
    static string nowTime();
};

void Person::sort_by_time(Roomlist &roomlist)
{
    int len = roomlist.size();
    auto beg = roomlist.begin();
    auto posi = beg, posj = beg, tmp = beg;
    for (int i = 1; i < len; i++)
    {
        posj = posi;
        tmp = posi;
        for (int j = i + 1; j <= len; j++)
        {
            posj++;
            Room room1 = *posi;
            Room room2 = *posj;
            if (room1.get_checkinTime() > room2.get_checkinTime())
            {
                tmp = posj;
            }
        }
        if (tmp != posi)
        {
            roomlist.swap(tmp, posi);
            posi = tmp;
        }
        posi++;
    }
    system("cls");
    Iterator<Room> it;
    cout << "房间号" << setw(15) << "房间类型" << setw(15) << "房间价格" << setw(15) << "是否预订" << setw(15) << "是否入住" << endl;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
    {
        Room room;
        room = *it;
        cout << room.get_number() << setw(15) << room.get_type() << setw(15) << room.get_price() << setw(15);
        cout << (room.get_isBooked() ? "Yes" : "No") << setw(15) << (room.get_isChecked() ? "Yes" : "No") << endl;
    }
}

void Person::sort_by_num(Roomlist &roomlist)
{
    int len = roomlist.size();
    auto beg = roomlist.begin();
    auto posi = beg, posj = beg, tmp = beg;
    for (int i = 1; i < len; i++)
    {
        posj = posi;
        tmp = posi;
        for (int j = i + 1; j <= len; j++)
        {
            posj++;
            Room room1 = *posi;
            Room room2 = *posj;
            if (room1.get_number() > room2.get_number())
            {
                tmp = posj;
            }
        }
        if (tmp != posi)
        {
            roomlist.swap(tmp, posi);
            posi = tmp;
        }
        posi++;
    }
    system("cls");
    Iterator<Room> it;
    cout << "房间号" << setw(15) << "房间类型" << setw(15) << "房间价格" << setw(15) << "是否预订" << setw(15) << "是否入住" << endl;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
    {
        Room room;
        room = *it;
        cout << room.get_number() << setw(15) << room.get_type() << setw(15) << room.get_price() << setw(15);
        cout << (room.get_isBooked() ? "Yes" : "No") << setw(15) << (room.get_isChecked() ? "Yes" : "No") << endl;
    }
}

string Person::nowTime()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    string res;
    res = to_string(time.wYear) + "." + to_string(time.wMonth) + "." + to_string(time.wDay) + "|" + to_string(time.wHour) + ":" + to_string(time.wMinute) + ":" + to_string(time.wSecond);
    return res;
}
#endif
