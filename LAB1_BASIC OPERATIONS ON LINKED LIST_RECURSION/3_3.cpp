#include <iostream>
#include <cmath>
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

        int addFirstIfPerfectSquare(int n) {
            if (n < 1) return 0;
            int root = (int)sqrt(n);
            if (root * root == n) {
                addFirst(n);
                return 1;
            }
            return 0;
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
    List* pList = new List;
	int valid = 1;
	char choice;
	int num;
	while (valid) {
		cout << "Do you want to enter a number? (Y/N):";
		cin >> choice;
		if ((choice == 'Y') || (choice == 'y')) {
			cin >> num;
			pList->addFirstIfPerfectSquare(num);
		} else  	
        valid = 0;
   	}

    cout << '{' ;
    pList->display();
    cout << '}' ;
    delete pList;
    return 0;
}