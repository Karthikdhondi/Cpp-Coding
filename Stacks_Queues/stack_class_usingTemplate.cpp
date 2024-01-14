#include <climits>
template <typename T>
class StackUsingArray{
    T *data;
    int  nextIndex;
    int capacity;


    public: 
    /*
    StackUsingArray(int total_size){
        data = new int[total_size];
        nextIndex = 0;
        capacity = total_size;
    }
    */
    //By the below code we are removing the size constraint by using dynamic arrays


    StackUsingArray(){
        data = new T(4);
        nextIndex = 0;
        capacity = 4;
    }
    //It tells the how many elements in the stack 
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
    /*  if(nextIndex == 0){
            return true;
            }
        else{
            return false;
            }
        }
    */
    //The below statement is same as the above commented code.
    return nextIndex == 0;
    }

    void push(T element){
        if(nextIndex == capacity){
            T *newdata = new T[ 2 * capacity ];
            for(int i=0;i < 2 * capacity; i++){
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data =newdata;
            /*
            cout << "Stack Overflow" << endl;
            return;
            */
        }
        
        data[nextIndex] = element;
        nextIndex++;
        
    }

    T pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return 0;
        }
    
        nextIndex--;
        return data[nextIndex];
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is Empty"<< endl;
            return 0;
        }
     return data[nextIndex - 1];
    }

};