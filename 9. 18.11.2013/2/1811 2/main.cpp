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
	cout << "����������, ������� �������� ������� ���������" << endl;
	cin >> untouchN;
	cout << "����������, ������� �������� ������� ���������" << endl;
	cin >> untouchM;
	int accountOfOtobr = degree(untouchN, untouchM);
	cout << "���������� �����������: " << accountOfOtobr << endl;

	if (untouchN != untouchM)
	{
		cout << "������� ���, ������ ��� �������� �������� �� �����";
	}
	else
	{
		cout << "���������� �������: " << bijection(untouchN) << endl;
	}
	cout << endl;

	if (untouchM < untouchN)
	{
		cout << "�������� ���" << endl;
	}
	else
	{
		int injection = bijection(untouchN) / (bijection(untouchN - untouchM + 1));
		cout << "����������� ��������: " << injection << endl;
	}
	cout << endl;

	if (untouchM > untouchN)
	{
		cout << "��������� ���" << endl;
	}
	else
	{
		double surjection = surjectionF(untouchN, untouchM);
		cout << "���������� ���������: " << surjection << endl;
	}

	return 0;
}