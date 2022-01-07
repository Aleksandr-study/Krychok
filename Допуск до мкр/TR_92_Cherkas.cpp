#include<iostream>

#include<iomanip>

using namespace std;

int main()

{
	setlocale(LC_ALL, "rus");
	char  cin_text[50];
	int* array = new int[strlen(cin_text)];
	cout << "¬вед≥ть слово дл¤ розшифровки:" << endl;
	cin >> cin_text;//вводимо слово ¤ке треба зашифрувати
	for (int i = 0; i < strlen(cin_text); i++)
	{
		if (cin_text[i] == 'a')
		{
			array[i] = 0;
		}
		else if (cin_text[i] == 'b')
		{
			array[i] = 1;
		}
		else if (cin_text[i] == 'c')
		{
			array[i] = 2;
		}
		else if (cin_text[i] == 'd')
		{
			array[i] = 3;
		}
		else if (cin_text[i] == 'e')
		{
			array[i] = 4;
		}
		else if (cin_text[i] == 'f')
		{
			array[i] = 5;
		}
		else if (cin_text[i] == 'g')
		{
			array[i] = 6;
		}
		else if (cin_text[i] == 'h')
		{
			array[i] = 7;
		}
		else if (cin_text[i] == 'i')
		{
			array[i] = 8;
		}
		else if (cin_text[i] == 'j')
		{
			array[i] = 9;
		}
		else if (cin_text[i] == 'k')
		{
			array[i] = 10;
		}
		else if (cin_text[i] == 'l')
		{
			array[i] = 11;
		}
		else if (cin_text[i] == 'm')
		{
			array[i] = 12;
		}
		else if (cin_text[i] == 'n')
		{
			array[i] = 13;
		}
		else if (cin_text[i] == 'o')
		{
			array[i] = 14;
		}
		else if (cin_text[i] == 'p')
		{
			array[i] = 15;
		}
		else if (cin_text[i] == 'q')
		{
			array[i] = 16;
		}
		else if (cin_text[i] == 'r')
		{
			array[i] = 17;
		}
		else if (cin_text[i] == 's')
		{
			array[i] = 18;
		}
		else if (cin_text[i] == 't')
		{
			array[i] = 19;
		}
		else if (cin_text[i] == 'u')
		{
			array[i] = 20;
		}
		else if (cin_text[i] == 'v')
		{
			array[i] = 21;
		}
		else if (cin_text[i] == 'w')
		{
			array[i] = 22;
		}
		else if (cin_text[i] == 'x')
		{
			array[i] = 23;
		}
		else if (cin_text[i] == 'y')
		{
			array[i] = 24;
		}
		else if (cin_text[i] == 'Z')
		{
			array[i] = 25;
		}
		cout << array[i] << " ";
	}
	cout << endl << endl;
	int n, m;
	cout << "¬вед≥ть к≥льк≥сть р¤дк≥в: ";
	cin >> m;
	cout << "¬вед≥ть к≥льк≥сть стовц≥в:";
	cin >> n;
	int** aArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		aArr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "¬вед≥ть елементи: ";
			cin >> aArr[i][j];
		}
	}
	cout << " лючова матриц¤: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << aArr[i][j];
		cout << endl;
	}

	float** inversearray = new float* [m];
	for (int j = 0; j < m; j++)
	{
		inversearray[j] = new float[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(inversearray + i) + j) = *(*(MatrixAlebrDop + i) + j);
		}
	}
	transpose1(inversearray, (float)m);//транспонируем матрицу

	cout << "Inverse matrix:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(inversearray + i) + j) = *(*(inversearray + i) + j) / determinant;
			cout << *(*(inversearray + i) + j) << " ";
		}
		cout << endl;
	}
	//==============================================================================================================
	cout << endl;
	for (int i = 0; i < sqrt(strlen(keyword)); i++)
	{
		delete[] inversearray[i];
	}
	delete[] inversearray;


	cout << endl;
	double cols_bArr;
	cols_bArr = (strlen(cin_text) / n);
	int** bArr = new int* [n];
	int  cols_bArr1 = int(cols_bArr);
	for (int i = 0, k = 0; i < n; i++)
	{
		*(bArr + i) = new int[cols_bArr1];
		for (int j = 0; j < m; j++)
		{
			*(*(bArr + i) + j) = array[k++];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < cols_bArr1; j++)
		{
			cout << *(*(bArr + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	int** cArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		cArr[i] = new int[cols_bArr1];
		for (int j = 0; j < cols_bArr1; j++)
		{
			cArr[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				cArr[i][j] += aArr[i][k] * bArr[k][j];
			}
		}
	}
	cout << "ћноженн¤:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < cols_bArr1; j++)
		{
			cout << cArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "ostacha:" << endl;
	int** dArr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		/*dArr[i] = new int[cols_bArr1];*/
		for (int j = 0; j < cols_bArr1; j++)
		{
			/*dArr[i][j] == cArr[i][j] %26;*/
			cout << cArr[i][j] % 26;
		}
		cout << endl;
	}/*
	for (int i = 0; i < m * cols_bArr1; i++)
	{
		cout << dArr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < strlen(cin_text); i++)
	{
		dArr[i] = cArr[i] % 26;
	}
	for (int i = 0; i < m * cols_bArr1; i++)
	{
		cout << dArr[i] << " ";
	}*/
	char  cout_text[50];

	cout << "Encryption:" << endl;
	for (int i = 0, k = 0; i < m; i++)
	{
		for (int j = 0; j < cols_bArr1; j++)
		{
			if (cArr[i][j] % 26 == 0)
			{
				cout_text[k++] = 'a';
			}
			else if (cArr[i][j] % 26 == 1)
			{
				cout_text[k++] = 'b';
			}
			else if (cArr[i][j] % 26 == 2)
			{
				cout_text[k++] = 'c';
			}
			else if (cArr[i][j] % 26 == 3)
			{
				cout_text[k++] = 'd';
			}
			else if (cArr[i][j] % 26 == 4)
			{
				cout_text[i] = 'e';
			}
			else if (cArr[i][j] % 26 == 5)
			{
				cout_text[k++] = 'f';
			}
			else if (cArr[i][j] % 26 == 6)
			{
				cout_text[k++] = 'g';
			}
			else if (cArr[i][j] % 26 == 7)
			{
				cout_text[k++] = 'h';
			}
			else if (cArr[i][j] % 26 == 8)
			{
				cout_text[k++] = 'i';
			}
			else if (cArr[i][j] % 26 == 9)
			{
				cout_text[k++] = 'j';
			}
			else if (cArr[i][j] % 26 == 10)
			{
				cout_text[k++] = 'k';
			}
			else if (cArr[i][j] % 26 == 11)
			{
				cout_text[k++] = 'l';
			}
			else if (cArr[i][j] % 26 == 12)
			{
				cout_text[k++] = 'm';
			}
			else if (cArr[i][j] % 26 == 13)
			{
				cout_text[k++] = 'n';
			}
			else if (cArr[i][j] % 26 == 14)
			{
				cout_text[k++] = 'o';
			}
			else if (cArr[i][j] % 26 == 15)
			{
				cout_text[k++] = 'p';
			}
			else if (cArr[i][j] % 26 == 16)
			{
				cout_text[k++] = 'q';
			}
			else if (cArr[i][j] % 26 == 17)
			{
				cout_text[k++] = 'r';
			}
			else if (cArr[i][j] % 26 == 18)
			{
				cout_text[k++] = 's';
			}
			else if (cArr[i][j] % 26 == 19)
			{
				cout_text[k++] = 't';
			}
			else if (cArr[i][j] % 26 == 20)
			{
				cout_text[k++] = 'u';
			}
			else if (cArr[i][j] % 26 == 21)
			{
				cout_text[k++] = 'v';
			}
			else if (cArr[i][j] % 26 == 22)
			{
				cout_text[k++] = 'w';
			}
			else if (cArr[i][j] % 26 == 23)
			{
				cout_text[k++] = 'x';
			}
			else if (cArr[i][j] % 26 == 24)
			{
				cout_text[k++] = 'y';
			}
			else if (cArr[i][j] % 26 == 25)
			{
				cout_text[k++] = 'z';
			}

		}
	}

	cout << cout_text;
	/*int aArr[4][1] = {1, 4, 3, 9};//створюЇмо матрицю з ключовим словом
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 1; j++)
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
		*(bArr + i) = new int[rows_bArr1];//создали матрицу дл¤ чисел изначального текста
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
				cArr[i][j] += aArr[i][k] * bArr[k][j];
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
	}*/
	system("pause");
	return 0;
}