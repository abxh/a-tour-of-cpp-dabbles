#include "Vector.h"

Vector::Vector(int s)
    : elem{new double[s]}
    , sz{s}
{
}

double& Vector::operator[](int i)
{
    return this->elem[i];
}

int Vector::size() {
    return this->sz;
}
