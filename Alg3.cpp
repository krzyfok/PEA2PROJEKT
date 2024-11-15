#include<iostream>
#include"Alg3.h"
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
 //LIFO dfs
  

 void Alg3::start()
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

     while (!stos.empty()) {
      //  if(best_node.parent!=nullptr)        cout<<best_node.wierzcholek<<" "<<best_node.parent->wierzcholek<<" "<<best_node.granica<<endl;
        node current = stos.top();
        stos.pop();
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

 

 void Alg3::rekurencja(node no)
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
        stos.push(temp);
            }
        }
    }
 }