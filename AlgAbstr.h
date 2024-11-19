#ifndef ALGABSTR_H
#define ALGABSTR_H

#include <vector>
#include <string>
#include "node.h"
#include<Algorithm>
#include<queue>
#include"LicznikCzasu.h"
class AlgAbstr {
public:

static priority_queue<node, vector<node>, CompareNode> pq; // Kolejka priorytetowa
static queue<node> qq; //fifo 

    virtual double start()=0;
    virtual void rekurencja(node no)=0;
    static void wynik();
    static int UB; // Upper bound
    static node best_node; // Najlepszy węzeł
    static void wczytywanie(string nazwa);
    static void wyswietlanie();
    static void generacja(int n);
    static void generacja_sym(int n);
    static vector<vector<int>> macierz;
    int pierwsze_min(int rzad);
 
    int lower_bound(node n, int nastepny);
    int* minima; // Dynamiczna tablica minimalnych wartości
};

#endif // ALGABSTR_H
