namespace User {

class complex {
public:
    complex(double r, double i) :m_re{r}, m_im{i} {}
    complex(double r) :m_re{r}, m_im{0} {}
    complex() :m_re{0}, m_im{0} {}
    // construct complex from two scalars
    // construct complex from one scalar
    // default complex: {0,0}
    double real() const { return m_re; }
    void real(double d) { m_re=d; }
    double imag() const { return m_im; }
    void imag(double d) { m_im=d; }
    complex& operator+=(complex z) { m_re+=z.m_re, m_im+=z.m_im; return *this; }
    // add to re and im
    // and return the result
    complex& operator-=(complex z) { m_re-=z.m_re, m_im-=z.m_im; return *this; }
    complex& operator*=(complex);
    complex& operator/=(complex);
    // deﬁned out-of-class somewhere
    // deﬁned out-of-class somewhere
private:
    double m_re, m_im; // representation: two doubles
};

}


