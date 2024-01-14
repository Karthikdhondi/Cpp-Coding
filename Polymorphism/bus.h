//Hybrid Inheritance
/*
                        vehicle
                          / \             
                         /   \            
                       Car   Truck         
                         \   /             
                          \ /           
                          Bus   

    The above problem in known as "Dimond problem" 

    There are two copies of Vehicle in "Bus class" to avoid multiple copies we use "Virtual" keyword for the classes 
    Which are inheriting the vehicle class. 

    For Ex:
      class Car : virtual public Vehicle{

      }
      class Truck : virtual public Vehicle{
        
      }
*/

class Bus : public Car, public Truck{
    public: 
    //This is to test virtual Inheritance, that is, whether a Child class can directly call the Grand parent's constructor or not. 
    //Yes,it will directly call   Grand parent's constructor. In case we use virtual keyword.
        Bus() : Vehicle(5){
            cout << "Bus's Default Constructor " << endl;
        }
        void print(){
            cout << "Bus Print function" << endl;
        }
};