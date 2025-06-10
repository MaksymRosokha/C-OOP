#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            cout << "Denominator cannot be zero! Setting to 1." << endl;
            denominator = 1;
        }
    }

    ~Fraction() {}

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw runtime_error("Division by zero!");
        }
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return Fraction(new_num, new_den);
    }

    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    void simplify() {
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    void display() const {
        cout << numerator << "/" << denominator;
    }

    friend class MathOperations;
};

class MathOperations {
public:
    static Fraction add(const Fraction& a, const Fraction& b) {
        return a + b;
    }

    static Fraction subtract(const Fraction& a, const Fraction& b) {
        return a - b;
    }

    static Fraction multiply(const Fraction& a, const Fraction& b) {
        return a * b;
    }

    static Fraction divide(const Fraction& a, const Fraction& b) {
        return a / b;
    }

    static bool compare(const Fraction& a, const Fraction& b) {
        return a == b;
    }
};

void testOperation(const string& operationName, const Fraction& result, const Fraction& expected) {
    cout << "Test " << operationName << ": ";
    result.display();
    cout << " (Expected: ";
    expected.display();
    cout << ") - " << (result == expected ? "OK" : "ERROR") << endl;
}

int main() {
    Fraction u1(1, 2);
    u1.display();
    cout << endl;
    Fraction u2(1, 3);
    u2.display();
    cout << endl;
    Fraction u3(0, 1);
    u3.display();
    cout << endl;
    Fraction u4(1, 0);
    u4.display();
    cout << endl;
    Fraction u5(7, 14);
    u5.display();
    cout << endl;
    Fraction u6(8, 17);
    u6.display();
    cout << endl;

    testOperation("addition", u1 + u2, Fraction(5, 6));
    testOperation("subtraction", u1 - u2, Fraction(1, 6));
    testOperation("multiplication", u1 * u2, Fraction(1, 6));
    testOperation("division", u1 / u2, Fraction(3, 2));

    cout << "Comparison test: 1/2 = 1/3: " << (MathOperations::compare(u1, u2) ? "Equal" : "Not equal") << endl;
    cout << "Comparison test: 1/2 = 1/2: " << (MathOperations::compare(u1, u1) ? "Equal" : "Not equal") << endl;

    cout << "Fraction "; u5.display(); cout << ": ";
    u5.simplify();
    testOperation("reduction", u5, Fraction(1, 2));
    cout << "Fraction "; u6.display(); cout << ": ";
    u6.simplify();
    testOperation("reduction", u6, Fraction(8, 17));

    return 0;
}