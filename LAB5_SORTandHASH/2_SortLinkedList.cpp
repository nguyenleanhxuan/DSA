#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Utility: Print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility: Push front
void pushFront(ListNode *&head, int val)
{
    ListNode *node = new ListNode(val);
    node->next = head;
    head = node;
}

// Merge two sorted lists (for Merge Sort)
ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Split list into two halves
void split(ListNode *head, ListNode **front, ListNode **back)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *front = head;
    *back = slow->next;
    slow->next = nullptr;
}

// Merge Sort for Linked List
void mergeSort(ListNode *&head)
{
    if (!head || !head->next)
        return;
    ListNode *a;
    ListNode *b;
    split(head, &a, &b);
    mergeSort(a);
    mergeSort(b);
    head = merge(a, b);
}

// Partition for Quick Sort (returns new head and tail)
pair<ListNode *, ListNode *> partition(ListNode *head, ListNode *end, ListNode **newHead, ListNode **newEnd)
{
    ListNode *pivot = end;
    ListNode *prev = nullptr, *cur = head, *tail = pivot;
    *newHead = nullptr;
    while (cur != pivot)
    {
        if (cur->val < pivot->val)
        {
            if (!*newHead)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            ListNode *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (!*newHead)
        *newHead = pivot;
    *newEnd = tail;
    return {pivot, tail};
}

// Quick Sort recursive
ListNode *quickSortRecur(ListNode *head, ListNode *end)
{
    if (!head || head == end)
        return head;
    ListNode *newHead = nullptr, *newEnd = nullptr;
    auto [pivot, tail] = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        ListNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;
        newHead = quickSortRecur(newHead, tmp);
        tmp = newHead;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

// Quick Sort for Linked List
void quickSort(ListNode *&head)
{
    ListNode *end = head;
    while (end && end->next)
        end = end->next;
    head = quickSortRecur(head, end);
}

int main()
{
    // Example: 64, 34, 25, 12, 22, 11, 90
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Merge Sort
    ListNode *head1 = nullptr;
    for (int i = n - 1; i >= 0; --i)
        pushFront(head1, arr[i]);
    mergeSort(head1);
    cout << "MergeSort - Sorted linked list:\n";
    printList(head1);

    // Quick Sort
    ListNode *head2 = nullptr;
    for (int i = n - 1; i >= 0; --i)
        pushFront(head2, arr[i]);
    quickSort(head2);
    cout << "QuickSort - Sorted linked list:\n";
    printList(head2);

    return 0;
}