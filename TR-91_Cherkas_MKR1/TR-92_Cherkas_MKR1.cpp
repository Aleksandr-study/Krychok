#include<iostream>

#include<iomanip>

using namespace std;

int main()

{
	setlocale(LC_ALL, "rus");
	char  cin_text[50];
	int* array = new int[strlen(cin_text)];
	cout << "Введiть слово для розшифровки:" << endl;
	cin >> cin_text;//вводимо слово яке треба зашифрувати
	for (int i = 0; i < strlen(cin_text); i++)
	{
		if (cin_text[i] == 'a')
		{
			array[i] = 1;
		}
		else if (cin_text[i] == 'b')
		{
			array[i] = 2;
		}
		else if (cin_text[i] == 'c')
		{
			array[i] = 3;
		}
		else if (cin_text[i] == 'd')
		{
			array[i] = 4;
		}
		else if (cin_text[i] == 'e')
		{
			array[i] = 5;
		}
		else if (cin_text[i] == 'f')
		{
			array[i] = 6;
		}
		else if (cin_text[i] == 'g')
		{
			array[i] = 7;
		}
		else if (cin_text[i] == 'h')
		{
			array[i] = 8;
		}
		else if (cin_text[i] == 'i')
		{
			array[i] = 9;
		}
		else if (cin_text[i] == 'j')
		{
			array[i] = 10;
		}
		else if (cin_text[i] == 'k')
		{
			array[i] = 11;
		}
		else if (cin_text[i] == 'l')
		{
			array[i] = 12;
		}
		else if (cin_text[i] == 'm')
		{
			array[i] = 13;
		}
		else if (cin_text[i] == 'n')
		{
			array[i] = 14;
		}
		else if (cin_text[i] == 'o')
		{
			array[i] = 15;
		}
		else if (cin_text[i] == 'p')
		{
			array[i] = 16;
		}
		else if (cin_text[i] == 'q')
		{
			array[i] = 17;
		}
		else if (cin_text[i] == 'r')
		{
			array[i] = 18;
		}
		else if (cin_text[i] == 's')
		{
			array[i] = 19;
		}
		else if (cin_text[i] == 't')
		{
			array[i] = 20;
		}
		else if (cin_text[i] == 'u')
		{
			array[i] = 21;
		}
		else if (cin_text[i] == 'v')
		{
			array[i] = 22;
		}
		else if (cin_text[i] == 'w')
		{
			array[i] = 23;
		}
		else if (cin_text[i] == 'x')
		{
			array[i] = 24;
		}
		else if (cin_text[i] == 'y')
		{
			array[i] = 25;
		}
		else if (cin_text[i] == 'z')
		{
			array[i] = 26;
		}
	}
	cout << endl;
	int m = 2;
	int** bArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		bArr[i] = new int[m];
	}
	for (int i = 0, k = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bArr[i][j] = array[k++];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(5) << bArr[i][j];
		}
		cout << endl;
	}
	cout << "Введiть елементи матрицi 2x2: ";
	int** aArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		aArr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> aArr[i][j];
		}
	}
	cout << "Ключова матриця: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(5) << aArr[i][j];
		}
		cout << endl;
	}
	double det = 0;
	int j;
	det = aArr[0][0] * aArr[1][1] - aArr[0][1] * aArr[1][0];
	int** algArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		algArr[i] = new int[m];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if  (algArr[i][j] == algArr[1][1])
			{
			algArr[1][1] = ((aArr[0][0] + 26*1) / det);
			}
			if (algArr[i][j] == algArr[1][1])
			{
				algArr[0][0] = ((aArr[1][1] + 26*2) / det);

			}
			if (algArr[i][j] == algArr[1][1])
			{
				algArr[0][1] = ((aArr[0][1] * (-1) + 26*9) / det);
			}
			if (algArr[i][j] == algArr[1][1])
			{
				algArr[1][0] = ((aArr[1][0] * (-1) + 26*3) / det);
			}
		}
	}
	cout << "Обернена матриця" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << algArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int** cArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		cArr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cArr[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				cArr[i][j] += bArr[i][k] * algArr[k][j];
			}
		}
	}
	cout << "Результат множення:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << cArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Результат множення як остача:" << endl;
	cout << endl;
	int* dArr = new int [m];
	int n = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dArr[n] = (cArr[i][j] % 26);
			cout << dArr[n] << " ";
			n++;
		}
	}
	cout << endl << "Розшифроване слово:";
	for (int i = 0; i < m*m; i++)
	{
		if (dArr[i] == 1)
		{
			cout << 'a';
		}
		else if (dArr[i] == 2)
		{
			cout << 'b';
		}
		else if (dArr[i] == 3)
		{
			cout << 'c';
		}
		else if (dArr[i] == 4)
		{
			cout << 'd';
		}
		else if (dArr[i] == 5)
		{
			cout << 'e';
		}
		else if (dArr[i] == 6)
		{
			cout << 'f';
		}
		else if (dArr[i] == 7)
		{
			cout << 'g';
		}
		else if (dArr[i] == 8)
		{
			cout << 'h';
		}
		else if (dArr[i] == 9)
		{
			cout << 'i';
		}
		else if (dArr[i] == 10)
		{
			cout << 'j';
		}
		else if (dArr[i] == 11)
		{
			cout << 'k';
		}
		else if (dArr[i] == 12)
		{
			cout << 'l';
		}
		else if (dArr[i] == 13)
		{
			cout << 'm';
		}
		else if (dArr[i] == 14)
		{
			cout << 'n';
		}
		else if (dArr[i] == 15)
		{
			cout << 'o';
		}
		else if (dArr[i] == 16)
		{
			cout << 'p';
		}
		else if (dArr[i] == 17)
		{
			cout << 'q';
		}
		else if (dArr[i] == 18)
		{
			cout << 'r';
		}
		else if (dArr[i] == 19)
		{
			cout << 's';
		}
		else if (dArr[i] == 20)
		{
			cout << 't';
		}
		else if (dArr[i] == 21)
		{
			cout << 'u';
		}
		else if (dArr[i] == 22)
		{
			cout << 'v';
		}
		else if (dArr[i] == 23)
		{
			cout << 'w';
		}
		else if (dArr[i] == 24)
		{
			cout << 'x';
		}
		else if (dArr[i] == 25)
		{
			cout << 'y';
		}
		else if (dArr[i] == 26)
		{
			cout << "z";
		}
	}
	system("pause");
	return 0;
}