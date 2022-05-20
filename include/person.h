#ifndef PERSON_H
#define PERSON_H
#include "room.h"
#include "roomlist.h"
#include "list.h"
#include "iterator.h"
#include "const_iterator.h"
#include <windows.h>
class Room;
class Roomlist;
class Person
{
public:
    void view(Roomlist); //可以改为纯虚函数
    void sort_by_time(Roomlist);
    void sort_by_num(Roomlist);
    static string nowTime();
};

void Person::view(Roomlist roomlist)
{
    system("cls");
    Iterator<Room> it;
    cout << "房间号\t房间类型\t房间价格\t是否预订\t是否入住\t" << endl;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
    {
        Room room;
        room = *it;
        cout << room.get_number() << '\t' << room.get_type() << '\t' << room.get_price() << '\t';
        cout << (room.get_isBooked() ? "Yes" : "No") << '\t' << (room.get_isChecked() ? "Yes" : "No") << endl;
    }
}

void Person::sort_by_time(Roomlist roomlist)
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
            if (room1.get_checkinTime() < room2.get_checkinTime())
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
    view(roomlist);
}

void Person::sort_by_num(Roomlist roomlist)
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
            if (room1.get_number() < room2.get_number())
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
    view(roomlist);
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
