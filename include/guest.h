#ifndef GUEST_H
#define GUEST_H
#include "person.h"
#include <string>
#include <time.h>
#include "file.h"
using namespace std;
class Roomlist;
class Guest : public Person
{
private:
    string name;
    string id;
    int cost;

public:
    class Book
    {
    public:
        void add(Roomlist);
        void modify(Roomlist);
        void del(Roomlist);
    } book;
    class Checkin
    {
    public:
        void add(Roomlist);
        void modify(Roomlist);
        void del(Roomlist);
    } checkin;
    class Checkout
    {
    public:
        void checkout(Roomlist);
    } checkout;
};

void Guest::Book::add(Roomlist roomlist)
{
    cout << "请输入您要选择预订的房间号。" << endl;
    int num = 0;
    int idx = 0;
    while (cin >> num)
    {
        idx = 0;
        for (int i = 1; i <= roomlist.size(); i++)
        {
            if (roomlist[i].get_number() == num)
            {
                idx = i;
                break;
            }
        }
        if (idx != 0)
            break;
        else
        {
            cout << "该房间号不存在！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号！" << endl;
    string name, id, phoneNum;
    time_t time;
    cin >> name >> id >> phoneNum;
    roomlist[idx].set_isBooked(true);
    roomlist[idx].set_guestName(name);
    roomlist[idx].set_guestID(id);
    // roomlist[idx].set_bookTime();修改时间
    File file;
    file.write(roomlist);
    cout << "预订成功！" << endl;
}

void Guest::Book::modify(Roomlist roomlist)
{
}

void Guest::Book::del(Roomlist roomlist)
{
}

void Guest::Checkin::add(Roomlist roomlist)
{
}

void Guest::Checkin::modify(Roomlist roomlist)
{
}

void Guest::Checkin::del(Roomlist roomlist)
{
}

void Guest::Checkout::checkout(Roomlist roomlist)
{
}

#endif
