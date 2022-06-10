#include <stdio.h>

int main()
{
    printf("char:%lu byte\n",sizeof(char));
    printf("short:%lu byte\n",sizeof(short));
    printf("int:%lu byte\n",sizeof(int));
    printf("long:%lu byte\n",sizeof(long));
    printf("long long:%lu byte\n",sizeof(long long));
    printf("float:%lu byte\n",sizeof(float));
    printf("double:%lu byte\n",sizeof(double));
    printf("long double:%lu byte\n",sizeof(long double));
    printf("void*:%lu byte\n",sizeof(void*));
    return 0;
}