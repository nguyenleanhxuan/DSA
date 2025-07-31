#ifndef __MAXHEAP__CPP__
#define __MAXHEAP__CPP__

#include <iostream>
#include "MaxHeap.h"

using namespace std;

//---------------------------------------------------------				
Heap::Heap()
{
	count = 0;
}
//---------------------------------------------------------
void Heap::ReheapUp(int position)
{
	if(position > 0)
	{
		int parent = (position - 1) / 2;
		if(data[position] > data[parent])
		{
			swap(position, parent);
			ReheapUp(parent);
		}
	}
}
//---------------------------------------------------------
void Heap::ReheapDown(int position, int lastPosition)
{
	int leftChild = 2 * position + 1;
	int rightChild = 2 * position + 2;
	int largest = position;
	
	// Tìm child lớn nhất
	if (leftChild <= lastPosition && data[leftChild] > data[largest])
		largest = leftChild;
	
	if (rightChild <= lastPosition && data[rightChild] > data[largest])
		largest = rightChild;
	
	// Nếu largest không phải là position hiện tại, swap và tiếp tục
	if (largest != position) {
		swap(position, largest);
		ReheapDown(largest, lastPosition);
	}
}
//---------------------------------------------------------
void Heap::swap(int low, int high)
{
	int temp;
	temp = data[low];
	data[low] = data[high];
	data[high] = temp;
}
//---------------------------------------------------------
bool Heap::full()
{
	return (count == max_length);
}
//---------------------------------------------------------
bool Heap::empty()
{
	return (count == 0);
}
//---------------------------------------------------------
int Heap::size()
{
	return count;
}
//---------------------------------------------------------
void Heap::clear()
{
	count = 0;
}
//---------------------------------------------------------
Error_code Heap::insertHeap(int dataIn)
{
	if(full()) return overflow;
	else
	{
		data[count] = dataIn;
		ReheapUp(count);
		count++;
		return success;
	}
}
//---------------------------------------------------------
Error_code Heap::deleteHeap(int &dataOut)
{
	if (empty()) return underflow;
	else {
		dataOut = data[0];  // Lấy root (phần tử lớn nhất)
		data[0] = data[count - 1];  // Đưa phần tử cuối lên root
		count--;
		
		if (count > 0) {
			ReheapDown(0, count - 1);  // ReheapDown từ root
		}
		
		return success;
	}
}
//---------------------------------------------------------
Error_code Heap::buildHeap(int listData[], int size)
{
	count = 0;
	while(!full() && count < size)
	{
		data[count] = listData[count];
		ReheapUp(count);
		count++;
	}
	if(count < size) return overflow;
	else return success;
}
//---------------------------------------------------------
void Heap::printHeap()
{
	for(int i = 0; i < count; i++)
		cout << data[i] << " ";
	cout << endl;
}
				
#endif //__MAXHEAP__CPP__
