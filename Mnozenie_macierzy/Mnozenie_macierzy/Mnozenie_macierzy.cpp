#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ostream>
#include <sstream>

using namespace std;

class matrix
{
	long long** macierz;
	long long* wektor;
	long long c;
	long long row;
	long long col;
	long long* wynik;
	long long n;
	long long mod;
	long long** macierzJednostkowa;
public:
	friend std::ostream& operator<<(std::ostream& out, const matrix& o);
	matrix()
	{
		this->row = 3;
		this->col = 3;
		macierz = new long long* [row];
		for (int i = 0; i < row; i++)
		{
			macierz[i] = new long long[col];
		}
		wynik = new long long [row] { 0, 0, 0 };
		macierzJednostkowa = new long long* [row];
		for (int i = 0; i < row; i++)
		{
			macierzJednostkowa[i] = new long long[col];
		}
		this->c = 0;
		this->mod = 0;
	}
	matrix(long long c, long long n, long long mod) : matrix()
	{
		this->c = c;
		wektor = new long long[row] { 2, 1, (2 - c)};
		InitiateDataToMatrix();
		this->n = n - 2;
		this->mod = mod;

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
	void wyliczSn()
	{
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
						macierzJednostkowa[i][j] = pomocnicza[i][j] % mod;
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
	long long* operator+(const matrix& t)
	{

	}
	long long* operator*(const matrix& t)
	{
		for (int i = 0; i < 3; i++)
		{
			wynik[i] = 0;
			for (int j = 0; j < 3; j++)
			{
				wynik[i] += (this->macierzJednostkowa[i][j] * t.wektor[j]);
			}
		}
		return wynik;
	}
};

std::ostream& operator<<(std::ostream& out, const matrix& m)
{
	return out << m.wynik[0];
}

int main()
{
	long long n = 9;
	long long c = 3;
	long long mod = 7;
	matrix macierz(c,n, mod);
	matrix macierz2(c,n, mod);
	macierz.wyliczSn();
	long long* wynik = macierz * macierz2;
	cout << wynik;
	return 0;
}