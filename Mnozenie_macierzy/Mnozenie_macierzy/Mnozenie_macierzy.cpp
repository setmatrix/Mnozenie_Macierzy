#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

/*string* S[];

class matrix
{
public:
	static long** macierz;
	static vector <long> wektor;
	matrix();
	~matrix();
};

matrix::matrix()
{
	macierz = new long*[3];
	for (int i = 0; i < 3; i++)
	{
		macierz[i] = new long[3];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> macierz[i][j];
		}
	}
	long l;
	for (int i = 0; i < 3; i++)
	{
		cin >> l;
		wektor.push_back(l);
	}
}



matrix::~matrix()
{
	for (int i = 0; i < 3; i++)
	{
		delete[] macierz[i];
	}
	delete[] macierz;
}

void mnozenie(long ** macierz, vector <long> wektor)
{
	//long det = macierz[1][1] * macierz[2][2] * macierz[3][3] + macierz[1][2] * macierz[2][3] * macierz[3][1] + macierz[1][3] * macierz[2][1] * macierz[3][2]
	//	- macierz[1][3] * macierz[2][2]*macierz[3][1] - macierz[1][2] * macierz[2][1] * macierz[3][3] - macierz[1][1] * macierz[2][3] * macierz[3][2];

	long result[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			result[i] += macierz[i][j] * wektor[i];
		}
}

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

unsigned long long fibo(long n,long c)
{
	unsigned long long q11, q12, q21, q22, // macierz Q
		p11, p12, p21, p22, // macierz P
		w11, w12, w21, w22; // macierz W

	if (n < 2) return n;
	//if (n==2) return 1;

	// ustawiamy macierz Q

	q11 = q12 = q21 = 1;
	q22 = 0;
	// w macierzy W tworzymy macierz jednostkową

	w11 = w22 = 1;
	w12 = w21 = 0;

	n--;      // będzie nam potrzebna n-1 potęga Q
	while (n)
	{
		if (n & 1)
		{
			// wykonujemy mnożenie P = W x Q

			p11 = w11 * q11 + w12 * q21;  p12 = w11 * q12 + w12 * q22 ;

			// 11 = 

			p21 = w21 * q11 + w22 * q21 ;  p22 = w21 * q12 + w22 * q22;

			// wynik przenosimy: W = P

			w11 = p11; w12 = p12;
			w21 = p21; w22 = p22;
		}

		n >>= 1;    // usuwamy z n sprawdzony bit
		
		if (!n) break;

		// podnosimy Q do kwadratu:  P = Q x Q *c

		p11 = q11 * q11 + q12 * q21; p12 = q11 * q12 + q12 * q22 ;

		// 11 = 7*7+3*3    12=7*3+3*1

		p21 = q21 * q11 + q22 * q21 ; p22 = q21 * q12 + q22 * q22;

		// 21= 3*1+1*3    22=3*3+*1*1

		// wynik przenosimy: Q = p
		q11 = p11; q12 = p12;
		q21 = p21; q22 = p22;

	}
	return w11;
}

unsigned int fib(long n, long c) {
	if (n == 0) return 0;
	if (n == 1||n==2) return 1;
	return fib(n - 1, c)*c + fib(n - 2, c);
}
int main()
{
	//matrix();
	//mnozenie(matrix::macierz, matrix::wektor);
	//ladowanie();
	long n = 7;
	long c = 4;
	long x = 0;
	for (int i = 1; i <= n; i++)
	{
		x += fib(i, c);
	}
	cout << x<<endl;
	cout<<CCC(c, n-2);//obliczanie sn
	return 0;
}
