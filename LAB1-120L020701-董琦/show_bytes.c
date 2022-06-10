#include <stdio.h>
#include <stdlib.h>

int main (int argc,char* argv[])
{
    int i=argc-1;
    int j;
    for(j=0;j<i;j++)
    {
        FILE* file=fopen(argv[j+1],"r");
        unsigned cpr;
        int count=0;
        while(1)
        {
            cpr=getc(file);
            if(feof(file))
            	break;
            if(cpr==0x0A)
                printf("\\n:%x\t",cpr);
            else if(cpr>=(unsigned)0x7f)
            {
                printf("%o:%x\t",cpr,cpr);
            }
            else
                printf("%c:%x\t",cpr,cpr);
            count++;
            if(count==16)
            {  
                count=0;
                printf("\n");
            }
        }
        fclose(file);
        printf("\n");
    }
    return 0;
}