#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<string>
#include<cmath>
#include<cstdio>
#include<stdarg.h>
#include"Trifles.h"

namespace ScienceMathLib
{

    struct Vector2
    {
        double X, Y;

        Vector2();
        Vector2(const double x, const double y);

        friend Vector2 operator +(const Vector2& a, const Vector2& b);
        friend Vector2 operator -(const Vector2& a, const Vector2& b);
        friend double operator *(const Vector2& a, const Vector2& b);
        friend Vector2 operator *(const double a, const Vector2& b);

        std::string ToString();

        double Modulus();
        double ModulusSquare();
        double Angle();
        static double AngleBetween(Vector2& a, Vector2& b);
        static double CosAngleBetween(Vector2& a, Vector2& b);
        Vector2 UnitVector();
        Vector2 operator +=(const Vector2& a);

        Vector2 operator -=(Vector2 a);
    };


    struct Vector3
    {
        double X, Y, Z;

        Vector3(double _x, double _y, double _z);
        Vector3(double Longitude, double Latitude);

        friend Vector3 operator +(const Vector3& a,const Vector3& b);
        friend Vector3 operator -(const Vector3& a,const Vector3& b);
        friend double operator *(const Vector3& a,const Vector3& b);
        friend Vector3 operator *(const double a,const Vector3& b);
        friend Vector3 operator &(const Vector3& a,const Vector3& b);



        std::string ToString();

        double Modulus();
        double ModulusSquare();
        double Angle();
        static double AngleBetween(Vector3& a, Vector3& b);

        Vector3 UnitVector();
        Vector3 AntiUnitVector();

        Vector3 operator +=(const Vector3& a);
        Vector3 operator -=(const Vector3& a);

    };


    struct Vector
    {
        unsigned int N;
        double* X;

        Vector();
        Vector(const unsigned int _N);
        Vector(const Vector& v);
        Vector(const unsigned int _N,double _X[]);
        Vector(const unsigned int _N, double _X1, ...);

        ~Vector();


        void Assign(const unsigned int _N,double _X,...);
        void Reset(const unsigned int _N);
        void operator =(const Vector& v);
        friend Vector operator +(const Vector& a,const Vector& b);
        friend Vector operator -(const Vector& a,const Vector& b);
        friend Vector operator *(const Vector& a,const Vector& b);
        friend Vector operator *(const double a, const Vector& b);

        double Modulus();
        double ModulusSquare();

        std::string ToString();
        double& operator [](unsigned int i);

        ///从字符串中指定起始位置开始识别一个向量（有具体数值的）。若识别成功，则返回true,并用i指示所识别向量的末尾位置的后一位；否则返回false.
        static bool recVector(std::string& str,const unsigned int _start, unsigned int &i, Vector& v);
    };
}



#endif // VECTOR_H_INCLUDED
