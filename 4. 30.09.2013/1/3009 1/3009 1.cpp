/* проверка
78
-55
0..01001110
1..1001001
0..010111
23
--
89
72

1011001
1001000
10100001
161*/
#include <iostream>
#include <stdio.h>

using namespace std;

void toBinary (bool result[], int number)
{
	int mask = 1;
	for (int i = 0; i < sizeof(int) * 8; ++i) 
		{
			result[i] = (number & mask) != 0;
			mask = mask << 1;
		}
}

void binarySum (bool result1[], bool result2[], bool resultSum[])
{
	bool check = false;
	bool check2 = true;
	int i = 0;
	while (i < sizeof(int) * 8) 
	{
		if (result1[i] && result2[i] && !check && check2)
		{
			resultSum[i] = false;
			check = true;
			check2 = false;
		}
		if (result1[i] && result2[i] && check && check2)
		{
			resultSum[i] = true;
			check = true;
			check2 = false;
		}
		
		if (!result1[i] && !result2[i] && check && check2)
		{
			resultSum[i] = true;
			check = false;
			check2 = false;
		}
		if ((result1[i] || result2[i]) && check && check2)
		{
			resultSum[i] = false;
			check = true;
			check2 = false;
		}
		if ((result1[i] || result2[i]) && !check && check2)
		{
			resultSum[i] = true;
			check = false;
			check2 = false;
		}
		if (!result1[i] && !result2[i] && !check && check2)
		{
			resultSum[i] = false;
			check = false;
			check2 = false;
		}
		++i;
		check2 = true;
	}
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int first = 0;
	int second = 0;
	cout<< "Введите первое число"<<endl;
	cin>> first;
	cout<< "Введите второе число"<<endl;
	cin>> second;
	int mask = 1;
	bool result1 [sizeof (int) * 8];
	toBinary(result1, first);
	bool result2 [sizeof (int) * 8];
	toBinary(result2, second);
	cout << "Двоичное представление первого числа : ";
	for (int i = sizeof(int) * 8 - 1; i >= 0 ; --i) 
	{
		cout << result1[i];
	}
	cout << endl;
	cout << "Двоичное представление второго числа : ";
	for (int i = sizeof(int) * 8 - 1; i >= 0 ; --i) 
	{
		cout << result2[i];
	}
	cout << endl;

	bool resultSum[sizeof(int) * 8];
	binarySum(result1, result2, resultSum);
	cout << "Сумма данных чисел в двоичном виде : ";
	for (int i = sizeof(int) * 8 - 1; i >= 0 ; --i) 
	{
		cout << resultSum[i];
	}
	cout << endl;

	int decSum = 0;
	int minus = true;
	if (resultSum[sizeof(int) * 8 - 1]) 
	{
		decSum = 1;
		minus = false;
		for (int i = sizeof(int) * 8 - 1; i >= 0 ; --i) 
		{
			resultSum[i] = !resultSum[i];
		}
	}
	int overFull = 1;
	for (int i = 0; i < sizeof(int) * 8; ++i) 
	{
		if (resultSum[i])
		{
			decSum = decSum + overFull;
		}
		overFull = overFull * 2;
	}
	if (minus)
	{
		cout << "Десятичное представление этой суммы : " << decSum;
	}
	else
	{
		cout << "Десятичное представление этой суммы : " << -decSum;
	}
	cout << endl;
	return 0;
}