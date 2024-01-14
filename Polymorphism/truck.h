class Truck : virtual public Vehicle{ //This kindof of Inheritance is also known as "Virtual inheritance/Hybrid Inheritance"
    //This is example of hierarcial inheritance
    // Where we vehicle class is ihnerited in car class and as well in this Truck class.
    public:
        Truck() : Vehicle(4){
            cout << "Truck's Default Constructor "<< endl;
        }
};