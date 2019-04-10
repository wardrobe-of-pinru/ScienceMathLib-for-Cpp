#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;
typedef long long integer;
class Fraction
{
public:
  Fraction();                                               
  Fraction(integer _numerator, integer _denominator);               
  ~Fraction();                                              
  integer GCD(integer a, integer b);                
  void Simplify();
  Fraction operator+(const Fraction &t) const;              
  Fraction operator*(const Fraction &t) const;              
  Fraction operator/(const Fraction &t) const;              
  Fraction operator-(const Fraction &t) const;              
  bool operator==(const Fraction &t) const;                 
  bool operator<=(const Fraction &t) const;                 
  bool operator>=(const Fraction &t) const;                 
  bool operator<(const Fraction &t) const;                  
  bool operator>(const Fraction &t) const;                  
  void operator+=(const Fraction &t);                       
  void operator-=(const Fraction &t);                       
  void operator*=(const Fraction &t);                       
  void operator/=(const Fraction &t);                       
  friend istream &operator>>(istream &input, Fraction &a);  
  friend ostream &operator<<(ostream &output, const Fraction &a);
  friend Fraction operator+(const Fraction &a, const integer b);
  friend Fraction operator+(const integer b, const Fraction &a);
  friend Fraction operator-(const Fraction &a, const integer b);
  friend Fraction operator-(const integer a, const Fraction &b);
  friend Fraction operator*(const Fraction &a, const integer b);
  friend Fraction operator*(const integer b, const Fraction &a);
  friend Fraction operator/(const Fraction &a, const integer b);
  friend Fraction operator/(const integer a, const Fraction &b);

protected:
private:
  integer numerator;
  integer denominator;
};

Fraction ToFraction(string s);

#endif // FRACTION_H
