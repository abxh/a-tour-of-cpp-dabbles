
#include <iostream>

struct VectorST {
    int sz;
    double* elem;
};

class VectorCL {
    VectorCL(int s)
        : elem{new double[s]}
        , sz{s}
    {
    }
    double& operator[](int i)
    {
        return elem[i];
    };
    int size()
    {
        return sz;
    }

private:
    double* elem;
    int sz;
};

void vector_init(VectorST& v, int s)
{
    v.elem = new double[s]; // an array of s doubles
    v.sz = s;
}

double read_and_sum(int s)
{
    using namespace std;
    VectorST v;
    vector_init(v, s);
    for (int i = 0; i < s; i++) {
        cin >> v.elem[i];
    }

    double sum = 0;
    for (int i = 0; i < s; i++) {
        sum += v.elem[i];
    }
    return sum;
}

void f(VectorST v, VectorST& rv, VectorST* pv)
{
    int i1 = v.sz;
    int i2 = rv.sz;
    int i3 = pv->sz;
}

int main()
{
    VectorST v;
    vector_init(v, 5);
}
