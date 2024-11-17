
enum Type { str, num };

struct Entry {
    char* name;
    Type t;
    union {
        char* s;
        int i;
    } u;
};

void f(Entry* p)
{
    if (p->t == str) {
        (void)p->u.s;
    }
}

#include <variant>

struct EntryAlt {
    char* name;
    Type t;
    std::variant<char*, int> u;
};

void g(EntryAlt* p)
{
    if (p->t == str) {
        (void)std::get<char*>(p->u);
    }
}
