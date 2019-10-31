#include<iostream>
#include<unordered_map>
using namespace std;

class Fruit{
public:

 string name;
 int price;
 string city;

     Fruit()
     {

     }

     Fruit(string n,int p,string c)
     {
         name=n;
         price = p;
         city = c;
     }

};

int main()
{
    unordered_map<string,Fruit> h;
    Fruit f("Mango",100,"Delhi");

    h[f.name]= f;

    Fruit fs = h["Mango"];
    cout<<fs.city<<endl;
    cout<<fs.price<<endl;

    ///Count function return - 0 or 1
    cout<<"Apple "<<h.count("Apple")<<endl;
    cout<<"Mango "<<h.count("Mango")<<endl;

    cout<<"Enter a Fruit to search ";
    string fruit;
    cin>>fruit;
    h.erase("Mango");

    if(h.count(fruit)!=0)
    {
        cout<<"price is "<<h[fruit].price<<endl;

    }
    else
    {

        cout<<"Fruit doesn't exist";
    }

    return 0;
}
