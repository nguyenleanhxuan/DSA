#include <iostream>
using namespace std;


class Node {
 	public:	
		int data; 
	 	Node* next;
};


class List {
	private:
		int count;
		Node* pHead;
	public:
		List() {
            pHead = NULL; 
            count = 0;
        }
		void addFirst(int newdata) 	{
			Node* pTemp = new Node;
			pTemp->data = newdata;
			pTemp->next = pHead;
			pHead = pTemp;
			count++;
		}
		void display() {
			Node* pTemp = pHead;
			while (pTemp != NULL ) {
				cout << pTemp->data ;
				pTemp = pTemp->next;
                if (pTemp != NULL) cout << ' ';
			}
		}
		~List() {
			Node* pTemp = pHead;
			while (pTemp!=NULL) {
				pTemp = pTemp->next;
				delete pHead;
				pHead = pTemp;
			}
		}
};

int main(){
	List aList;
    aList.addFirst(78);
    aList.addFirst(35);
    aList.addFirst(83);
    aList.addFirst(35);
    aList.addFirst(51);
    aList.addFirst(12);
    aList.addFirst(29);
	aList.addFirst(6);
    aList.addFirst(12);
    cout << '{' ;
    aList.display();
    cout << '}' ;
    return 0;
}