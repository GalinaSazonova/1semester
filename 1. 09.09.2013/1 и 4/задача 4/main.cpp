#include <stdio.h>
#include <iostream>
#include <cstdlib>

int main()
 { 
	 int delimoe = 0;
	 printf("vvedi delimoe ");
	 scanf("%d", &delimoe);
	 
	 int delitel = 0;
	 printf("vvedi delitel ");
	 scanf("%d", &delitel); 
	 
	 int otr = 0;
	 if ((delimoe < 0) || (delitel < 0)) {
		abs(delimoe);
		abs(delitel);
		++otr;
	 }
	 int count = 0;
	 while (delimoe < delitel) {
		 ++count;
		 delimoe = delimoe - delitel;
	 }
	 if (otr>0) {
		 count = -1 * count;
	 }
	 printf("nepolnoe chastnoe = %d\n", count);
	 return 0;
 }