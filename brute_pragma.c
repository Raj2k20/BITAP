#include"bitap.h"

void SearchString_pragma(int* a, const char *text, const char *pattern)
{
	int m = strlen(pattern);
	unsigned long R;
	unsigned long patternMask[CHAR_MAX + 1];
	
	int i;
	k=0;
	int check = 0;
	
	R = ~1;
	printf("------------------- Pragma approach --------------------\n");
	#pragma parallel omp for
	for (i = 0; i <= CHAR_MAX; ++i)
		patternMask[i] = ~0;

	#pragma parallel omp for
	for (i = 0; i < m; ++i)
		patternMask[pattern[i]] &= ~(1UL << i);

	for (i = 0; text[i] != '\0'; ++i)
	{
		R |= patternMask[text[i]];
		R <<= 1;

		if (0 == (R & (1UL << m)))
		{	
			check = 1;
			a[k] = (i - m) + 1;
			k++;
		}
	}
	if(check==0)
	{
		a[0]=-1;
		k++;
	}
}