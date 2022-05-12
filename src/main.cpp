#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
#include "../include/menu.h"
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    Menu menu;
    menu.defaultMenu();
    int opt;
    while (cin >> opt && opt)
    {
        if (opt == 1)
        {
            menu.mainMenu();
        }
        else if (opt == 2)
        {
        }
        else
            continue;
    }
    return 0;
}