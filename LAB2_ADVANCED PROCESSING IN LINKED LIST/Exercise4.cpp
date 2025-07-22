#include <iostream>
#include "List.cpp"

using namespace std;

int main(){
    List<int> intList;
    int initial[] = {12, 5, 79, 82, 21, 43, 31, 35, 57};
    for (int i = 0; i < 9; i++) intList.insert(i,initial[i]);
    intList.printAll();
    
}