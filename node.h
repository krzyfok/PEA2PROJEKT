#include<vector>
using namespace std;
struct node
{
    node * parent;//wskaznik na poprzedni
    int granica;//lower bound
    int wierzcholek;//numer wierzchołka- wierzchołek nie wynika bezpośrednio w wskaznika
    vector<int > odwiedzone;
    node():parent(nullptr), granica(0), wierzcholek(0){};

};
struct CompareNode {
    bool operator()(const node a, const node b) {
        return a.granica > b.granica; 
    }
};