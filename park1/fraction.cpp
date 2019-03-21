// File: fraction.cpp
// Name: Heecheon Park
// Class: CSIS 352
// Program: prog1
// Date: January 21st, 2019

/*  
This file includes the actual implementation of fraction class.
For description of each function, please refer to fraction.h file.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "fraction.h"

using namespace std;

formatType fraction::format=mixed;

void fraction::outputFormat(formatType f)
{
    fraction::format = f;
}

fraction::fraction(int num, int denom)
{
    fraction::setFraction(num, denom);
}

fraction::fraction(double decim)
{
    ostringstream output;
    string stringDecimal, stringNumerator, stringDenominator;
    int numer, denom, countFloats, gcd;
    
    output << decim;
    stringDecimal = output.str();

    int decimalIndex = 0;
    for (int i = 0; stringDecimal[i] != '.'; i++)
    {
        decimalIndex = i;
    }
// cerr << "Decimal Index: " << decimalIndex << endl;
    countFloats = stringDecimal.size() - (decimalIndex + 2);
    stringNumerator = stringDecimal.erase(decimalIndex + 1, 1);
    denom = pow(10, countFloats);
// cerr << "countFloats: " << countFloats << endl;
// cerr << "stringNumerator: " << stringNumerator << endl;
// cerr << "stringDenominator: "<< denom << endl;

    istringstream inputNumer(stringNumerator);
    inputNumer >> numer;

    gcd = getGCD(abs(numer), abs(denom));

    numer /= gcd;
    denom /= gcd;

    // istringstream inputDenom(stringDenominator);
    // inputDenom >> denom;

    setFraction(numer, denom);
}

void fraction::setFraction(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

void fraction::setFraction(int integer)
{
    setFraction(integer * 100, 100);
}

void fraction::setFraction(double decim)
{
    ostringstream output;
    string stringDecimal, stringNumerator, stringDenominator;
    int numer, denom, countFloats, gcd;
    
    output << decim;
    stringDecimal = output.str();

    int decimalIndex = 0;
    for (int i = 0; stringDecimal[i] != '.'; i++)
    {
        decimalIndex = i;
    }
// cerr << "Decimal Index: " << decimalIndex << endl;
    countFloats = stringDecimal.size() - (decimalIndex + 2);
    stringNumerator = stringDecimal.erase(decimalIndex + 1, 1);
    denom = pow(10, countFloats);
// cerr << "countFloats: " << countFloats << endl;
// cerr << "stringNumerator: " << stringNumerator << endl;
// cerr << "stringDenominator: "<< denom << endl;

    istringstream inputNumer(stringNumerator);
    inputNumer >> numer;

    gcd = getGCD(abs(numer), abs(denom));

    numer /= gcd;
    denom /= gcd;

    // istringstream inputDenom(stringDenominator);
    // inputDenom >> denom;

    setFraction(numer, denom);
}

int fraction::getDenominator() const
{
    return denominator;
}

int fraction::getNumerator() const
{
    return numerator;
}

double fraction::decimalValue() const
{
    double decValue = static_cast<double>(getNumerator()) / getDenominator();
    return decValue;
}

int fraction::getGCD(int numerator, int denominator) const
{
    if (numerator % denominator == 0)
    {
        return denominator;
    }
    else
        return getGCD(denominator, numerator % denominator);
}

/*
Practicing "?" expression from 252

int fraction::getGCD(int numerator, int denominator)
{
    return (numerator % denominator == 0 ? denominator : getGCD(denominator, numerator % denominator));
}
 */

string fraction::getProper() const
{
    ostringstream outputInt, outputNumerator, outputDenominator;
    string result;
    int intVal, tmpNumer, tmpDenom, gcd;

    gcd = getGCD(getNumerator(), getDenominator());

    if(abs(getNumerator()) > abs(getDenominator()) && (getNumerator() % getDenominator() != 0))
    {
        intVal = getNumerator() / getDenominator();
        tmpNumer = (getNumerator() % getDenominator()) / gcd;
        tmpDenom = getDenominator() / gcd;
        outputInt << intVal;
        outputNumerator << abs(tmpNumer);
        outputDenominator << abs(tmpDenom);
        result = outputInt.str() + ' ' + outputNumerator.str() + '/' + outputDenominator.str();
    }
    else if (abs(getNumerator()) < abs(getDenominator()) || (getNumerator() % getDenominator() == 0))
    {
        intVal = getNumerator() / getDenominator();
        outputInt << intVal;
        result = outputInt.str();
    }
    if(abs(getNumerator()) < abs(getDenominator()))
    {
        outputNumerator << getNumerator();
        outputDenominator << getDenominator();
        result = outputNumerator.str() + '/' + outputDenominator.str();
    }
    return result;
}

