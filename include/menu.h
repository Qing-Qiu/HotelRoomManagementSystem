#ifndef MENU_H
#define MENU_H
#include <iostream>
class Menu
{
public:
    void defaultMenu();
    void mainMenu();
    void bookMenu();
    void checkinMenu();
    void checkoutMenu();
    void loginMenu();
    void adminMenu();
};

void Menu::defaultMenu()
{
    cout << string(40, '-') + "\n";
    cout << "\t欢迎进入宾馆客房管理系统\n";
    cout << "\t请问您是:\n";
    cout << "\t\t1.客人\n";
    cout << "\t\t2.管理员\n";
    cout << "\t0.退出系统\n";
    cout << string(40, '-') + "\n";
}

void Menu::mainMenu()
{
    cout << string(40, '-') + "\n";
    cout << "\t请选择您要进行的操作\n";
    cout << "\t\t1.预订客房\n";
    cout << "\t\t2.入住登记\n";
    cout << "\t\t3.退房结算\n";
    cout << "\t\t4.客房信息浏览\n";
    cout << "\t\t0.返回\n";
    cout << string(40, '-') + "\n";
}

void Menu::bookMenu()
{
    cout << string(40, '-') + "\n";
    cout << "\t欢迎预订秋刀鱼宾馆的房间\n";
    cout << "\t请选择您要进行的操作\n";
    cout << "\t\t1.我要预订\n";
    cout << "\t\t2.修改信息\n";
    cout << "\t\t3.取消预订\n";
    cout << "\t\t0.返回\n";
    cout << string(40, '-') + "\n";
}

void Menu::checkinMenu()
{
    cout << string(40, '-') + "\n";
    cout << "\t欢迎入住秋刀鱼宾馆\n";
    cout << "\t请选择您要进行的操作\n";
    cout << "\t\t1.我要入住\n";
    cout << "\t\t2.修改信息\n";
    cout << "\t\t3.取消入住\n";
    cout << "\t\t0.返回\n";
    cout << string(40, '-') + "\n";
}

void Menu::checkoutMenu()
{
    cout << string(40, '-') + "\n";
    cout << "\t欢迎下次光临秋刀鱼宾馆\n";
    cout << "\t请选择您要进行的操作\n";
    cout << "\t\t1.退房结算\n";
    cout << "\t\t0.返回\n";
    cout << string(40, '-') + "\n";
}

void Menu::loginMenu()
{
    cout << string(40, '-') + "\n";
    cout << "\t您好,系统管理员!\n";
    cout << "\t请输入您的账号和密码:\n";
}

void Menu::adminMenu()
{
    cout << "\t欢迎系统管理员!\n";
}
#endif