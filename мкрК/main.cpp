#include<iostream>

#include<iomanip>

using namespace std;

int main()

{
	/*int answer;
	cout << "Enter your task:" << endl << "1 - Encryption" << endl << "2 - Decryption" << endl;
	cin >> answer;
	switch (answer) {
	case 1:*/
		char  cin_text[50];
		int a;
		int* array = new int[strlen(cin_text)];
		cout << "Enter word that you want to encrypt:" << endl;
		cin >> cin_text;//вводимо слово яке треба зашифрувати
		for (int i = 0; i < strlen(cin_text); i++)
		{
			if (cin_text[i] == 'A')
			{
				array[i] = 0;
			}
			else if (cin_text[i] == 'B')
			{
				array[i] = 1;
			}
			else if (cin_text[i] == 'c')
			{
				array[i] = 2;
			}
			else if (cin_text[i] == 'D')
			{
				array[i] = 3;
			}
			else if (cin_text[i] == 'E')
			{
				array[i] = 4;
			}
			else if (cin_text[i] == 'F')
			{
				array[i] = 5;
			}
			else if (cin_text[i] == 'G')
			{
				array[i] = 6;
			}
			else if (cin_text[i] == 'H')
			{
				array[i] = 7;
			}
			else if (cin_text[i] == 'I')
			{
				array[i] = 8;
			}
			else if (cin_text[i] == 'J')
			{
				array[i] = 9;
			}
			else if (cin_text[i] == 'K')
			{
				array[i] = 10;
			}
			else if (cin_text[i] == 'L')
			{
				array[i] = 11;
			}
			else if (cin_text[i] == 'M')
			{
				array[i] = 12;
			}
			else if (cin_text[i] == 'N')
			{
				array[i] = 13;
			}
			else if (cin_text[i] == 'O')
			{
				array[i] = 14;
			}
			else if (cin_text[i] == 'P')
			{
				array[i] = 15;
			}
			else if (cin_text[i] == 'Q')
			{
				array[i] = 16;
			}
			else if (cin_text[i] == 'R')
			{
				array[i] = 17;
			}
			else if (cin_text[i] == 'S')
			{
				array[i] = 18;
			}
			else if (cin_text[i] == 'T')
			{
				array[i] = 19;
			}
			else if (cin_text[i] == 'U')
			{
				array[i] = 20;
			}
			else if (cin_text[i] == 'V')
			{
				array[i] = 21;
			}
			else if (cin_text[i] == 'W')
			{
				array[i] = 22;
			}
			else if (cin_text[i] == 'X')
			{
				array[i] = 23;
			}
			else if (cin_text[i] == 'Y')
			{
				array[i] = 24;
			}
			else if (cin_text[i] == 'Z')
			{
				array[i] = 25;
			}
			else if (cin_text[i] == '_')
			{
			array[i] = 26;
			}
			cout << array[i] << " ";
		}
		cout << endl << endl;
		int n, m, q;
		int aArr[3][3] = {6, 24, 1, 13, 16, 10, 20, 17, 15};//створюємо матрицю з ключовим словом
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << aArr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		double rows_bArr;
		rows_bArr = ceil(strlen(cin_text) / 3 + 0.4);
		int** bArr = new int* [rows_bArr];
		int  rows_bArr1 = int(rows_bArr);
		for (int i = 0; i < 3; i++)
		{
			*(bArr + i) = new int[rows_bArr1];//создали матрицу для чисел изначального текста
		}
		for (int i = 0, k = 0; i < 3; i++)
		{
			for (int j = 0; j < rows_bArr1; j++)
			{
				if (k >= strlen(cin_text))
				{
					*(*(bArr + i) + j) = 26;//если чисел в strlen(text) будем меньше чем элементов матрицы то инициализруем эти элементы матрицы как пробелы( 26)
				}
				else
				{
					*(*(bArr + i) + j) = array[k++];
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < rows_bArr1; j++)
			{
				cout << *(*(bArr + i) + j) << " "; //вывели матрицу на экран
			}
			cout << endl;
		}
		cout << endl;
		
		int** cArr = new int* [3];
		for (int i = 0; i < 3; i++)
		{
			cArr[i] = new int[rows_bArr1];
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= rows_bArr1; j++)
			{
				cArr[i][j] = 0;
				for (int k = 0; k < rows_bArr1; k++)
				{
					cArr[i][j] += aArr[i][k]*bArr[k][j];
				}
			}
		}
		for (int i = 0; i < rows_bArr1; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				cout << cArr[i][j] << " ";
			}
			cout << endl;
		}
	/*	break;
	case 2:
		cout << " task:";
		break;
	defoult:
		cout << "defoult: ";
	}*/
}

	/*int n, m, q, i, j;
	cout << "Enter cols count in matrix A and rows count in matrix B: ";
	cin >> n;
	cout << "Enter rows count in matrix A: ";
	cin >> m;
	cout << "Enter cols count in matrix B: ";
	cin >> q;
	int** aArr = new int* [m];
	for (i = 0; i < m; i++)
		aArr[i] = new int[n];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "Enter arrays elements of matrix A ";
			cin >> aArr[i][j];
		}
	}
	cout << "Matrix A: " << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(5) << aArr[i][j];
		cout << endl;
	}
	int** bArr = new int* [n];
	for (i = 0; i < n; i++)
		bArr[i] = new int[q];
	for (i = 0;  i < m; i++)
		{
		for (j = 0; j < q; j++)
		{
		cout << "Enter arrays elements of matrix B ";
		cin >> bArr[i][j];
		}
		}
	cout << "Matrix B: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < q; j++)
			cout << setw(5) << bArr[i][j];
		cout << endl;
	}
	int** cArr = new int* [i];
	for (i = 0; i < m; i++)
		cArr[i] = new int[j];
	for (i = 0; i < m; i++)
		for (j = 0; j < q; j++)
		{
			cArr[i][j] = 0;
			for (int k = 0; k <= q + 1; k++)
				cArr[i][j] += (aArr[i][k] * bArr[k][j]);
		}
	cout << "Matrix C: " << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < q; j++)
			cout << setw(5) << cArr[i][j];
		cout << endl;
	}
	return 0;
	*/