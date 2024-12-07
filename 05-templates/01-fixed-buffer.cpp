
#include <cstddef>

template <typename T, int N>
struct Buffer {
    using ValueType = T;
    constexpr int size()
    {
        return N;
    }
    ValueType buf[static_cast<std::size_t>(N)];
};

Buffer<char, 1024> global_buffer;

void f()
{
    Buffer<int, 10> buf0;
    Buffer<int, buf0.size()> buf1;
}
