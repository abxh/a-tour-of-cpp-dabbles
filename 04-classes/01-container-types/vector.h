#include <algorithm>
#include <initializer_list>

class Vector {
public:
    Vector(std::size_t size)
        : m_count{0}
        , m_size{size}
        , m_elems{new double[size]{0}} {};
    Vector(std::initializer_list<double> list)
        : m_count{0}
        , m_size{list.size()}
        , m_elems{new double[list.size()]{0}}
    {
        std::copy(list.begin(), list.end(), m_elems);
    };
    ~Vector()
    {
        delete[] m_elems;
    }
    double pop()
    {
        return m_elems[--m_count];
    }
    void push_back(double x)
    {
        m_elems[m_count++] = x;
    }

private:
    double* m_elems;
    std::size_t m_size;
    int m_count;
};
