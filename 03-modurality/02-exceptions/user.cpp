#include "Vector.h"
#include <iostream>
#include <limits>
#include <ostream>

double f(const Vector& v) {
    return v[2];
}

int main(void)
{
    Vector v{2};
    try {
        (void)f(v);
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "f() failed: " << ex.what() << std::endl;
    }
    std::cout << v.get(2).value_or(std::numeric_limits<double>::infinity()) << std::endl;

    try {
        Vector v{-27};
    }
    catch (std::out_of_range) {
        throw;
    }
    catch (std::bad_alloc) {
        std::terminate();
    }
}
