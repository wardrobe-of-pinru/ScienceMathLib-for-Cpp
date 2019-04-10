#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Vector.h"
#include <string>

namespace ScienceMathLib
{

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
    for(unsigned int i;i<=Row;i++)
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
    for (int i = 1; i <= Row; i++)
        delete[] X[i];
    delete[] X;
}

Matrix::Matrix(const Matrix &A)
{
    Row = A.Row;
    Column = A.Column;

    X = new double *[Row + 1];
    for (int i = 1; i <= Row; i++)
    {
        X[i] = new double[Column + 1];
        for (int j = 1; j <= Column; j++)
        {
            X[i][j] = A.X[i][j];
        }
    }
}

void Matrix::operator=(const Matrix &A)
{

    for (int i = 1; i <= Row; i++)
    {
        delete[] X[i];
    }
    delete[] X;
    Row = A.Row;
    Column = A.Column;

    X = new double *[Row + 1];
    for (int i = 1; i <= Row; i++)
    {
        X[i] = new double[Column + 1];
        for (int j = 1; j <= Column; j++)
        {
            X[i][j] = A.X[i][j];
        }
    }
}
void Matrix::operator=(std::string &Astr)
{
    for (int i = 1; i <= Row; i++)
    {
        delete[] X[i];
    }
    delete[] X;
    Row = 1;
    Column = 0;

    char buf[20];
    int chcount, lineMcount, rowNcount;

    int i = 0;
    while (Astr[i] == ' ' || Astr[i] == '\n')
        i++;
    if (Astr[i] != '{')
        return;

    i++;
    while (true)
    {
        while (Astr[i] != ',' && Astr[i] != ';' && Astr[i] != ' ')
            i++;
        while (Astr[i] == ' ' || Astr[i] == '\n')
            i++;
        if (Astr[i] == ',')
        {
            Column++;
            i++;
        }
        else if (Astr[i] == ';')
        {
            Column++;
            i++;
            break;
        }
        else
            return;
    }
    while (true)
    {
        Row++;
        rowNcount = 0;
        while (true)
        {
            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;
            while (Astr[i] != ',' && Astr[i] != ';' && Astr[i] != ' ')
                i++;
            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;
            if (Astr[i] == ',')
            {
                rowNcount++;
                i++;
            }
            else if (Astr[i] == ';')
            {
                rowNcount++;
                if (rowNcount != Column)
                    return;
                else
                {
                    i++;
                    break;
                }
            }
            else
                return;
        }
        while (Astr[i] == ' ' || Astr[i] == '\n')
            i++;
        if (Astr[i] == '}')
            break;
    }

    X = new double *[Row + 1];
    for (int ii = 0; ii <= Row; ii++)
        X[ii] = new double[Column + 1];

    lineMcount = 0;

    i = 0;
    while (Astr[i] == ' ' || Astr[i] == '\n')
        i++;
    if (Astr[i] == '{')
        i++;
    while (true)
    {
        lineMcount++;
        rowNcount = 0;
        Matrix a;

        while (true)
        {
            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;

            chcount = 0;
            while (Astr[i] != ',' && Astr[i] != ';' && Astr[i] != ' ')
            {
                buf[chcount++] = Astr[i++];
            }
            buf[chcount] = '\0';
            X[lineMcount][++rowNcount] = atof(buf);

            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;
            if (Astr[i] == ',')
            {
                i++;
            }
            else if (Astr[i] == ';')
            {
                i++;
                break;
            }
        }
        while (Astr[i] == ' ' || Astr[i] == '\n')
            i++;
        if (Astr[i] == '}')
            break;
    }
}
void Matrix::operator=(const char *Astr)
{
    for (int i = 1; i <= Row; i++)
    {
        delete[] X[i];
    }
    delete[] X;
    Row = 1;
    Column = 0;

    char buf[20];
    int chcount, lineMcount, rowNcount;

    int i = 0;
    while (Astr[i] == ' ' || Astr[i] == '\n')
        i++;
    if (Astr[i] != '{')
        return;

    i++;
    while (true)
    {
        while (Astr[i] != ',' && Astr[i] != ';' && Astr[i] != ' ')
            i++;
        while (Astr[i] == ' ' || Astr[i] == '\n')
            i++;
        if (Astr[i] == ',')
        {
            Column++;
            i++;
        }
        else if (Astr[i] == ';')
        {
            Column++;
            i++;
            break;
        }
        else
            return;
    }
    while (true)
    {
        Row++;
        rowNcount = 0;
        while (true)
        {
            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;
            while (Astr[i] != ',' && Astr[i] != ';' && Astr[i] != ' ')
                i++;
            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;
            if (Astr[i] == ',')
            {
                rowNcount++;
                i++;
            }
            else if (Astr[i] == ';')
            {
                rowNcount++;
                if (rowNcount != Column)
                    return;
                else
                {
                    i++;
                    break;
                }
            }
            else
                return;
        }
        while (Astr[i] == ' ' || Astr[i] == '\n')
            i++;
        if (Astr[i] == '}')
            break;
    }

    X = new double *[Row + 1];
    for (int ii = 0; ii <= Row; ii++)
        X[ii] = new double[Column + 1];

    lineMcount = 0;

    i = 0;
    while (Astr[i] == ' ' || Astr[i] == '\n')
        i++;
    if (Astr[i] == '{')
        i++;
    while (true)
    {
        lineMcount++;
        rowNcount = 0;
        while (true)
        {
            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;

            chcount = 0;
            while (Astr[i] != ',' && Astr[i] != ';' && Astr[i] != ' ')
            {
                buf[chcount++] = Astr[i++];
            }
            buf[chcount] = '\0';
            X[lineMcount][++rowNcount] = atof(buf);

            while (Astr[i] == ' ' || Astr[i] == '\n')
                i++;
            if (Astr[i] == ',')
            {
                i++;
            }
            else if (Astr[i] == ';')
            {
                i++;
                break;
            }
        }
        while (Astr[i] == ' ' || Astr[i] == '\n')
            i++;
        if (Astr[i] == '}')
            break;
    }
}

