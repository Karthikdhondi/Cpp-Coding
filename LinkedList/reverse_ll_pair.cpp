#include<iostream>
using namespace std;

#include "node_class.cpp"

class Pair{
    public:
     
     Node *head;
     Node *tail;
};
//With single function we can return multiple parameters using class.
Pair reverse_ll_2(Node *head){
    if(head == NULL || head->next == NULL){
        
        Pair ans;

        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverse_ll_2(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    //Here we are returning multiple parameters with single object of a class.
    return ans;
}

Node* reverse_ll_better(Node *head){
    return reverse_ll_2(head).head;
}

Node *takeInput(){
    
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
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(Node* head){
    Node* tmp = head;

    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    cout << "Enter the Input vlaues of Linked List: " << endl;
    Node *head = takeInput();


    head = reverse_ll_better(head);
    cout << "Reversed Linked List with T.C O(N): "<< endl;
    print(head);
}