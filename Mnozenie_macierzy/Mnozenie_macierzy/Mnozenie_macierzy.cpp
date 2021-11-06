#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

class matrix
{
public:
	long long** macierz;
	long long* wektor;
	long long c;
	matrix()
	{
		macierz = new long long* [3];
		wektor = new long long[3];
		for (int i = 0; i < 3; i++)
		{
			macierz[i] = new long long[3];
		}
	}
	matrix(long long c) : matrix()
	{
		this->c = c;
	}
	void InitiateDataToMatrix()
	{
		macierz[0][0] = c;
		macierz[0][1] = 1;
		macierz[0][2] = 1;
		macierz[1][0] = 1;
		macierz[1][1] = 0;
		macierz[1][2] = 0;
		macierz[2][0] = 0;
		macierz[2][1] = 0;
		macierz[2][2] = 1;
	}
	void wyliczSn(long long n)
	{
		long long wektor[3] = { 2,1,(2 - c) };
		long long wynik[3] = { 0 };
		long long macierzJednostkowa[3][3] = { {1,0,0 },{0,1,0},{0,0,1} };
		long long pomocnicza[3][3] = { {0,0,0 },{0,0,0},{0,0,0} };
		long long s;
		while (n)
		{
			if (n % 2 == 1) //jesli bit jest = 1
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						s = 0;
						for (int k = 0; k < 3; k++)
						{
							s += macierzJednostkowa[i][k] * macierz[k][j];
						}
						pomocnicza[i][j] = s;
					}
				}
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						macierzJednostkowa[i][j] = pomocnicza[i][j];
					}
				}
			}
			n /= 2; //skrócenie o jeden bit
			if (!n) break;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					s = 0;
					for (int k = 0; k < 3; k++)
					{
						s += macierz[i][k] * macierz[k][j];
					}
					pomocnicza[i][j] = s;
				}
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					macierz[i][j] = pomocnicza[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			wynik[i] = 0;
			for (int j = 0; j < 3; j++)
			{
				wynik[i] += (macierzJednostkowa[i][j] * wektor[j]);
			}
		}
		cout << wynik[0];
	}
	~matrix()
	{
		for (int i = 0; i < 3; i++)
		{
			delete[] macierz[i];
		}
		delete[] macierz;
	}
	void printMatrix()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << macierz[i][j] << " ";
			}
			cout << endl;
		}
	}
};


void mnozenie(long** macierz, vector <long> wektor)
{
	//long det = macierz[1][1] * macierz[2][2] * macierz[3][3] + macierz[1][2] * macierz[2][3] * macierz[3][1] + macierz[1][3] * macierz[2][1] * macierz[3][2]
	//	- macierz[1][3] * macierz[2][2]*macierz[3][1] - macierz[1][2] * macierz[2][1] * macierz[3][3] - macierz[1][1] * macierz[2][3] * macierz[3][2];

	long wynik[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			wynik[i] += macierz[i][j] * wektor[i];
		}
}
/*
void ladowanie()
{
	string linia;
	fstream plik;

	plik.open("plik.txt", ios::in);
	if (plik.good() == true)
	{
		int i = 0;
		while (!plik.eof())
		{
			i++;
			getline(plik, linia);
		}
		S[i] = new string[i];
		while (!plik.eof())
		{
			S[i] = getline(plik, linia);
			i--;
		}
		plik.close();
	}
}
*/

long long CCC(long c, long n)
{
	long tab[3][3] = { { c,1,1 }, { 1, 0, 0 }, { 0, 0, 1 } };
	long vector[3] = { 2,1,(2 - c) };
	long result[3] = { 0 };
	long results[3][3] = { {1,0,0 },{0,1,0},{0,0,1} };
	long p[3][3];
	long long s;
	while (n)
	{
		if (n % 2 == 1) //jesli bit jest = 1
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					s = 0;
					for (int k = 0; k < 3; k++)
					{
						s += results[i][k] * tab[k][j];
					}
					p[i][j] = s;
				}
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					results[i][j] = p[i][j];
				}
			}
		}
		n /= 2; //skrócenie o jeden bit
		if (!n) break;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				s = 0;
				for (int k = 0; k < 3; k++)
				{
					s += tab[i][k] * tab[k][j];
				}
				p[i][j] = s;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				tab[i][j] = p[i][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		result[i] = 0;
		for (int j = 0; j < 3; j++)
		{
			result[i] += (results[i][j] * vector[j]);
		}
	}
	return result[0];
}

void wyliczSn(long c, long n)
{

	long macierz[3][3] = { { c,1,1 }, { 1, 0, 0 }, { 0, 0, 1 } };
	long wektor[3] = { 2,1,(2 - c) };
	long wynik[3] = { 0 };
	long macierzJednostkowa[3][3] = { { c,1,1 }, { 1, 0, 0 }, { 0, 0, 1 } };
	long Sn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int u = 0; u < 3; u++)
				macierzJednostkowa[i][j] += macierzJednostkowa[i][u] * macierz[u][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		//for (int j = 0; j < 3; j++) {
			//wynik[i] += macierzJednostkowa[i][j] * wektor[i];
		//}
	}
	for (int j = 0; j < 3; j++) {
		cout << macierzJednostkowa[j] << " ";
	}
}
unsigned int fib(long n, long c) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return fib(n - 1, c) * c + fib(n - 2, c);
}
int main()
{
	//matrix();
	//mnozenie(matrix::macierz, matrix::wektor);
	//ladowanie();
	long long n = 7;
	long long c = 4;
	long long x = 0;
	matrix macierz(c);
	macierz.InitiateDataToMatrix();
	cout << endl;
	macierz.wyliczSn(n-2);
	cout << endl;
	//macierz.printMatrix();
	//cout << endl;
	for (int i = 1; i <= n; i++)
	{
		x += fib(i, c);
	}
	cout << x << endl;

	cout << CCC(c, n - 2) << endl;

	return 0;
}