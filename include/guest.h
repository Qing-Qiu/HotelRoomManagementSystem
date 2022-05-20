#ifndef GUEST_H
#define GUEST_H
#include "person.h"
#include <string>
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
    int num;
    int idx;
    while (cin >> num)
    {
        idx = 0;
        bool flag = false;
        for (auto it = roomlist.begin(); it != roomlist.end(); it++)
        {
            Room room = *it;
            idx++;
            if (room.get_number() == num)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "该房间号不存在！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号！" << endl;
    string name, id, phoneNum;
    cin >> name >> id >> phoneNum;
    roomlist[idx].set_isBooked(true);
    roomlist[idx].set_guestName(name);
    roomlist[idx].set_guestID(id);
    roomlist[idx].set_guestPhoneNum(phoneNum);
    roomlist[idx].set_bookTime(nowTime());
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
    cout << "请输入您要选择入住的房间号。" << endl;
    int num;
    int idx;
    while (cin >> num)
    {
        idx = 0;
        bool flag = false;
        for (auto it = roomlist.begin(); it != roomlist.end(); it++)
        {
            Room room = *it;
            idx++;
            if (room.get_number() == num)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "该房间号不存在！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号！" << endl;
    string name, id, phoneNum;
    while (cin >> name >> id >> phoneNum)
    {
        if (name == roomlist[idx].get_guestName() && id == roomlist[idx].get_guestID() && phoneNum == roomlist[idx].get_guestPhoneNum())
        {
            cout << "欢迎入住！" << endl;
            break;
        }
    }

    roomlist[idx].set_isChecked(true);
    roomlist[idx].set_guestName(name);
    roomlist[idx].set_guestID(id);
    roomlist[idx].set_bookTime(nowTime());
    File file;
    file.write(roomlist);
    cout << "欢迎入住！" << endl;
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
