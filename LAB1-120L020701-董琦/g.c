#include <stdio.h>
#include <stdlib.h>

double fib(int n)
{
    double f1,f2,f3;
    int i;
    if(n==0||n==1)
        return 1.0;
    else
    {
        f1=f2=1.0;
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
    int n=atoi(argv[1]);
    double result=fib(n)/fib(n+1);
    printf("%10lf\n",result);
    return 0;
}