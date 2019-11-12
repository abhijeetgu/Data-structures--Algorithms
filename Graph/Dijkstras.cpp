#include<iostream>
#include<climits>
#include<unordered_map>
#include<map>
#include<queue>
#include<set>
#include<list>
using namespace std;

template<typename T>
class Graph{
  map<T,list<pair<T,int>>> h;
  public:

      void addEdge(T u,T v,int dist,bool bidir=true)
      {
          h[u].push_back(make_pair(v,dist));
          if(bidir)
          {
              h[v].push_back(make_pair(u,dist));
          }
      }

      void print()
      {
          //lets try to print the adj list
          //Iterate over all the key value pairs in the map
          for(auto node:h)
          {
              cout<<node.first<<"-->";

          //iterate over the list of cities
          for(auto children:node.second)
          {
              cout<<"("<<children.first<<","<<children.second<<")";
          }

          cout<<endl;
          }
      }

      void SSSP(T src)
      {
          map<T,int> dist;
          //make a set to find a node with the minimum distance
          set<pair<int,T>> s;
          //set all distance to infinity
          for(auto node:h)
          {
              dist[node.first]=INT_MAX;
          }
          dist[src]=0;
          s.insert(make_pair(0,src));

          while(!s.empty())
          {
              auto p=*(s.begin());
              T parent =p.second;
              int parent_dist=p.first;

              s.erase(s.begin());
              //iterate over neighbour/child of the current node
              for(auto children:h[parent])
              {
                  if(dist[children.first]>dist[parent]+children.second)
                  {
                      auto f=s.find(make_pair(dist[children.first],children.first));
                      if(f!=s.end())
                      {
                          s.erase(f);
                      }
                      dist[children.first]=dist[parent]+children.second;
                      s.insert(make_pair(dist[children.first],children.first));
                  }
              }
          }
          for(auto node:dist)
          {
              cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
          }
      }





};
int main()
{
    Graph<string> g;
    g.addEdge("Amritsar","Agra",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Delhi","Jaipur",2);
    g.addEdge("Delhi","Agra",1);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Bhopal","Mumbai",3);
    g.addEdge("Jaipur","Mumbai",8);
    g.print();
    cout<<endl;
    g.SSSP("Amritsar");
}
