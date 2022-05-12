#include "person.h"
#include<string>
using namespace std;
class Admin : public Person
{
    private:
        string username;
        string password;
    public:
        void modify_price();
};