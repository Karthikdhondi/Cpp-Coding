 #include<iostream>
 using namespace std;
 #include "node_class.cpp"

 Node* takeInput(){

    int data;
    cout <<"Enter the values for Linked List:"<< endl;
    //enter -1 to terminate while giving input
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


/*
//itereative method
Node* insertNode(Node *head,int i,int data){
    
    Node *newNode = new Node(data);
    Node *tmp = head;
    int count =0;
    if(i==0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(tmp!=NULL && count < i-1){
        tmp = tmp->next;
        count++;
    }   
        if(tmp!=NULL){
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    return head;
   }   
    */

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
  //Recursive method to delete a node 

    Node* deleteNode(Node *head,int i){
        if(head == NULL){
            return head;
        }

        if(i == 0){
           Node* tmp = head;
            head = head->next;
            tmp->next = NULL;
            delete tmp;
            return head;

        }

        else {
           Node *x = deleteNode(head->next, i-1);
           head->next =x;
           return head;
        }
         
    }



    /*
    //Iterative method to delete a node 
    
    Node* deleteNode(Node *head, int i){
        Node *tmp = head;
        int count =0;
        
        int lenght_ll =length(head);
        //cout << lenght_ll << endl;

        if(i >= lenght_ll){
            cout << "Index value exceeds length of the linked list:" << endl;
            return head;
        }

        if(i==0){
            head = tmp->next;
            delete tmp;
            return head;
        }
        while(tmp != NULL && count<i-1){
            tmp = tmp->next;
            count++;
        }
        //corner case is missing i.e what if index value is greater than length
       
 
        Node* b = tmp->next;
        Node* a = tmp->next->next;
        tmp->next = a;
        delete b;

        return head;
    }
     */

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
 }

 int main(){
 

        Node *head = takeInput();
        print(head);

        int i,j,data;
        cout<<"Enter the value of index and data:"<<endl;
        cin>>i>>data;

        head = insertNode(head,i,data);
        print(head);
        cout <<"Enter the Index value which is to be deleted:" << endl;
        cin>> j;

        head = deleteNode(head,j);
        print(head);



 /*
    //statically

    
    Node a(10);
    Node *head = &a;
    Node b(20);
    Node c(50);
    Node d(60);
    Node e(70);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    print(head);
*/
    //cout << a.data << " " << b.data << endl;
    //cout << head->data<< " " << head->next->data << " "<< endl;
/*
    //dynamically

    Node *c = new Node(30);
    Node *head1 = c;
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);
    Node *g = new Node(70);

    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    print(head1);

    // cout << c->data<< " " << c->next->data << " "<< endl;

    */
     
 }