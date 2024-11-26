#include "Vector.h"
#include <cstring>

Vector::Vector(int s)
    : m_elem{new double[s]}
    , m_sz{s}
{
    for (int i = 0; i < s; i++) {
        m_elem[i] = 0.f;
    }
}

Vector::~Vector() {
    delete[] m_elem;
}

double& Vector::operator[](int i)
{
    return this->m_elem[i];
}

int Vector::size() {
    return this->m_sz;
}
