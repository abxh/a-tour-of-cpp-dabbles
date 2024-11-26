#include "Vector.h"

#include <stdexcept>

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

double& Vector::operator[](int i) const
{
    if (!(0 <= i && i < size())) {
        throw std::out_of_range{"Vector::operator[]"};
    }
    return m_elem[i];
}

std::optional<double> Vector::get(int i) noexcept
{
    if (!(0 <= i && i < size())) {
        return std::nullopt;
    }
    return m_elem[i];
}

int Vector::size() const noexcept
{
    return m_sz;
}
