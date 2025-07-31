/*
AVL Tree Implementation
- 2.1: Insert các số từ danh sách và in ra cây sau mỗi lần insert
- 2.2: Sửa đổi method avl_insert để chấp nhận dữ liệu trùng lặp
- 2.3: Hoàn thành method avl_remove để xóa node từ AVL tree
=======================
Cách chạy chương trình:
Trên Windows PowerShell:
cd AVL
g++ -std=c++11 -Wall -Wextra main.cpp AVL.cpp -o avl_program.exe
.\avl_program.exe

Trên Linux/Mac:
cd AVL
g++ -std=c++11 -Wall -Wextra main.cpp AVL.cpp -o avl_program
./avl_program
*/

#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    cout << "=== AVL TREE IMPLEMENTATION ===" << endl << endl;
    
    // Yêu cầu 2.1: Insert các số từ danh sách
    cout << "2.1. AVL Tree Insertion Process" << endl;
    
    AVL_tree tree1;
    
    // Danh sách các số cần insert
    int numbers[] = {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Inserting numbers: {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17}" << endl << endl;
    
    for (int i = 0; i < size; i++) {
        cout << "Step " << (i + 1) << ": Inserting " << numbers[i] << endl;
        
        Error_code result = tree1.insert(numbers[i]);
        
        if (result == success) {
            cout << "Insert successful. Current tree (LNR traversal): ";
        } else if (result == dupplicated) {
            cout << "Duplicate value inserted to right subtree. Current tree (LNR traversal): ";
        } else {
            cout << "Insert failed. Current tree (LNR traversal): ";
        }
        
        tree1.printLNR();
        cout << endl;
    }
    
    cout << "=== Final AVL Tree ===" << endl;
    cout << "Final tree (LNR traversal): ";
    tree1.printLNR();
    
    cout << endl << endl;
    
    // Yêu cầu 2.2: Test với dữ liệu trùng lặp
    cout << "=====================================" << endl;
    cout << "2.2. Testing Duplicate Data Handling" << endl;
    
    AVL_tree tree2;
    
    // Test với dữ liệu trùng lặp
    int test_numbers[] = {50, 30, 70, 30, 50, 70, 30, 50, 70};
    int test_size = sizeof(test_numbers) / sizeof(test_numbers[0]);
    
    cout << "Inserting numbers with duplicates: {50, 30, 70, 30, 50, 70, 30, 50, 70}" << endl << endl;
    
    for (int i = 0; i < test_size; i++) {
        cout << "Step " << (i + 1) << ": Inserting " << test_numbers[i] << endl;
        
        Error_code result = tree2.insert(test_numbers[i]);
        
        if (result == success) {
            cout << "Insert successful. Current tree (LNR traversal): ";
        } else if (result == dupplicated) {
            cout << "Duplicate value inserted to right subtree. Current tree (LNR traversal): ";
        } else {
            cout << "Insert failed. Current tree (LNR traversal): ";
        }
        
        tree2.printLNR();
        cout << endl;
    }
    
    cout << "=== Final AVL Tree with Duplicates ===" << endl;
    cout << "Final tree (LNR traversal): ";
    tree2.printLNR();
    
    cout << endl << endl;
    
    // Yêu cầu 2.3: Test method remove
    cout << "=====================================" << endl;
    cout << "2.3. Testing AVL Tree Remove Operation" << endl;
    
    AVL_tree tree3;
    
    // Tạo một cây AVL đơn giản để test remove
    int remove_test[] = {50, 30, 70, 20, 40, 60, 80};
    int remove_size = sizeof(remove_test) / sizeof(remove_test[0]);
    
    cout << "Building AVL tree with: {50, 30, 70, 20, 40, 60, 80}" << endl;
    for (int i = 0; i < remove_size; i++) {
        tree3.insert(remove_test[i]);
    }
    
    cout << "Initial tree (LNR traversal): ";
    tree3.printLNR();
    cout << endl;
    
    // Test remove các node khác nhau
    int remove_values[] = {20, 50, 70, 30};
    int remove_count = sizeof(remove_values) / sizeof(remove_values[0]);
    
    for (int i = 0; i < remove_count; i++) {
        cout << "Removing " << remove_values[i] << "..." << endl;
        
        Error_code result = tree3.remove(remove_values[i]);
        
        if (result == success) {
            cout << "Remove successful. Current tree (LNR traversal): ";
        } else if (result == not_present) {
            cout << "Value not found in tree. Current tree (LNR traversal): ";
        } else {
            cout << "Remove failed. Current tree (LNR traversal): ";
        }
        
        tree3.printLNR();
        cout << endl;
    }
    
    cout << "=== Final AVL Tree after removals ===" << endl;
    cout << "Final tree (LNR traversal): ";
    tree3.printLNR();
    
    return 0;
} 