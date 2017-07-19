#include <iostream>
#include <math.h>
#include <queue>

/* Documentation-
1. Search methods:
    1.1 Recursive
    1.2 Non-recursive using while

2. Adding Node
    2.1 There's only one I've come across yet.

3. Traversal
    3.1 In-order
*/

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(){
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    public: node* ROOT;
    BinaryTree(){
        ROOT = NULL;
    }

    void depthFinder(int &cnt, node* root);
    int realDepth(node* ptr);

    void insertNode(int data, BinaryTree &B);

    //Search Methods
    void findRecursive(int data, node *currentNode);
    node* findIterative(int data);

    void inorder(node* ptr);
    void preorder(node* root);
    void postorder(node* root);
    void BFS(int level, int width, node* ptr);

    void printTree(node* root);
};


int BinaryTree :: realDepth(node* ptr){
    if(ptr->left==NULL && ptr->right==NULL)
        return 1;
    else if(ptr->left==NULL && ptr->right!=NULL)
            return 1 + realDepth(ptr->right);
    else if(ptr->left!=NULL && ptr->right==NULL)
            return 1 + realDepth(ptr->left);
    else
        return 1 + max(realDepth(ptr->right), realDepth(ptr->left));
}

void BinaryTree :: depthFinder(int &cnt, node* root){
        cnt++;
        if(root->left!=NULL)
            depthFinder(cnt, root->left);
        if(root->right!=NULL)
            depthFinder(cnt, root->right);
    //cout<<cnt<<endl;
}

//Search 1.1 Recursive version to find. Does not return anything
void BinaryTree :: findRecursive(int data, node *currentNode){
    static int count = 0;
    //currentNode = ROOT;
    if(currentNode == NULL){
        count++;
        cout<<"Not found\n"<<endl;
    }

    else if(currentNode->data == data){
        count++;
        cout<<"Found in "<<count<<" tries.\n"<<endl;
    }

    else{
        count++;
        if(currentNode->data > data){
            cout<<"\nLeft\n"<<endl;
            findRecursive(data,currentNode->left);
        }
        if(currentNode->data < data){
            cout<<"\nRight\n"<<endl;
            findRecursive(data,currentNode->right);
        }
    }
}

//Search 1.2 Iterative version to find. Returns the pointer to the node if found else return NULL
node* BinaryTree :: findIterative(int data){
    node* currentNode = BinaryTree::ROOT;
    while(currentNode!= NULL){
        if(currentNode->data == data){
            return currentNode;
        }
        else if(currentNode->data > data)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }
    return currentNode;
}

//Insert 2.1 Inserting a node into the Binary Tree. Uses the iterativeFind() method for check.
void BinaryTree :: insertNode(int data, BinaryTree &B){
    if(!findIterative(data)){
        node* ptr = new node();
        ptr->data = data;

        if(B.ROOT == NULL){
            cout<<"The tree was empty"<<endl;
            B.ROOT = ptr;
        }

        else if(B.ROOT!=NULL){

            node* currentNode = B.ROOT;
            node* parent = NULL;
            while(currentNode != NULL){
                parent = currentNode;
                if(currentNode->data > data){
                    currentNode = currentNode->left;
                }
                else{
                    currentNode = currentNode->right;
                }
            }
            if(parent->data > data)
                parent->left = ptr;
            else
                parent->right = ptr;
        }
    }
    else
        cout<<"Value already present"<<endl;
}

void BinaryTree :: inorder(node* ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }
    else{

    }
}

void BinaryTree :: BFS(int level, int width, node* ptr){
    if (ptr == NULL)
        return ;
    if(level == 1){
        for(int i=1; i<(width/2) ; i++)
            cout<<" ";
        cout<<ptr->data;
    }
    else if(ptr->left==NULL && ptr->right!=NULL){
        //BFS(level-1, width/2, ptr->left);
        cout<<"    ";
        BFS(level-1, width/2, ptr->right);
        cout<<"\n ";
    }

    else if(ptr->left!=NULL && ptr->right==NULL){
        BFS(level-1, width/2, ptr->left);
        cout<<"    ";
        //BFS(level-1, width/2, ptr->right);
        //cout<<"\n ";
    }

    else{
        BFS(level-1, width/2, ptr->left);
        cout<<"   ";
        BFS(level-1, width/2, ptr->right);
        cout<<"\n ";
    }
}

int main()
{
    BinaryTree b1;
    b1.ROOT = NULL;

    cout<<""<<endl;
    int button = 1;
    int choice;
    while(button != 0){
        cout<<"***Welcome to the most awesome binary tree in the world!***"<<endl;
        cout<<""<<endl;
        cout<<"1. Search Recursive"<<endl;
        cout<<"2. Search Iterative"<<endl;
        cout<<"3. Insert node"<<endl;
        cout<<"4. In-order traversal"<<endl;
        cout<<"5. Depth of Binary Tree"<<endl;
        cout<<"6. Print the Tree\n"<<endl;
        cout<<"7. Press 0 to Exit\n"<<endl;
        cout<<"Enter your option: ";
        cin>>choice;
        switch(choice){

            //1. Recursive Search
            case 1: {
                int num;
                cout<<"\nThis is the Recursive search method\n"<<endl;
                cout<<"Enter the number to be searched: ";
                cin>>num;
                b1.findRecursive(num,b1.ROOT);
            }
            break;

            //2. iterative Search
            case 2: {
                int num;
                cout<<"\nThis is the Iterative search method\n"<<endl;
                cout<<"Enter the number to be searched: ";
                cin>>num;
                node* val = b1.findIterative(num);
                if(val!=NULL)
                    cout<<"Found: "<<val->data<<", at: "<<val<<"\n"<<endl;
                else
                    cout<<"Not found!\n"<<endl;
            }
            break;

            //3. Add a node
            case 3: {
                int num;
                cout<<"Adding a new node? You're at the right place!\n"<<endl;
                cout<<"Enter the number to be added: ";
                cin>>num;
                b1.insertNode(num,b1);
                cout<<b1.ROOT->data<<endl;
                b1.findIterative(num);
            }
            break;

            case 4: {
                cout<<"\n";
                b1.inorder(b1.ROOT);
                cout<<"\n"<<endl;
            }
            break;

            case 5: {
                cout<<"\nDepth of the Tree is: "<<b1.realDepth(b1.ROOT)<<"\n"<<endl;
            }
            break;

            case 6: {
                int depth = b1.realDepth(b1.ROOT);
                cout<<"\nDepth: "<<depth<<endl;
                cout<<"\n";
                for(int i=1; i<depth+1; i++){
                    b1.BFS(i, 6*depth,b1.ROOT);
                    cout<<"\n";
                }
                cout<<" "<<endl;
            }
            break;

            case 0:
                button = 0;
            break;

            default:{
                cout<<"Wrong choice Honey! Try again."<<endl;
            }
        }
    }
    return 0;
}
