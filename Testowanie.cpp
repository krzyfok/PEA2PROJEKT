#include<iostream>
#include"Testowanie.h"
#include"AlgAbstr.h"
#include"Alg1.h"
#include"Alg2.h"
#include"Alg3.h"
#include<vector>
#include <iostream>
#include <fstream>

using namespace std;
void Testowanie:: test_start(vector <int> rozmiary, int powtorzenia, int progres,string plik_wyjsciowy)
{
	Alg1 a1;
    Alg2 a2;
    Alg3 a3;
	double czas=0;
	double suma=0;
	ofstream myfile;
	myfile.open(plik_wyjsciowy);
	if (!myfile.is_open()) {
		cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;
		return;
	}
	//brutefroce
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{
			system("cls");
			if(progres==1)cout << "lc " << instancje << "  " << i << endl;
			AlgAbstr ::generacja(rozmiary[instancje]);
          
			czas = a1.start();
			myfile <<czas <<";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{
			system("cls");
			if (progres == 1)cout << "lc " << instancje << "  " << i << endl;
			AlgAbstr::generacja_sym(rozmiary[instancje]);
			czas = a1.start();
			myfile << czas << ";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}

	
	myfile << "\n";
	//dfs
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if(progres==1)cout <<"bfs" << instancje << "  " << i << endl;
			AlgAbstr::generacja(rozmiary[instancje]);
			czas = a2.start();
			myfile << czas << ";";
			suma += czas;
			
		}
		myfile<<"srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";


	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if (progres == 1)cout << "bfs " << instancje << "  " << i << endl;
			AlgAbstr::generacja_sym(rozmiary[instancje]);
			czas = a2.start();
			myfile << czas << ";";
			suma += czas;

		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";

	//dfs
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if(progres==1)cout <<" dfs " << instancje << "  " << i << endl;
			AlgAbstr::generacja(rozmiary[instancje]);
			czas = a3.start();
			myfile << czas << ";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if (progres == 1)cout << " dfs " << instancje << "  " << i << endl;
			AlgAbstr::generacja(rozmiary[instancje]);
			czas = a3.start();
			myfile << czas << ";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile.close();
	cout << "koniec" << endl;
}