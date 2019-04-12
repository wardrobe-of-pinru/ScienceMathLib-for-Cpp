#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "Vector.h"
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
namespace ScienceMathLib
{

/// matrix
class Matrix
{
private:
public:
  ///<summary>行数</summary>
  unsigned int Row;
  ///<summary>列数</summary>
  unsigned int Column;
  ///<summary>元素（外部访问请使用[]操作符）</summary>
  double **X;
  Matrix();
  ///<summary>构造指定行数列数的矩阵</summary>
  Matrix(const unsigned int _Row, const unsigned int _Column);
  ///<summary>构造一个指定阶的单位方阵</summary>
  Matrix(const unsigned int _N);
  Matrix(const Matrix &A);
  ~Matrix();
  void operator=(const Matrix &A);
  void operator=(std::string& str);
  ///<summary>重设矩阵大小</summary>
  void Reset(const unsigned int _Row, const unsigned int _Column);
  ///<summary>从字符串中指定起始位置开始识别一个矩阵（有具体数值的）。若识别成功，则返回true,并用i指示所识别矩阵的末尾位置的后一位；否则返回false.</summary>
  static bool recMatrix(std::string &str, const unsigned int _start, unsigned int &i, Matrix &mat);

  friend Matrix operator+(Matrix &a, Matrix &b);             //已测试，通过
  friend Matrix operator-(Matrix &a, Matrix &b);             //已测试，通过
  friend Matrix operator*(const double a, const Matrix &b);  //未测试
  friend Matrix operator*(const Matrix &a, const Matrix &b); //已测试，通过
  friend Vector operator*(Vector &a, Matrix &b);             //未测试
  friend Vector operator*(Matrix &a, Vector &b);             //未测试

  ///<summary>初等变换：将第i行与第j行交换</summary>
  void SR(const unsigned int i, const unsigned int j);
  ///<summary>初等变换：将第i列与第j列交换</summary>
  void SC(const unsigned int i, const unsigned int j);
  ///<summary>初等变换：将第i行乘以l</summary>
  void DR(const unsigned int i, const double l);
  ///<summary>初等变换：将第i列乘以l</summary>
  void DC(const unsigned int i, const double l);
  ///<summary>初等变换：将第i行加上第j行的l倍</summary>
  void TR(const unsigned int i, const unsigned int j, const double l);
  ///<summary>初等变换：将第i列加上第j列的l倍</summary>
  void TC(const unsigned int i, const unsigned int j, const double l);

  double *&operator[](unsigned int i);
  ///<summary>返回矩阵的迹</summary>
  double Trace();       //未测试
  ///<summary>返回矩阵的转置</summary>
  Matrix Transpose();   //未测试
  ///<summary>返回矩阵的逆</summary>
  Matrix Inverse();     //未测试
  ///<summary>返回矩阵行列式的值</summary>
  double Determinate(); //未完成
  ///<summary>返回矩阵的秩</summary>
  int rank();
  ///<summary>返回一个子矩阵</summary>
  Matrix Submatrix(unsigned int R1, unsigned int C1, unsigned int R2, unsigned int C2); //未测试
  ///<summary>返回矩阵字符串形式</summary>
  std::string ToString();
  ///<summary>返回生成一个对角元都是x的_N阶数量矩阵</summary>
  static Matrix xUnitMatrix(const unsigned int _N, const double x);
};

std::istream& operator >>(std::istream& ist, Matrix& mat);
std::ostream& operator<<(std::ostream& ost, Matrix mat);


} // namespace ScienceMathLib

#endif // MATRIX_H_INCLUDED
