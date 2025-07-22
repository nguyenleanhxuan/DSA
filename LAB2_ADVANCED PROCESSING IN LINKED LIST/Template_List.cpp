#include <iostream>
using namespace std;

template<class NodeType>
class Node {
    public:
		NodeType data; 
	 	Node<NodeType> * next;
}; 

//interface part
template<class ListType>
class List {
    private:
		int count;
		Node<ListType>* pHead;
    public:
		List() ;
		void addFirst(ListType) ;
		void display();
		~List(); 	
};

//implementation part
template<class ListType>
List<ListType>::List() {pHead = NULL; count = 0;}

template<class ListType>
void List<ListType>::addFirst(ListType newdata) {
	Node<ListType>* pTemp = new Node<ListType>;
	pTemp->data = newdata;
	pTemp->next = pHead;
	pHead = pTemp;
	count++;
}

template<class ListType>
void List<ListType>::display() {
	Node<ListType>* pTemp = pHead;
	while (pTemp != NULL) {
		cout << pTemp->data << "\t";
		pTemp = pTemp->next;
	}
}

template<class ListType>
List<ListType>::~List()  {
	Node<ListType>* pTemp = pHead;
	while (pTemp != NULL) {
		pTemp = pTemp->next;
		delete pHead;
		pHead = pTemp;
	}
}

// void main() {
// 	Node<int> intNode;
// 	intNode.data = 3;
// 	intNode.next = NULL;

// 	Node<float> floatNode;
// 	floatNode.data = 5.2;
// 	floatNode.next = NULL;
// };

void main() {
	List<int> intList;
	intList.addFirst(5);
	intList.addFirst(3);
	intList.addFirst(2);
	intList.display();

	List<float> floatList;
	floatList.addFirst(5.2);
	floatList.addFirst(3.14);
	floatList.addFirst(2.13);
	floatList.display();
}
