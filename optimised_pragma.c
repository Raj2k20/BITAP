#include"bitap.h"

void SearchString_opt_pragma(int* a, const char *text, const char *pattern)
{
	int m = strlen(pattern);
	unsigned long R;
	unsigned long patternMask[CHAR_MAX + 1];
	int i;
	int start[10000];
	int start_index = 0;

	k=0;
	int check = 0;
	
	printf("\n-------------------- Optimised pragma approach -------------------\n");
	R = ~1;
    #pragma parallel omp for
	for (i = 0; i <= CHAR_MAX; ++i)
		patternMask[i] = ~0;

    #pragma parallel omp for
	for (i = 0; i < m; ++i)
		patternMask[pattern[i]] &= ~(1UL << i);
	
    #pragma parallel omp for
	for (i = 0; i < strlen(text); i++)
	{
		if(pattern[0] == text[i])
		{
			start[start_index] = i;
			start_index += 1;
		}
	}

    #pragma parallel omp for
	for (i = 0; i<start_index; ++i)
	{
		R = ~1;
		for (int j=0; j<m; j++)
		{
			R |= patternMask[text[start[i]+j]];
			R <<= 1;
			if (0 == (R & (1UL << m)))
			{	
				check = 1;
				a[k] = (i - m) + 1;
				k++;
			}
		}

	}
	if(check==0)
	{
		a[0]=-1;
		k++;
	}
}