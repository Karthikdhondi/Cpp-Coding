 #include<iostream>
 using namespace std;
 #include "node_class.cpp"

 Node* takeInput(){

    int data;
    cout <<"Enter the values for Linked List:"<< endl;
    cin >> data;

    Node *head  = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }
        else {
            Node *temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }   
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;

    
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
 }

 int main(){
 

        Node *head = takeInput();
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