class Vehicle{
    private:
        int maxspeed;
    protected:
        int numTyers;
    public:
        string color;

    /*
    Vehicle(){
        cout << "Vehicle's Default Constructor " << endl;
    }*/

    void print(){
        cout << "Vehicle "<< endl;
    }

    Vehicle(int z){
        cout << "Vehicle's Parameterized constructor :" << z << endl;
        maxspeed = z; 
    }

    ~Vehicle(){
        cout << "Vehicle's Destructor " << endl;
    }

};