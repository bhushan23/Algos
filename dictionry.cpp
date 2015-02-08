#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;


class SearchDic{
    public:
        string key;
        hash_map<string,list<string> > Matchstr;
        queue<pair<string,int> > que;

        SearchDic(string &key1) : key(key1)
        {
            sort(key.begin(),key.end());
            buildMap();
        }

        void buildMap()
        {
          list<string> lst;
          pair<string,int> tp;  
          for(int i = 0; i < key.length(); ++i ) {
               que.push(make_pair(key.substr(i,1),i));       
          }

          while (!que.empty()) {
                tp = que.front();
                que.pop();

                if (Matchstr.find(tp.first) == Matchstr.end()) {
                      Matchstr.insert(make_pair(tp.first,NULL));
                      for(int i = tp.second+1; i < key.size(); ++i) {
                            string ts = tp.first + key[i];
                            que.push(make_pair(ts,i));
                      }
                }
          }
        }
        
        void SearchFile(string ar[],int len)
        {
            string temp;    
            for(int i = 0; i < len; ++i){
                temp = ar[i];
                sort(temp.begin(),temp.end());
                if (Matchstr.find(temp) != Matchstr.end())
                    Matchstr[temp].push_back(ar[i]);
            }
        }
        
        void Print()
        {
            for (map<string,list<string> > :: iterator mit = Matchstr.begin(), mend = Matchstr.end(); mit != mend; ++mit) {
                cout << "\n" << mit->first << " : ";
                for (list<string> :: iterator lit = mit->second.begin(), lend = mit->second.end(); lit != lend; ++lit ) {
                   cout << *lit << " " ; 
               } 
            }
        }

};
int main(){
    string ar[] = {"abdc","abc","ab","bac","bca"};
    string key = "abcd";
    SearchDic sd(key);
    sd.SearchFile(ar,sizeof(ar)/sizeof(ar[0]));
    sd.Print();
}
