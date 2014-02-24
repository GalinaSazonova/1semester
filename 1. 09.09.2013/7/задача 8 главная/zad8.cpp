#include <stdio.h>
#include <iostream>

int main()
{
	char S[255] = {0};
	printf("Input S ");
	scanf("%s", &S);

	char S1[255] = {0};
	printf("Input S1 ");
	scanf("%s", &S1);

	int result = 0;
	for ( int i = 0; i <= strlen(S) - strlen(S1) + 1; ++i)
	{
		bool check = false;
		for (int j = 0; j < strlen(S1); ++j)
		{   
			if (S1[j] != S[j+i])
			{   
				check = true;
				break;
			}
		}
		if (!check)
		{
			++result;
		}
	} 
	printf("number of occurrences = %d\n", result);
	return 0;
}