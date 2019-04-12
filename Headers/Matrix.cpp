#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include "Trifles.h"
#include "Vector.h"
#include "Matrix.h"


namespace ScienceMathLib
{
std::set<char> FactorStart_ = { '*', '/', '+', '-', ',', '[', '(', '{' };
Matrix::Matrix()
{
    X = nullptr;
    Row = 0;
    Column = 0;
}

Matrix::Matrix(const unsigned int _Row, const unsigned int _Column)
{

    Row = _Row;
    Column = _Column;
    X = new double *[Row + 1];
    for (unsigned int i = 1; i <= Row; i++)
        X[i] = new double[Column + 1];
}

Matrix::Matrix(const unsigned int _N)
{
    Row=Column=_N;
    X=new double* [Row+1];
    for(unsigned int i=1;i<=Row;i++)
    {
        X[i]=new double[Row+1];
        for(unsigned int j=1;j<=Row;j++)
        {
            X[i][j]=0;
        }
        X[i][i]=1;
    }
}
Matrix::~Matrix()
{
    for (unsigned int i = 1; i <= Row; i++)
        delete[] X[i];
    delete[] X;
}

Matrix::Matrix(const Matrix &A)
{
    Row = A.Row;
    Column = A.Column;

    X = new double *[Row + 1];
    for (unsigned int i = 1; i <= Row; i++)
    {
        X[i] = new double[Column + 1];
        for (unsigned int j = 1; j <= Column; j++)
        {
            X[i][j] = A.X[i][j];
        }
    }
}

void Matrix::Reset(const unsigned int _Row,const unsigned int _Column)
{
    for (unsigned int i = 1; i <= Row; i++)
        delete[] X[i];
    delete[] X;
    Row = _Row;
    Column = _Column;
    X = new double *[Row + 1];
    for (unsigned int i = 1; i <= Row; i++)
        X[i] = new double[Column + 1];
}
void Matrix::operator=(const Matrix &A)
{

    for (unsigned int i = 1; i <= Row; i++)
    {
        delete[] X[i];
    }
    delete[] X;
    Row = A.Row;
    Column = A.Column;

    X = new double *[Row + 1];
    for (unsigned int i = 1; i <= Row; i++)
    {
        X[i] = new double[Column + 1];
        for (unsigned int j = 1; j <= Column; j++)
        {
            X[i][j] = A.X[i][j];
        }
    }
}
void Matrix::operator=(std::string& str)
{
	unsigned int i;
	recMatrix(str, 0, i, *this);
}


///从字符串中指定起始位置开始识别一个矩阵（有具体数值的）。若识别成功，则返回true,并用i指示所识别矩阵的末尾位置的后一位；否则返回false.
bool Matrix::recMatrix(std::string& str, const unsigned int _start, unsigned int& i, Matrix& mat)
{
    if(str[_start]!='M'||str[_start+1]!='A'||str[_start+2]!='T'||str[_start+3]!='{')return false;
    if(_start>0&&FactorStart_.find(str[_start-1])==FactorStart_.end())return false;//一个向量的上下文环境就是因子的上下文环境

    unsigned int strln=str.size();
    i=_start+4;

    Vector v;
    unsigned int cm=0;
    std::vector<Vector> vs;
    while(Vector::recVector(str,i,i,v))
    {
        if(cm==0)cm=v.N;
        if(v.N!=cm)
        {
            i=_start;
            return false;
        }
        vs.push_back(v);
        if(str[i]==',')
        {
            i++;
        }
        else if(str[i]=='}')
        {
            i++;
            mat.Reset(vs.size(),cm);
            for(unsigned int k=1;k<=mat.Row;k++)
            {
                for(unsigned int j=1;j<=mat.Column;j++)
                {
                    mat.X[k][j]=vs[k-1][j];
                }
            }
            return true;
        }
        else
        {
            i=_start;
            return false;
        }
    }
    //由于recVector失败而结束循环的。注意如果是空矩阵"MAT{}"也会运行到这里并返回识别失败
    i=_start;
    return false;
}
Matrix operator+(Matrix &a, Matrix &b)
{

    if (a.Row == b.Row && a.Column == b.Column)
    {
        Matrix ret(a.Row, a.Column);
        for (unsigned int i = 1; i <= a.Row; i++)
        {
            for (unsigned int j = 1; j <= a.Column; j++)
            {
                ret.X[i][j] = a.X[i][j] + b.X[i][j];
            }
        }
        return ret;
    }
    else
    {
        std::string ex("!");
        throw ex;
    }
}

Matrix operator-(Matrix &a, Matrix &b)
{

    if (a.Row == b.Row && a.Column == b.Column)
    {
        Matrix ret(a.Row, a.Column);
        for (unsigned int i = 1; i <= a.Row; i++)
        {
            for (unsigned int j = 1; j <= a.Column; j++)
            {
                ret.X[i][j] = a.X[i][j] - b.X[i][j];
            }
        }
        return ret;
    }
    else
    {
        std::string ex("!");
        throw ex;
    }
}

Matrix operator*(const double a,const Matrix &b)
{
    Matrix ret(b.Row, b.Column);
    for (unsigned int i = 1; i <= b.Row; i++)
    {
        for (unsigned int j = 1; j <= b.Column; j++)
        {
            ret.X[i][j] = a * b.X[i][j];
        }
    }
    return ret;
}

Matrix operator*(const Matrix &a, const Matrix &b)
{
    if (a.Column == b.Row)
    {
        Matrix ret(a.Row, b.Column);
        for (unsigned int i = 1; i <= a.Row; i++)
        {
            for (unsigned int j = 1; j <= b.Column; j++)
            {

                ret.X[i][j] = 0;
                for (unsigned int k = 1; k <= a.Column; k++)
                {
                    ret.X[i][j] += a.X[i][k] * b.X[k][j];
                }
            }
        }
        return ret;
    }
    else
    {
        Matrix ret(0, 0);
        return ret;
    }
}

Vector operator*(Vector &a, Matrix &b)
{
    if (a.N == b.Row)
    {
        Vector ret(b.Column);
        for (unsigned int j = 1; j <= b.Column; j++)
        {
            ret.X[j] = 0;
            for (unsigned int k = 1; k <= a.N; k++)
            {
                ret.X[j] += a.X[k] * b.X[k][j];
            }
        }
        return ret;
    }
	else
	{
		Vector ret(0);
		return ret;
	}
}

Vector operator*(Matrix &a, Vector &b)
{

    if (a.Column == b.N)
    {
        Vector ret(a.Row);
        for (unsigned int i = 1; i <= a.Row; i++)
        {
            ret.X[i] = 0;
            for (unsigned int k = 1; k <= b.N; k++)
            {
                ret.X[i] += a.X[i][k] * b.X[k];
            }
        }
        return ret;
    }
	else
	{
		Vector ret(0);
		return ret;
	}
}

Matrix Matrix::xUnitMatrix(const unsigned int _N, const double x)
{
    Matrix ret(_N);
    if(x!=1)
        return ret;
    else
        return x*ret;
}

double *&Matrix::operator[](unsigned int i)
{
    return X[i];
}

Matrix Matrix::Transpose()
{
    Matrix ret(Column, Row);
    for (unsigned int i = 1; i <= Row; i++)
        for (unsigned int j = 1; j <= Column; j++)
        {
            ret.X[j][i] = X[i][j];
        }
    return ret;
}

void Matrix::SR(const unsigned int i, const unsigned int j)
{
    double* temp=X[i];
    X[i]=X[j];
    X[j]=temp;
}

void Matrix::SC(const unsigned int i, const unsigned int j)
{
    double temp;
    for(unsigned int k=1;k<=Row;k++)
    {
        temp=X[k][i];
        X[k][i]=X[k][j];
        X[k][j]=temp;
    }
}

void Matrix::TR(const unsigned int i, const unsigned int j, const double l)
{
    for(unsigned int k=1;k<=Column;k++)
    {
        X[i][k]+=l*X[j][k];
    }
}

void Matrix::TC(const unsigned int i, const unsigned int j, const double l)
{
    for(unsigned int k=1;k<=Row;k++)
    {
        X[k][i]+=l*X[k][j];
    }
}

void Matrix::DR(const unsigned int i, const double l)
{
    for(unsigned int k=1;k<=Column;k++)
    {
        X[i][k]*=l;
    }
}

void Matrix::DC(const unsigned int i, const double l)
{
    for(unsigned int k=1;k<=Row;k++)
    {
        X[k][i]*=l;
    }
}

double Matrix::Determinate()
{
    if(Row!=Column)
    {
		std::string ex = " ";
        throw ex;
    }
    Matrix mat(*this);
    unsigned int firstlinenot0, i, j;

    bool sign=false;//是否取相反数

    for(i=1;i<=Column;i++)
    {
        for(firstlinenot0=i;firstlinenot0<=Column&&0==mat.X[firstlinenot0][i];firstlinenot0++);
        if(firstlinenot0>Column)return 0;

        if(firstlinenot0!=i)
        {
            sign=!sign;
            mat.SR(i,firstlinenot0);
        }
        for(j=i+1;j<=Column;j++)
        {
            if(mat.X[j][i]!=0)
            {
                mat.TR(j,i,-mat.X[j][i]/mat.X[i][i]);
            }
        }
    }

    double ans=mat.X[1][1];
    for(i=2;i<=Column;i++)
    {
        ans*=mat.X[i][i];
    }

    if(sign)ans=-ans;
    return ans;
}
///<summary>求矩阵的逆</summary>
Matrix Matrix::Inverse()
{
    if(Row!=Column)
    {
        std::string ex("求逆的矩阵不是方阵");
        throw ex;
    }
    Matrix ret(Column);
    Matrix mat(*this);
    unsigned int firstlinenot0, i, j;

    for(i=1;i<=Column;i++)
    {
        for(firstlinenot0=i;firstlinenot0<=Column&&0==mat.X[firstlinenot0][i];firstlinenot0++);
        if(firstlinenot0>Column)
        {
            std::string ex("求逆的矩阵行列式为0");
            throw ex;
        }
        if(firstlinenot0!=i)
        {
            mat.SR(i,firstlinenot0);
            ret.SR(i,firstlinenot0);
        }
        for(j=i+1;j<=Column;j++)
        {
            if(mat.X[j][i]!=0)
            {
                mat.TR(j,i,-mat.X[j][i]/mat.X[i][i]);
                ret.TR(j,i,-mat.X[j][i]/mat.X[i][i]);
            }
        }
    }

    for(i=Column;i>=1;i--)
    {
        ret.DR(i,1/mat.X[i][i]);
        for(j=i-1;j>=1;j--)
        {
            if(mat.X[j][i]!=0)
            {
                ret.TR(j,i,-mat.X[j][j]);
            }
        }
    }
    return ret;

}
///<summary>求矩阵的秩</summary>
int Matrix::rank()
{
    Matrix mat(*this);
    if(Column>Row)
    {
        mat.Transpose();
    }

    unsigned int firstlinenot0, i, j;
    int rk=Column;
    for(i=1;i<=mat.Row;i++)
    {
        for(firstlinenot0=i;firstlinenot0<=mat.Row&&0==mat.X[firstlinenot0][i];firstlinenot0++);
        if(firstlinenot0>mat.Row)
        {
            rk--;
            return 0;
        }

        if(firstlinenot0!=i)
        {
            mat.SR(i,firstlinenot0);
        }
        for(j=i+1;j<=mat.Row;j++)
        {
            if(mat.X[j][i]!=0)
            {
                mat.TR(j,i,-mat.X[j][i]/mat.X[i][i]);
            }
        }
    }

    return rk;
}

/// Get the trace of the matrix
double Matrix::Trace()
{
    double ans = 0;
    int mn = Row < Column ? Row : Column;
    for (int i = 1; i < mn; i++)
    {
        ans += X[i][i];
    }
    return ans;
}

///<summary>获得从第R1行到R2行，第C1列到C2列的子矩阵</summary>
Matrix Matrix::Submatrix(unsigned int R1, unsigned int C1, unsigned int R2, unsigned int C2)
{

    if (R1 > R2 || C1 > C2)
    {
        std::string ex("!");
        throw ex;
    }
    else
    {
        Matrix ret(R2 - R1 + 1, C2 - C1 + 1);
        for (unsigned int i = R1; i <= R2; i++)
        {
            for (unsigned int j = C1; j <= C2; j++)
            {
                ret.X[i - R1 + 1][j - C1 + 1] = X[i][j];
            }
        }
        return ret;
    }
}

///<summary>获得文本形式的矩阵</summary>
std::string Matrix::ToString()
{
    std::string ret = "MAT{";
    if (Row == 0 || Column == 0)
    {
        ret = "{}";
        return ret;
    }
	
    for (unsigned int i = 1; i < Row; i++)
    {
        ret.append("{");
        for (unsigned int j = 1; j < Column; j++)
        {
            ret+=DtoStr(X[i][j]);
            ret.append(",");
        }
        ret+=DtoStr(X[i][Column]);
        ret.append("},");
    }
    ret.append("{");
    for (unsigned int j = 1; j < Column; j++)
    {
        ret+=DtoStr(X[Row][j]);
        ret.append(",");
    }
    ret+=DtoStr(X[Row][Column]);
    ret.append("}}");

    return ret;
}

std::istream& operator >>(std::istream& ist, Matrix& mat)
{
	std::string s;
	unsigned int i;
	ist >> s;
	Matrix::recMatrix(s, 0, i, mat);
	return ist;
}

std::ostream& operator <<(std::ostream& ost, Matrix mat)
{
	ost << mat.ToString();
	return ost;
}
} // namespace ScienceMathLib

