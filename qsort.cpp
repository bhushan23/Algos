#include <iostream>
#include <vector>
using namespace std;

template<class T>
int partition(T* ar,int lower,int upper){
  int x = lower;
  T temp;
  T X = ar[upper-1];
  for(int i = lower; i < upper; ++i){
    if(X <= ar[i] ){
      temp = ar[i];
      ar[i] = ar[x];
      ar[x] = temp;
      ++x;
    }
        
  }
return x;
}

template<class T>
void QSort(T* ar,int lower,int upper){
  if(lower < upper) {  
  int pivot = partition(ar,lower,upper);
  cout << "\n Pivot: " << pivot;
  QSort(ar,lower,pivot-1);
  QSort(ar,pivot+1,upper);
  }
}

int main(){
 int ar[] = {5,6,2,5,16,1,12,7};
 QSort(ar,0,(sizeof(ar)/sizeof(ar[0])));
cout << "\n";
 for(int i = 0; i < 8; ++i){
cout <<"  "<< ar[i];
}

}
