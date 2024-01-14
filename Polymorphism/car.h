
class Car : public Vehicle { 
    public:
        int numGears;

        
        //Actually here Function override happend 
        void print(){
            cout << "Car " << endl; 
        }
    
};