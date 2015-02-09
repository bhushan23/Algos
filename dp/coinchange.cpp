#include <iostream>
#include <vector>
#include <string>
using namespace std;
int coinchange(int *S,int m,int n){
    int ar[n+1][m];
    for(int i = 0; i < m; ++i){
        ar[0][i] = 1;
    }
    for(int i = 1; i < n+1; ++i){
        for(int j = 0; j < m; ++j){
            int exc = (j>=1)? ar[i][j-1]:0;
            int inc = (i - S[j] >= 0) ? ar[i-S[j]][j] : 0;
            ar[i][j] = exc + inc;
        }
    }
return ar[n][m-1];
}
int main(){
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    cout << " Total no. of coin change: " << coinchange(arr,m,n);
}
