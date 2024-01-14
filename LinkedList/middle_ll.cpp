#include<iostream>
using namespace std;
#include "node_class.cpp"

Node* takeInput(){

    int data;
    
    cin >> data;

    Node *head  = NULL;
    Node *tail  = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
                tail->next = newNode;
                tail = tail->next;
                //or
                //tail = newNode;
            }   
            cin >> data;
        }
        return head;
    }

    // Recursive method of insertion 
    Node* insertNode(Node *head, int i , int data){
        
        if(head == NULL){
            return head;
        }
        if(i == 0){
            Node *newNode = new Node(data);
            newNode->next = head;
            head =newNode;
            return head;
        }
        else { 

            Node *x = insertNode(head->next, i-1, data);
            head->next = x; 
            return head;
        }


    }
    int length(Node* head)
   {
    int count =0;

    Node* current = head;
    while(current != NULL){
        count++;
        current = current ->next;
    } 
    return count;
   }

    void print(Node *head){
    Node *tmp = head;// to keep head safe we are taking tmp
    //here head is a local variable
    while(tmp!= NULL)
    {
        cout<< tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return;
g }

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



 int main(){

        cout <<"Enter the values for Linked List:"<< endl;
        Node *head = takeInput();
        cout <<"Input Linked List: ";
        print(head);

        int i,j,data;
        //cout<<"Enter the value of index and data:"<<endl;
        //cin>>i>>data;

        //head = insertNode(head,i,data);
        //print(head);
       // cout <<"Enter the Index value which is to be deleted:" << endl;
        //cin>> j;

      Node* mid_element = mid_ll(head);
      cout << mid_element->data << endl;
 }