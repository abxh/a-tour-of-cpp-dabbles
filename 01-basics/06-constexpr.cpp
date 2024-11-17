#include <vector>

using namespace std;

constexpr double square(double x)
{
    return x * x;
}

double sum(const vector<double>& array)
{
    auto sum = 0.;
    for (auto x : array) {
        sum += x;
    }
    return sum;
}

int main()
{
    const int dmv = 17;
    int var = 17;

    constexpr double max1 = 1.4 * square(dmv);
    constexpr double max2 = 1.4 * square(dmv);
    const double max3 = 1.4 * square(dmv);

    vector<double> v{1.2, 3.4, 4.5};
    const double s1 = sum(v);
    constexpr double s2 = sum(v);
}
