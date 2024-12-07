#include <assert.h>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T> // for all types 'T'. older alt: template <class T>
class Vector {
public:
    // "ordinary" constructor. explicit means no `Vector a = 5` but `Vector a(5)`;
    explicit Vector(int s)
        : m_elem{new T[static_cast<std::size_t>(s)]{0}}
        , m_sz{s}
    {
    }
    ~Vector()
    {
        delete[] m_elem;
    }
    // copy constructor and assignment:
    Vector(const Vector& v)
        : m_elem{new T[static_cast<std::size_t>(v.m_sz)]}
        , m_sz{v.m_sz}
    {
        for (int i = 0; i < v.m_sz; i++) {
            m_elem[i] = v.m_elem[i];
        }
        std::cout << "copied" << std::endl;
    }
    Vector& operator=(const Vector& v)
    {
        delete[] m_elem;
        m_elem = new T[v.m_sz];
        m_sz = v.m_sz;
        for (int i = 0; i < v.m_sz; i++) {
            m_elem[i] = v.m_elem[i];
        }
        std::cout << "copied" << std::endl;
        return *this;
    }
    // move constructor and assignment:
    Vector(Vector&& v)
        : m_elem{new T[static_cast<std::size_t>(v.m_sz)]}
        , m_sz{v.m_sz}
    {
        m_elem = v.m_elem;
        v.m_elem = nullptr;
        v.m_sz = 0;
        std::cout << "moved" << std::endl;
    }
    Vector& operator=(Vector&& v)
    {
        delete[] m_elem;
        m_elem = v.m_elem;
        m_sz = v.m_sz;
        v.m_elem = nullptr;
        v.m_sz = 0;
        std::cout << "moved" << std::endl;
        return *this;
    }

    T& operator[](int i)
    {
        if (i < 0 || m_sz < i) {
            throw std::out_of_range("Vector::operator[]");
        }
        return m_elem[i];
    }
    const T& operator[](int i) const
    {
        if (i < 0 || m_sz < i) {
            throw std::out_of_range("Vector::operator[]");
        }
        return m_elem[i];
    }

    int size() const
    {
        return m_sz;
    }

    Vector operator+(const Vector& other) const
    {
        Vector res{m_sz};
        for (int i = 0; i < m_sz; i++) {
            res[i] = m_elem[i] + other[i];
        }
        return res;
    }
    T* begin() const;
    T* end() const;

private:
    T* m_elem;
    int m_sz;
};

template <typename T>
T* Vector<T>::begin() const
{
    return size() > 0 ? &m_elem[0] : nullptr;
}

template <typename T>
T* Vector<T>::end() const
{
    return begin() + size();
}

template <typename T>
void print_to_cout(const Vector<T>& v)
{
    std::cout << "{";
    for (auto& e : v) {
        std::cout << e << ", ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
Vector<T> f(const Vector<T>& x, const Vector<T>& y, const Vector<T>& z)
{
    assert(x.size() == y.size() && y.size() == z.size());
    Vector<T> r{x.size()};
    std::cout << r[0] << std::endl; // something must be done in between for this effect.
    r = x + y + z;                  // use copy constructor. if move is not defined.
    return r;
}

int main(void)
{
    Vector<int> v1{2};
    v1[0] = 1;
    v1[1] = 2;
    Vector<int> v2{v1}; // copy constructor
    v1[0] = 3;
    assert(v2[0] == 1);
    v2 = v1; // copy assignment
    assert(v2[0] == 3);

    Vector<int> v3{2};

    std::cout << "calling f()" << std::endl;
    Vector v4 = f(v1, v2, v3);
    print_to_cout(v4);
}
