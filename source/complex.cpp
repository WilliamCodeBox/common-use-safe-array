#include "complex.hpp"

namespace cousar {

Complex::Complex() : m_real(0.0), m_imag(0.0) {}

Complex::Complex(double a, double b) : m_real(a), m_imag(b) {}

Complex::Complex(const Complex& other)
    : m_real(other.real), m_imag(other.imag) {}

double Complex::real() { return m_real; }
double Complex::imag() { return m_imag; }

Complex& Complex::conj() {
    Complex a;
    a.m_real = this->m_real;
    a.m_imag = -this->m_imag;
    return a;
}

Complex& Complex::operator=(const Complex& other) {
    this->m_real = other.m_real;
    this->m_imag = other.m_imag;
    return *this;
}

Complex& Complex::operator+(const Complex& other) {
    Complex a;
    a.m_real = this->m_real + other.m_real;
    a.m_imag = this->m_imag + other.m_imag;
    return a;
}

Complex& Complex::operator+(double other) {
    Complex a;
    a.m_real = this->m_real + other;
    a.m_imag = this->m_imag;
    return a;
}

}  // namespace cousar
