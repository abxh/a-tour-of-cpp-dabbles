#include <vector>

using namespace std;

template <typename T>
class complex {
public:
    complex(double i) {}
    complex(double i, double j) {}
};

int main(void)
{
    double d1 = 2.3;
    double d2{2.3};
    complex<double> z = 1;
    complex<double> z2{d1, d2};

    vector<int> v{1, 2, 3, 4, 5, 6};

    int i1 = 7.2;
    int i2{7.2};
    int i3 = {7.2};

    const int a;

    auto b = true;
    auto ch = 'x';
    auto i = 123;
    auto d = 1.2;
    auto c = complex<double>(1);
}
