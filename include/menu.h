#include <iostream>
class Menu
{
public:
    void defaultMenu();
    void mainMenu();
    void reserveMenu();
    void checkinMenu();
    void checkoutMenu();
};

void Menu::defaultMenu()
{
    cout << string(32, '-') + "\n";
    cout << "\t欢迎进入宾馆客房管理系统\n";
    cout << "\t请问您是:\n";
    cout << "\t\t1.客人\n";
    cout << "\t\t2.管理员\n";
    cout << string(32, '-') + "\n";
}

void Menu::mainMenu()
{
    cout << string(32, '-') + "\n";
    cout << "\t请选择您要进行的操作\n";
    cout << "\t\t1.预订客房\n";
    cout << "\t\t2.入住登记\n";
    cout << "\t\t3.退房结算\n";
    cout << "\t\t4.客房信息浏览\n";
    cout << "\t\t5.返回\n";
}