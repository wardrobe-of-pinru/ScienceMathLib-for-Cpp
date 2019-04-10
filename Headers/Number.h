#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

namespace ScienceMathLib
{

typedef long long integer;

integer gcd(integer a, integer b);                                    //求最大公因子
void exgcd(integer a, integer b, integer &d, integer &x, integer &y); //根据a、b，求ax+by=gcd(a,b)
integer Inverse(integer a, integer m);                                //求逆元。若逆元不存在返回-1

} // namespace ScienceMathLib

#endif // NUMBER_H_INCLUDED
