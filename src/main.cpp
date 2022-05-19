#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
#include "../include/listnode.h"
#include "../include/iterator.h"
#include "../include/menu.h"
#include "../include/file.h"
#include "../include/admin.h"
#include <windows.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    Menu menu;
    menu.defaultMenu();
    File file;
    Adminlist adminlist;
    adminlist = file.get_admin_data(); //获取管理员账号密码
    Roomlist roomlist;
    roomlist = file.get_room_data(); //获取客房信息
/*  cout<<(*roomlist[1]).get_number()<<endl;
    cout<<(*roomlist[2]).get_number()<<endl;
    auto a=roomlist.begin(),b=roomlist.begin();
    b++;
    roomlist.swap(a,b);
    cout<<(*roomlist[1]).get_number()<<endl;
    cout<<(*roomlist[2]).get_number()<<endl;
    return 0; */
    bool back2Main = false;          //返回主界面
    bool back2Default = false;       //返回默认界面
    while (1)
    {
        char opt;
        cin >> opt;
        if (opt == '1') //客人身份
        {
            menu.mainMenu();
            Guest guest;
            char opt_;
            while (cin >> opt_)
            {
                if (opt_ == '1') //选择预订客房功能
                {
                    menu.bookMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1') //增加预订客房信息
                        {
                            guest.book.add();
                        }
                        else if (opt__ == '2') //修改预订客房信息
                        {
                            guest.book.modify();
                        }
                        else if (opt__ == '3') //删除预订房间信息
                        {
                            guest.book.del();
                        }
                        else if (opt__ == '0') //返回上一级
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //输入无效，重新输入
                    }
                }
                else if (opt_ == '2') //选择入住登记功能
                {
                    menu.checkinMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1') //入住登记
                        {
                            guest.checkin.add();
                        }
                        else if (opt__ == '2') //修改入住登记信息
                        {
                            guest.checkin.modify();
                        }
                        else if (opt__ == '3') //删除入住登记信息
                        {
                            guest.checkin.del();
                        }
                        else if (opt__ == '0') //返回上一级
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //输入无效，重新输入
                    }
                }
                else if (opt_ == '3') //选择退房结算功能
                {
                    menu.checkoutMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1') //退房结算
                        {
                            guest.checkout.checkout();
                        }
                        else if (opt__ == '0') //返回上一级
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //输入无效，重新输入
                    }
                }
                else if (opt_ == '4') //选择客房信息浏览功能
                {
                    guest.view(roomlist);
                    menu.viewMenu();
                    char ch;
                    while (cin >> ch)
                    {
                        if (ch == '1')  //按照房间号排序
                        {
                        	guest.sort_by_num(roomlist);
                        }
                        else if (ch == '2') //按照入住时间排序
                        {
                            guest.sort_by_time(roomlist);
                        }
                        else if (ch == '3') //搜索功能
                        {
                        }
                        else if (ch == '0') //返回上一级
                        {
                        }
                        else
                            continue;
                    }
                }
                else if (opt_ == '0') //返回初始默认界面
                {
                    back2Default = true;
                    break;
                }
                if (back2Main)
                {
                    menu.mainMenu();
                    back2Main = false;
                }
            }
        }
        else if (opt == '2')
        {
            menu.loginMenu();
            bool loginSuccess = false;
            string username, password;
            while (1)
            {
                cout << "请输入您的账号:";
                cin >> username;
                cout << "请输入您的密码:";
                cin >> password;
                Iterator<Admin> it;
                Admin admin;
                for (int i = 1; i <= 10; i++)
                {
                    admin = adminlist[i];
                    if (username == admin.get_username() && password == admin.get_password())
                    {
                        loginSuccess = true;
                        break;
                    }
                }
                if (loginSuccess)
                {
                    menu.adminMenu();
                    char opt_;
                    while (cin >> opt_)
                    {
                        if (opt_ == '1')    //客房信息浏览
                        {
                        }
                        else if (opt_ == '2')   //客房信息修改
                        {
                        }
                        else if (opt_ == '0')   //返回上一级
                        {
                            back2Default = true;
                            break;
                        }
                        else
                            continue;
                    }
                    break;
                }
                else
                {
                    system("cls");
                    cout << "密码错误，是否重新输入？(Y/N)\n";
                    char ch;
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                        continue;
                    else if (ch == 'N' || ch == 'n')
                    {
                        back2Default = true;
                        break;
                    }
                    else
                    {
                        cout << "请不要输入无效字符！";
                        cout << endl;
                        continue;
                    }
                }
            }
        }
        else if (opt == '0')
        {
            system("pause");
            break;
        }
        else
            continue; //输入无效，重新输入
        if (back2Default)
        {
            menu.defaultMenu();
            back2Default = false;
        }
    }
    return 0;
}
