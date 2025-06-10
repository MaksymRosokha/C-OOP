#pragma once
#include "Fraction.h"

class MathOperations
{
public:
    static Fraction add(const Fraction& a, const Fraction& b);
    static Fraction subtract(const Fraction& a, const Fraction& b);
    static Fraction multiply(const Fraction& a, const Fraction& b);
    static Fraction divide(const Fraction& a, const Fraction& b);

    static bool equals(const Fraction& a, const Fraction& b);
    static bool notEquals(const Fraction& a, const Fraction& b);
};

