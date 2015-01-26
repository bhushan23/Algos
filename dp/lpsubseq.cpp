#include <iostream>
#include <vector>
#include <string>
using namespace std;
int lpsubseq(const string &s){
    int n = s.length();
    vector < vector<int> > ar(n, vector<int> (n,0));
    for(int i = 0; i < n; ++i){
        ar[i][i] = 1;
    }

    for(int cl = 2; cl <= n; ++cl ){
        for(int i = 0; i < n-cl+1; ++i){
            int j = i + cl - 1;
            if(s.at(i) == s.at(j))
                ar[i][j] = ar[i+1][j-1]+2;
            else{
                ar[i][j] = max(ar[i+1][j],ar[i][j-1]);
            }
        }
    }
    return ar[0][n-1];
}

int main(){
    string s = "asdfkjbasdfdsafda";
    cout << " LPSubseq: " << lpsubseq(s);
}
