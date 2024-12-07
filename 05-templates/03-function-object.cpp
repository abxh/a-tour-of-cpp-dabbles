#include <iostream>
#include <string>
#include <vector>

template <typename T>
class LessThan {
    const T val;

public:
    LessThan(const T& v)
        : val{v}
    {
    }
    bool operator()(const T& x) const
    {
        return x < val;
    }
};

template <typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x : c) {
        if (pred(x)) {
            ++cnt;
        }
    }
    return cnt;
}

template <typename C, typename Oper>
void for_all(C& c, Oper op) { // assume C is a container of pointers
    for (auto& x : c) {
        op(*x);
    }
}

int main()
{
    LessThan<int> lti{42};
    LessThan<std::string> lts{"Backus"};

    bool b1 = lti(69);
    std::cout << "lti(42)(69) = " << b1 << std::endl;
    bool b2 = lts("Cackus");
    std::cout << "lti(\"Cackus\")(\"Backus\") = " << b2 << std::endl;

    int total = 0;
    int cnt = count(std::vector{1, 2, 3}, [&total](const int& x) {
        total++;
        return x % 2 == 1;
    });
    std::cout << "count: " << cnt << " / " << total << std::endl;
}
