/*
 пр и вводе 1.22Е5
 33333.Е-7
 1.55
 пишет, что все корректно,
 при вводе 
 1Е
 1.Е
 .
 2.4-5
 пишет, что не правильно
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

enum User
{
	beginU,
	firstSign,
	digit,
	onlyLetter,
	digitAfterLetter,
	point,
	sign,
	error,
};

int main()
{
	cout << "please, enter line" << endl;
	char *tmp = new char[100];
	char *str = tmp;
	gets(str);
	User check = beginU;
	char temp = 0;
	while ((check != error) && (*str))
	{
		switch (check)
		{
		case beginU:
			temp = str[0];
			str++;
			if ((temp >= '0') && (temp <= '9'))
				check = firstSign;
			else
				check = error;
			break;

		case firstSign:
			temp = str[0];
			str++;
			if (temp >= '0' && temp <= '9')
				check = firstSign;
			else
			{
				if (temp == '.')
				{
					check = point;
				}
				else
				{
					if (temp = 'E')
					{
						check = onlyLetter;
						if (str[0] == NULL)
						{
							check = error;
						}
					}
					else
					{
						check = error;
					}
				}
			}
			break;

		case point:
			temp = str[0];
			str++;
			if (temp >= '0' && temp <= '9')
			{
				check = digit;
			}
			else
			{
				check = error;
			}
			break;

		case digit:
			temp = str[0];
			str++;
			if (temp >= '0' && temp <= '9')
			{
				check = digit;
			}
			else
			{
				if (temp == 'E')
				{
					check = onlyLetter;
					if (str[0] == NULL)
					{
						check = error;
					}
				}
				else
				{
					check = error;
				}
			}
			break;

		case onlyLetter:
			temp = str[0];
			str++;
			if (temp == '+' || temp == '-')
				check = sign;
			else
			{
				if (temp >= '0' && temp <= '9')
					check = digitAfterLetter;
				else
				{
					check = error;
				}
			}
			break;

		case sign:
			temp = str[0];
			str++;
			if (temp >= '0' && temp <= '9')
			{
				check = digitAfterLetter;
			}
			else
			{
				check = error;
			}
			break;

		case digitAfterLetter:
			temp = str[0];
			str++;
			if (temp >= '0' && temp <= '9')
			{
				check = digitAfterLetter;
			}
			else
				check = error;
		}
	}
	if (check == error)
	{
		cout << "line is not correct" << endl;
	}
	else
	{
		cout << "line is correct" << endl;
	}
	delete[]tmp;
	return 0;
}