#pragma once

#include <vector>
using namespace std;

struct node {
    int granica; // lower bound
    int wierzcholek; // numer wierzchołka
    vector<int> odwiedzone; // odwiedzone wierzchołki
    vector<int> trasa; // trasa

    node() : granica(0), wierzcholek(0) {}
};

struct CompareNode {
    bool operator()(const node a, const node b) {
        return a.granica > b.granica; 
    }
};
