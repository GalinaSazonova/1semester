#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int degree(int n, int m)
{
	int check = 1;
	while (m != 1)
	{
		if (m % 2 == 1)
		{
			check = check * n;
		}
		n *= n;
		m = m / 2;
	}
	int accountOfOtobr = n * check;
	return accountOfOtobr;
}

int bijection(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*bijection(n - 1);
	}
}

double surjectionF(int n, int m)
{
	double surSum = 0;
	for (int i = 0; i != m; i++)
	{
		surSum += (pow(-1, i) * bijection(m) * degree(m - i, n)) / (bijection(i) * bijection(m - i));
	}
	return surSum;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int untouchN = 0;
	int untouchM = 0;
	cout << "Пожалуйста, введите мощность первого множества" << endl;
	cin >> untouchN;
	cout << "Пожалуйста, введите мощность второго множества" << endl;
	cin >> untouchM;
	int accountOfOtobr = degree(untouchN, untouchM);
	cout << "Количество отображений: " << accountOfOtobr << endl;

	if (untouchN != untouchM)
	{
		cout << "Биекций нет, потому что мощности множеств не равны";
	}
	else
	{
		cout << "Количество биекций: " << bijection(untouchN) << endl;
	}
	cout << endl;

	if (untouchM < untouchN)
	{
		cout << "Инъекций нет" << endl;
	}
	else
	{
		int injection = bijection(untouchN) / (bijection(untouchN - untouchM + 1));
		cout << "Колическтво инъекций: " << injection << endl;
	}
	cout << endl;

	if (untouchM > untouchN)
	{
		cout << "Сюръекций нет" << endl;
	}
	else
	{
		double surjection = surjectionF(untouchN, untouchM);
		cout << "Количество сюръекций: " << surjection << endl;
	}

	return 0;
}