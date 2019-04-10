#include "Number.h"

namespace ScienceMathLib
{

integer Gcd(integer a,integer b)
{
    integer c=a%b;
    while(c>0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

void Exgcd(integer a,integer b,integer& d,integer& x,integer& y)
{
    if(b==0)
    {
        d=a; x=1; y=0; 
    }
    else
    {
        exgcd(b, a%b, d, y, x);
        y-=x*(a/b);
    }
}

integer Inverse(integer a, integer m)
{
    integer d, x, y;
    exgcd(a,m,d,x,y);
    return d==1?(x+m)%m:-1;
}

}