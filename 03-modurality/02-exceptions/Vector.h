#include <optional>

class Vector {
public:
    Vector(int s); 
    ~Vector();
    double& operator[](int i) const;
    std::optional<double> get(int i) noexcept;
    int size() const noexcept; 

private:
    double* m_elem;
    int m_sz;
};
