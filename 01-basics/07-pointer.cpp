#include <assert.h>
#include <iostream>
#include <vector>

void copy_fct();
void print1();
void reference();

int main() {
    char v[6] = {1,2,3,4,5,6};
    char *p = &v[3];
    char x = *p;

    assert(x == 4);

    print1();
    copy_fct();
    reference();
}

void copy_fct() {
    int v1[] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10];

    for (auto i = 0; i < 10; ++i) {
        v2[i] = v1[i];
    }
    for (auto i = 0; i < 10; ++i) {
        assert(v2[i] == v1[i]);
    }
}


void print1() {
    using namespace std;

    int v[] = {1,2,3,4,5,6,7,8,9};

    for (auto x : v) {
        cout << x << '\n';
    }

    for (auto x : {1,2,3}) {
        cout << x << '\n';
    }

    for (auto& x : v) {
        ++x;
    }
}

double sum(const std::vector<double>& v) {
    return v[0];
}

void reference() {
    std::vector<double>*a = nullptr;
    sum(*a);
}

void declarations() {
    int a[5];
    int* b;
    // int& c;

}
