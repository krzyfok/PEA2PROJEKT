#include"AlgAbstr.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<Algorithm>
using namespace std;
vector<vector<int>> AlgAbstr::macierz;
 priority_queue<node, vector<node>, CompareNode>AlgAbstr:: pq;
 queue<node> AlgAbstr::qq;
 stack<node> AlgAbstr :: stos;
 int AlgAbstr::UB;
node AlgAbstr::best_node;  
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

int AlgAbstr::drugie_min(int rzad)
{
  int obecna=INT_MAX;
  int obecna2=INT_MAX;
 for(int i=0;i<macierz.size();i++)
 {
    if(rzad==i) continue;
     
     if(macierz[rzad][i]<obecna)
     {
        obecna2=obecna;
        obecna=macierz[rzad][i];
     }
    else if (macierz[rzad][i]<=obecna2 && macierz[rzad][i]!=obecna)
    {
        obecna2=macierz[rzad][i];
    }
    
 }
 return obecna2;
}
int AlgAbstr::lower_bound(node n, int nastepny)
{
    
    int wynik=n.granica;
    wynik-=minima[n.wierzcholek];
    wynik+=macierz[n.wierzcholek][nastepny];
    return wynik;
}