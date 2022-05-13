#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
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
    char opt;
    while (cin >> opt)
    {
        if (opt == '1')
        {
            menu.mainMenu();
            char opt_;
            while (cin >> opt_)
            {
                if (opt_ == '1')
                {
                    menu.reserveMenu();
                }
                else if (opt_ == '2')
                {
                    menu.checkinMenu();
                }
                else if (opt_ == '3')
                {
                    menu.checkoutMenu();
                }
                else if (opt_ == '4')
                {
                                }
                else if (opt_ == '0')
                {
                    menu.mainMenu();
                    break;
                }
            }
        }
        else if (opt == '2')
        {
            menu.loginMenu();
            Admin admin;
            if (admin.login()) {
                menu.adminMenu();
            }
        }
        else if (opt == '0')
        {
            break;
        }
        else
            continue;
    }
    return 0;
}