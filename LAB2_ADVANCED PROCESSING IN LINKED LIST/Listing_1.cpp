#include <iostream>
using namespace std;

//just an entry in the list, a “struct++” in fact
class Node {
    public:
        int data; 
        Node* next;
};

//interface part
class List {
    private:
        int count;
        Node* pHead;
    public:
        List() ;
        void addFirst(int) ;
        void display();
        ~List(); 	
};

//implementation part
List::List() {pHead = NULL; count = 0;}

void List::addFirst(int newdata) {
	Node* pTemp = new Node;
	pTemp->data = newdata;
	pTemp->next = pHead;
	pHead = pTemp;
	count++;
}

void List::display() {
	Node* pTemp = pHead;
	while (pTemp != NULL)	{
		cout << pTemp->data << "\t";
		pTemp = pTemp->next;
	}
}

List::~List()  {
	Node* pTemp = pHead;
	while (pTemp != NULL) {
		pTemp = pTemp->next;
		delete pHead;
		pHead = pTemp;
	}
}

