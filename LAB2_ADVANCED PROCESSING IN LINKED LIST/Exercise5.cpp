#include <iostream>
#include "List.cpp"

using namespace std;

int main(){
    List<int> intList;
    int initial[] = {12, 5, 79, 82, 21, 43, 31, 35, 57, 1, 2, 3};
    for (int i = 0; i < 12; i++) intList.insert(i,initial[i]);
    
    // CHECK REMOVE METHOD
    for (int i = 11; i > 8; i--) intList.remove(i,initial[i]);
    intList.printAll();
    cout << endl;

    // CHECK RETRIEVE METHOD
    for (int i = 0; i < intList.size(); i++) 
    {
        if(intList.retrieve(i,initial[i]) == success)
            cout << "Element at position " << i <<":  "<< initial[i] << " ";
        cout << endl;
    }
}