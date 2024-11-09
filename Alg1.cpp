#include<iostream>
#include"Alg1.h"
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 //lowest cost
   priority_queue<node, vector<node>, CompareNode> pq;
 int UB;
node best_node;  

 void Alg1::start()
 {

    minima = new  int[macierz.size()];
    int LB0=0;
    UB=INT_MAX;
    for(int i=0;i<macierz.size();i++)
    {
   
        minima[i]=pierwsze_min(i);
        LB0+=minima[i];
    }
  
    node poczatek;
    poczatek.wierzcholek=0;
    poczatek.granica=LB0;
    poczatek.parent=nullptr;
   
   for (int i = 0; i < macierz.size(); i++) {
        if (i != poczatek.wierzcholek) {
            poczatek.odwiedzone.push_back(i);
        }
    }
    rekurencja(poczatek);

     while (!pq.empty()) {
        node current = pq.top();
        pq.pop();
        if(current.granica>UB) continue;
        else(rekurencja(current));
    }


    cout << "Koszt trasy : " << UB << endl;
    node* a=&best_node;         // Definiujemy wskaźnik do obiektu node
//naprawic maganyzowanie trasy    
    for(int i=0;i<macierz.size();i++)
    {
   
    cout<<a->wierzcholek;
    a=a->parent;
    }
cout<<endl;
    
}

 

 void Alg1::rekurencja(node no)
 {
    //iteracja przez dzieci wierzcholka i obliczanie granicy
    for(int i=0;i<no.odwiedzone.size();i++)
    {
       
        node temp;
        temp.wierzcholek=no.odwiedzone[i];
        temp.parent= &no;
        temp.granica=lower_bound(no,no.odwiedzone[i]);
        for(int k=0;k<no.odwiedzone.size();k++)
        {
            if(no.odwiedzone[k]!=no.odwiedzone[i])
            {
                temp.odwiedzone.push_back(no.odwiedzone[k]);
            }
        }
        if (temp.odwiedzone.empty())
        {
            temp.granica=lower_bound(temp,0);
            if(temp.granica<UB){
            UB=temp.granica;
            best_node=temp;
            }
        }
        else{
            if(temp.granica<UB){
        pq.push(temp);
            }
        }
    }
 }