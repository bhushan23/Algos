#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node *left;
    Node *right;
    Node(T d){
        //cout << "\n New node created " << d << "\n"; 
        data = d;
        left = NULL;
        right = NULL;
    }
};

template <class T>
class Tree{
    public:    
    Node<T> *root;

    Tree(T data){
        root = new Node<T>(data);
    }
    Tree(){
        root = NULL;
    }
    void Insert(T data){
        if(root == NULL){
            root = new Node<T>(data);
            return;
        }
        InsertRec(root,data);  
    }

    Node<T>* InsertRec(Node<T>* cur, T data){
        if (cur == NULL) {
            Node<T>* temp = new Node<T>(data);
            return temp;
        }
        if (cur->data < data) {
           cur->right = InsertRec(cur->right,data);
        }else {
           cur->left = InsertRec(cur->left,data);   
        }
        return cur;
    }

    void Print(){
        PrintInorder(root);
    }

    void PrintInorder(Node<T>* cur){
        if(cur == NULL)
            return;

        PrintInorder(cur->left);
        cout << " " << cur->data;
        PrintInorder(cur->right);
    }

};

int main(){
    int ar[] = {2,5,13,51,24,5,1,12,41,42,55,62,66};

    Tree<int> btree;    
    for(int i = 0; i < sizeof(ar)/sizeof(ar[0]); ++i){
        btree.Insert(ar[i]);
    }
    cout << "\n\n";
    btree.Print();
    cout << "\n\n";
}
