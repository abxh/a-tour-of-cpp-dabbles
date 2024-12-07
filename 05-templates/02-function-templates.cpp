#include <vector>
#include <iostream>

template <typename Container, typename Value>
Value sum(const Container& c, Value v)
{
    for (auto x : c) {
        v += x;
    }
    return v;
}

int main()
{
    std::vector<int> vi{1, 2, 3, 4};
    std::vector<char> vd{'a', 'b', 'c', 'd'};

    int x = sum(vi, 0);
    std::cout << x << std::endl;

    double d = sum(vi, 0.5);
    std::cout << d << std::endl;

    char c = sum(vd, -'b' - 'c' - 'd');
    std::cout << c << std::endl;
}
