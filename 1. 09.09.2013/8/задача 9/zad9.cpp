#include <stdio.h>

int main()
{
	int given = 0;
	printf("Input number ");
	scanf("%d", &given);
	printf("prime numbers: ");
	for (int i = 1; i <= given; ++i)
	{   
		int check = 0;
		for (int j = 1; j <= i; ++j)
		{
			if ((i % j) == 0)
			{
				++check;
			}
		}
		if (check == 2)
		{
			printf("%d, ", i);
		}
	}	
	return 0;
}