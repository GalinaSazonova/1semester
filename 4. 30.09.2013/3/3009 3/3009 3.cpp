#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char str[260];
	int count = 0;
	ifstream in("lines.txt");
	while (!in.eof())
	{
		in.getline(str, 256);
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] != '\t' && str[i] != ' ')
			{
				++count;
				break;
			} 
		}
	}
	cout << "Number of not-empty lines : " << count << endl;
	in.close();
	return 0;
}