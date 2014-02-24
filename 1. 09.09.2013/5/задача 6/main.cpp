#include <stdio.h>

 int main()
 { 
	 int a[28] = {0};
	 for (int i = 0; i < 29; ++i) {
		 for (int j = 0; j < 1000; ++j) {
			 int summ = (j % 10) + ((j / 10) % 10) + (j / 100);
			 if (summ == i) {
				 ++a[i];
			 }
		 }
	 }
		 int result = 0;
		 for (int i = 0; i < 29; ++i) {
			 result += a[i] * a[i];
		 }
	 printf("number of lucky tickets = %d\n", result);
	 return 0;
	 }