#include <stdio.h>
#include <stdlib.h>

long fib(long n);

int main (int argc,char* argv[])
{
    long n=(long)atoi(argv[1]);
    double result=(double)fib(n)/fib(n+1);
    printf("%lf\n",result);
    return 0;

}

long fib(long n)
{
    if(n==0||n==1)
        return 1;
    else return fib(n-1)+fib(n-2);
}
