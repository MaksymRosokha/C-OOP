#pragma once
#include "MathOperations.h"

class Fraction
{
private:
    int numerator;
    int denominator;
    void reduce();

public:
    Fraction(int num = 0, int den = 1);
    ~Fraction();

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int num);
    void setDenominator(int den);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    void display() const;

    friend class MathOperations;
};

