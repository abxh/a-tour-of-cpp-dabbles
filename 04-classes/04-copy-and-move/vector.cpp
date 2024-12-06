
#include <cassert>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <iostream>

class Vector {
private:
    double* m_elem;
    int m_sz;

public:
    explicit Vector(int s) // ordinary constructor: create an objec
        : m_sz{s}
        , m_elem{new double[static_cast<std::size_t>(s)]{0.f}}
    {
    }
    ~Vector()
    {
        delete[] m_elem;
    }

    Vector(const Vector& a) // copy constructor
        : m_sz{a.m_sz}
        , m_elem{new double[static_cast<std::size_t>(a.m_sz)]}
    {
        std::memcpy(m_elem, a.m_elem, static_cast<std::size_t>(a.m_sz) * sizeof(double));
        std::cout << "copied" << std::endl;
    }
    Vector& operator=(const Vector& a) // copy assignment: clean up target and copy
    {
        delete[] m_elem;

        m_elem = new double[static_cast<std::size_t>(a.m_sz)];
        m_sz = a.m_sz;
        std::memcpy(m_elem, a.m_elem, static_cast<std::size_t>(a.m_sz) * sizeof(double));

        std::cout << "copied" << std::endl;
        return *this;
    }

    // if defining copy constructor -> also define move constructor
    /**/
    Vector(Vector&& a) // move constructor
        : m_elem{a.m_elem}
        , m_sz{a.m_sz}
    { 
        a.m_elem = nullptr;
        a.m_sz = 0;
        std::cout << "moved" << std::endl;
    }
    Vector& operator=(Vector&& a) // move assignment: clean up target and move
    { 
        delete[] m_elem;

        m_elem = a.m_elem;
        m_sz = a.m_sz;

        a.m_elem = nullptr;
        a.m_sz = 0;

        std::cout << "moved" << std::endl;
        return *this;
    }
    /**/

    double& operator[](int i)
    {
        if (i < 0 || i > m_sz) {
            throw std::out_of_range("Vector::operator[]");
        }
        return m_elem[i];
    }
    const double& operator[](int i) const
    {
        if (i < 0 || i > m_sz) {
            throw std::out_of_range("Vector::operator[]");
        }
        return m_elem[i];
    }

    int size() const
    {
        return m_sz;
    }

    Vector operator+(const Vector& other) const {
        Vector res{m_sz};
        for (int i = 0; i < m_sz; i++) {
            res[i] = m_elem[i] + other[i];
        }
        return res;
    }
};

Vector f(const Vector& x, const Vector& y, const Vector& z) {
    assert(x.size() == y.size() && y.size() == z.size());
    Vector r{x.size()}; 
    std::cout << r[0] << std::endl; // something must be done in between for this effect.
    r = x+y+z; // use copy constructor. if move is not defined.
    return r;
}

Vector g() {
    Vector x(100);
    Vector y(100);
    Vector z(100);

    z = x; // copy
    y = std::move(x); // move
    return z; // move
}

int main(void)
{
    Vector v1{2};
    v1[0] = 1;
    v1[1] = 2;
    Vector v2{v1}; // copy constructor
    v1[0] = 3;
    assert(v2[0] == 1);
    v2 = v1; // copy assignment
    assert(v2[0] == 3);
    Vector v3{2};

    std::cout << "calling f()" << std::endl;
    Vector v4 = f(v1, v2, v3);
    std::cout << v4[0] << std::endl;
}
