#include <iostream>
#include <vector>
using namespace std;

template<class T> class Heap{
    vector<T> heap;
    int size;
    bool Maxheap;
    public:
        Heap(T *ar, int s,bool maxHeap = true ): heap(s){
          size = s;  
          copy(ar,ar+s,heap.begin());
          print();  

            Maxheap = maxHeap;
            if(Maxheap){ //MAX HEAP
              for(int i = s/2; i >= 0; --i){
                MaxHeapify(i);   
              }
            }
            print();
        }

      
        int left(int index){
          int ind = 2*index+1;
          if( ind >= size)
              return -1;
          return ind;
        } 
        int right(int index){
          int ind = 2*index+2;
          if( ind >= size)
              return -1;
          return ind;
        }  
        
        void SWAP(T* a,T* b){
          T* temp;
          temp = a;
          a = b;
          b = temp;
        }
        void MaxHeapify(int nodenum){
          cout<<" maxheapify on "<<heap[nodenum] << "\n"; 
          T tnode = heap[nodenum];
         
          int l,r,largest;
          
          l = left(nodenum);
          r = right(nodenum);
         
          cout<< " l " << l << "  " << r; 
          largest = nodenum;
          if ( l != -1 && heap[largest] < heap[l] )
            largest = l;
          if( r != -1 && heap[largest] < heap[r] )
            largest = r;
          
          cout << "\nlargest : " << heap[largest] << "\n";
          if(largest != nodenum ){
              cout << "Swapping "<< heap[largest] << "  " <<heap[nodenum];
              T temp = heap[largest];
              heap[largest] = heap[nodenum];
              heap[nodenum] = temp; 
             // SWAP(&heap[largest], &heap[nodenum]);
              
               MaxHeapify(largest); 
          }
        }


      void print(){
            for(typename vector<T>::iterator it = heap.begin(), end = heap.end(); it != end; ++it){
                cout<< *it << "  ";
            }    
            cout<< "\n";
      }
           
};

int main(){
    int ar[] = {5,6,2,5,16,1,12,7};
    
    Heap<int> h(ar, (sizeof(ar)/sizeof(ar[0])) );
    
}
