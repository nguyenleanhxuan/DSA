//#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;
#include "HashTable.cpp"

int main()
{
    cout << "=== Hash Table Test Program ===" << endl;
    cout << "Testing all three hash functions with improved insert/search methods" << endl << endl;
    
    // Test data
    struct TestData {
        int key;
        string value;
    };
    
    TestData testData[] = {
        {123, "Alice"},
        {456, "Bob"},
        {789, "Charlie"},
        {234, "David"},
        {567, "Eve"},
        {890, "Frank"},
        {345, "Grace"},
        {678, "Henry"},
        {901, "Ivy"},
        {432, "Jack"},
        {765, "Kate"},
        {198, "Liam"},
        {543, "Mia"},
        {876, "Noah"},
        {321, "Olivia"}
    };
    
    int numTests = sizeof(testData) / sizeof(testData[0]);
    
    // Test each hash function
    for (int funcID = 0; funcID < 3; funcID++)
    {
        cout << "\n=== Testing Hash Function " << funcID << " ===" << endl;
        string funcName;
        switch(funcID) {
            case 0: funcName = "Modulo Division"; break;
            case 1: funcName = "Mid-Square"; break;
            case 2: funcName = "Pseudo-Random"; break;
        }
        cout << "Function: " << funcName << endl;
        
        // Create hash table
        HashTable<string> ht(7, 3); // 7 buckets, 3 slots per bucket
        
        // Insert test data
        cout << "\n--- Inserting Data ---" << endl;
        for (int i = 0; i < numTests; i++)
        {
            Record<string> record;
            record.key = testData[i].key;
            record.value = testData[i].value;
            
            cout << "Inserting key=" << record.key << ", value=" << record.value << ": ";
            ht.insert(record, funcID);
        }
        
        // Search for some keys
        cout << "\n--- Searching Data ---" << endl;
        int searchKeys[] = {123, 456, 789, 999, 234, 567};
        int numSearches = sizeof(searchKeys) / sizeof(searchKeys[0]);
        
        for (int i = 0; i < numSearches; i++)
        {
            string foundValue;
            cout << "Searching for key=" << searchKeys[i] << ": ";
            if (ht.search(searchKeys[i], foundValue, funcID))
            {
                cout << "Found value: " << foundValue << endl;
            }
        }
        
        cout << "\n" << string(50, '-') << endl;
    }
    
    // Test collision handling
    cout << "\n=== Testing Collision Handling ===" << endl;
    cout << "Using Modulo Division hash function" << endl;
    
    HashTable<string> collisionTest(3, 2); // 3 buckets, 2 slots per bucket (small to force collisions)
    
    // Insert keys that will likely collide
    TestData collisionData[] = {
        {3, "First"},
        {6, "Second"},
        {9, "Third"},
        {12, "Fourth"},
        {15, "Fifth"},
        {18, "Sixth"},
        {21, "Seventh"},
        {24, "Eighth"},
        {27, "Ninth"},
        {30, "Tenth"}
    };
    
    cout << "\n--- Inserting with Collisions ---" << endl;
    for (int i = 0; i < 10; i++)
    {
        Record<string> record;
        record.key = collisionData[i].key;
        record.value = collisionData[i].value;
        
        cout << "Inserting key=" << record.key << ", value=" << record.value << ": ";
        collisionTest.insert(record, 0); // Use modulo division
    }
    
    cout << "\n--- Searching with Collisions ---" << endl;
    for (int i = 0; i < 10; i++)
    {
        string foundValue;
        cout << "Searching for key=" << collisionData[i].key << ": ";
        if (collisionTest.search(collisionData[i].key, foundValue, 0))
        {
            cout << "Found value: " << foundValue << endl;
        }
    }
    
    cout << "\n=== Test Complete ===" << endl;
    return 0;
} 