#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node *left;
        Node *right;
        Node *parent;
        Node(T d,Node *par=NULL){
            //cout << "\n New node created " << d << "\n"; 
            data = d;
            left = NULL;
            right = NULL;
            parent = par;
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
            InsertRec(root,data,root);  
        }

        Node<T>* InsertRec(Node<T>* cur, T data,Node<T>* par){
            if (cur == NULL) {
                Node<T>* temp = new Node<T>(data,par);
                return temp;
            }
            if (cur->data < data) {
                cur->right = InsertRec(cur->right,data,cur);
            }else {
                cur->left = InsertRec(cur->left,data,cur);   
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
            cout << " " << cur->data ;
            if (cur->parent)
                cout<< "(" << cur->parent->data << ")";
            else
                cout << "(..)";
            PrintInorder(cur->right);
        }
        void BstToDll()
        {
            Node<T> *head = root;
            while (head->left) {
                head = head->left;
            }
            convertToDll(root);

            cout << "\n DONE \n";    
            while (head->right != NULL) {
                cout << head->data << " ";
            }
            cout << "\n";
        }

        Node<T>* convertToDll(Node<T> *cur)
        {
            if (cur == NULL) {
                return NULL;
            }
          convertToDll(cur->left);
           
            Node<T>* h = inorderSucc(cur);
            cout << "\nCurrent " << cur->data << " " <<  h->data;
           
          convertToDll(cur->right);
          //  cur->right = inorderSucc(cur);
            
        }
        Node<T>* inorderSucc(Node<T>* cur)
        {
            if (cur != NULL) {
            if (cur->right != NULL) {
                cout << "\n Going Right";
                cur = cur->right;
                while (cur->left != NULL) {
                    cur = cur->left;
                }
                return cur;
            }
            Node<T> *n = cur->parent;
            while (n != NULL && n->right == cur) {
                cout << "\nGoing to par";
                cur = n;
                n = n->parent;
            }
            }
            return cur;
        }
};

int main(){
    int ar[] = {5,2,13,51,24,53,1,12,41,42,55,62,66};

    Tree<int> btree;    
    for(int i = 0; i < sizeof(ar)/sizeof(ar[0]); ++i){
        btree.Insert(ar[i]);
    }
    cout << "\n\n";
    btree.Print();
    cout << "\n\n";
    btree.BstToDll();
}
