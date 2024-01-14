#include<iostream>
using namespace std;
#include "node_class.cpp"

Node* takeInput(){


int data;
cin >> data;

Node *head = NULL;
Node *tail = NULL;
while(data !=-1){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
    cin >> data;

}
return head;
}

void print(Node *head){
    Node *tmp = head;
    while(tmp !=NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return;
}

Node* merge(Node *h1, Node *h2){
    
    Node *fh = NULL;
    Node *ft = NULL;
    if(h1->data < h2->data){
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }
    else{
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }

    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            ft->next = h1;
            h1 = h1->next;
            ft = ft->next;
        }
        else{
            ft->next = h2;
            h2 = h2->next;
            ft = ft->next;
        }
    }
    if(h1 == NULL){
        ft->next = h2;
    }
    else{
        ft->next =h1;
    }
    return fh;
}
 
int main()
{
    cout << "Enter the values for the First LL:" << " ";
    Node *head1 = takeInput();
    cout<< "First Linked List:"<< " ";
    print(head1);
    cout<< "Enter the vlaues for the second LL:" << " "; 
    Node *head2 = takeInput();
    cout<< "Second Linked List:"<< " ";
    print(head2);

    Node *merge_list = merge(head1, head2);
    cout<< "Mergered Linked List: "<<" ";
    print(merge_list);
}