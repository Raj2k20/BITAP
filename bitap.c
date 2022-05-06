#include "brute.c"
#include "brute_pragma.c"
#include"helper.c"
#include "bitap.h"
#include"optimised.c"
#include "optimised_pragma.c"

int main(int argc, char *argv[])
{
	struct timeval calc;
    double calctime;
    double gflops;

	int* array;
	array = (int*)malloc(sizeof(int)*100000);
	int t;
	
    char *text;
    char *pattern;
	FILE *ptr1;
	FILE *ptr2;
    text = (char*)malloc(sizeof(char)*TEXTMAX);
    assert(text!=NULL);
    pattern = (char*)malloc(sizeof(char)*TEXTMAX);
    assert(pattern!=NULL);
    
    ptr1 = fopen(argv[1],"r");
    ptr2 = fopen(argv[2],"r");
    
	fscanf(ptr1,"%s",text);
	fscanf(ptr2,"%s",pattern);

	fclose(ptr1);
	fclose(ptr2);

	gflops = (TEXTMAX + CHAR_MAX) * 1e-09;

	srand((unsigned)time(NULL));

	tick(&calc);
    SearchString_opt(array, text, pattern);
	calctime = tock(&calc);

	float mem_bw = 8.0*(TEXTMAX + CHAR_MAX)*1e-09/calctime;

	printf("Time (in milli-secs) %f\n", calctime*1000);
    printf("Memory Bandwidth (in GBytes/s): %f\n", mem_bw);
    printf("Compute Throughput (in GFlops/s): %f\n", gflops / calctime);

	srand((unsigned)time(NULL));

	tick(&calc);
    SearchString(array, text, pattern);
	calctime = tock(&calc);

	printf("Time (in milli-secs) %f\n", calctime*1000);
    printf("Memory Bandwidth (in GBytes/s): %f\n", mem_bw);
    printf("Compute Throughput (in GFlops/s): %f\n", gflops / calctime);

	srand((unsigned)time(NULL));

	tick(&calc);
    SearchString_pragma(array, text, pattern);
	calctime = tock(&calc);

	printf("Time (in milli-secs) %f\n", calctime*1000);
    printf("Memory Bandwidth (in GBytes/s): %f\n", mem_bw);
    printf("Compute Throughput (in GFlops/s): %f\n", gflops / calctime);

	srand((unsigned)time(NULL));

	tick(&calc);
    SearchString_opt_pragma(array, text, pattern);
	calctime = tock(&calc);

	printf("Time (in milli-secs) %f\n", calctime*1000);
    printf("Memory Bandwidth (in GBytes/s): %f\n", mem_bw);
    printf("Compute Throughput (in GFlops/s): %f\n", gflops / calctime);
    return 0;
}