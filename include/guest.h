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
        void add(Roomlist &);
        void modify(Roomlist &);
        void del(Roomlist &);
    } book;
    class Checkin
    {
    public:
        void add(Roomlist &);
        void modify(Roomlist &);
        void del(Roomlist &);
    } checkin;
    class Checkout
    {
    public:
        void checkout(Roomlist &);
    } checkout;
};

void Guest::Book::add(Roomlist &roomlist)
{
    cout << "请输入您要选择预订的房间号：" << endl;
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
            if (room.get_number() == num && !room.get_isBooked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号：" << endl;
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
    system("pause");
}

void Guest::Book::modify(Roomlist &roomlist)
{
    cout << "请输入您预订的房间号：" << endl;
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
            if (room.get_number() == num && room.get_isBooked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请输入您要修改的信息：" << endl;
    cout << "\t1.姓名" << endl;
    cout << "\t2.身份证号" << endl;
    cout << "\t3.手机号" << endl;
    cout << "\t0.返回" << endl;
    string name, id, phoneNum;
    char ch;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            cout << "请输入您的身份证号和手机号：" << endl;
            while (cin >> id >> phoneNum)
            {
                if (roomlist[idx].get_guestID() == id && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cin >> name;
                    roomlist[idx].set_guestName(name);
                    cout << "修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "修改失败！" << endl;
                    break;
                }
            }
        }
        else if (ch == '2')
        {
            cout << "请输入您的姓名和手机号：" << endl;
            while (cin >> name >> phoneNum)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cin >> id;
                    roomlist[idx].set_guestID(id);
                    cout << "修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "修改失败！" << endl;
                    break;
                }
            }
        }
        else if (ch == '3')
        {
            cout << "请输入您的身份证号和手机号：" << endl;
            while (cin >> name >> id)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestID() == id)
                {
                    cin >> phoneNum;
                    roomlist[idx].set_guestPhoneNum(phoneNum);
                    cout << "修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "修改失败！" << endl;
                    break;
                }
            }
        }
        else if (ch == '0')
        {
            break;
        }
        else
            continue;
    }
    File file;
    file.write(roomlist);
    cout << "修改成功！" << endl;
    system("pause");
}

void Guest::Book::del(Roomlist &roomlist)
{
    cout << "请输入您预订的房间号：" << endl;
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
            if (room.get_number() == num && room.get_isBooked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号：" << endl;
    string name, id, phoneNum;
    cin >> name >> id >> phoneNum;
    Room room = roomlist[idx];
    if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
    {
        room.set_isBooked(false);
        room.set_isChecked(false);
        room.set_guestName("NULL");
        room.set_guestID("NULL");
        room.set_guestPhoneNum("NULL");
        room.set_bookTime("NULL");
        room.set_checkinTime("NULL");
        room.set_checkoutTime("NULL");
    }
    File file;
    file.write(roomlist);
    cout << "删除成功！" << endl;
    system("pause");
}

void Guest::Checkin::add(Roomlist &roomlist)
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
            if (room.get_number() == num && !room.get_isChecked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号：" << endl;
    string name, id, phoneNum;
    while (cin >> name >> id >> phoneNum)
    {
        if (name == roomlist[idx].get_guestName() && id == roomlist[idx].get_guestID() && phoneNum == roomlist[idx].get_guestPhoneNum())
        {
            cout << "欢迎入住！" << endl;
            roomlist[idx].set_isChecked(true);
            roomlist[idx].set_guestName(name);
            roomlist[idx].set_guestID(id);
            roomlist[idx].set_bookTime(nowTime());
            File file;
            file.write(roomlist);
            break;
        }
        else
        {
            cout << "验证失败，请重新输入!" << endl;
            break;
        }
    }
    system("pause");
}

void Guest::Checkin::modify(Roomlist &roomlist)
{
    cout << "请输入您入住的房间号：" << endl;
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
            if (room.get_number() == num && room.get_isChecked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请输入您要修改的信息：" << endl;
    cout << "\t1.姓名" << endl;
    cout << "\t2.身份证号" << endl;
    cout << "\t3.手机号" << endl;
    cout << "\t0.返回" << endl;
    string name, id, phoneNum;
    char ch;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            cout << "请输入您的身份证号和手机号：" << endl;
            while (cin >> id >> phoneNum)
            {
                if (roomlist[idx].get_guestID() == id && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cin >> name;
                    roomlist[idx].set_guestName(name);
                    cout << "修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "修改失败！" << endl;
                    break;
                }
            }
        }
        else if (ch == '2')
        {
            cout << "请输入您的姓名和手机号：" << endl;
            while (cin >> name >> phoneNum)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cin >> id;
                    roomlist[idx].set_guestID(id);
                    cout << "修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "修改失败！" << endl;
                    break;
                }
            }
        }
        else if (ch == '3')
        {
            cout << "请输入您的身份证号和手机号：" << endl;
            while (cin >> name >> id)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestID() == id)
                {
                    cin >> phoneNum;
                    roomlist[idx].set_guestPhoneNum(phoneNum);
                    cout << "修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "修改失败！" << endl;
                    break;
                }
            }
        }
        else if (ch == '0')
        {
            break;
        }
        else
            continue;
    }
    File file;
    file.write(roomlist);
    cout << "修改成功！" << endl;
    system("pause");
}

void Guest::Checkin::del(Roomlist &roomlist)
{
    cout << "请输入您入住的房间号：" << endl;
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
            if (room.get_number() == num && room.get_isChecked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号：" << endl;
    string name, id, phoneNum;
    cin >> name >> id >> phoneNum;
    Room room = roomlist[idx];
    if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
    {
        room.set_isBooked(false);
        room.set_isChecked(false);
        room.set_guestName("NULL");
        room.set_guestID("NULL");
        room.set_guestPhoneNum("NULL");
        room.set_bookTime("NULL");
        room.set_checkinTime("NULL");
        room.set_checkoutTime("NULL");
    }
    File file;
    file.write(roomlist);
    cout << "删除成功！" << endl;
    system("pause");
}

void Guest::Checkout::checkout(Roomlist &roomlist)
{
    cout << "请输入您入住的房间号：" << endl;
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
            if (room.get_number() == num && room.get_isChecked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请正确输入您的姓名、身份证号、手机号：" << endl;
    string name, id, phoneNum;
    cin >> name >> id >> phoneNum;
    Room room = roomlist[idx];
    if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
    {
        room.set_isBooked(false);
        room.set_isChecked(false);
        room.set_guestName("NULL");
        room.set_guestID("NULL");
        room.set_guestPhoneNum("NULL");
        room.set_bookTime("NULL");
        room.set_checkinTime("NULL");
        room.set_checkoutTime("NULL");
    }
    File file;
    file.write(roomlist);
    cout << "退房成功，欢迎下次光临！" << endl;
    system("pause");
}

#endif
