#include "00-complex.hpp"

using namespace User;

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a-= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a*= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) { return a.real()==b.real() && a.imag()==b.imag(); }
bool operator!=(complex a, complex b) { return !(a==b); }

complex& complex::operator*=(complex) {return *this;}
complex& complex::operator/=(complex) {return *this;}



void f(complex z)
{
    complex a{2.3};
    // construct {2.3,0.0} from 2.3
    complex b{1 / a};
    complex c{a + z * complex{1, 2.3}};
    // ...
    if (c != b)
        c = -(b / a) + 2 * b;
}

int main(void) {

}
