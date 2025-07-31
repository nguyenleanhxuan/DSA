/*
MaxHeap Implementation
- 2.4: Insert các số từ danh sách và in ra heap sau mỗi lần insert
- 2.5: Nhập dữ liệu từ bàn phím và build heap từ mảng
=======================
Cách chạy chương trình:
Trên Windows PowerShell:
cd Heap
g++ -std=c++11 -Wall -Wextra main.cpp MaxHeap.cpp -o heap_program.exe
.\heap_program.exe

Trên Linux/Mac:
cd Heap
g++ -std=c++11 -Wall -Wextra main.cpp MaxHeap.cpp -o heap_program
./heap_program
*/

#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main() {
    cout << "=== MAX HEAP IMPLEMENTATION ===" << endl << endl;
    
    // Yêu cầu 2.4: Insert các số từ danh sách
    cout << "2.4. MaxHeap Insertion Process" << endl;
    cout << "===============================" << endl;
    
    Heap heap1;
    
    // Danh sách các số cần insert
    int numbers[] = {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Inserting numbers: {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17}" << endl << endl;
    
    for (int i = 0; i < size; i++) {
        cout << "Step " << (i + 1) << ": Inserting " << numbers[i] << endl;
        
        Error_code result = heap1.insertHeap(numbers[i]);
        
        if (result == success) {
            cout << "Insert successful. Current heap: ";
        } else if (result == overflow) {
            cout << "Heap is full! Current heap: ";
        } else {
            cout << "Insert failed. Current heap: ";
        }
        
        heap1.printHeap();
        cout << endl;
    }
    
    cout << "=== Final MaxHeap ===" << endl;
    cout << "Final heap: ";
    heap1.printHeap();
    
    cout << endl << endl;
    
    // Yêu cầu 2.5: Nhập dữ liệu từ bàn phím và build heap
    cout << "=====================================" << endl;
    cout << "2.5. Build Heap from User Input" << endl;
    cout << "=================================" << endl;
    
    Heap heap2;
    int inputArray[max_length];
    int inputSize = 0;
    
    cout << "Enter integers (end with 0):" << endl;
    
    while (inputSize < max_length) {
        int value;
        cout << "Enter number " << (inputSize + 1) << ": ";
        cin >> value;
        
        if (value == 0) {
            break;  // Kết thúc nhập khi gặp 0
        }
        
        inputArray[inputSize] = value;
        inputSize++;
    }
    
    cout << endl << "Input array: ";
    for (int i = 0; i < inputSize; i++) {
        cout << inputArray[i] << " ";
    }
    cout << endl;
    
    // Build heap từ mảng đã nhập
    cout << "Building heap from input array..." << endl;
    Error_code result = heap2.buildHeap(inputArray, inputSize);
    
    if (result == success) {
        cout << "Heap built successfully!" << endl;
    } else if (result == overflow) {
        cout << "Heap overflow! Some elements may not be inserted." << endl;
    } else {
        cout << "Failed to build heap!" << endl;
    }
    
    cout << "Built heap: ";
    heap2.printHeap();
    
    cout << endl << endl;
    
    return 0;
} 