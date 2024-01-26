#include<iostream>
#include"UI.hpp"
using namespace std;
int main()
{
	UI ui;
	//Wykorzystanie rzucania wyjatkow
	try
	{
		do
		{
			;
		} while (ui.actions());
	}
	catch (const exception& e) 
	{
		std::cerr << "Blad, cos poszlo nie tak: " << e.what() << std::endl;
	}

	cout << "Zakonczono dzialanie programu" << endl;
	return 0;
}