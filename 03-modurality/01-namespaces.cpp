namespace MyCode {

namespace MySubCode {

class complex {
public:
    complex(double x, double i) {};
    double real();
    double imag();
};

complex sqrt(complex);

int main();
} // namespace MySubCode

} // namespace MyCode

#include <iostream>

int MyCode::MySubCode::main()
{
    complex z{1, 2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    return 0;
}

int main()
{
    return MyCode::MySubCode::main();
}
