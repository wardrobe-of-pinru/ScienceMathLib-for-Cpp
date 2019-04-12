#include "Vector.h"
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <stdarg.h>


namespace ScienceMathLib
{
	std::set<char> FactorStart__ = { '*', '/', '+', '-', ',', '[', '(', '{' };
///////////////////////////////////////////////////////////////////////////////////
//                                 Vector2                                       //
///////////////////////////////////////////////////////////////////////////////////

Vector2::Vector2()
{
    X = 0;
    Y = 0;
}

Vector2::Vector2(const double x,const double y)
{
    X = x;
    Y = y;
}


Vector2 operator+(const Vector2 &a, const Vector2 &b)
{
    Vector2 v(a.X + b.X, a.Y + b.Y);
    return v;
}
Vector2 operator-(const Vector2 &a, const Vector2 &b)
{
    Vector2 v(a.X - b.X, a.Y - b.Y);
    return v;
}
double operator*(const Vector2 &a, const Vector2 &b)
{
    return a.X * b.X + a.Y * b.Y;
}
Vector2 operator*(const double a, const Vector2 &b)
{
    Vector2 v(a * b.X, a * b.Y);
    return v;
}

std::string Vector2::ToString()
{
    char buf[20];
    sprintf_s(buf, "%.5lf", X);
    std::string xstr(buf);
    sprintf_s(buf, "%.5lf", Y);
    std::string ystr(buf);
    return "(" + xstr + "," + ystr + ")";
}

double Vector2::Modulus()
{
    return sqrt(X * X + Y * Y);
}

double Vector2::ModulusSquare()
{
    return X * X + Y * Y;
}

double Vector2::Angle()
{
    return acos(X / (Modulus() * 1.00000001));
}

double Vector2::AngleBetween(Vector2 &a, Vector2 &b)
{
    return acos(a * b / (a.Modulus() * b.Modulus()));
}

double Vector2::CosAngleBetween(Vector2 &a, Vector2 &b)
{
    return a * b / a.Modulus() / b.Modulus();
}

Vector2 Vector2::UnitVector()
{
    double m = Modulus();
    if (m != 0)
    {
        Vector2 v(X / m, Y / m);
        return v;
    }
    else
    {
        Vector2 v(0, 0);
        return v;
    }
}

Vector2 Vector2::operator+=(const Vector2 &a)
{
    X += a.X;
    Y += a.Y;
    return *this;
}

Vector2 Vector2::operator-=(Vector2 a)
{
    X -= a.X;
    Y -= a.Y;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////
//                                 Vector3                                       //
///////////////////////////////////////////////////////////////////////////////////

Vector3::Vector3(double _x, double _y, double _z)
{
    X = _x;
    Y = _y;
    Z = _z;
}

Vector3::Vector3(double Longitude, double Latitude)
{
    X = cos(Longitude) * cos(Latitude);
    Y = sin(Longitude) * cos(Latitude);
    Z = sin(Latitude);
}
Vector3 operator+(const Vector3 &a, const Vector3 &b)
{
    Vector3 v(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
    return v;
}
Vector3 operator-(const Vector3 &a, const Vector3 &b)
{
    Vector3 v(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
    return v;
}
double operator*(const Vector3 &a, const Vector3 &b)
{
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}
Vector3 operator*(const double a, const Vector3 &b)
{
    Vector3 v(a * b.X, a * b.Y, a * b.Z);
    return v;
}

Vector3 operator&(const Vector3 &a, const Vector3 &b)
{
    Vector3 v(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
    return v;
}

std::string Vector3::ToString()
{
    char buf[20];
    sprintf_s(buf, "%.5lf", X);
    std::string xstr(buf);
    sprintf_s(buf, "%.5lf", Y);
    std::string ystr(buf);
    sprintf_s(buf, "%.5lf", Z);
    std::string zstr(buf);
    return "(" + xstr + "," + ystr + "," + zstr + ")";
}

double Vector3::Modulus()
{
    return sqrt(X * X + Y * Y + Z * Z);
}

double Vector3::ModulusSquare()
{
    return X * X + Y * Y + Z * Z;
}

double Vector3::Angle()
{
    return acos(X / (Modulus() * 1.00000001));
}

double Vector3::AngleBetween(Vector3 &a, Vector3 &b)
{
    return acos(a * b / (a.Modulus() * b.Modulus() * 1.00000001));
}

Vector3 Vector3::UnitVector()
{
    double m = Modulus();
    Vector3 v(X / m, Y / m, Z / m);
    return v;
}

Vector3 Vector3::AntiUnitVector()
{
    double m = -Modulus();
    Vector3 v(X / m, Y / m, Z / m);
    return v;
}

Vector3 Vector3::operator+=(const Vector3 &a)
{
    X += a.X;
    Y += a.Y;
    Z += a.Z;
    return *this;
}

Vector3 Vector3::operator-=(const Vector3 &a)
{
    X -= a.X;
    Y -= a.Y;
    Z -= a.Z;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////
//                                  Vector                                       //
///////////////////////////////////////////////////////////////////////////////////

Vector::Vector()
{
    N = 0;
    X = nullptr;
}

Vector::Vector(const unsigned int _N)
{
    N = _N;
    X = new double[N + 1];
}

Vector::Vector(const unsigned int _N, double _X1, ...)
{
    va_list ap;
    va_start(ap, _N);
    N = _N;
    X = new double[N + 1];
    X[1] = _X1;
    for (int i = 2; i <= N; i++)
    {
        X[i] = va_arg(ap, double);
    }
    va_end(ap);
}
Vector::Vector(const Vector &v)
{
    N = v.N;
    X = new double[N + 1];
    for (int i = 1; i <= N; i++)
    {
        X[i] = v.X[i];
    }
}
void Vector::operator=(const Vector& v)
{
    N = v.N;
    delete[] X;
    X = new double[N + 1];
    for (int i = 1; i <= N; i++)
    {
        X[i] = v.X[i];
    }
}
Vector::Vector(const unsigned int _N, double _X[])
{
    N = _N;
    X = new double[N + 1];
    for (int i = 1; i <= N; i++)
    {
        X[i] = _X[i];
    }
}

Vector::~Vector()
{
    delete[] X;
}

void Vector::Assign(const unsigned int _N, double _X, ...)
{
    delete[] X;

    va_list ap;
    va_start(ap, _N);
    N = _N;
    X = new double[N + 1];
    for (int i = 1; i <= N; i++)
    {
        X[i] = va_arg(ap, double);
    }
    va_end(ap);
}

void Vector::Reset(const unsigned int _N)
{
    delete[] X;
    N = _N;
    X = new double[N + 1];
}

Vector operator+(const Vector &a, const Vector &b)
{
    Vector v;
    if (a.N == b.N)
    {
        v.X = new double[a.N + 1];
        for (int i = 1; i <= a.N; i++)
        {
            v.X[i] = a.X[i] + b.X[i];
        }
    }
    else
    {
        v.X = new double[1];
    }
    return v;
}

Vector operator-(const Vector &a, const Vector &b)
{
    Vector v;
    if (a.N == b.N)
    {
        Vector v(a.N);
        for (int i = 1; i <= a.N; i++)
        {
            v.X[i] = a.X[i] - b.X[i];
        }
    }
    else
    {
        Vector v(0);
        return v;
    }
}

Vector operator*(const Vector &a, const Vector &b)
{

    if (a.N == b.N)
    {
        Vector v(a.N);
        for (int i = 1; i <= a.N; i++)
        {
            v.X[i] = a.X[i] * b.X[i];
        }
        return v;
    }
    else
    {
        Vector v(0);
        return v;
    }
}

Vector operator*(const double a, const Vector& b)
{
    Vector v(b.N);
    for (int i = 1; i <= b.N; i++)
    {
        v.X[i] = a * b.X[i];
    }
    return v;
}
///求模长
double Vector::Modulus()
{
    double m = 0;
    for (int i = 1; i <= N; i++)
    {
        m += X[i] * X[i];
    }
    return sqrt(m);
}
///求模长的平方
double Vector::ModulusSquare()
{
    double m = 0;
    for (int i = 1; i <= N; i++)
    {
        m += X[i] * X[i];
    }
    return m;
}

///返回字符串形式
std::string Vector::ToString()
{
    std::string s = "{";
    char buf[20];
    for (int i = 1; i < N; i++)
    {
        sprintf_s(buf, "%.5f", X[i]);
        s.append(buf);
        s.append(",");
    }
    sprintf_s(buf, "%.5f", X[N]);
    s.append(buf);
    s.append("}");
    return s;
}

double &Vector::operator[](unsigned int i)
{
    return X[i];
}

bool Vector::recVector(std::string& str,const unsigned int _start, unsigned int& i,Vector& v)
{   //此识别向量recVector与符号识别的识别向量recVectorS有所不同。recVector带括号识别:{x1,x2,...} 而revVectorS不带括号识别:x1,x2,...，更类似与recList


    //由于经常可能调用进行识别尝试，如果识别不匹配，要尽量早地退出，避免多余操作，所以先识别括号，再识别上文环境。
    if(str[_start]!='{')return false;
    if(_start>0&&FactorStart__.find(str[_start-1])==FactorStart__.end())return false;//一个向量的上下文环境就是因子的上下文环境

    unsigned int strln=str.size();
    i=_start+1;

    double x;
    std::vector<double> xs;//用stl的vector来暂时存储
    while(recFigure(str,i,i,x))
    {
        xs.push_back(x);
        if(str[i]==',')
        {
            i++;
        }
        else if(str[i]=='}')
        {
            i++;
            v.Reset(xs.size());
            for(unsigned int k=1;k<=v.N;k++)
                v.X[k]=xs[k-1];
            return true;
        }
    }
    i=_start;
    return false;
}
} // namespace ScienceMathLib
