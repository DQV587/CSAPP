#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define lenth 1080
#define width 1920

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
	for(int k=0;k<1000;k++)
		process(img);
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("total time=%lld\n", (end - start) * 1000 / freq);
	return 0;
}
//不处理边界像素点
void process(long long img[lenth][width])
{
	long long buf[width];
	for (int i = 0; i < lenth; i++)
		buf[i] = img[0][i];
	for (int j = 1; j < width - 1; j++)
		for (int i = 1; i < lenth - 1; i++)		
		{
			long long temp = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4;
			img[i - 1][j] = buf[j];
			buf[j] = temp;	
		}
	for (int i = 0; i < width; i++)
		img[lenth - 2][i] = buf[i];
}