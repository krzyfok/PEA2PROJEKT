#include<vector>
#include<string>
#include"node.h"
using namespace std;
class AlgAbstr {
public:
static void wczytywanie(string nazwa);
static void wyswietlanie();
static vector<vector<int>> macierz;
int pierwsze_min(int rzad);
int drugie_min(int rzad);
int lower_bound(node n, int nastepny);
int  * minima;
};
