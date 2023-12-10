/*
Course: CS 255
Name: Lucas Hasting and James Palmer
Date: 9/13/2022
Description: Adds fraction ability to c++
*/
#include <iostream>
using namespace std;
// Class declaration
class Fraction{
private:
    int num;
    int den;
public:
    //constructors-Done In Class
    Fraction(); // no data
    Fraction(int whole); // 1 data
    Fraction(int n, int d); // 2 data

    //arithmetic operators-Done In Class
    Fraction operator*  (const Fraction& right)const;
    Fraction operator/  (const Fraction& right)const;
    Fraction operator+  (const Fraction& right)const;
    Fraction operator-  (const Fraction& right)const;

    //IOstream operators-Done In Class
    friend ostream& operator<<(ostream& os, const Fraction& right);
    friend istream& operator>>(istream& is, Fraction& right);

    //relational operator friend functions by James Palmer
    friend bool operator==(const Fraction& left, const Fraction& right);
    friend bool operator!=(const Fraction& left, const Fraction& right);
    friend bool operator<(const Fraction& left, const Fraction& right);
    friend bool operator<=(const Fraction& left, const Fraction& right);
    friend bool operator>(const Fraction& left, const Fraction& right);
    friend bool operator>=(const Fraction& left, const Fraction& right);
};

//constructors-Done In Class
Fraction::Fraction()
{
   num = 0;
   den = 1;
}

Fraction::Fraction(int whole)
{
   num = whole;
   den = 1;
}

Fraction::Fraction(int n, int d)
{
   num = n;
   if (d == 0)
      d = 1;
   den = d;
}

//arithmetic operator methods-Done In Class
Fraction Fraction::operator*(const Fraction& right)const
{
    Fraction product(num * right.num, den * right.den);
    return product;
}

Fraction Fraction::operator/(const Fraction& right)const
{
    Fraction quotient(num * right.den, den * right.num);
    return quotient;
}

Fraction Fraction::operator+(const Fraction& right)const
{
    Fraction sum((num * right.den) + (right.num * den), den * right.den);
    return sum;
}

Fraction Fraction::operator-(const Fraction& right)const
{
    Fraction difference((num * right.den) - (right.num * den), den * right.den);
    return difference;
}

//IOstream operator methods-Done In Class
ostream& operator<<(ostream& os, const Fraction& right)
{
    os << right.num << "/" << right.den;
    return os;
}

istream& operator>>(istream& is, Fraction& right)
{
    char slash;
    is >> right.num;
    is >> slash;
    is >> right.den;
    return is;
}

//relational operator friend functions-James Palmer
bool operator==(const Fraction& left, const Fraction& right)
{
    return ((left.num * right.den) == (left.den * right.num));
}

bool operator!=(const Fraction& left, const Fraction& right)
{
    return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right)
{
    return ((left.num * right.den) < (left.den * right.num));
}

bool operator<=(const Fraction& left, const Fraction& right)
{
    return ((left < right) || (left == right));
}

bool operator>(const Fraction& left, const Fraction& right)
{
    return ((left.num * right.den) > (left.den * right.num));
}

bool operator>=(const Fraction& left, const Fraction& right)
{
    return ((left > right) || (left == right));
}

int main() //main driver program by Lucas Hasting
{
    //Creates f1 and f2 objects with no data
    Fraction f1, f2;

    //get input for the f1 and f2 objects
    cin >> f1 >> f2;

    //test each relational operator
    cout << "equals: " << (f1 == f2) << endl;
    cout << "not equals: " << (f1 != f2) << endl;
    cout << "less than: " << (f1 < f2) << endl;
    cout << "greater than: " << (f1 > f2) << endl;
    cout << "less than/equals: " << (f1 <= f2) << endl;
    cout << "greater than/equals: " << (f1 >= f2) << endl;

    //end the program
    return 0;
}
