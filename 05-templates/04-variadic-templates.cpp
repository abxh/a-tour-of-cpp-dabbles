#include <iostream>

// recursive definition:
// f {}          = nop
// f head : tail = g(head); f(tail)

template<typename T>
void g(T x) {
    std::cout << x << " ";
}

void f() {
    // nop
}

template<typename T, typename... Tail>
void f(T head, Tail... tail) {
    g(head);
    f(tail...);
}

int main() {
    std::cout << "first: ";
    f(1, 2.2, "hello");
    std::cout << std::endl;
}
