#if !defined(COUSAR_COMPLEX_H)
#define COUSAR_COMPLEX_H

namespace cousar {
class Complex {
   private:
    double m_real;
    double m_imag;

   public:
    Complex();
    Complex(double a, double b);
    Complex(const Complex& other);
    ~Complex() = default;

    double real();
    double imag();
    Complex& conj();

    Complex& operator=(const Complex& other);
    Complex& operator+(const Complex& other);
    Complex& operator+(double other);
    Complex& operator-(const Complex& other);
    Complex& operator-(double other);
    Complex& operator*(const Complex& other);
    Complex& operator*(double other);
    Complex& operator/(const Complex& other);
    Complex& operator/(double other);

    Complex& operator+=(const Complex& other);
    Complex& operator+=(double a);
    Complex& operator-=(const Complex& other);
    Complex& operator-=(double a);

    bool operator==(const Complex& other);
    bool operator!=(const Complex& other);

    friend Complex& add(const Complex& a, const Complex& b);
    friend Complex& add(const Complex& a, double b);
    friend Complex& add(double a, const Complex& b);

    friend Complex& subtract(const Complex& a, const Complex& b);
    friend Complex& subtract(const Complex& a, double b);
    friend Complex& subtract(double a, const Complex& b);

    friend Complex& multiply(const Complex& a, const Complex& b);
    friend Complex& multiply(const Complex& a, double b);
    friend Complex& multiply(double a, const Complex& b);

    friend Complex& divide(const Complex& a, const Complex& b);
    friend Complex& divide(const Complex& a, double b);

    friend Complex& pow(double a, const Complex& b);
    friend Complex& pow(const Complex& a, double b);

    friend double abs(const Complex& a);

    friend double imag(const Complex& a);
    friend double real(const Complex& a);
};
}  // namespace cousar

#endif  // COUSAR_COMPLEX_H
