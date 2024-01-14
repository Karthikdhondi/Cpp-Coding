template<typename T>
class Node{
    public:
        T data;
        Node<T> *next;
    Node(T data){
        this->data =data;
        next = NULL;
    }
};


template<typename T>
class StackUsingLL{
    Node<T> *head;
    T size ;

    public:
    StackUsingLL(){
        head = NULL;
        size = 0;
        
    }

    T getSize(){
        return size;
    }

    bool isEmpty(){
        if(size){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element){
        if(head == NULL){
            Node<T> *newNode = new Node(element);
            head = newNode;
            size++;
        }
        else{
            Node<T> *newNode = new Node(element);
            newNode->next = head;
            head = newNode;
            size++;
        }
        
    }
    T pop(){
        if(isEmpty()){
            return 0;
        }}
        T del_el = head->data;
        Node<T> *tmp = head;
        head = head->next; 
        delete tmp;
        size--;
        return del_el;
    }

    T top(){
        if(isEmpty()){
            return 0;
        }
       return head->data;
    }

};