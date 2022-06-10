//#pragma pack (n)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
//#include <immintrin.h>

#define lenth 1920
#define width 1080

#define likely(x) __builtin_expect(!!(x), 1)

long long img[lenth][width];

void process(long long img[lenth][width]);

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < lenth; i++)
		for (int j = 0; j < width; j++)
			img[i][j] = rand() % 10000;
	LARGE_INTEGER  num;
	long long start, end, freq;
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	for(int c=0;c<1000;c++)
		process(img);
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("total time=%lld\n",(end - start) * 1000 / freq);
	return 0;
}
//不处理边界像素点
void process(long long img[lenth][width])
{
	long long buf[width];
	register long long* imge = (long long*)img;
	for (register unsigned int i = 0; i < width; i++)
	{
		buf[i] = img[0][i];
	}
	register int row_bd = lenth - 1;
	register int col_bd = width - 1;
	int row_size = sizeof(long long) * width;
	long long buf2[width];
	for (register unsigned int i = 1; i < row_bd; i++)
	{
		long long * bias1 = imge+i * width;	
		for (register unsigned int j = 1; j < col_bd; j+=14)
		{
			int m = j;
			int n = j + 1;
			register long long * bias2 = bias1 + m;
			memcpy(buf2+m, bias1 + width+m, 14*8);
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
			{register long long temp1 = ((buf[m] + buf2[m]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[m] = *(bias2);
			*bias2++ = temp1;
			m += 2;
			register long long temp2 = ((buf[n] + buf2[n]) + (*(bias2 - 1) + *(bias2 + 1))) >> 2;
			buf[n] = *(bias2);
			*bias2++ = temp1;
			n += 2; }
		}
	}
	long long * bias1 = imge+(lenth - 2) * width;
	for (register int j = 1; j <col_bd; j++)
	{
		long long * bias2 = bias1 + j;
		*(bias2) = ((buf[j] + *( bias2 + width)) + (*(bias2 - 1) + *( bias2 + 1))) >> 2;
	}
}