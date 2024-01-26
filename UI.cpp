#include<iostream>
#include"UI.hpp"

UI::UI()
{
	cout << "Witaj uzytkowniku" << endl;
}
bool UI::actions()
{
	{
		unsigned int wybor;
		cout << "Wybierz operacje: " << endl;
		cout << "1)Stworz swoja macierz: " << endl;
		cout << "2) Dodaj macierze: " << endl;
		cout << "3) Odejmij macierze: " << endl;
		cout << "4) Przemnoz macierze: " << endl;
		cout << "5) Wylicz wyznacznik macierzy: " << endl;
		cout << "6) Transpozycja macierzy: " << endl;
		cout << "0) Zakonczono dzialanie programu" << endl;

			
			while (!(cin >> wybor))
			{
				cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
				
			if (wybor == 2)
			{
				dodaj();
				return 1;
			}
			else if (wybor == 1)
			{
				create();
				return 1;
			}
			else if (wybor == 3)
			{
				odejmij();
				return 1;
			}
			else if (wybor == 4)
			{
				pomnoz();
				return 1;
			}
			else if (wybor == 5)
			{
				det();
				return 1;
			}
			else if (wybor == 6)
			{
				transformacja();
				return 1;
			}
			else if (wybor == 0)
			{
				return 0;
			}
			else
			{
				cout << "Nie ma takiej opcji! Wybierz ponownie";
			}
	}

}

void UI::dodaj()
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
	cout << "Jakie macierze chcesz dodac:" << endl;
	cout << "1) Dwie normale" << endl;
	cout << "2) Jedna normalna i jedna jednostkowa" << endl;
	cout << "3) Dwie jednostkowe" << endl;
	while (!(cin >> a))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (a == 1)
	{
		cout << "Wprowadz liczbe rzedow macierzy: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Wprowadz liczbe kolumn macierzy: " << endl;
		while (!(cin >> b))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		Matrix m1(a, b);
		Matrix m2(a, b);

		cout << "Wpisz wartosci w pierwsza macierz: " << endl;
		m1.wypelnij();
		cout << "Wpisz wartosci w druga macierz: " << endl;
		m2.wypelnij();
		Matrix m3 = m1 + m2;
		cout << "Wynik dodawania macierzy: " << endl;
		m1.print();
		cout << "+" << endl;
		m2.print();
		cout << "=" << endl;
		m3.print();
		cout << "Macierz zapisana" << endl;
	}
	else if (a == 2)
	{
		cout << "Wprowadz wymiar macierzy: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		JednostkowaMatrix m1(a);
		Matrix m2(a, a);
		cout << "Wpisz wartosci w normalna macierz: " << endl;
		m2.wypelnij();
		Matrix m3 = m1 + m2;
		cout << "Wynik dodawania macierzy: " << endl;
		m1.print();
		cout << "+" << endl;
		m2.print();
		cout << "=" << endl;
		m3.print();
	}
	else if (a == 3)
	{
		cout << "Wprowadz liczbe rzedow macierzy jednostkowych: " << endl;
		while (!(cin >> d))
		{
			cout << "Blad! To nie jest liczba calkowita dodatnia. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		JednostkowaMatrix j1(d);
		JednostkowaMatrix j2(d);
		Matrix m = j1 + j2;
		cout << "Wynik dodawania macierzy: " << endl;
		j1.print();
		cout << "+" << endl;
		j2.print();
		cout << "=" << endl;
		m.print();
	}
	else
	{
		cout << "Nie ma takiej opcji" << endl;
	}
	
}
void UI::odejmij()
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
	cout << "Jakie macierze chcesz odjac:" << endl;
	cout << "1) Dwie normale" << endl;
	cout << "2) Jedna normalna i jedna jednostkowa" << endl;
	cout << "3) Dwie jednostkowe" << endl;
	while (!(cin >> a))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (a == 1)
	{
		cout << "Wprowadz liczbe rzedow macierzy: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Wprowadz liczbe kolumn macierzy: " << endl;
		while (!(cin >> b))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		Matrix m1(a, b);
		Matrix m2(a, b);

		cout << "Wpisz wartosci w pierwsza macierz: " << endl;
		m1.wypelnij();
		cout << "Wpisz wartosci w druga macierz: " << endl;
		m2.wypelnij();
		Matrix m3 = m1 - m2;
		cout << "Wynik dodawania macierzy: " << endl;
		m1.print();
		cout << "-" << endl;
		m2.print();
		cout << "=" << endl;
		m3.print();
	}
	else if (a == 2)
	{
		cout << "Wprowadz wymiar macierzy: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		JednostkowaMatrix m1(a);
		Matrix m2(a, a);
		cout << "Wpisz wartosci w normalna macierz: " << endl;
		m2.wypelnij();
		Matrix m3 = m1 - m2;
		cout << "Wynik odejmowania macierzy: " << endl;
		m1.print();
		cout << "-" << endl;
		m2.print();
		cout << "=" << endl;
		m3.print();
	}
	else if (a == 3)
	{
		cout << "Wprowadz liczbe rzedow macierzy jednostkowych: " << endl;
		while (!(cin >> d))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		JednostkowaMatrix j1(d);
		JednostkowaMatrix j2(d);
		Matrix m = j1 - j2;
		cout << "Wynik odejmowania macierzy: " << endl;
		j1.print();
		cout << "-" << endl;
		j2.print();
		cout << "=" << endl;
		m.print();
	}
	else
	{
		cout << "Nie ma takiej opcji" << endl;
	}
}
void UI::pomnoz()
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
	cout << "Jakie macierze chcesz pomnozyc:" << endl;
	cout << "1) Dwie normale" << endl;
	cout << "2) Jedna normalna i jedna jednostkowa" << endl;
	cout << "3) Dwie jednostkowe" << endl;
	while (!(cin >> a))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (a == 1)
	{
		cout << "Wprowadz liczbe rzedow pierwszej macierzy: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Wprowadz liczbe kolumn pierwszej macierzy: " << endl;
		while (!(cin >> b))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Wprowadz liczbe kolumn drugiej macierzy" << endl;
		while (!(cin >> c))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		Matrix m1(a, b);
		Matrix m2(b, c);

		cout << "Wpisz wartosci w pierwsza macierz: " << endl;
		m1.wypelnij();
		cout << "Wpisz wartosci w druga macierz: " << endl;
		m2.wypelnij();
		Matrix m3 = m1 * m2;
		cout << "Wynik mnozenia macierzy: " << endl;
		m1.print();
		cout << "*" << endl;
		m2.print();
		cout << "=" << endl;
		m3.print();
	}
	else if (a == 2)
	{
		cout << "Wprowadz wymiar macierzy jednostkowej: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Wprowadz liczbe rzedow macierzy niecharakterystycznej: " << endl;
		while (!(cin >> b))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		JednostkowaMatrix jm(a);
		Matrix m2(b, a);
		cout << "Wpisz wartosci w macierzy niecharakterystycznej: " << endl;
		m2.wypelnij();
		cout << "Wynik mnozenia macierzy: " << endl;
		m2.print();
		cout << "*" << endl;
		jm.print();
		cout << "=" << endl;
		m2.print();
	}
	else if (a == 3)
	{
		cout << "Wprowadz wymiar macierzy jednostkowych: " << endl;
		while (!(cin >> a))
		{
			cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		JednostkowaMatrix jm(a);
		cout << "Wynik mnozenia macierzy: " << endl;
		jm.print();
		cout << "*" << endl;
		jm.print();
		cout << "=" << endl;
		jm.print();
	}
	else
	{
		cout << "Nie ma takiej opcji" << endl;
	}
}
void UI::det()
{
	unsigned int a;
	cout << "Podaj wymiar macierzy, ktorej wyznacznik chcesz policzyc: " << endl;
	while (!(cin >> a))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Matrix m(a, a);
	cout << "Podaj macierz: " << endl;
	m.wypelnij();
	cout << "Podana macierz: " << endl;
	m.print();
	cout << "Wyznacznik z podanej macierzy wynosi: " << m.det() << endl;
}
void UI::transformacja()
{
	unsigned int a;
	unsigned int b;
	cout << "Podaj liczbe wierszy macierzy do przetransponowania" << endl;
	while (!(cin >> a))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Podaj liczbe kolumn macierzy do przetransponowania" << endl;
	while (!(cin >> b))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Matrix m(a, b);
	m.wypelnij();
	cout << "Macierz przed przetransponowaniem: " << endl;
	m.print();
	cout << "Macierz po przetransponowaniu: " << endl;
	m.transpozycja();
	m.print();
}
void UI::create()
{
	unsigned int a;
	unsigned int b;
	cout << "Podaj liczbe wierszy macierzy" << endl;
	while (!(cin >> a))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Podaj liczbe kolumn macierzy" << endl;
	while (!(cin >> b))
	{
		cout << "Blad! To nie jest liczba calkowita. Podaj liczbe ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Matrix m(a, b);
	m.wypelnij();
	m.print();
}