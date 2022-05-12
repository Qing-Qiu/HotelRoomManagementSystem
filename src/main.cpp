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
    for (int i=1;i<=3;i++) {
        li.push_back(3);
        cout<<li.size()<<endl;
    }
    for (int i=1;i<=3;i++) {
        li.pop_back();
        cout<<li.size()<<endl;
    }
    cout<<li.size()<<endl;
    li.clear();
    cout<<li.size()<<endl;
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