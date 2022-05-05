#include"brute.c"
// #include"optimised.c"

int main(int argc, char *argv[])
{
	int* array;
	array = (int*)malloc(sizeof(int)*100);
	int t;
	// a = (int*)malloc(sizeof(int)*TEXTMAX);
    // assert(a!=NULL);
    char *text;
    char *pattern;
	FILE *ptr1;
	FILE *ptr2;
    text = (char*)malloc(sizeof(char)*TEXTMAX);
    assert(text!=NULL);
    pattern = (char*)malloc(sizeof(char)*TEXTMAX);
    assert(pattern!=NULL);
    // pattern = "ACTGTTCG";
    // text="CTG";
    ptr1 = fopen(argv[1],"r");
    ptr2 = fopen(argv[2],"r");
    fscanf(ptr1,"%s",text);
	fscanf(ptr2,"%s",pattern);
	// printf("%s\n",text);
	// printf("%s\n",pattern);
    SearchString(array, text, pattern);
    // a = SearchString(text,pattern);
	// t = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<k;i++)
	{
	    printf("%d\n",*(array + i));
	}
	fclose(ptr1);
	fclose(ptr2);
    return 0;
}