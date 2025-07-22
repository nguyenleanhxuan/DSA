#include <iostream>
#include "List.cpp"

using namespace std;

int main(){
    List<int> intList;
    int initial[] = {12, 5, 79, 82, 21, 43, 31, 35, 57, 1, 2, 3};
    for (int i = 0; i < 12; i++) intList.insert(i,initial[i]);
    
    int value;
    cout << "Chọn số cần xóa: " << "\n";
    cin >> value;

    // CHECK RETRIEVE METHOD
    for (int i = 0; i < intList.size(); i++) 
    {
        Node<int>* pTemp = *head;
	    while (pTemp != NULL) {
		    if(pTemp->entry == value) intList.remove(i,initial[i]);
		    pTemp = pTemp->next;
	    }
    }
    intList.printAll();
    cout << endl;
}