Matrix operator+(Matrix &a, Matrix &b)
{

    if (a.Row == b.Row && a.Column == b.Column)
    {
        Matrix ret(a.Row, a.Column);
        for (int i = 1; i <= a.Row; i++)
        {
            for (int j = 1; j <= a.Column; j++)
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
        for (int i = 1; i <= a.Row; i++)
        {
            for (int j = 1; j <= a.Column; j++)
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
    for (int i = 1; i <= b.Row; i++)
    {
        for (int j = 1; j <= b.Column; j++)
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
        for (int i = 1; i <= a.Row; i++)
        {
            for (int j = 1; j <= b.Column; j++)
            {

                ret.X[i][j] = 0;
                for (int k = 1; k <= a.Column; k++)
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
        for (int j = 1; j <= b.Column; j++)
        {
            ret.X[j] = 0;
            for (int k = 1; k <= a.N; k++)
            {
                ret.X[j] += a.X[k] * b.X[k][j];
            }
        }
        return ret;
    }
}

Vector operator*(Matrix &a, Vector &b)
{

    if (a.Column == b.N)
    {
        Vector ret(a.Row);
        for (int i = 1; i <= a.Row; i++)
        {
            ret.X[i] = 0;
            for (int k = 1; k <= b.N; k++)
            {
                ret.X[i] += a.X[i][k] * b.X[k];
            }
        }
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

Matrix Matrix::Tanspose()
{
    Matrix ret(Column, Row);
    for (int i = 1; i <= Row; i++)
        for (int j = 1; j <= Column; j++)
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

void Matrix::TC(const unsigned int i, const unsigned j, const double l)
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
        std::string ex="求行列式的矩阵不是方阵";
        throw ex;
    }
    Matrix mat(*this);
    unsigned int firstlinenot0, i, j;
    for(i=1;i<=Column;i++)
    {
        for(firstlinenot0=i;firstlinenot0<=Column&&0==mat.X[firstlinenot0][i];firstlinenot0++);
        if(firstlinenot0>Column)return 0;

        if(firstlinenot0!=i)mat.SR(i,firstlinenot0);
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
    return ans;
}

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

///Get Submatrix from [R1][C1] to [R2][C2]
Matrix Matrix::Submatrix(unsigned int R1, unsigned int C1, unsigned int R2, unsigned int C2)
{

    if (R1 > R2 || C1 > C2)
    {
        std::string ex("!");
        throw ex;
    }
    else
    {
        Matrix ret(C2 - C1 + 1, C2 - C1 + 1);
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

///Get string form of the matrix
std::string Matrix::ToString()
{
    std::string ret = "(";
    char buf[50];
    if (Row == 0 || Column == 0)
    {
        ret = "()";
        return ret;
    }

    for (int i = 1; i < Row; i++)
    {
        for (int j = 1; j < Column; j++)
        {

            sprintf(buf, "%f", X[i][j]);
            ret.append(buf);

            ret.append(",");
        }
        sprintf(buf, "%f", X[i][Column]);
        ret.append(buf);
        ret.append(";\n");
    }
    for (int j = 1; j < Column; j++)
    {
        sprintf(buf, "%f", X[Row][j]);
        ret.append(buf);
        ret.append(",");
    }
    sprintf(buf, "%f", X[Row][Column]);
    ret.append(buf);
    ret.append(";)");

    return ret;
}
} // namespace ScienceMathLib

