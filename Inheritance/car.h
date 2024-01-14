 /*
 There are two copies of Vehicle in "Bus class" to avoid multiple copies we use "Virtual" keyword for the classes 
    Which are inheriting the vehicle class.

    Virtual key word makes sure that whichever class is inheriting the Car class, it tell that to access vehicle class directly.
    In this case Bus class will directly access the vehicle class.

    As we know that a child class can only call the immediate parent class's constructor. 

    But when we use "virtual keyword" a "child class" can also call its "Grandparent's constructor."" 

*/

class Car : virtual public Vehicle { //This kindof of Inheritance is also known as "Virtual inheritance/Hybrid Inheritance"
    public:
        int numGears;

    Car() : Vehicle(3){
        cout << "Car's Default Constructor " << endl;
    }

    /*
    Car(int x, int y) : Vehicle(x){
        cout << "Car's Parameterized Constructor " << endl;
        numGears = y; 
    }
    */
    ~Car(){
        cout << "Car's Destructor " << endl; 
    }

    void print(){
        cout << "NumTyers :" << numTyers << endl;
        cout << "Color :" << color << endl;
        cout << "NumGears :" << numGears << endl;
        /*
        While Inheritance if we us "Public" modifier then
        
        1. Public properties of Base Class will convert to Public
        2. Protected properties of Base Class will convert to Protected
        3. Private properties of Base Class will not be inherited. 

        Therefore maxspeed will not be used accessible in this class.
        It will through an error.

        private members of the class cannot be accessible outside the class.
        */

        //cout << "MaxSpeed :" << maxspeed << endl; 
    }
    
};