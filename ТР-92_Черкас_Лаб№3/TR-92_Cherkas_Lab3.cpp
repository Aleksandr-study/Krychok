#include <iostream>
#include  <conio.h>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

struct magaz
{
	char nazva[60];
	char adresa[60];
	char chas_roboti[60];
	char tip_tovaru[60];
};

void magazin(const magaz obj[], int n);

int main()
{
	setlocale(LC_ALL, "rus");
	const int n = 1;
	magaz array[n] = {};
	for (int i = 0; i < n; i++)
	{
		cout << "Назва магазину: ";
		cin.getline( array[i].nazva, 60);
		cout << "\nАдреса магазину: ";
		cin.getline(array[i].adresa, 60);
		cout << "\nЧас роботи: ";
		cin.getline(array[i].chas_roboti, 60);
		cout << "\nТип товару: ";
		cin.getline(array[i].tip_tovaru, 60);
		cin.get();
	}
	magazin(array, n);
	return 0;
}

void magazin(const magaz obj[], int n)
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < n; i++)
	{
		cout << "\nНазва магазину:\t" << obj[i].nazva << "\nАдреса магазину:\t" << obj[i].adresa << "\nЧас роботи:\t" << obj[i].chas_roboti << "\nТип товару:\t" << obj[i].tip_tovaru;
	}
	string path;
	cout << "\n\nВведiть файлу для запису даних: " << endl;
	cin >> path;
	ofstream f;
	f.open(path);
	for (int i = 0; i < n; i++)
	{
		f << "Назва магазину:\t" << obj[i].nazva << "\nАдреса магазину:\t" << obj[i].adresa << "\nЧас роботи:\t" << obj[i].chas_roboti << "\nТип товару:\t" << obj[i].tip_tovaru;
	}
	f.close();
}
