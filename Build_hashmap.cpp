#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    unordered_map<string,int> h;

    ///insert
    h["Mango"]=200;

    ///second insert
    h.insert(make_pair("Apple",120));

    ///search
    if(h.count("Apple")==1)
    {
        cout<<"Price of Apple "<<h["Apple"];
    }

    cout<<endl;
    h["Chiku"]=h["Apple"]+20;

    ///delete
    h.erase("Chiku");

    if(h.count("Chiku")==0)
    {
        cout<<"Chiku doesn't exist";
    }
    else
    {
        cout<<"price of chiku is "<<h["Chiku"];
    }
    cout<<endl;

    ///Iterators to search
    auto f=h.find("Apple");
    if(f!=h.end())
    {
        cout<<"Price of Apple "<<f->second<<endl;
    }

    for(auto it:h)
    {
        cout<<it.first<<"->"<<it.second;
        cout<<endl;
    }
}
