#ifndef __LIST__CPP__
#define __LIST__CPP__

#include "List.h"

template<class Node_entry>
Node<Node_entry>::Node() {
	next = NULL;
}
//---------------------------------------------------------
template<class Node_entry>
Node<Node_entry>::Node(Node_entry item,Node<Node_entry> * link) {
	entry = item;
	next = link;
}
//---------------------------------------------------------
template<class List_entry>
List<List_entry>::List() {
	head = NULL;
	count = 0;
}
//---------------------------------------------------------
template<class List_entry>
List<List_entry>::~List() {
	List_entry temp;
	while(!empty())
		remove(0, temp);
}
//---------------------------------------------------------
template<class List_entry>
Node<List_entry> * List<List_entry>::set_position(int position) {
	Node<List_entry> *q = head;
	for(int i = 0; i < position; i++) q = q->next;
	return q;
}
//---------------------------------------------------------
template<class List_entry>
void List<List_entry>::clear() {
	List_entry temp;
	while(!empty())
		remove(0, temp);
}
//---------------------------------------------------------
template<class List_entry>
int List<List_entry>::size() {
	return count;
}
//---------------------------------------------------------
template<class List_entry>
Error_code List<List_entry>::insert(int position, List_entry x) {
	if(position < 0 || position > count) return rangeerror;
	Node<List_entry> *new_node, *previous, *following;
	if(position > 0) {
		previous = set_position(position - 1);
		following = previous->next;
	} else {
		following = head;
	}
	new_node = new Node<List_entry>(x, following);
	if(new_node == NULL)
		return overflow;
	if(position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}
//---------------------------------------------------------
template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (position < 0 || position >= count) return rangeerror;
    Node<List_entry> *old_node, *previous;
    if (position == 0) {
        old_node = head;
        head = head->next;
    } else {
        previous = set_position(position - 1);
        old_node = previous->next;
        previous->next = old_node->next;
    }
    x = old_node->entry;
    delete old_node;
    count--;
    return success;
}

//---------------------------------------------------------
template<class List_entry>
bool List<List_entry>::empty() {
	return (count == 0);
}

//---------------------------------------------------------
template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x)
{
    if (position < 0 || position >= count) return rangeerror;
    Node<List_entry> *current = set_position(position);
    x = current->entry;
    return success;
}

//---------------------------------------------------------
template <class List_entry>
void List<List_entry>::printAll()
{
    Node<List_entry>* pTemp = head;
	while (pTemp != NULL) {
		std::cout << pTemp->entry << " ";
		pTemp = pTemp->next;
	}
}
#endif 