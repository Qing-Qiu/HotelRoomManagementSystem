template <typename T>
class Listnode
{
    T val;
    Listnode<T> *prev;
    Listnode<T> *next;
    Listnode(const T &v) : val(v), next(nullptr), prev(nullptr) {}
    Listnode() : next(nullptr), prev(nullptr) {}
};