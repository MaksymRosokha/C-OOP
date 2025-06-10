#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        std::cout << "Denominator cannot be zero!\nSetting to 1.\n";
        den = 1;
    }
    numerator = num;
    denominator = den;
}

Fraction::~Fraction() {}

void Fraction::reduce() {
    
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int num) {
    numerator = num;
    reduce();
}

void Fraction::setDenominator(int den) {
    if (den == 0) {
        std::cout << "Denominator cannot be zero!\nSetting to 1.\n";
        den = 1;
    }
    denominator = den;
    reduce();
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator,
        denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    return Fraction(numerator * other.denominator,
        denominator * other.numerator);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

void Fraction::display() const {
    std::cout << numerator << "/" << denominator;
}