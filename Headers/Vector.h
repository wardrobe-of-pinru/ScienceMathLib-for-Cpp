#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<string>
#include<cmath>
#include<cstdio>
#include<stdarg.h>

namespace ScienceMathLib
{
    /// <summary>
    /// 二维向量
    /// </summary>
    struct Vector2
    {
        double X, Y;

        Vector2()
        {
            X=0;Y=0;
        }

        /// 初始化一个二维向量
        Vector2(double x, double y)
        {
            X = x;
            Y = y;
        }
        ~Vector2()
        {

        }

        friend Vector2 operator +(const Vector2& a, const Vector2& b)
        {
            Vector2 v(a.X + b.X, a.Y + b.Y);
            return v;
        }
        friend Vector2 operator -(const Vector2& a, const Vector2& b)
        {
            Vector2 v(a.X - b.X, a.Y - b.Y);
            return v;
        }
        friend double operator *(const Vector2& a, const Vector2& b)
        {
            return a.X * b.X + a.Y * b.Y;
        }
        friend Vector2 operator *(const double a, const Vector2& b)
        {
            Vector2 v(a * b.X, a * b.Y);
            return v;
        }

        /// 返回向量的字符串形式
        std::string ToString()//字符串形式
        {
            char buf[20];
            sprintf(buf,"%.5lf",X);
            std::string xstr(buf);
            sprintf(buf,"%.5lf",Y);
            std::string ystr(buf);
            return "(" + xstr + "," + ystr + ")";
        }

        /// 返回向量的模长
        double Modulus()//模长
        {
            return sqrt(X * X + Y * Y);
        }

        /// 返回向量的模长的平方
        double ModulusSquare()//平方
        {
            return X * X + Y * Y;
        }

        /// 返回向量和X轴的夹角，∈[0,π]
        double Angle()
        {
            return acos(X / (Modulus() * 1.00000001));
        }
        /// 返回两个向量的夹角
        static double AngleBetween(Vector2& a, Vector2& b)//夹角(0-π)
        {
            return acos(a * b / (a.Modulus() * b.Modulus()));
        }

        /// 返回两个向量间夹角的余弦值
        static double CosAngleBetween(Vector2& a, Vector2& b)
        {
            return a * b / a.Modulus() / b.Modulus();
        }

        /// 返回其单位向量
        Vector2 UnitVector()
        {
            double m = Modulus();
            if (m != 0)
            {
                Vector2 v(X/m,Y/m);
                return v;
            }
            else
            {
                Vector2 v(0,0);
                return v;
            }
        }

        /// 自增
        Vector2 operator +=(const Vector2& a)
        {
            X += a.X;
            Y += a.Y;
            return *this;
        }

        /// 自减
        Vector2 operator -=(Vector2 a)
        {
            X -= a.X;
            Y -= a.Y;
            return *this;
        }
    };

    /// 三维向量
    struct Vector3
    {
        double X, Y, Z;

        /// 从坐标初始化一个向量
        Vector3(double _x, double _y, double _z)
        {
            X = _x;
            Y = _y;
            Z = _z;
        }

