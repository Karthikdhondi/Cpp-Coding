#include<iostream> 
using namespace std;
#include<vector>

int main(){
    //Dynamic allocation (we need to delete on oursleves,by using free)
    //vector<int> *v = new vector<int>();

    //static allocation (Template) it will be deleted automatically 
    vector<int> v;
    //push_back will check all the things, like if the vector is full, 
    //if full, it will double the size of the current array and then insert the value.
    //use push_back to insert, because it will check the size of the array, is there any neccessity of doubling the array,then it will enter the element to array
    // safe to use push_back
     

    for(int i = 0; i < 100; i++ ){
        cout<< "Capacity: "<< v.capacity() << endl;
        cout<< "Size: " << v.size() << endl;
        v.push_back(i+1);
    }



    //To insert we use push_back
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    /*
    for(int i=0; i< v.size(); i++){
            cout<< "Elements of vector Before modification: " << v.at(i) << endl;
    }
    */

    //If we want to modify the data of a particular value in the vector we can use following syntax
    v[1] = 100;
    /*
        for(int i=0; i< v.size(); i++){
            cout<< "Elements of vector: " << v.at(i) << endl;
    }
            cout<< "Elements of vector at 2nd Index: " << v.at(2) << endl;
            cout<< "Elements of vector at 8th Index: " << v[8] << endl;
            //position at index 8 is given some grabage value.
            //position at index 6 is given as out_of_range error which is safer to use. 
          //  cout<< "Elements of vector at 6nd Index: " << v.at(6) << endl;
 
    */
     //To delete an entry we have a key word "pop_back".
        v.pop_back();
    /*
    for(int i=0; i< v.size(); i++){
            cout<< "Elements of vector After Deletion: " << v.at(i) << endl;
    }
    */
}