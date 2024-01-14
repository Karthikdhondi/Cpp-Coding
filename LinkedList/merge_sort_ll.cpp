#include<iostream>
using namespace std;
#include "node_class.cpp"

Node* takeInput(){

    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
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
    cout << endl;
    return;
}

  
    Node* mid_ll(Node *head){
        Node* slow = head;
        Node* fast = head->next;
        if(fast->next == NULL){
            return slow;
        }

         while(fast != NULL){
            slow = slow->next;
            fast = fast->next->next;

        if(fast == NULL || fast->next == NULL){
               return slow;
            }
       
        }
        return 0;
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

Node *mergeSort(Node *head){
   
    if(head->next == NULL){
        return head;
    }
    else{
    Node *mid = mid_ll(head); 
    
    Node *second_ll = mid->next;
    mid->next = NULL ;
    Node *first_ll = head;
   
    Node *fll = mergeSort(first_ll);
    Node *sll = mergeSort(second_ll);

    Node *merge_ll = merge(fll, sll);
   
    return merge_ll;
 }
}



int main(){
    cout << "Enter the input values of the linked list: ";
    Node *head = takeInput();
    cout << "Input Linked List: ";
    print(head);

    Node *final_ll = mergeSort(head);
    cout << "Final Sorted Linked List: " ;
    print(final_ll);

  


}