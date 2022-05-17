#ifndef PERSON_H
#define PERSON_H
#include "room.h"
#include "roomlist.h"
#include "list.h"
#include "iterator.h"
#include "const_iterator.h"
class Room;
class Roomlist;
class Person
{
public:
    void view(Roomlist);
    void sort_by_time();
    void sort_by_num();
};
void Person::view(Roomlist roomlist)
{
    system("cls");
    Iterator<Room> it;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
        ; //输出房间信息
}
#endif
