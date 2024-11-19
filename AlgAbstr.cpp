#include"AlgAbstr.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<Algorithm>
using namespace std;
vector<vector<int>> AlgAbstr::macierz;
 priority_queue<node, vector<node>, CompareNode>AlgAbstr:: pq;
 queue<node> AlgAbstr::qq;
 int AlgAbstr::UB;
node AlgAbstr::best_node;  

LicznikCzasu licznik;
void AlgAbstr:: wczytywanie(string nazwa)
{
macierz.clear();
	
	int rozmiar;
	string wynik_oczekiwany;

	ifstream plik(nazwa);  

	if (plik.is_open()) {
		plik >> rozmiar;  

		macierz.resize(rozmiar, vector<int>(rozmiar));

		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				plik >> macierz[i][j]; 
			}
		}
		plik >> wynik_oczekiwany;
		cout << wynik_oczekiwany << endl;
		plik.close();  
	}
	else {
		cout << "BRAK PLIKU,"<<" NACISNIJ DOWOLNY PRZYCISK BY ZAKONCZYC";
		getchar();
		exit(0);
	}
}

void AlgAbstr::wyswietlanie()
{
    for (int i = 0; i < macierz.size(); i++)
	{
		for (int k = 0; k < macierz[i].size(); k++)
		{
			cout << macierz[i][k] << " ";
		}
		cout << endl;
	}
}
void AlgAbstr::generacja_sym(int n)
{

	int rozmiar = n;

	//deklaracja rozmiary wektora
	macierz.resize(rozmiar);

	for (int i = 0; i < rozmiar; i++)
	{
		macierz[i].resize(rozmiar);
	}
	//genracja macierzy asymetrycznej 
	for (int i = 0; i < rozmiar; i++)
	{

		for (int k =i+1 ; k < rozmiar; k++)
		{
			int wartosc_losowa = rand();
			macierz[i][k] = wartosc_losowa;
			macierz[k][i] = wartosc_losowa;
		}
		macierz[i][i] = -1;
	}


}
void AlgAbstr::generacja(int n)
{

	int rozmiar=n;
	
	//deklaracja rozmiary wektora
	macierz.resize(rozmiar);
	
	for (int i = 0; i < rozmiar; i++)
	{
		macierz[i].resize(rozmiar);
	}
	//genracja macierzy asymetrycznej 
	for (int i = 0; i < rozmiar; i++)
	{
		
		for (int k = 0; k < rozmiar; k++)
		{
			if (k != i)
			{
				do
				{
					macierz[i][k] = rand();

				} while (macierz[i][k]==macierz[k][i]);
			}
			else
			{
				macierz[i][k] = -1;
			}
		}
	}



}


void AlgAbstr::wynik()
{
	cout << "Koszt trasy : " << UB;

cout<<"  trasa: ";
   for(int i=0;i<best_node.trasa.size();i++)
   {
    cout<<best_node.trasa[i]<<" ";
   }
}

int AlgAbstr::pierwsze_min(int rzad)
{
    int obecna=INT_MAX;
 for(int i=0;i<macierz.size();i++)
 {
    if(macierz[rzad][i]<obecna && i!=rzad)
    {
        obecna=macierz[rzad][i];
    }
 }
 return obecna;
}


int AlgAbstr::lower_bound(node n, int nastepny)
{
    
    int wynik=n.granica;
    wynik-=minima[n.wierzcholek];
    wynik+=macierz[n.wierzcholek][nastepny];
    return wynik;
}