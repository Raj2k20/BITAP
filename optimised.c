#include"bitap.h"


void SearchString(int* a, const char *text, const char *pattern)
{
	int m = strlen(pattern);
	unsigned long R;
	unsigned long patternMask[CHAR_MAX + 1];
	int i;
	k=0;
	int check = 0;
	// if (pattern[0] == '\0') 
	// {	
	// 	a[0] = 0;
	// 	k++;
	// }
	// if (m > 31) return -1; //Error: The pattern is too long!
	R = ~1;
	for (i = 0; i <= CHAR_MAX; ++i)
		patternMask[i] = ~0;
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