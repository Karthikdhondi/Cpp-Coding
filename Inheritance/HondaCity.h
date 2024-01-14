class HondaCity : public Car {
    public:
        HondaCity(int x, int y) : Car(x,y){
            cout << "HondaCity's Constructor " << endl;
        }
        ~HondaCity(){
            cout << "HondaCity's Destructor " << endl;
        }
};