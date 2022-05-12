template <typename T>
class Listnode
{
    T val;
    Listnode<T> *prev;
    Listnode<T> *next;
    Listnode(const v &) : val(v), next(NULL), prev(NULL) {}
    Listnode() : next(NULL), prev(NULL) {}
};