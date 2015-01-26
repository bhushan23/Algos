#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <climits>
#include <queue>   
#define V 9
using namespace std;

class ComparePair{
    public:
        bool operator() (const pair<int,int> p1 , const pair<int,int> p2)  const {
            return p1.second <  p2.second;
        }
};
template<class T>
class Graph{
    public:
        vector< list< pair<int,T> > > graph;
        int size;

        Graph(int ar[V][V],int size) : graph(size){

            pair<int,T> tpair;
            list<pair<int,T> > lst; 
            for(int i =0; i < size; ++i){
                lst.resize(0);
                for(int j =0; j < size; ++j){

                    if(ar[i][j] != 0){
                        tpair = make_pair(j,ar[i][j]);
                        lst.push_back(tpair);     
                    }
                }    
                graph[i] = lst;
            }

            printgraph();
            cout <<"\n";
        }

        void printgraph(){
            for(typename vector< list<pair<int,T> > > :: iterator it = graph.begin(),end=graph.end(); it != end; ++it){
                cout<< "\nNode: " << it - graph.begin() << ":";
                for(typename list<pair<int,T> > ::iterator lit= it->begin(),lend = it->end(); lit != lend; ++lit ){
                    cout<< "  " << lit -> first << "("  << lit->second <<")" ;
                }
                cout << "\n";
            }
        }
        int getMinDist(vector<T> &mind,set<int> &unvis){
            T min = INT_MAX;
            int minindex = -1;
    
            for( set<int>::iterator it = unvis.begin(),end=unvis.end(); it != end; ++it){
             //   cout << "Comapring "<< mind[*it]   << " and " << min << "\n"; 
                if(mind[*it] < min){ 
                    min = mind[*it];
                    minindex = *it;
                }
            }
            
            unvis.erase(minindex);
//            cout << "\n returning  " << min << "  " <<minindex;
            return minindex;
        }
        void dijkstra(int source){
            int min;
            vector <T> mindist(V,INT_MAX);
            vector<bool> visit(V,false);
            set<int> unvis;
            for(int i = 0; i < V; ++i)
                unvis.insert(i);
            mindist[source] = 0;


            while( !unvis.empty() ){    
               min = getMinDist(mindist,unvis);
            // cout << "  min: " << min << " " << unvis.size() << "\n";
                
                if(min != -1){
                    
                    for(typename list<pair<int,T> > ::iterator lit= graph[min].begin(),lend =graph[min].end(); lit != lend; ++lit ){
                        if(mindist[min] != INT_MAX && unvis.find(lit->first) != unvis.end() && mindist[lit->first] > mindist[min] + lit->second){
                            mindist[lit->first] = mindist[min] + lit->second; 
                        } 
                    }

                }
            }
            cout << "\nDONE\n";
            for(typename vector<T> ::iterator it = mindist.begin(),end= mindist.end(); it != end; ++it){
                cout << *it << "  ";
            }
            cout << "\n\n";
            printgraph();
        }
        void dijkstraHeap(int source){
            typedef pair<int,int> ii;
            priority_queue<pair<int,int> ,vector<pair<int,int> >,ComparePair>  pq;
            pq.push(make_pair(0,0));
            pair<int,int> pa;
            vector< int > mindist(V,INT_MAX);
            int index,data;
            mindist[0] = 0;
            while(!pq.empty()){
                pa = pq.top();
                pq.pop();
                index = pa.first;
                data = pa.second;
                for(typename list<pair<int,T> > ::iterator lit= graph[index].begin(),lend =graph[index].end(); lit != lend; ++lit ){
                        if(mindist[lit->first] > mindist[index] + lit->second){
                            mindist[lit->first] = mindist[index] + lit->second;
                            pq.push(make_pair(lit->first,mindist[lit->first]));
                        } 
                    }

            }
         cout << "\nUsing PQ\n";
            for(typename vector<T> ::iterator it = mindist.begin(),end= mindist.end(); it != end; ++it){
                cout << *it << "  ";
            }


        }
};

int main(){
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 0, 10, 0, 2, 0, 0},
        {0, 0, 0, 14, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    Graph<int> g(graph,V);
  g.dijkstra(0);
    g.dijkstraHeap(0);
    return 0;
}