void fraction::reduce()
{
    int gcd = getGCD(getNumerator(), getDenominator());
    int tmpNum = getNumerator()/gcd;
    int tmpDenom = getDenominator()/gcd;
    setFraction(tmpNum, tmpDenom);
}

void fraction::setDenominator(int newDenom)
{
    int newNumer;
    if ((getNumerator() * newDenom % getDenominator()) == 0)
    {
        newNumer = getNumerator() * newDenom / getDenominator();
        setFraction(newNumer, newDenom);
    }
    else
    {
        cout << "This is an error because the numerator becomes " << static_cast<double>(getNumerator() * newDenom)/getDenominator() << endl; 
    }
}

fraction fraction::operator+(const fraction& f) const
{
    double sumDecimal;
    sumDecimal = decimalValue() + f.decimalValue();
    fraction tmpFrac(sumDecimal);
    return tmpFrac;
}

fraction fraction::operator-(const fraction& f) const
{
    double subtractDecimal;
    subtractDecimal = decimalValue() - f.decimalValue();
    fraction tmpFrac(subtractDecimal);
    return tmpFrac;
}

fraction fraction::operator*(const fraction& f) const
{
    double multDecimal;
    multDecimal = decimalValue() * f.decimalValue();
    fraction tmpFrac(multDecimal);
    return tmpFrac;
}

fraction fraction::operator/(const fraction& f) const
{
    double divDecimal;
    divDecimal = decimalValue() / f.decimalValue();
    fraction tmpFrac(divDecimal);
    return tmpFrac;
}

const fraction& fraction::operator=(fraction f)
{
    setFraction(f.decimalValue());
    return *this;
}

const fraction& fraction::operator=(double d)
{
    setFraction(d);
    return *this;
}

bool fraction::operator==(const fraction& f) const
{
    return decimalValue() == f.decimalValue();
}

bool fraction::operator==(const double d) const
{
    return decimalValue() == d;
}

bool fraction::operator==(const int i) const
{
    return decimalValue() == i;
}

bool fraction::operator<=(const fraction& f) const
{
    return *this == f || *this < f;
}

bool fraction::operator<=(const double d) const
{
    return *this == d || *this < d;
}

bool fraction::operator<=(const int i) const
{
    return *this == i || *this < i;
}

bool fraction::operator<(const fraction& f) const
{
    return decimalValue() < f.decimalValue();
}

bool fraction::operator<(const double d) const
{
    return decimalValue() < d;
}

bool fraction::operator<(const int i) const
{
    return decimalValue() < i;
}

bool fraction::operator>(const fraction& f) const
{
    return decimalValue() > f.decimalValue();
}

bool fraction::operator>(const double d) const
{
    return decimalValue() > d;
}

bool fraction::operator>(const int i) const
{
    return decimalValue() > i;
}

bool fraction::operator>=(const fraction& f) const
{
    return *this == f || *this > f;
}

bool fraction::operator>=(const double d) const
{
    return *this == d || *this > d;
}

bool fraction::operator>=(const int i) const
{
    return *this == i || *this > i;
}

istream& operator >>(istream& in, fraction& f)
{
    int numerator, denominator;
    char delimiter;
    in >> numerator;
    in >> delimiter;
    in >> denominator;
    f.setFraction(numerator, denominator);

    return in;
}

ostream& operator <<(ostream& out, const fraction& f)
{
    switch (f.format)
    {
        // case improper: out << (f.getNumerator() / f.getGCD(f.getNumerator(), f.getDenominator())) << "/" << f.getDenominator() / f.getGCD(f.getNumerator(), f.getDenominator()); break;
        case improper: out << (f.getNumerator()) << "/" << f.getDenominator(); break;
        case mixed: out << f.getProper(); break;
        case decimal: out << f.decimalValue(); break;
        default: out << f.getProper(); break;
    }
    return out;
}