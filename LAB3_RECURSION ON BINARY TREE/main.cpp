#include <stdio.h>
using namespace std;
#include <iostream>
#include "TreeSample.cpp"
int main()
{
    Tree<string> aTree;
    TreeNode<string> *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;

    aTree.insertAt(NULL, true, "+", p1);
    aTree.insertAt(p1, true, "-", p2);
    aTree.insertAt(p1, false, "*", p3);
    aTree.insertAt(p2, true, "12", p4);
    aTree.insertAt(p2, false, "7", p5);
    aTree.insertAt(p3, true, "3", p6);
    aTree.insertAt(p3, false, "/", p7);
    aTree.insertAt(p7, true, "16", p8);
    aTree.insertAt(p7, false, "4", p9);

    cout << "\n";
    cout << "=========================================================\n";
    cout << "Exercise 4.2\n";
    cout << "Left Node Right: ";
    aTree.printLNR();
    cout << "\n";

    cout << "Left Right Node: ";
    aTree.printLRN();
    cout << "\n";

    cout << "Node Left Right: ";
    aTree.printNLR();
    cout << "\n";

    cout << "Node Right Left: ";
    aTree.printNRL();
    cout << "\n";

    cout << "Right Node Left: ";
    aTree.printRNL();
    cout << "\n";

    cout << "Right Left Node: ";
    aTree.printRLN();
    cout << "\n";

    cout << "\n";
    cout << "=========================================================\n";
    cout << "Exercise 4.3\n";
    cout << "Height of the tree: " << aTree.height() << "\n";

    cout << "\n";
    cout << "=========================================================\n";
    cout << "Exercise 4.4\n";
    cout << "Is the tree balanced? " << (aTree.is_balanced() ? "Yes" : "No") << "\n";

    cout << "\n";
    cout << "=========================================================\n";
    cout << "Exercise 4.5\n";
    cout << "What node do you want to swap left and right subtrees? (Enter value): ";
    string value;
    cin >> value;
    TreeNode<string> *nodeToSwap = aTree.getNode(value);
    if (nodeToSwap)
    {
        cout << "Swapping left and right subtrees at node " << value << "...\n";
        aTree.swap_left_right(nodeToSwap);
    }
    else
    {
        cout << "Node with value '" << value << "' not found.\n";
    }

    cout << "Node Left Right - After swapping: ";
    aTree.printNLR();
    cout << "\n";

    cout << "\n";
    cout << "=========================================================\n";
    cout << "Exercise 4.6\n";
    cout << "Number of leaves: " << aTree.count_leaves() << "\n";

    cout << "\n";
    cout << "=========================================================\n";

    cout << "Exercise 4.7\n";
    cout << "Deleting leaves...\n";
    aTree.delete_leaves();
    cout << "Node Left Right After Deleting All Leaves: ";
    aTree.printNLR();
    cout << "\n";
    cout << "\n";
    cout << "=========================================================\n";

    return 0;
}