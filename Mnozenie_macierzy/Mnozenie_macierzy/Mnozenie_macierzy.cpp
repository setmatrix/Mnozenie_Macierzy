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

// Create an array for memoization


// Returns n'th fibonacci number using table f[]


long* f;
int fib(int n)
{
	// Base cases
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	// If fib(n) is already computed
	if (f[n])
		return f[n];

	int k = (n & 1) ? (n + 1) / 2 : n / 2;

	// Applying above formula [Note value n&1 is 1
	// if n is odd, else 0.
	f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
		: (2 * fib(k - 1) + fib(k)) * fib(k);

	return f[n];
}

long fibonacci(long n)
{
	f = new long[n] = { 0 };
	return fib(n);
}
int main()
{
	//matrix();
	//mnozenie(matrix::macierz, matrix::wektor);
	//ladowanie();
	long n = 5;

	cout << " " << fibonacci(n);

	return 0;
}
