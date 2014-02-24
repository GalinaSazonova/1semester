#include <stdio.h>

int main()
 { 
	 int x = 0;
	 printf("Input x");
	 scanf("%d", &x);
	 int squareOfX = x * x;
	 int result = (squareOfX + 1) * (squareOfX + x);
	 printf("Answer = %d\n", result);
	 return 0;
 }
 