#include<iostream>
#include"Matrix.hpp"
using namespace std;
Matrix::Matrix()
{
	rows = 1;
	columns = 1;
	macierz = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		macierz[i] = new double[columns];
		for (int j = 0; j < columns; j++)
		{
			macierz[i][j] = 0.0;
		}
	}
	//cout << "Stworzylem macierz domyslna o row: " << rows << "columns: " << columns << endl;
}
Matrix::Matrix(unsigned int p_rows, unsigned int p_columns) :rows(p_rows), columns(p_columns)
{
	//Wykorzystanie dynamicznej alokacji pamieci na macierz
	macierz = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		macierz[i] = new double[columns];
		for (int j = 0; j < columns; j++)
		{
			macierz[i][j] = 0;
		}
	}

	//cout << "Stworzylem macierz parametryczny  o row: " << rows << "columns: " << columns << endl;
}
void Matrix::wypelnij()
{
	double wartosc_podana;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Podaj wartosc elementu z " << i + 1 << " rzedu " << j + 1 << " kolumny";
			while (!(cin >> wartosc_podana))
			{
				cout << "Blad! To nie jest liczba zmiennoprzecinkowa. Podaj liczbe ponownie: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			macierz[i][j] = wartosc_podana;
		}
	}
}
void Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << macierz[i][j] << " ";
		}
		cout << endl;
	}
}
unsigned int Matrix::rowsAmount()
{
	return rows;
}
unsigned int Matrix::columnsAmount()
{
	return columns;
}
void Matrix::setElement(unsigned int p_row, unsigned int p_columns, double value)
{
	macierz[p_row][p_columns] = value;
}
double Matrix::getElement(unsigned int p_row, unsigned int p_column)
{
	return macierz[p_row][p_column];
}
double Matrix::det()
{
	if (rows == columns)
	{
		double determinant = 0.0;
		if (rows == 1)
		{
			determinant = macierz[0][0];
		}
		else if (rows == 2)
		{
			determinant = macierz[0][0] * macierz[1][1] - macierz[0][1] * macierz[1][0];
		}
		else//Gdy rozmiar macierzy jest wiekszy niz 2 trzeba zastosowaæ laplace'a
		{
			for (int j = 0; j < columns; j++)
			{
				Matrix podmacierz(rows - 1, columns - 1);

				for (int i = 1; i < rows; i++)
				{
					for (int k = 0, l = 0; k < columns; k++)
					{
						if (k == j) continue;
						podmacierz.setElement(i - 1, l++, macierz[i][k]);
					}
				}

				if (j % 2 == 0) {
					determinant = determinant + macierz[0][j] * podmacierz.det();
				}
				else {
					determinant = determinant - macierz[0][j] * podmacierz.det();
				}

			}
		}
		return determinant;
	}
	else
	{
		cout<< "Nie da sie wyznaczyc wyznacznika dla macierzy niekwadratowej." << std::endl;
		return 0.0;
	}
}

Matrix::~Matrix()
{
	//Zwalnianie pamieci dla macierzy dwuwymiarowej
	for (int i = 0; i < rows; i++)
		delete[] macierz[i];
}
Matrix Matrix::operator+(Matrix& other) {
	if (this->columnsAmount() == other.columnsAmount() && this->rowsAmount() == other.rowsAmount())
	{
		cout << "Ma tyle samo kolumn" << endl;
		Matrix return_matrix(this->rowsAmount(), this->columnsAmount());
		for (int i = 0; i < other.rowsAmount(); i++)
		{
			for (int j = 0; j < other.columnsAmount(); j++)
			{
				return_matrix.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
			}
		}
		return return_matrix;
	}
	else
	{
		cout << "Nie ma tyle samo kolumn" << endl;
		throw exception();
	}
}
Matrix Matrix::operator-(Matrix& other) {
	if (this->columnsAmount() == other.columnsAmount() && this->rowsAmount() == other.rowsAmount())
	{
		cout << "Ma tyle samo kolumn" << endl;
		Matrix return_matrix(this->rowsAmount(), this->columnsAmount());
		for (int i = 0; i < other.rowsAmount(); i++)
		{
			for (int j = 0; j < other.columnsAmount(); j++)
			{
				return_matrix.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
			}
		}
		return return_matrix;
	}
	else
	{
		cout << "Nie ma tyle samo kolumn" << endl;
		throw exception();
	}
}
Matrix Matrix::operator*(Matrix& other) {
	if (this->columnsAmount() == other.rowsAmount())
	{
		double new_element;
		//cout << "Mozna przemnozyc" << endl;
		Matrix return_matrix(this->rowsAmount(), other.columnsAmount());
		for (int i = 0; i < this->rowsAmount(); i++)
		{
			for (int j = 0; j < other.columnsAmount(); j++)
			{
				new_element = 0;
				for (int b = 0; b < other.rowsAmount(); b++)
				{
					new_element = new_element + (this->getElement(i, b) * other.getElement(b, j));
				}
				return_matrix.setElement(i, j, new_element);
			}
		}
		return return_matrix;
	}
	else
	{
		cout << "Nie ma tyle samo kolumn" << endl;
		throw exception();
	}
}
void Matrix::transpozycja()
{
	//Tworzenie nowego bloku
	double** new_macierz;
	int p_columns = rows;
	int p_rows = columns;

	new_macierz = new double* [p_rows];
	for (int i = 0; i < p_rows; i++)
	{
		new_macierz[i] = new double[p_columns];
		for (int j = 0; j < p_columns; j++)
		{
			new_macierz[i][j] = macierz[j][i];
		}
	}
	for(int i=0; i<rows; i++)
		delete[] macierz[i];

	macierz = new double* [p_rows];
	for (int i = 0; i < p_rows; i++)
	{
		macierz[i] = new double[p_columns];
		for (int j = 0; j < p_columns; j++)
		{
			macierz[i][j] = new_macierz[i][j];
		}
	}
	rows = p_rows;
	columns = p_columns;
	for (int i = 0; i < rows; i++)
		delete[] new_macierz[i];
}

JednostkowaMatrix::JednostkowaMatrix()
{
	rows = 1;
	columns = 1;
	macierz = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		macierz[i] = new double[columns];
		for (int j = 0; j < columns; j++)
		{
			macierz[i][j] = 1.0;
		}
	}
	cout << "Stworzylem macierz domyslna o row: " << rows << "columns: " << columns << endl;
}
JednostkowaMatrix::JednostkowaMatrix(unsigned int rozmiar) :Matrix(rozmiar, rozmiar)
{
	macierz = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		macierz[i] = new double[columns];
		for (int j = 0; j < columns; j++)
		{
			if (i == j)
				macierz[i][j] = 1.0;
			else
			{
				macierz[i][j] = 0.0;
			}
		}
	}
}
void JednostkowaMatrix::wypelnij()
{
	cout << "Nie mozna wypelnic macierzy jednostkowej, macierz jednostkowa ma znane z gorwy wartosci elementow" << endl;
}
double JednostkowaMatrix::det()
{
	return 1.0;
}