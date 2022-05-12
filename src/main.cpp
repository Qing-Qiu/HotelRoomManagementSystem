#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
#include "../include/menu.h"
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    std::cout << "-------------------------------\n";
    std::cout << "|    欢迎进入宾馆客房管理系统   |\n";
    std::cout << "|       1.客房信息浏览         |\n";
    std::cout << "|       2.登录                 |\n";
    std::cout << "-------------------------------\n";
    List<int> li;
    cout<<li.empty()<<endl;
    return 0;
    char ch;
    while (std::cin>>ch) {
        if (ch=='1') {

        }
        else if (ch=='2') {

        }
        else continue;
    }
    return 0;
}