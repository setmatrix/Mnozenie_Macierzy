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
	void wyliczSn(long long n, long long M)
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
						macierzJednostkowa[i][j] = pomocnicza[i][j] % M;
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
		cout << wynik[0] %M<< endl;
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
	long long operator+(const matrix& t)
	{

	}
	long long operator*(const matrix& t)
	{

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
int main()
{
	long long n = 9;
	long long c = 3;
	long long M = 7;
	matrix macierz(c);
	macierz.InitiateDataToMatrix();
	macierz.wyliczSn(n-2, M);

	return 0;
}