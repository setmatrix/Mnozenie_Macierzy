#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

string* S[];

class matrix
{
public:
	long** macierz;
	int l;
	int n;
	int m;
	matrix()
	{
		macierz = new long* [3];
		for (int i = 0; i < 3; i++)
		{
			macierz[i] = new long[3];
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
	long operator*(const matrix& v)
	{
		return (this->l * v.macierz[n][m]);
	}
	long operator+(const matrix &v)
	{
		return (this->l + v.macierz[n][m]);
	}
};

void read_from_file(int C, int M)
{
	string linia;
	fstream plik;
	string slowo;

	bool isCandM = true;

	plik.open("cipher*.in", ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(plik, linia);
			if (isCandM)
			{
				for (int i = 0; i < linia.size(); i++)
				{
					if (linia[i] == ' ')
					{
						C = stoi(slowo);
						slowo.clear();
					}
					else if (linia[i] == '\0')
					{
						M = stoi(slowo);
						slowo.clear();
					}
					else
					{
						slowo[i] = linia[i];
					}
				}
				isCandM = false;
			}
			else
			{

			}
		}
		plik.close();
	}
}



int main()
{
	matrix A;
	int C, M;
	//ladowanie();
}
