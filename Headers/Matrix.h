#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "Vector.h"
#include <string>

namespace ScienceMathLib
{

/// matrix
class Matrix
{
  private:
  public:
    /// The Number of Rows
    int Row;
    /// The Number of Columns
    int Column;
    /// Elements
    double **X;
    Matrix();
    Matrix(const unsigned int _Row, const unsigned int _Column);
    Matrix(const unsigned int _N);
    Matrix(const Matrix &A);
    ~Matrix();
    void operator=(const Matrix &A);
    void operator=(std::string &Astr); //已测试，通过。这个函数有待改进
    void operator=(const char *Astr);  //

    friend Matrix operator+(Matrix &a, Matrix &b);             //已测试，通过
    friend Matrix operator-(Matrix &a, Matrix &b);             //已测试，通过
    friend Matrix operator*(const double a,const Matrix& b);               //未测试
    friend Matrix operator*(const Matrix &a, const Matrix &b); //已测试，通过
    friend Vector operator*(Vector& a, Matrix& b);               //未测试
    friend Vector operator*(Matrix& a, Vector& b);               //未测试

    void SR(const unsigned int i, const unsigned int j);
    void SC(const unsigned int i, const unsigned int j);
    void DR(const unsigned int i, const double l);
    void DC(const unsigned int i, const double l);
    void TR(const unsigned int i, const unsigned int j, const double l);
    void TC(const unsigned int i, const unsigned int j, const double l);

    double *&operator[](unsigned int i);
    double Trace();                                                                       //待测试
    Matrix Transpose();                                                                    //待测试
    Matrix Inverse();                                                                     //待测试
    double Determinate();                                                                 //已测试
    Matrix Submatrix(unsigned int R1, unsigned int C1, unsigned int R2, unsigned int C2); //待测试
    std::string ToString();
    static Matrix xUnitMatrix(const unsigned int _N,const double x);


};

} // namespace ScienceMathLib

#endif // MATRIX_H_INCLUDED