        /// 根据经纬度初始化一个单位向量
        Vector3(double Longitude, double Latitude)
        {
            X = cos(Longitude) * cos(Latitude);
            Y = sin(Longitude) * cos(Latitude);
            Z = sin(Latitude);
        }
        friend Vector3 operator +(const Vector3& a,const Vector3& b)
        {
            Vector3 v(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
            return v;
        }
        friend Vector3 operator -(const Vector3& a,const Vector3& b)
        {
            Vector3 v(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
            return v;
        }
        friend double operator *(const Vector3& a,const Vector3& b)
        {
            return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
        }
        friend Vector3 operator *(const double a,const Vector3& b)
        {
            Vector3 v(a*b.X, a*b.Y, a*b.Z);
            return v;
        }

        /// 三维向量叉乘运算
        friend Vector3 operator &(const Vector3& a,const Vector3& b)
        {
            Vector3 v(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
            return v;
        }

        /// 返回向量的字符串形式
        std::string ToString()//字符串形式
        {
            char buf[20];
            sprintf(buf,"%.5lf",X);
            std::string xstr(buf);
            sprintf(buf,"%.5lf",Y);
            std::string ystr(buf);
            sprintf(buf,"%.5lf",Z);
            std::string zstr(buf);
            return "(" + xstr + "," + ystr + "," + zstr + ")";
        }

        /// 返回向量的模长
        double Modulus()//模长
        {
            return sqrt(X*X + Y*Y + Z*Z);
        }

        /// 返回向量模长的平方
        double ModulusSquare()//模长平方
        {
            return X * X + Y * Y + Z * Z;
        }

        /// 返回向量与X轴正方向的夹角，∈[0,π]
        double Angle()
        {
            return acos(X / (Modulus() * 1.00000001));
        }

        /// 返回两个向量之间的夹角，∈[0,π]
        static double AngleBetween(Vector3& a, Vector3& b)//夹角(0-π)
        {
            return acos(a * b / (a.Modulus() * b.Modulus() * 1.00000001));
        }


        /// 返回这个向量的单位向量
        Vector3 UnitVector()
        {
            double m = Modulus();
            Vector3 v(X / m, Y / m, Z / m);
            return v;
        }

        /// 返回这个向量的相反方向的单位向量
        Vector3 AntiUnitVector()
        {
            double m = -Modulus();
            Vector3 v(X / m, Y / m, Z / m);
            return v;
        }

        /// 自增
        Vector3 operator +=(const Vector3& a)
        {
            X += a.X;
            Y += a.Y;
            Z += a.Z;
            return *this;
        }

        /// 自减
        Vector3 operator -=(const Vector3& a)
        {
            X -= a.X;
            Y -= a.Y;
            Z -= a.Z;
            return *this;
        }

    };

    /// N维向量

    struct VectorN
    {
        unsigned int N;//维度

        /// 各维度分量
        double* X;

        /// 初始化一个N维向量

        VectorN()
        {
            X=nullptr;
        }

        VectorN(const unsigned int _N)
        {
            N = _N;
            X = new double[N + 1];
        }

        VectorN(const unsigned int _N, double _X1, ...)
        {
            va_list ap;
            va_start(ap, _N);
            N=_N;
            X = new double[N + 1];
            X[1]=_X1;
            for(int i=2;i<=N;i++)
            {
                X[i]=va_arg(ap, double);
            }
            va_end(ap);
        }

        VectorN(const unsigned int _N,double _X[])
        {
            N=_N;
            X=new double[N+1];
            for(int i=1;i<=N;i++)
            {
                X[i]=_X[i];
            }
        }

        ~VectorN()
        {
            delete[] X;
        }

        void Assign(const unsigned int _N,double _X,...)
        {
            delete[] X;

            va_list ap;
            va_start(ap, _N);
            N=_N;
            X = new double[N + 1];
            for(int i=1;i<=N;i++)
            {
                X[i]=va_arg(ap,double);
            }
            va_end(ap);
        }

        void ResetN(const unsigned int _N)
        {
            delete[] X;
            N=_N;
            X=new double[N+1];
        }
        friend VectorN operator +(const VectorN& a,const VectorN& b)
        {
            VectorN v;
            if (a.N == b.N)
            {
                v.X=new double[a.N + 1];
                for (int i = 1; i <= a.N; i++)
                {
                    v.X[i] = a.X[i] + b.X[i];
                }
            }
            else
            {
                v.X=new double[1];
            }
            return v;
        }

        friend VectorN operator -(const VectorN& a,const VectorN& b)
        {
            VectorN v;
            if (a.N == b.N)
            {
                VectorN v(a.N);
                for (int i = 1; i <= a.N; i++)
                {
                    v.X[i] = a.X[i] - b.X[i];
                }
            }
            else
            {
                VectorN v(0);
                return v;
            }

        }

        friend VectorN operator *(const VectorN& a,const VectorN& b)
        {

            if (a.N == b.N)
            {
                VectorN v(a.N);
                for (int i = 1; i <= a.N; i++)
                {
                    v.X[i] = a.X[i] * b.X[i];
                }
                return v;
            }
            else
            {
                VectorN v(0);
                return v;
            }
        }

        friend VectorN operator *(double a, VectorN b)//向量数乘
        {
            VectorN v(b.N);
            for (int i = 1; i <= b.N; i++)
            {
                v.X[i] = a * b.X[i];
            }
            return v;
        }

        /// 返回向量的模长
        double Modulus()//
        {
            double m = 0;
            for (int i = 1; i <= N; i++)
            {
                m += X[i] * X[i];
            }
            return sqrt(m);
        }

        /// 返回向量模长平方
        double ModulusSquare()
        {
            double m = 0;
            for (int i = 1; i <= N; i++)
            {
                m += X[i] * X[i];
            }
            return m;
        }

        /*// 返回Matrix类型
        public Matrix ToMatrix()
        {
            Matrix ret = new Matrix(1, dimension);
            for (int j = 1; j <= dimension; j++)
            {
                ret.X[1, j] = X[j];
            }
            return ret;
        }*/


        /// 返回字符串格式
        std::string ToString()
        {
            std::string s = "(";
            char buf[20];
            for (int i = 1; i < N; i++)
            {
                sprintf(buf,"%.5f",X[i]);
                s.append(buf);
                s.append(",");
            }
            sprintf(buf,"%.5f",X[N]);
            s.append(buf);
            s.append(")");
            return s;
        }
    };
}



#endif // VECTOR_H_INCLUDED
