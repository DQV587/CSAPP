#include <stdio.h>
#include <stdlib.h>

long fib(long n)
{
    long f1,f2,f3;
    int i;
    if(n==0||n==1)
        return 1;
    else
    {
        f1=f2=1;
        for(i=1;i<n;i++)
        {
            f3=f1+f2;
            f1=f2;
            f2=f3;
        }
        return f3;        
    }
}
int main(int argc,char* argv[])
{
    long n=(long)atoi(argv[1]);
    double result=(double)fib(n)/fib(n+1);
    printf("%8lf\n",result);
    return 0;
}