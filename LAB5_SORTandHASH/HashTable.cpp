#ifndef __HASHTABLE__CPP__
#define __HASHTABLE__CPP__

#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
HashTable<T>::HashTable()
{
	numBucks = 11; // should be a prime number
	sizeBuck = 3;
	int hashSize = numBucks * sizeBuck;
	hashArray = new hashItem<T>[hashSize];
	for (int i = 0; i < hashSize; i++)
		hashArray[i].occupied = false;
	for (int i = 0; i < OVERFLOW_SIZE; i++)
		overBuck[i].occupied = false;
}
//---------------------------------------------------------
template <class T>
HashTable<T>::HashTable(int num, int size)
{
	numBucks = num;
	sizeBuck = size;
	int hashSize = numBucks * sizeBuck;
	hashArray = new hashItem<T>[hashSize];
	for (int i = 0; i < hashSize; i++)
		hashArray[i].occupied = false;
	for (int i = 0; i < OVERFLOW_SIZE; i++)
		overBuck[i].occupied = false;
}
//---------------------------------------------------------
template <class T>
HashTable<T>::~HashTable()
{
	delete[] hashArray;
	cout << "Destructor called\n";
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::hashFunc(int key, int funcID)
{
	if (funcID == 0)
		return moduloDivision(key);
	else if (funcID == 1)
		return midSquare(key);
	else if (funcID == 2)
		return pseudoRandom(key);
	else
		return -1;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::moduloDivision(int key)
{
	if (key < 0)
		key = -key;
	return key % numBucks;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::midSquare(int key)
{
	// Mid-square hash function
	// Square the key and extract middle digits
	if (key < 0)
		key = -key;
	
	// Square the key
	long long squared = (long long)key * key;
	
	// Convert to string to extract middle digits
	string squaredStr = to_string(squared);
	
	// If squared number has less than 3 digits, return modulo
	if (squaredStr.length() < 3) {
		return squared % numBucks;
	}
	
	// Extract middle digits (remove first and last digit)
	// For even length, take middle 2 digits
	// For odd length, take middle 3 digits
	int startPos, length;
	if (squaredStr.length() % 2 == 0) {
		// Even length: take middle 2 digits
		startPos = (squaredStr.length() - 2) / 2;
		length = 2;
	} else {
		// Odd length: take middle 3 digits
		startPos = (squaredStr.length() - 3) / 2;
		length = 3;
	}
	
	string middleDigits = squaredStr.substr(startPos, length);
	int result = stoi(middleDigits);
	
	return result % numBucks;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::pseudoRandom(int key)
{
	// Pseudo-random hash function using two prime numbers
	// Using prime numbers 17 and 31 for better distribution
	const int prime1 = 17;
	const int prime2 = 31;
	
	if (key < 0)
		key = -key;
	
	// Apply pseudo-random transformation
	// h(k) = (k * prime1 + prime2) % numBucks
	int hashValue = (key * prime1 + prime2) % numBucks;
	
	return hashValue;
}
//---------------------------------------------------------
template <class T>
bool HashTable<T>::insert(Record<T> data, int funcID)
{
	int hashVal = hashFunc(data.key, funcID);
	int bucketStart = hashVal * sizeBuck;
	
	// First, try to insert in the main bucket
	for (int i = 0; i < sizeBuck; i++)
	{
		int slot = bucketStart + i;
		if (hashArray[slot].occupied == false)
		{
			hashArray[slot].data = data;
			hashArray[slot].occupied = true;
			cout << "Inserted in main bucket at slot " << slot << endl;
			return true;
		}
		// Check if key already exists
		if (hashArray[slot].data.key == data.key)
		{
			cout << "Key already exists in main bucket" << endl;
			return false;
		}
	}
	
	// If bucket is full, try overflow area
	for (int i = 0; i < OVERFLOW_SIZE; i++)
	{
		if (overBuck[i].occupied == false)
		{
			overBuck[i].data = data;
			overBuck[i].occupied = true;
			cout << "Inserted in overflow area at slot " << i << endl;
			return true;
		}
		// Check if key already exists in overflow
		if (overBuck[i].data.key == data.key)
		{
			cout << "Key already exists in overflow area" << endl;
			return false;
		}
	}
	
	cout << "Hash table is full (both main and overflow areas)" << endl;
	return false;
}
//---------------------------------------------------------
template <class T>
bool HashTable<T>::search(int key, T &value, int funcID)
{
	int hashVal = hashFunc(key, funcID);
	int bucketStart = hashVal * sizeBuck;
	
	// First, search in the main bucket
	for (int i = 0; i < sizeBuck; i++)
	{
		int slot = bucketStart + i;
		if (hashArray[slot].occupied == true && hashArray[slot].data.key == key)
		{
			value = hashArray[slot].data.value;
			cout << "Found in main bucket at slot " << slot << endl;
			return true;
		}
	}
	
	// If not found in main bucket, search in overflow area
	for (int i = 0; i < OVERFLOW_SIZE; i++)
	{
		if (overBuck[i].occupied == true && overBuck[i].data.key == key)
		{
			value = overBuck[i].data.value;
			cout << "Found in overflow area at slot " << i << endl;
			return true;
		}
	}
	
	cout << "Key not found" << endl;
	return false;
}

#endif //__HASHTABLE__CPP__
