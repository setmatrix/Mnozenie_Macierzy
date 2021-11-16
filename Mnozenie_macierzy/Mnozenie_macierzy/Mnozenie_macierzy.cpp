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
private:
	long long int** macierz;
	long long int* wektor;
	long long int c;
	int row;
	int col;
	long long int* wynik;
	long long int n;
	long long int mod;
	long long int** macierzJednostkowa;
public:
	friend std::ostream& operator<<(std::ostream& out, const matrix& o);
	matrix()
	{
		this->row = this->col = 3;
		macierz = new long long* [row];
		for (int i = 0; i < row; i++)
		{
			macierz[i] = new long long[col];
		}
		wynik = new long long [3] { 0, 0, 0 };
		macierzJednostkowa = new long long* [row];
		for (int i = 0; i < row; i++)
		{
			macierzJednostkowa[i] = new long long[col];
		}
		this->c = this->mod = this->n = 0;
		this->wektor = NULL;
	}
	matrix(long long c, long long n, long long mod) : matrix()
	{
		this->c = c;
		wektor = new long long[row] { 2, 1, (2 - c)};
		InitiateDataToMatrix();
		this->n = n-2;
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

		macierzJednostkowa[0][0] = 1;
		macierzJednostkowa[0][1] = 0;
		macierzJednostkowa[0][2] = 0;
		macierzJednostkowa[1][0] = 0;
		macierzJednostkowa[1][1] = 1;
		macierzJednostkowa[1][2] = 0;
		macierzJednostkowa[2][0] = 0;
		macierzJednostkowa[2][1] = 0;
		macierzJednostkowa[2][2] = 1;
	}
	void wyliczSn()
	{
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
		delete[] wektor;
		delete[] wynik;
		for (int i = 0; i < 3; i++)
		{
			delete[] macierzJednostkowa[i];
		}
		delete[] macierzJednostkowa;

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
	void operator*(const matrix& t)
	{
		for (int i = 0; i < 3; i++)
		{
			this->wynik[i] = 0;
			for (int j = 0; j < 3; j++)
			{
				this->wynik[i] += (this->macierzJednostkowa[i][j] * t.wektor[j]) % mod;
			}
		}
	}
};

std::ostream& operator<<(std::ostream& out, const matrix& m)
{
	return out << m.wynik[0] % m.mod << endl;
}

int main()
{
	int t;
	long long n = 0;
	long long c = 0;
	long long mod = 0;
	cout << "Podaj c\n";
	cin >> c;
	cout << "\nPodaj modulo\n";
	cin >> mod;
	cout << "\nPodaj ilosc cyfr\n";
	cin >> t;
	for (; t > 0; t--)
	{
		cout << "Podaj n\n";
		cin >> n;
		if (n >= 2)
		{
			matrix macierz(c, n, mod);
			matrix macierz2(c, n, mod);
			macierz.wyliczSn();
			macierz* macierz2;
			cout << macierz;
		}
		else if (n == 1)
		{
			cout << n << endl;
		}
	}
	return 0;
}