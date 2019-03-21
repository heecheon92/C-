// File: fraction.h
// Name: Heecheon Park
// Class: CSIS 352
// Program: prog1
// Date: January 21st, 2019

/*  
This file contains declaration of fraction class, its implementation, and stream operators (extraction and injection)
*/
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <string>
using namespace std;

/* 
    enum data type that indicates how to display a fraction object.
 */
enum formatType {improper, decimal, mixed};

class fraction
{
    public:
        /*
            method - constructor
            description - construct a new fraction instance
            preconditions - fraction.h must be included for this file to be used
            postconditions - fraction object will be created
            method input - none (default is 0, 0)
                         - int, int
                         - double
            method output - fraction object
        */
        fraction(int = 0, int = 0);
        fraction(double);
        /*
            method - getNumerator, accessor, getter
            description - retrieve a numerator of a fraction object
            preconditions - fraction object must exist
            postconditions - numerator value will be displayed
            method input - none
            method output - int numerator
        */
        int getNumerator() const;
        /*
            method - getDenominator, accessor, getter
            description - retrieve a denominator of a fraction object
            preconditions - fraction object must exist
            postconditions - denominator value will be displayed
            method input - none
            method output - int denominator
        */
        int getDenominator() const;
        /*
            method - int getGCD
            description - retrieves a greates common divisor of 2 integers
            preconditions - it is not a static so a fraction object must exist to call this function
            postconditions - GCD of 2 integers will be displayed
            method input - int, int
            method output - int Greatest Common Divisor
        */
        int getGCD() const;
        /*
            method - double decimalValue
            description - returns a decimal value of a fraction
            preconditions - a fraction object must exist to call this function
            postconditions - decimal value will be displayed
            method input - None
            method output - double decimal
        */
        double decimalValue() const;
        /*
            method - setNumerator, mutator, setter
            description - sets a Numerator
            preconditions - a fraction object must exist to call this function
            postconditions - it changes numerator and proportionally changes the denominator
            method input - int
            method output - void
        */
        void setNumerator(int);
        /*
            method - setDenominator, mutator, setter
            description - sets a denominator
            preconditions - a fraction object must exist to call this function
            postconditions - it changes denominator and proportionally changes the numerator
            method input - int
            method output - void
        */
        void setDenominator(int);
        /*
            method - setFraction, mutator, setter
            description - sets a fraction parameters
            preconditions - a fraction object must exist to call this function
            postconditions - sets a value of a fraction object
            method input - int numerator, int denominator
                         - int
                         - double
            method output - void
        */
        void setFraction(int, int);
        void setFraction(int);
        void setFraction(double);
        /*
            method - reduce
            description - converts fraction into minimum term possible
            preconditions - a fraction object must exist to call this function
            postconditions - it reduces numerator and denominator by dividing by GCD
            method input - void
            method output - void
        */
        void reduce();
        /*
            method - getProper
            description - this function determines if a fraction object can be represented as mixed or improper
            preconditions - a fraction object must exist to call this function
            postconditions - it returns string value of mixed form of fraction
            method input - void
            method output - string mixed form fraction
        */
        string getProper() const;
        /*
            method - Equal operator
            description - compares a fraction object to other values
            preconditions - a fraction object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - fraction
                         - double
                         - int
            method output - bool
        */
        bool operator==(const fraction&) const;
        bool operator==(const double) const;
        bool operator==(const int) const;
        /*
            method - Less than or equal to operator
            description - compares a fraction object to other values
            preconditions - a fraction object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - fraction
                         - double
                         - int
            method output - bool
        */
        bool operator<=(const fraction&) const;
        bool operator<=(const double) const;
        bool operator<=(const int) const;
        /*
            method - Less than operator
            description - compares a fraction object to other values
            preconditions - a fraction object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - fraction
                         - double
                         - int
            method output - bool
        */
        bool operator<(const fraction&) const;
        bool operator<(const double) const;
        bool operator<(const int) const;
        /*
            method - Greater than or equal to operator
            description - compares a fraction object to other values
            preconditions - a fraction object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - fraction
                         - double
                         - int
            method output - bool
        */
        bool operator>=(const fraction&) const;
        bool operator>=(const double) const;
        bool operator>=(const int) const;
        /*
            method - Greater than operator
            description - compares a fraction object to other values
            preconditions - a fraction object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - fraction
                         - double
                         - int
            method output - bool
        */
        bool operator>(const fraction&) const;
        bool operator>(const double) const;
        bool operator>(const int) const;
        /*
            method - Addition operator
            description - Adds two fractions
            preconditions - a fraction object must exist to call this function
            postconditions - returns a summed fraction
            method input - fraction
            method output - fraction
        */
        fraction operator+(const fraction&) const;
        /*
            method - Subtraction operator
            description - Subtracts two fractions
            preconditions - a fraction object must exist to call this function
            postconditions - returns a subtracted fraction
            method input - fraction
            method output - fraction
        */
        fraction operator-(const fraction&) const;
        /*
            method - Multiplication operator
            description - Multiplies two fractions
            preconditions - a fraction object must exist to call this function
            postconditions - returns a product of fractions as a fraction object
            method input - fraction
            method output - fraction
        */
        fraction operator*(const fraction&) const;
        /*
            method - Division operator
            description - Divide two fractions
            preconditions - a fraction object must exist to call this function
            postconditions - returns a divided fraction
            method input - fraction
            method output - fraction
        */
        fraction operator/(const fraction&) const;
        /*
            method - Assignment operator
            description - Assigns a value to a fraction object
            preconditions - a fraction object must exist to call this function
            postconditions - A fraction gets assigned with a value
            method input - fraction
                         - double
            method output - fraction
        */
        const fraction& operator=(fraction);
        const fraction& operator=(double);

        /*
            method - getFormat, accessor, getter
            description - returns enum data type object
            preconditions - fraction.h must be included
            postconditions - None
            method input - None
            method output - formatType
        */
        static formatType getFormat();
        /*
            method - outputFormat, mutator, setter
            description - sets how a fraction object can be presented
            preconditions - fraction.h must be included
            postconditions - Fraction representation will be set
            method input - formatType
            method output - void
        */
        static void outputFormat(formatType);

        /*
        ostream "<<" is not a member function of this class.
        "friend" identifier allows non-member function to access
        private attributes.

        friend function
            - a non member function given access to the private members of a class.
            - avoid friends if possible.
         */
        friend ostream& operator<<(ostream&, const fraction&);

        /* 
        I want to use a gcd function to convert decimal to fraction
        gcd by Euclidean algorithm
         */
        int getGCD(int, int) const;

    private:

        int numerator;
        int denominator;

    static formatType format;

};
/*
    method - injection operator
    description - in stream operator
    preconditions - None
    postconditions - None
    method input - standard input, int, double
    method output - in stream operator, fraction
*/
istream& operator>>(istream&, fraction&);

#endif