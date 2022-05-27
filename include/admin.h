#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "adminlist.h"
#include "file.h"
#include <string>
#include <iostream>
using namespace std;
class File;
class Admin : public Person
{
private:
    string username;
    string password;

public:
    virtual ~Admin() {}
    void view(Roomlist);
    void set_username(string);
    void set_password(string);
    string get_username();
    string get_password();
    class Checkin
    {
    public:
        void modify(Roomlist &);
    } checkin;
};

void Admin::view(Roomlist roomlist)
{
    system("cls");
    Iterator<Room> it;
    cout << "房间号\t房间类型\t房间价格\t是否预订\t是否入住\t宾客姓名\t宾客身份证号\t宾客手机号码\t宾客预订时间\t宾客入住时间" << endl;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
    {
        Room room;
        room = *it;
        cout << room.get_number() << '\t' << room.get_type() << '\t' << room.get_price() << '\t'
             << (room.get_isBooked() ? "Yes" : "No") << '\t' << (room.get_isChecked() ? "Yes" : "No") << '\t'
             << room.get_guestName() << '\t' << room.get_guestID() << '\t' << room.get_guestPhoneNum() << '\t'
             << room.get_bookTime() << '\t' << room.get_checkinTime() << endl;
    }
}

void Admin::Checkin::modify(Roomlist &roomlist)
{
    cout << "请输入您要修改的房间号（输入0退出）：" << endl;
    int num;
    int idx;
    while (cin >> num)
    {
        if (num == 0)
            return;
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
            cout << "请检查房间号是否输入有误！" << endl;
            continue;
        }
    }
    cout << "请输入您要修改的信息：" << endl;
    cout << "\t1.房间价格" << endl;
    cout << "\t2.宾客姓名" << endl;
    cout << "\t3.宾客身份证号" << endl;
    cout << "\t4.宾客手机号" << endl;
    cout << "\t5.取消该宾客入住" << endl;
    cout << "\t6.取消该宾客预订" << endl;
    cout << "\t0.返回" << endl;
    string name, id, phoneNum;
    char ch;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            cout << "请输入您要修改成的房间价格：" << endl;
            int p;
            cin >> p;
            try
            {
                if (p < 100 || p > 1000)
                    throw "价格超出正常范围！";
                roomlist[idx].set_price(p);
            }
            catch (const char *&e)
            {
                cout << e << endl;
                system("pause");
            }
            break;
        }
        else if (ch == '2')
        {
            cout << "请输入您要修改成的宾客姓名：" << endl;
            while (cin >> name)
            {
                roomlist[idx].set_guestName(name);
                break;
            }
            break;
        }
        else if (ch == '3')
        {
            cout << "请输入您要修改成的宾客身份证号：" << endl;
            while (cin >> id)
            {
                roomlist[idx].set_guestID(id);
                break;
            }
            break;
        }
        else if (ch == '4')
        {
            cout << "请输入您要修改成的宾客手机号：" << endl;
            while (cin >> phoneNum)
            {
                roomlist[idx].set_guestPhoneNum(phoneNum);
                break;
            }
            break;
        }
        else if (ch == '5')
        {
            roomlist[idx].set_checkinTime("NULL");
            roomlist[idx].set_isChecked(false);
            break;
        }
        else if (ch == '6')
        {
            Room room;
            room = roomlist[idx];
            roomlist[idx].set_room(room.get_number(), room.get_type(), room.get_price(), false, false);
            break;
        }
        else if (ch == '0')
        {
            system("pause");
            return;
        }
        else
        {
            cout << "请重新输入您要修改的信息：" << endl;
            cout << "\t1.姓名" << endl;
            cout << "\t2.身份证号" << endl;
            cout << "\t3.手机号" << endl;
            cout << "\t0.返回" << endl;
            continue;
        }
    }
    //    File file;
    //    file.write(roomlist);
    //    system("pause");
}

void Admin::set_username(string user)
{
    username = user;
}

void Admin::set_password(string pwd)
{
    password = pwd;
}

string Admin::get_username()
{
    return username;
}

string Admin::get_password()
{
    return password;
}
#endif
