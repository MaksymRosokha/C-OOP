#include "MathOperations.h"
#include "Fraction.h"

Fraction MathOperations::add(const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,
        a.denominator * b.denominator);
}

Fraction MathOperations::subtract(const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,
        a.denominator * b.denominator);
}

Fraction MathOperations::multiply(const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

Fraction MathOperations::divide(const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
}

bool MathOperations::equals(const Fraction& a, const Fraction& b) {
    return a.numerator == b.numerator && a.denominator == b.denominator;
}

bool MathOperations::notEquals(const Fraction& a, const Fraction& b) {
    return !(equals(a, b));
}
