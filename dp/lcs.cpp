#include <iostream>
#include <vector>
#include <string>
using namespace std;
int maxOf(vector< vector<int> > &vec,int i,int j){
    int max = -1;
    if( max < vec[i-1][j] )
        max = vec[i-1][j];
    if( max < vec[i][j-1] )
        max = vec[i][j-1];
    if( max < vec[i-1][j-1] )
        max = vec[i-1][j-1];
    return max;
}
int LCS(string &s1,string &s2){
    vector< vector<int> > vec(s1.length(), vector<int> (s2.length(),0));
    int maxin;
    int len1 = s1.size(), len2 = s2.size();
    for(int i = 0; i < len2; ++i){
        if(s1.at(0) == s2.at(i))
            vec[0][i] = 1;
    }
    for(int i = 0; i < len1; ++i){
        if(s2.at(0) == s1.at(i))
            vec[i][0] = 1;
    }

    for(int i = 1; i < len1; ++i ){
        for(int j = 1; j <len2 ; ++j ){
            maxin = maxOf(vec,i,j);
            if(s1.at(i) == s2.at(j)){
                ++maxin;
            }
            vec[i][j] = maxin;
        }
    }

    cout << "MAX LCS" << vec[len1-1][len2-1];
}

int main(){
    string s1= "bhushan";
    string s2= "shan";
    LCS(s1,s2);    
}

