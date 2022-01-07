#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class cl
{
public:
	int getn()
	{
		return n;
	}
	int getm()
	{
		return m;
	}
	void setn(int valueN)
	{
		n = valueN;
	}
	void setm(int valueM)
	{
		m = valueM;
	}
private:
	int n;
	int m;
};

/*Швидке сортування:*/
void quickSort(int *numbers, int l, int r)
{
  int p;
  int l_hold = l; 
  int r_hold = r;
  p = numbers[l];
  while (l < r) 
  {
    while ((numbers[r] >= p) && (l < r))
      r--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (l != r) // если границы не сомкнулись
    {
      numbers[l] = numbers[r]; // перемещаем элемент [right] на место разрешающего
      l++; // сдвигаем левую границу вправо
    }
    while ((numbers[l] <= p) && (l < r))
	{
		l++;
	}
    if (l != r) 
    {
      numbers[r] = numbers[l];
      r--; 
    }
  }
  numbers[l] = p;
  p = l;
  l = l_hold;
  r = r_hold;
  if (l < p)
    quickSort(numbers, l, p - 1);
  if (r > p)
    quickSort(numbers, p + 1, r);
}

/*Сортування методом Шелла:*/
void Shell(int arrShel[], int y)
{
	int z = y / 2;                       
	while (z > 0)
	{
		for (int i = 0; i < y - z; i++)
		{
			int j = i;
			while (j >= 0 && arrShel[j] > arrShel[j + z])
			{
				int temp = arrShel[j];
				arrShel[j] = arrShel[j + z];
				arrShel[j + z] = temp;
				j--;
			}
		}
		z = z / 2;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	ifstream fin;
	cl a;
	fin.open("C://Prog.conf");
	if ((fin.is_open()) && (fin.peek() != EOF))
	{
		int n;
		int m;
		while (!fin.eof())
		{
			fin >> n >> m;
		}
		a.setn(n);
		a.setm(m);
		fin.close();
	}
	else
		if (argc > 1 && argc < 4)
		{

			a.setn(stoi(argv[1]));
			a.setm(stoi(argv[2]));
		}
		else
		{
			int n;
			int m;
			cout << "Введiть кiлькiсть рядкiв та стовпцiв:\n";
			cin >> n;
			cin >> m;
			a.setn(n);
			a.setm(m);
		}
	string path;
	string path1;
	cout << "Введiть назву *.txt файлу: " << endl;
	cin >> path;
	cout << "Введiть назву *.dat файлу: " << endl;
	cin >> path1;
	int n;
	int m;
	n = a.getn();
	m = a.getm();
	int i;
	int j;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
	cout << "Початкова матриця:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix[i][j] = i + j;
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	int* masiv1 = new int[n * m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			masiv1[i * m + j] = matrix[i][j];
		}
	}
	int temp;
	/*Cортування методом бульбашки:*/
	for (i = 0; i < n*m - 1; i++)
	{
		for (j = 0; j < n*m - i - 1; j++)
		{
			if (masiv1[j] > masiv1[j + 1]) 
			{
				temp = masiv1[j];
				masiv1[j] = masiv1[j + 1];
				masiv1[j + 1] = temp;
			}
		}
	}
	int** matrix1 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix1[i] = new int[m];
	}
	int k;
	cout << "Cортування методом бульбашки:" << endl;
	for (i = 0, k = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix1[i][j] = masiv1[k++];
			cout << matrix1[i][j] << " ";
		}
		cout << "\n";
	}
	/*=====================================================*/
	/*Швидке сортування:*/
	int* masiv2 = new int[n * m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			masiv2[i * m + j] = matrix[i][j];
		}
	}
	int** matrix2 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix2[i] = new int[m];
	}
	quickSort(masiv2, 0, m*n - 1);
	cout << "Швидке сортування:" << endl;
	for (i = 0, k = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix2[i][j] = masiv2[k++];
			cout << matrix2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
	/*======================================================*/
	/*Сортування методом Шелла:*/
	int* masiv3 = new int[n * m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			masiv3[i * m + j] = matrix[i][j];
		}
	}
	int** matrix3 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix3[i] = new int[m];
	}
	Shell(masiv3, m*n);
	cout << "Сортування методом Шелла:" << endl;
	for (i = 0, k = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix3[i][j] = masiv3[k++];
			cout << matrix3[i][j] << " ";
		}
		cout << "\n";
	}
	/*======================================================*/
	ofstream f;
	f.open(path);
	f << "Кiлькiсть рядкiв: " << n << "\n";
	f << "Кiлькiсть стовпцiв: " << m << "\n";
	f << "Початкова матриця:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			f << matrix[i][j] << " ";
		}
		f << "\n";
	}
	f << "Вiдсотована матриця:" << endl;
	for (i = 0, k = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix1[i][j] = masiv1[k++];
			f << matrix1[i][j] << " ";
		}
		f << "\n";
	}
	f.close();
	ofstream b;
	b.open(path1, ios_base::out | ios_base::binary);
	b << "Number of rows: " << n << "\n";
	b << "Number of columns: " << m << "\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			b << matrix[i][j] << " ";
		}
		b << "\n";
	}
	b << "Початкова матриця:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			b << matrix[i][j] << " ";
		}
		b << "\n";
	}
	b << "Вiдсотована матриця:" << endl;
	for (i = 0, k = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix2[i][j] = masiv2[k++];
			b << matrix2[i][j] << " ";
		}
		b << "\n";
	}
	b.close();
	delete[]  matrix;
	return 0;
}