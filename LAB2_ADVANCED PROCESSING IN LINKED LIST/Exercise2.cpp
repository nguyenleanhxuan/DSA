#include <iostream>
using namespace std;

#define MAX 100

class Queue {
        int arr[MAX];
        int top;
    public:
        Queue() { top = -1; }

        bool encodeElement(int x) {
            if (top >= MAX - 1) return false;
            arr[++top] = x;
            return true;
        }

        bool decodeElement() {
            if (top < 0) return false;
            top--;
            return true;
        }

        int peekElement() {
            if (top < 0) return -1;
            return arr[top];
        }

        bool isEmpty() {
            return top < 0;
        }

        int size() {
            return top + 1;
        }
        void display(){
            for (int i = 0; i < size(); i++){
                cout << arr[i] << " ";
            }
        }
};


int main() {
    Queue s;
    int initial[] = {12, 5, 79, 82, 21};
    for (int i = 0; i < 5; i++) s.encodeElement(initial[i]);
    s.decodeElement();
    s.decodeElement();
    int more[] = {43, 31, 35, 57};
    for (int i = 0; i < 4; i++) s.encodeElement(more[i]);
    s.display();
}

