
#include <cstddef>

using uint = unsigned int; // typedef alt. works also for templates

template <typename T, int N>
struct Buffer {
    using value_type = T;
    constexpr int size()
    {
        return N;
    }
    T buf[static_cast<std::size_t>(N)];
};

Buffer<char, 1024> global_buffer;

void f()
{
    using foo = Buffer<int, 10>;

    foo buf0;
    foo buf1;

    Buffer<int, buf1.size()> buf2;
    Buffer<foo::value_type, 10> buf3;
}
