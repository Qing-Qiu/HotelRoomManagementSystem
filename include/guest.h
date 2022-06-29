#ifndef GUEST_H
#define GUEST_H
#include "person.h"
#include <string>
#include <iomanip>
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
    virtual ~Guest() {}
    void view(Roomlist);
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
    } checkin;
    class Checkout
    {
    public:
        void checkout(Roomlist &);
    } checkout;
};

void Guest::view(Roomlist roomlist)
{
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

void Guest::Book::add(Roomlist &roomlist)
{
    cout << "请输入您要选择预订的房间号（输入0退出）：" << endl;
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
    cout << "请输入您预订的房间号（输入0退出）：" << endl;
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
    bool modifySuccess = false;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            cout << "请输入您的身份证号和手机号：" << endl;
            while (cin >> id >> phoneNum)
            {
                if (roomlist[idx].get_guestID() == id && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cout << "请输入您的姓名：" << endl;
                    cin >> name;
                    roomlist[idx].set_guestName(name);
                    cout << "修改成功！" << endl;
                    modifySuccess = true;
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
                    cout << "请输入您的身份证号：" << endl;
                    cin >> id;
                    roomlist[idx].set_guestID(id);
                    cout << "修改成功！" << endl;
                    modifySuccess = true;
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
            cout << "请输入您的姓名和身份证号：" << endl;
            while (cin >> name >> id)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestID() == id)
                {
                    cout << "请输入您的手机号：" << endl;
                    cin >> phoneNum;
                    roomlist[idx].set_guestPhoneNum(phoneNum);
                    cout << "修改成功！" << endl;
                    modifySuccess = true;
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
            system("pause");
            return;
        }
        if (modifySuccess)
        {
            modifySuccess = false;
            break;
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
    File file;
    file.write(roomlist);
    system("pause");
}

void Guest::Book::del(Roomlist &roomlist)
{
    cout << "请输入您预订的房间号（输入0退出）：" << endl;
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
    while (cin >> name >> id >> phoneNum)
    {
        Room room = roomlist[idx];
        if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
        {
            roomlist[idx].set_room(room.get_number(), room.get_type(), room.get_price(), false, false);
            break;
        }
        else
        {
            cout << "请正确输入您的姓名、身份证号、手机号：" << endl;
            continue;
        }
    }
    File file;
    file.write(roomlist);
    cout << "删除成功！" << endl;
    system("pause");
}

void Guest::Checkin::add(Roomlist &roomlist)
{
    cout << "请输入您要选择入住的房间号（输入0退出）。" << endl;
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
            if (room.get_number() == num && !room.get_isChecked() && room.get_isBooked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "请检查房间号是否输入有误，或请先预订房间后再入住！" << endl;
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
            roomlist[idx].set_checkinTime(nowTime());
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

void Guest::Checkout::checkout(Roomlist &roomlist)
{
    cout << "请输入您入住的房间号（输入0退出）：" << endl;
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
    roomlist[idx].set_checkoutTime(nowTime());
    Room room = roomlist[idx];
    if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
    {
        cout << "退房成功，欢迎下次光临！" << endl;
        cout << "房间号：" << room.get_number() << endl;
        cout << "房间类型：" << room.get_type() << endl;
        cout << "宾客姓名：" << room.get_guestName() << endl;
        cout << "宾客身份证号：" << room.get_guestID() << endl;
        cout << "宾客手机号：" << room.get_guestPhoneNum() << endl;
        cout << "宾客预订时间：" << room.get_bookTime() << endl;
        cout << "宾客入住时间：" << room.get_checkoutTime() << endl;
        cout << "宾客退房时间：" << nowTime() << endl;
        cout << "宾客预付金额：" << 100 << endl;
        cout << "宾客实付金额：" << room.get_price() - 100 << endl;
        cout << "宾客共付金额：" << room.get_price() << endl;
        //退房后可以生成一个log日志
        roomlist[idx].set_room(room.get_number(), room.get_type(), room.get_price(), false, false);
    }
    File file;
    file.write(roomlist);
    system("pause");
}

#endif
