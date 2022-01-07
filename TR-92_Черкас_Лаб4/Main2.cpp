#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include  <conio.h>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

struct Magaz
{
	char nazva[60];
	char adresa[60];
	char chas_roboti[60];
	char tip_tovaru[60];
	void Input(Magaz& magaz);
	Magaz* Next;
};

class List
{
	Magaz* Head;
public:
	List() :Head(NULL) {};
	~List();
	void Add(Magaz& magaz);
	void Show();
	void Show1();
};

void Magaz::Input(Magaz& magaz)
{
	cout << "\nНазва магазину: ";
	cin.getline(nazva, 60);
	cout << "Адреса магазину: ";
	cin.getline(adresa, 60);
	cout << "Час роботи: ";
	cin.getline(chas_roboti, 60);
	cout << "Тип товару: ";
	cin.getline(tip_tovaru, 60);
}

List::~List()
{
	while (Head != NULL)
	{
		Magaz* temp = Head->Next;
		delete Head;
		Head = temp;
	}
}

void List::Add(Magaz& magaz)
{
	Magaz* temp = new Magaz;
	temp->Next = Head;
	ifstream fin;
	fin.open("C://Laba4.dat", ios_base::out | ios_base::binary);
	if ((fin.is_open()) && (fin.peek() != EOF))
	{
		while (!fin.eof())
		{
			strcpy(temp->nazva, magaz.nazva);
			strcpy(temp->adresa, magaz.adresa);
			strcpy(temp->chas_roboti, magaz.chas_roboti);
			strcpy(temp->tip_tovaru, magaz.tip_tovaru);
		}
		fin.close();
	}
	strcpy(temp->nazva, magaz.nazva);
	strcpy(temp->adresa, magaz.adresa);
	strcpy(temp->chas_roboti, magaz.chas_roboti);
	strcpy(temp->tip_tovaru, magaz.tip_tovaru);
	Head = temp;
}

void List::Show()
{
	Magaz* temp = Head;
	cout << "Назва магазину:\t" << "Адреса магазину:\t" << "Час роботи:\t" << "Тип товару:\n";
	while (temp != NULL)
	{
		cout << temp->nazva << "\t\t";
		cout << temp->adresa << "\t\t";
		cout << temp->chas_roboti << "\t";
		cout << temp->tip_tovaru << endl;
		temp = temp->Next;
	}
	cout << endl;
}
void List::Show1()
{
	ofstream f;
	f.open("C://Lab4.dat", ios_base::out | ios_base::binary);
	Magaz* temp = Head;
	f << "Назва магазину:\t" << "Адреса магазину:\t" << "Час роботи:\t" << "Тип товару:\n";
	while (temp != NULL)
	{
		f << temp->nazva << "\t\t";
		f << temp->adresa << "\t\t";
		f << temp->chas_roboti << "\t";
		f << temp->tip_tovaru << endl;
		temp = temp->Next;
	}
	f << endl;
	f.close();
}

int main()
{
	setlocale(LC_ALL, "rus");
	Magaz magaz;
	int N, m, r, num;

	List lst;
	cout << "Введiть кiлькiсть записiв:\n";
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		magaz.Input(magaz);
		lst.Add(magaz);
	}
	cout << endl;
	lst.Show();
	lst.Show1();
	cout << "Введiть 1 якщо бажаете додати ще 1 елемент у список\n";
	cin >> m;
	cin.ignore();
	if (m == 1)
	{
		magaz.Input(magaz);
		lst.Add(magaz);
		lst.Show();
	}
	cin.ignore().get();
	return 0;
}
/*#include <iostream>
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

int main(int argc, char* argv[])
{
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
			cout << "Enter number of rows and columns:\n";
			cin >> n;
			cin >> m;
			a.setn(n);
			a.setm(m);
		}
	string path;
	string path1;
	cout << "Enter the name of  txt file: " << endl;
	cin >> path;
	cout << "Enter the name of  dat file: " << endl;
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
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			matrix[i][j] = i + j;
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	ofstream f;
	f.open(path);
	f << "Number of rows: " << n << "\n";
	f << "Number of columns: " << m << "\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			f << matrix[i][j] << " ";
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
	b.close();
	return 0;
}*/