#include "Fraction.h"

Fraction::Fraction()
{
	this->denominator = 1;
	this->numerator = 0;
}

Fraction::Fraction(integer _numerator, integer _denominator)
{
	this->numerator = _numerator;
	this->denominator = _denominator;
	if (this->denominator < 0)
	{
		this->denominator = -this->denominator;
		this->numerator = -this->numerator;
	}
}

Fraction::~Fraction()
{
}

integer Fraction::GCD(integer a, integer b)
{
	integer maxx = a > b ? a : b;
	integer minn = a + b - maxx;
	integer r = maxx % minn;
	while (r > 0)
	{
		maxx = minn;
		minn = r;
		r = maxx % minn;
	}
	return minn;
}

void Fraction::Simplify()
{
	bool isnegative = this->numerator < 0 ? true : false;
	if (isnegative)
	{
		this->numerator = -this->numerator;
	}
	if (this->numerator == 0)
	{
		this->denominator = 1;
		return;
	}
	integer gcd = GCD(this->numerator, this->denominator);
	this->denominator /= gcd;
	this->numerator /= gcd;
	if (isnegative)
	{
		this->numerator = -this->numerator;
	}
}

Fraction Fraction::operator+(const Fraction &t) const
{
	Fraction ans;
	ans.denominator = this->denominator * t.denominator;
	ans.numerator = this->denominator * t.numerator + this->numerator * t.denominator;
	ans.Simplify();
	return ans;
}

Fraction Fraction::operator*(const Fraction &t) const
{
	Fraction ans;
	ans.denominator = this->denominator * t.denominator;
	ans.numerator = this->numerator * t.numerator;
	ans.Simplify();
	return ans;
}

Fraction Fraction::operator/(const Fraction &t) const
{
	Fraction ans;
	ans.denominator = this->denominator * t.numerator;
	ans.numerator = this->numerator * t.denominator;
	ans.Simplify();
	return ans;
}

Fraction Fraction::operator-(const Fraction &t) const
{
	Fraction ans;
	ans.denominator = this->denominator * t.denominator;
	ans.numerator = -this->denominator * t.numerator + this->numerator * t.denominator;
	ans.Simplify();
	return ans;
}

bool Fraction::operator==(const Fraction &t) const
{
	if (this->numerator == t.numerator && this->denominator == t.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator<=(const Fraction &t) const
{
	return this->numerator * t.denominator <= t.numerator * this->denominator;
}

bool Fraction::operator>=(const Fraction &t) const
{
	return this->numerator * t.denominator >= t.numerator * this->denominator;
}

bool Fraction::operator<(const Fraction &t) const
{
	return this->numerator * t.denominator < t.numerator * this->denominator;
}

bool Fraction::operator>(const Fraction &t) const
{
	return this->numerator * t.denominator > t.numerator * this->denominator;
}

void Fraction::operator+=(const Fraction &t)
{
	*(this) = *(this) + t;
}

void Fraction::operator-=(const Fraction &t)
{
	*(this) = *(this) - t;
}

void Fraction::operator*=(const Fraction &t)
{
	*(this) = *(this) * t;
}

void Fraction::operator/=(const Fraction &t)
{
	*(this) = *(this) / t;
}

istream &operator>>(istream &input, Fraction &a)
{
	char t;
	input >> a.numerator >> t >> a.denominator;
	return input;
}

ostream &operator<<(ostream &output, const Fraction &a)
{
	output << a.numerator << "/" << a.denominator;
	return output;
}

Fraction operator+(const Fraction &a, const integer b)
{
	Fraction ans(b, 1);
	ans += a;
	return ans;
}

Fraction operator+(const integer b, const Fraction &a)
{
	Fraction ans(b, 1);
	ans += a;
	return ans;
}

Fraction operator-(const Fraction &a, const integer b)
{
	Fraction t(b, 1);
	return a - t;
}

Fraction operator-(const integer a, const Fraction &b)
{
	Fraction t(a, 1);
	return t - b;
}

Fraction operator*(const Fraction &a, const integer b)
{
	Fraction t(b, 1);
	return a * t;
}

Fraction operator*(const integer b, const Fraction &a)
{
	Fraction t(b, 1);
	return a * t;
}

Fraction operator/(const Fraction &a, const integer b)
{
	Fraction t(b, 1);
	return a / t;
}

Fraction operator/(const integer a, const Fraction &b)
{
	Fraction t(a, 1);
	return t / b;
}

Fraction ToFraction(string s)
{
	int sl = s.length();
	string s1, s2, s3;
	bool dot1 = false, dot2 = false, end = false;
	for (int i = 0; i < sl; i++)
	{
		if (!dot1)
		{
			if (s[i] == '.')
			{
				dot1 = true;
				continue;
			}
			else
			{
				s1.push_back(s[i]);
			}
		}
		else if (!dot2)
		{
			if (s[i] == '.')
			{
				dot2 = true;
				continue;
			}
			else
			{
				s2.push_back(s[i]);
			}
		}
		else if (!end)
		{
			if (s[i] == '.')
			{
				end = true;
				break;
			}
			else
			{
				s3.push_back(s[i]);
			}
		}
	}
	end = true;
	integer k = 1;
	integer temp = 0;
	int s1l = s1.length();
	for (int i = 0; i < s1l; i++)
	{
		temp += (s1[i] - '0') * k;
		k *= 10;
	}
	integer part1 = temp;
	temp = 0;
	int s2l = s2.length();
	k = 1;
	for (int i = 0; i < s2l; i++)
	{
		temp += (s2[s2l - 1 - i] - '0') * k;
		k *= 10;
	}
	Fraction part2(temp, k);
	int k1 = k;
	temp = 0;
	k = 1;
	int s3l = s3.length();
	for (int i = 0; i < s3l; i++)
	{
		temp += (s3[s3l - 1 - i] - '0') * k;
		k *= 10;
	}
	if (temp != 0)
	{
		Fraction part3(temp, (k - 1) * k1);
		return part1 + part2 + part3;
	}
	else
	{
		return part1 + part2;
	}
}
