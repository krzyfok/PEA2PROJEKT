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
   
   for (int i = 0; i < macierz.size(); i++) {
        if (i != poczatek.wierzcholek) {
            poczatek.odwiedzone.push_back(i);
        }
    }
    rekurencja(poczatek);

     while (!pq.empty()) {
      //  if(best_node.parent!=nullptr)        cout<<best_node.wierzcholek<<" "<<best_node.parent->wierzcholek<<" "<<best_node.granica<<endl;
        node current = pq.top();
        pq.pop();
        if(current.granica>UB) continue;
        else(rekurencja(current));
    }


    cout << "Koszt trasy : " << UB << endl;
    /*
   
   cout<<best_node.wierzcholek<<" "<<best_node.parent->wierzcholek<<endl;
  a=*best_node.parent;
   cout<<a.wierzcholek<<" "<<a.parent->wierzcholek<<endl;
   b=*a.parent;
    cout<<b.wierzcholek<<" "<<b.parent->wierzcholek;
cout<<endl;
    */
cout<<"trasa: ";
   for(int i=0;i<best_node.trasa.size();i++)
   {
    cout<<best_node.trasa[i]<<" ";
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
        
          temp.granica=lower_bound(no,no.odwiedzone[i]);
        for(int k=0;k<no.odwiedzone.size();k++)
        {
            if(no.odwiedzone[k]!=no.odwiedzone[i])
            {
                temp.odwiedzone.push_back(no.odwiedzone[k]);
            }
        }
        temp.trasa=no.trasa;
        temp.trasa.push_back(no.wierzcholek);
        if (temp.odwiedzone.empty())
        {
          
            temp.granica=lower_bound(temp,0);
            if(temp.granica<UB){
            UB=temp.granica;
            temp.trasa.push_back(temp.wierzcholek);
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