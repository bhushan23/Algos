#include <iostream>
#include <vector>
#include <string>
using namespace std;
int max(int a,int b){
return a>b? a : b;
}
int knapsack(int* v,int* w,int W,int n){
    int ar[n+1][W+1];
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= W; ++j){
            if( i == 0 || j == 0)
                ar[i][j] = 0;
            else if( w[i-1] <= W ){
                ar[i][j] = max(v[i-1] + ar[i-1][W-w[i-1]], ar[i-1][j]);
            }  else
                ar[i][j] = ar[i-1][j];

        }
    }
    return ar[n][n];
}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<"CApacity " <<  knapsack(val,wt,W, n);
    return 0;
}
