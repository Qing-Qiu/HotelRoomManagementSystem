#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
#include "../include/listnode.h"
#include "../include/iterator.h"
#include "../include/menu.h"
#include "../include/file.h"
#include "../include/admin.h"
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    Menu menu;
    menu.defaultMenu();
    File file;
    Adminlist adminlist;
    adminlist = file.get_admin_data();
    bool back2Main = false;
    bool back2Default = false;
    while (1)
    {
        char opt;
        cin >> opt;
        if (opt == '1')
        {
            menu.mainMenu();
            char opt_;
            while (cin >> opt_)
            {
                if (opt_ == '1')
                {
                    menu.bookMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1')
                        {
                        }
                        else if (opt__ == '2')
                        {
                        }
                        else if (opt__ == '3')
                        {
                        }
                        else if (opt__ == '0')
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (opt_ == '2')
                {
                    menu.checkinMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1')
                        {
                        }
                        else if (opt__ == '2')
                        {
                        }
                        else if (opt__ == '3')
                        {
                        }
                        else if (opt__ == '0')
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (opt_ == '3')
                {
                    menu.checkoutMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1')
                        {
                        }
                        else if (opt__ == '0')
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (opt_ == '4')
                {
                }
                else if (opt_ == '0')
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
            bool flag = false;
            string username, password;
            cout << "ÇëÊäÈëÄúµÄÕËºÅ:\n";
            cin >> username;
            cout << "ÇëÊäÈëÄúµÄÃÜÂë\n";
            cin >> password;
            Iterator<Admin> it;
            Admin admin;
            for (int i = 1; i <= 10; i++)
            {
                admin = adminlist[i];
                if (username == admin.get_username() && password == admin.get_password())
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                menu.adminMenu();
            }
            else
            {
                cout << "ÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡\n";
            }
        }
        else if (opt == '0')
        {
            break;
        }
        else
            continue;
        if (back2Default)
        {
            menu.defaultMenu();
            back2Default = false;
        }
    }
    return 0;
}
