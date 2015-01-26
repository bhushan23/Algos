#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int>& ar,int len){
    //int len = ar.size();
    int max;
    vector<int> lis(len,1);
    vector<int> seq(len);
    max = -1;
    for(int i = 1; i < len; ++i){
        seq[i] = i;
        for(int j = 0; j < i; ++j){
            if(ar[i] > ar[j] && lis[i] < lis[j]+1 ){
                lis[i] = lis[j]+1;
                seq[i] = j;
            }
        }
        if(lis[i] > max)
            max = lis[i];
    }
    cout << "MAX Increasing Sequence length: " << lis[max] << "\n";
    for(int i = max; i != seq[i]; i = seq[i]){
        cout << " " << ar[i];
    }      
}

int main(){
    int ar[] = { 10, 22, 9, 33, 21, 50, 41, 60,80 };
    // int ar[] = {0,1,2,3,5,2,4,6,7};
    vector<int> vec(ar,ar+sizeof(ar)/sizeof(ar[0]));
    LIS(vec,9);
    return 0;
}
