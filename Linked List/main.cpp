#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


Node* head = NULL;

Node* addNode(int data, Node* head){
    //Creating an independent Node
    Node* p = new Node();
    p->data = data;
    p->next = NULL;

    if(head == NULL){
        return p;
    }
    Node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = p;
    return head;
}

//Iterative Methods

void iterativePrint(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        if(temp->next!= NULL)
            cout<<"-> ";
        temp = temp->next;
    }
}

//Recursive Methods

void recursivePrint(Node* p){
    //exit condition
    if(p==NULL)
        return;

    cout<<p->data<<" ";
    if(p->next != NULL)
        cout<<"-> ";
    recursivePrint(p->next); //Recursive call
}

void recursiveReversePrint(Node* p){
    //exit condition
    if(p==NULL)
        return;

    recursiveReversePrint(p->next); //Recursive call is called before printing
    if(p->next != NULL)
        cout<<"-> ";
    cout<<p->data<<" ";
}

/*
    This is a recursive reverse method. So I'm writing some description of how.
*/
    void recursiveReverseList(Node* x){
        if(x->next == NULL){
            head = x;
            return;
        }
        recursiveReverseList(x->next);
        Node *q = x->next;
        q->next = x;
        x->next = NULL;
    }

    void printKth(Node* p, int k){
        static int cnt = 0;
        if(p->next == NULL)
            return;
        else{
            printKth(p->next, k);
        }
        cnt++;
        if(cnt == k-1){
            cout<<p->data<<endl;
            return;
        }
    }


int main()
{
    cout << "Hello world!" << endl;
    head = addNode(2, head);
    head = addNode(4, head);
    head = addNode(1, head);
    head = addNode(7, head);
    head = addNode(9, head);

    iterativePrint(head);
    cout<<""<<endl;
    recursivePrint(head);
    cout<<""<<endl;
    recursiveReversePrint(head);
    cout<<""<<endl;

    recursiveReverseList(head);
    cout<<""<<endl;
    iterativePrint(head);
    cout<<"\n";
    printKth(head, 1);
    return 0;
}
