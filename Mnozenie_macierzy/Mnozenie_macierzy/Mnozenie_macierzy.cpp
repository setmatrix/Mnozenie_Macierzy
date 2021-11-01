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

//const int MAX = 1000;

// Create an array for memoization
//int f[MAX] = { 0 };
/*long fib(long n,long c)
{
	// Base cases
	if (n == 0)
		return 0;
	if (n == 1)
		return (f[n] = 1);

	// If fib(n) is already computed
	if (f[n])
		return f[n];

	long k = (n & 1) ? (n + 1) / 2 : n / 2;

	// Applying above formula [Note value n&1 is 1
	// if n is odd, else 0.
	f[n] = (n & 1) ? (fib(k,c) * fib(k,c) + fib(k - 1,c) * fib(k - 1,c))
		: (2 * fib(k - 1,c) + fib(k,c)) * fib(k,c);

	return f[n];
}*/
/*long fibonacci(long n)
{
	f = new long[n];
	f = { 0 };
	return fib(n);
}*/

/*long CCC(long c)
{
	long tab[3][3] = { { c,1,1 }, { 1, 0, 0 }, { 0, 0, 1 } };
	long vector[3] = { 1,1,(2 - c) };
	long result[3] = { 0 };
	long results[3][3] = { 0 };
	long product = 0;
	long n = 1;
	for (int k = 0; k > n; k++)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				for (int u = 0; u < 3; u++)
					results[i][j] += tab[i][u] * tab[u][j];
			}
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			result[i] += results[i][j] * vector[i];
		}

		for (int j = 0; j < 3; j++) {
			cout << result[j]<<" ";
		}
	return 0;
}*/
/*void test()
{
	long matrixx[2][2] = { {1,1},{1,0} };
	long wektor[2] = { 1, 0 };
	long result[2][2] = { 1 };

	for (long n = 0; n < 2; n++)
	{
		result[0][0] *= matrixx[0][0] * matrixx[0][0] - matrixx[1][0] * matrixx[0][1];
		result[1][0] *= result[1][0]* result[0][0]+ result[1][1]* result[1][0];
		result[0][1] *= result[0][0] * result[0][1] - result[0][1] * result[1][1];
		result[1][1] *= result[1][0] * result[0][1] + result[1][1] * result[1][1];
	}
	for (long n = 0; n < 2; n++)
	{
		for (long k = 0; k < 2; k++)
		{
			cout << result[n][k]<<" ";
		}
		cout << endl;
	}
}*/

unsigned long long fibo(int n,long c)
{
	unsigned long long q11, q12, q21, q22, // macierz Q
		p11, p12, p21, p22, // macierz P
		w11, w12, w21, w22; // macierz W

	if (n < 2) return n;

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

			p11 = w11 * q11 + w12 * q21 * c; p12 = w11 * q12 + w12 * q22 * c;
			p21 = w21 * q11 + w22 * q21 * c; p22 = w21 * q12 + w22 * q22 * c;

			// wynik przenosimy: W = P

			w11 = p11; w12 = p12;
			w21 = p21; w22 = p22;

		}

		n >>= 1;    // usuwamy z n sprawdzony bit

		if (!n) break;

		// podnosimy Q do kwadratu:  P = Q x Q

		p11 = q11 * q11 + q12 * q21 * c; p12 = q11 * q12 + q12 * q22 * c;
		p21 = q21 * q11 + q22 * q21 * c; p22 = q21 * q12 + q22 * q22 * c;

		// wynik przenosimy: Q = p

		q11 = p11; q12 = p12;
		q21 = p21; q22 = p22;

	}

	return w11;
}
/*unsigned int fib(int n,long c) {
	if ((n == 0) || (n == 1)) return n;
	return fib(n - 1,c) + fib(n - 2,c)*c;
}*/
int main()
{
	//matrix();
	//mnozenie(matrix::macierz, matrix::wektor);
	//ladowanie();
	long n = 7;
	long c = 2;
	//cout << " " << fib(n,c);
	//cout << CCC(c);
	//test();
	cout << fib(n,c)<<endl;
	cout << fibo(n, c);
	return 0;
}
