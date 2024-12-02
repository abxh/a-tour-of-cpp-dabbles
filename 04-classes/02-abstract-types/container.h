
// eventually look up videos on the virtual method table

#include "vector.h"

#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>

class Container {
public:
    virtual double& operator[](int) = 0; // = 0 to make the function obligatory to declare.
    virtual int size() const = 0;
    virtual ~Container() {}
};

inline void use(Container& c) {
    const int sz = c.size();

    for (int i = 0; i < sz; i++) {
        std::cout << c[i] << std::endl;
    }
}

class VectorContainer : public Container {
public:
    VectorContainer() : v(0) {}
    VectorContainer(std::initializer_list<double> il) : v{il} {}
    ~VectorContainer() {}

    double& operator[](int i) {return v[i];}
    int size() const { return v.size(); };
private:
    Vector v;
};

class ListContainer : public Container {
public:
    ListContainer() {}
    ListContainer(std::initializer_list<double> il) : ld{il} {}
    ~ListContainer() {}

    double& operator[](int i);
    int size() const { return ld.size(); };
private:
    std::list<double> ld;
};

inline double& ListContainer::operator[](int i) {
    for (auto& x : ld) {
        if (i == 0) return x;
        --i;
    }
    throw std::out_of_range("ListContainer::operator[]");
}

inline void g() {
    VectorContainer c {10, 9, 8};
    use(c);
}
