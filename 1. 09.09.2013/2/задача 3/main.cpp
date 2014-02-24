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
	 
	int check = 0;
	if (delimoe < 0) {
		delimoe = -delimoe;
		++check;
	}
	if (delitel < 0) {
		 delitel = -delitel;
		 ++check;
	}
	if (delitel != 0) {
		int count = 0;
		while (delitel < delimoe) {
			++count;
			delimoe = delimoe - delitel;
		}
		if (check == 1) {
			count = -count;
			printf("nepolnoe chastnoe = %d\n", count);
		}
	}
	 else {
			printf("impossible\n");
	 }
	
	 return 0;
 }