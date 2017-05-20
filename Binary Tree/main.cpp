#include <iostream>

/*
1. Search methods:
    1.1 Recursive
    1.2 Non-recursive using while
*/

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};

class BinaryTree{
    public: node* ROOT;
    BinaryTree(){
        ROOT = NULL;
    }

    void insertNode(int data);
    void findRecursive(int data, node *currentNode);
    void inorder(node* root);
    void preorder(node* root);
    void postorder(node* root);
};

//Search 1.1 Recursive version to find. Does not return anything
void BinaryTree :: findRecursive(int data, node *currentNode){
    static int count = 0;
    //currentNode = ROOT;
    if(currentNode == NULL){
        count++;
        cout<<"Not found"<<endl;
    }

    else if(currentNode->data == data){
        count++;
        cout<<"Found in "<<count<<" tries."<<endl;
    }

    else{
        count++;
        cout<<"getting here"<<endl;
        if(currentNode->data > data){
            cout<<"Left"<<endl;
            findRecursive(data,currentNode->left);
        }
        if(currentNode->data < data){
            cout<<"Right"<<endl;
            findRecursive(data,currentNode->right);
        }
    }
}


int main()
{
    BinaryTree b1;
    node* n1 = new node();
    b1.ROOT = n1;
    n1->data = 3;
    node* n2 = new node();
    n2->data = 2;
    node* n3 = new node();
    n3->data = 4;
    n1->left = n2;
    n1->right= n3;
    node* n4 = new node();
    n4->data = 1;
    n2->left = n4;

    //b1.findRecursive(1,b1.ROOT);
    int button = 1;
    int choice;
    while(button != 4){
        cout<<"***Welcome to the most awesome binary tree in the world!***"<<endl;
        cout<<""<<endl;
        cout<<"1. Search Recursive"<<endl;
        cout<<"2. Search Iterative"<<endl;
        cout<<"3. Insert node"<<endl;
        cout<<"4. Exit\n"<<endl;
        cout<<"Enter your option: ";
        cin>>choice;
        switch(choice){
            case 1: {
                int num;
                cout<<"This is the recursive search method\n"<<endl;
                cout<<"Enter the number to be searched: ";
                cin>>num;
                b1.findRecursive(num,b1.ROOT);
            }
            break;

            case 4:
                button = 4;
            break;

            default:{
                cout<<"Wrong choice Honey. Try again."<<endl;
            }
        }
    }
    return 0;
}
