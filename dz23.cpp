#include <iostream>
#include <cmath>

class Fraction {
private:
    int numerator;  
    int denominator;


    void simplify() {
        int gcd = std::__gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { 
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};












class Complex {
private:
    double real; 
    double imag; 

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        }
        else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }
};

int main() {
    Fraction f1(1, 2), f2(2, 3);
    std::cout << "Дроби:\n";
    std::cout << "f1 = " << f1 << ", f2 = " << f2 << "\n";
    std::cout << "f1 + f2 = " << f1 + f2 << "\n";
    std::cout << "f1 - f2 = " << f1 - f2 << "\n";
    std::cout << "f1 * f2 = " << f1 * f2 << "\n";
    std::cout << "f1 / f2 = " << f1 / f2 << "\n\n";

    Complex c1(3, 4), c2(1, -2);
    std::cout << "Комплексні числа:\n";
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << "\n";
    std::cout << "c1 + c2 = " << c1 + c2 << "\n";
    std::cout << "c1 - c2 = " << c1 - c2 << "\n";
    std::cout << "c1 * c2 = " << c1 * c2 << "\n";
    std::cout << "c1 / c2 = " << c1 / c2 << "\n";

    return 0;
}
