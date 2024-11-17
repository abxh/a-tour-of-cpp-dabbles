namespace MyCode {

class complex {
public:
    complex(double x, double i) {};
    double real();
    double imag();
};

complex sqrt(complex);

int main();

} // namespace MyCode

#include <iostream>

int MyCode::main()
{
    complex z{1, 2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    return 0;
}

int main()
{
    return MyCode::main();
}
