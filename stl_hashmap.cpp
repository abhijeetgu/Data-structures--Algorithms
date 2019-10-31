#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    //unordered_map<typeof_key,typeof_value> name;
    unordered_map<string,int> h;

    //in hashmap we insert key-value pair
    pair<string,int> p("Mango",100);
    //p.first="Pineapple";
    //cout<<p.first<<endl; //this will print the key
    //cout<<p.second<<endl; //this will print the value

    h.insert(p); //create a pair then insert in hashmap
    h.insert(make_pair("Pineapple",50));
    h.insert(make_pair("Apple",150));
    h.insert(make_pair("Gauva",60));


    for(auto iterator:h)
    {
        cout<<iterator.first<<"->"<<iterator.second<<endl;
    }
    cout<<endl;
    //Bucket iterate
    for(int i=0;i<h.bucket_count();i++)
    {
        cout<<i<<"->";

        //Iterate on every linked list
        for(auto it=h.begin(i);it!=h.end(i);it++)
        {
            cout<<"("<<it->first<<","<<it->second;
        }
        cout<<endl;
    }


}
