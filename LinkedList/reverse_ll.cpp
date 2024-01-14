#include<iostream>
using namespace std;
#include "node_class.cpp"




Node *takeInput(){

    int data ;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;
    while(data !=-1){
        Node *newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = tail->next;
    }
    cin >> data;
  }
  return head;

}

void print(Node *head){
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout<< endl;
}

Node *reverse_ll_3(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
     
    Node *smallAns = reverse_ll_3(head->next);

    // We don't need to traverse complete list since head_->next is holding the tail.
    // We can directly take it form head->next.
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}



Node *reverse_ll(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
     
    Node *smallAns = reverse_ll(head->next);

    // To find the tail we are traversing the entire list
    //it takes O(n^2) time complexity, which is not so good.
    Node *tmp = smallAns;
    while(tmp->next != NULL){
        tmp = tmp->next ;
    }
    tmp->next = head;
    head->next = NULL;
    return smallAns;
}



int main(){

    cout << "Enter the values for the Input LL: ";
    Node *head = takeInput();
    cout << "Input Linked List is: ";
    print(head);

    Node *Reverse_ll = reverse_ll_3(head);
    cout << "Output of the Reversed Linked List: ";
    print(Reverse_ll);

} 