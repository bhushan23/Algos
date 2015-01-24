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
            }else{
               for(int i = s/2; i >= 0; --i){
                MinHeapify(i);   
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
         // cout<<" maxheapify on "<<heap[nodenum] << "\n"; 
          T tnode = heap[nodenum];
         
          int l,r,largest;
          
          l = left(nodenum);
          r = right(nodenum);
         
         // cout<< " l " << l << "  " << r; 
          largest = nodenum;
          if ( l != -1 && heap[largest] < heap[l] )
            largest = l;
          if( r != -1 && heap[largest] < heap[r] )
            largest = r;
          
         // cout << "\nlargest : " << heap[largest] << "\n";
          if(largest != nodenum ){
           //   cout << "Swapping "<< heap[largest] << "  " <<heap[nodenum];
              T temp = heap[largest];
              heap[largest] = heap[nodenum];
              heap[nodenum] = temp; 
              MaxHeapify(largest); 
          }
        }
        void MinHeapify(int nodenum){
          T tnode = heap[nodenum];
         
          int l,r,smallest;
          
          l = left(nodenum);
          r = right(nodenum);
         
          smallest = nodenum;
          if ( l != -1 && heap[smallest] > heap[l] )
            smallest = l;
          if( r != -1 && heap[smallest] > heap[r] )
            smallest = r;
          
          if(smallest != nodenum ){
              T temp = heap[smallest];
              heap[smallest] = heap[nodenum];
              heap[nodenum] = temp; 
              MinHeapify(smallest); 
          }
        }

      T ExtractMax(){ // for MAX HEAP
          
          if(size == 0)
            return -1;
          
          T temp;
          temp = heap[0];
          heap[0] = heap[size-1];
          --size;
          MaxHeapify(0);

          return temp;
      }
           
      void print(){
            for(typename vector<T>::iterator it = heap.begin(), end = heap.end(); it != end; ++it){
                cout<< *it << "  ";
            }    
            cout<< "\n";
      }
           
};
template<class T>
void HeapSort(T* ar,int size){
 // int size =  sizeof(ar)/sizeof(ar[0]);
   Heap<int> h(ar,size);
   
   cout  << "Sorted \n";
   for(int i = size-1; i >= 0; --i){
      ar[i] = h.ExtractMax(); 
      cout << ar[i] << "  ";
   }  


    
}
int main(){
    int ar[] = {5,6,2,5,16,1,12,7};
     
   HeapSort(ar,(sizeof(ar)/sizeof(ar[0]))) ;
//    Heap<int> h1(ar, (sizeof(ar)/sizeof(ar[0])) ,false);
 /* cout<< "\n"; 
   for(int i = 0 ; i < 8;++i)
      cout << " " << ar[i];    
*/
      }
