#include<iostream>
using namespace std;

class Matrix
{
protected:
	unsigned int rows;
	unsigned int columns;
	double** macierz;
public:
	Matrix();
	Matrix(unsigned int p_rows, unsigned int p_columns);
	virtual void wypelnij();
	void print();
	unsigned int rowsAmount();
	unsigned int columnsAmount();
	void setElement(unsigned int p_row, unsigned int p_column, double value);
	double getElement(unsigned int p_row, unsigned int p_column);
	virtual double det();
	void transpozycja();
	virtual ~Matrix();

	//Wykorzystanie przeciazenia operatorow +, -, * dla klasy macierz
	Matrix operator+(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix operator*(Matrix& other);
};
//Wykorzystanie dziedziczenia: Macierz jednostkowa jest rowniez macierza
class JednostkowaMatrix :public Matrix
{
public:
	JednostkowaMatrix();
	JednostkowaMatrix(unsigned int rozmiar);
	//Wykorzystanie nadpisania metody wypelnij. W macierzy jednostkowej nie mozna zmieniac elementow, gdzy¿ przestanie byc wowczas jednostkowa
	void wypelnij() override;
	//Wykorzystanie nadpisania metody wyznacznika, Nie ma potrzeby przeprowadzania wyznaczenia wyznacznika za pomoca metody Laplacea, bo jak wiadomo, det macierzy jednostkowej jest zawsze 1
	double det() override;
};