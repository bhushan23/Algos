#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define R 3
#define C 3
int min(int a,int b){
    return (a < b ? a : b);
}
int minOf(int a,int b,int c){
    return min(min(a,b),c);
}
int mincost(int ar[R][C]){
    int mcost[R][C];
    mcost[0][0] = ar[0][0];
    for(int i = 1; i < C; ++i){

        mcost[0][i] = mcost[0][i-1] + ar[0][i]  ;

    }
    for(int i = 1; i < R; ++i){
        mcost[i][0] = mcost[i-1][0] + ar[i][0];

        for(int i = 1; i < R; ++i){
            for(int j = 1; j < C; ++j){
                mcost[i][j] = minOf(mcost[i-1][j] , mcost[i][j-1] ,mcost[i-1][j-1]) + ar[i][j]; 
            }
        }
    }
    return mcost[R-1][C-1];

}

int main(){

    int cost[R][C] = { {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3} };
    cout << " MIN COST " << mincost(cost);
}
