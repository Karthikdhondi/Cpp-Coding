class Vehicle{
    public:
        string color;

    /*
    Vehicle(){
        cout << "Vehicle's Default Constructor " << endl;
    }*/

    /*
    //it supports CompileTIme Polymorphism.
    void print(){
        cout << "Vehicle "<< endl;
    }
    */

    /*
    //Runtime Polymorphism.
    virtual void print(){
        cout << "Vehicle " << endl;
    }
    */

    virtual void print() = 0;
    

};