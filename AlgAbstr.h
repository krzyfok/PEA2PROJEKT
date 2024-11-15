#ifndef ALGABSTR_H
#define ALGABSTR_H

#include <vector>
#include <string>
#include "node.h"
#include<Algorithm>
#include<queue>
#include<stack>
class AlgAbstr {
public:

static priority_queue<node, vector<node>, CompareNode> pq; // Kolejka priorytetowa
static queue<node> qq; //fifo 
static stack<node> stos;//lifo
    static int UB; // Upper bound
    static node best_node; // Najlepszy węzeł
    static void wczytywanie(string nazwa);
    static void wyswietlanie();
    static vector<vector<int>> macierz;
    int pierwsze_min(int rzad);
    int drugie_min(int rzad);
    int lower_bound(node n, int nastepny);
    int* minima; // Dynamiczna tablica minimalnych wartości
};

#endif // ALGABSTR_H
