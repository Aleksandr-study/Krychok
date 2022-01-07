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
}