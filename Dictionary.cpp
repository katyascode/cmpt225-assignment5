/*
 * Dictionary.cpp
 * 
 * Class Description: Dictionary data collection ADT class.
 *                    The implementation of this class is based on 
 *                    the hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing.             
 * Class Invariant: Each element stored in this Dictionary is unique (no duplications allowed).
 *
 * Author: AL
 * Date: Last modified: Nov. 2023
 */

// You can add more #include statements if you wish.

#include <iostream>
#include <cstring>
#include "Dictionary.h"  
#include "Profile.h"
#include "UnableToInsertException.h"
#include "ElementAlreadyExistsException.h"
#include "EmptyDataCollectionException.h"
#include "ElementDoesNotExistException.h"

using std::cout;
using std::endl;
using std::__cxx11::stoul;

// Constructor
Dictionary::Dictionary() {}

// Destructor
// Description: Destruct a Dictionary object, releasing heap-allocated memory.
Dictionary::~Dictionary() {
  // Release all heap memory
  if ( hashTable != nullptr ) { 
    for ( unsigned int i = 0; i < CAPACITY; i++ ) 
      if ( hashTable[i] != nullptr ) {      
        delete hashTable[i]; // Delete object of Profile class on heap
        hashTable[i] = nullptr;
      }
    delete [] hashTable;
    hashTable = nullptr;	
  }
}

// Description: Returns the total element count currently stored in Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getElementCount() const {
   return elementCount;
}

// Description: Returns the CAPACITY (size) of the Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getCapacity() const{
   return CAPACITY;
}

// Hash Function
// Description: Hashes the given indexingKey producing a "hash table index".

// Time Efficiency: O(n) * O(n) = O(n^2). 
// Time Efficiency Analysis: Outer for loop iterates over n digits. Inner for loop iterates over n/4 digits, 4 times. 
//                           Thus, the function is of time efficiency O(n^2).
// Space Efficiency: O(1)
// Space Efficiency Analysis: Hash Function does not require another 
//                            data structure (of size n) to operate: O(1)
unsigned int Dictionary::hashFunction( string indexingKey ) {  
  // Approach: folding. 
  
  // Initialize variables for readiability. 
  unsigned int hashCode = 0, chunkSize = 4, length = 16;

  // Begin folding process. 
  for ( unsigned int i = 0; i < length; i += chunkSize ) {
    unsigned int chunkInt = 0; 
    // For each chunk of 4 digits, multiply the value by 10 and add the subsequent digit into the 1's slot. 
    for ( unsigned int j = 0; j < chunkSize; j++ ) {
      chunkInt = chunkInt*10 + (indexingKey[i + j] - '0');
    }
    // Once comptutation of each chunk of 4 is complete, add the chunk to a running total. 
    hashCode += chunkInt; 
  }

  return hashCode % CAPACITY; 
}

// Description: Inserts an element into the Dictionary and increments "elementCount".
//              For this Assignment 5, you do not have to expand the hashTable when it is full. 
// Precondition: newElement must not already be in in the Dictionary.  
// Exception: Throws UnableToInsertException if we cannot insert newElement in the Dictionary.
//            For example, if the operator "new" fails, or Dictionary is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the Dictionary. 
void Dictionary::insert( Profile * newElement )  {
  // Capacity check 
  if (elementCount == CAPACITY) {
    throw UnableToInsertException("Error. Hash table full.");
  }

  // Base case: Check that the element does not already exist in the hash table by computing its hash value. 
  unsigned int hashCode = hashFunction( newElement->getUserName() );

  if ( hashTable[hashCode] == nullptr ) {
    // Insert the element
    hashTable[hashCode] = newElement; 
    elementCount++;

  } else if ( hashTable[hashCode]->getUserName() == newElement->getUserName() ) {
    // Profile exists in calculated index, user duplicate found. Abort 
    throw ElementAlreadyExistsException("Element already exists. Cannot insert.");
  } else if ( hashTable[hashCode] != nullptr ) {
    // Profile exists in calculated index, not a duplicate. Find an empty index.

    // Beginning linear search. At each probe, check that the element does not already exist in the given slot. 
    for (unsigned int i = 0; i < CAPACITY; i++) {
      hashCode = (hashCode + i + 1) % CAPACITY;

      if (hashTable[hashCode] == nullptr) {
        // Insert element at the empty slot
        hashTable[hashCode] = newElement;
        elementCount++;
        break;  // Exit the loop after successful insertion
      } else if (hashTable[hashCode]->getUserName() == newElement->getUserName()) {
        // Profile with the same username found, throw an exception
        throw ElementAlreadyExistsException("Element already exists. Cannot insert.");
      }
    }  
      
  }

  return;
}


// Description: Returns a pointer to the target element if found.
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
// Exception: Throws ElementDoesNotExistException if target is not found in the Dictionary.
Profile * Dictionary::get( Profile & target )  {
  // Check for capacity. 
  if (elementCount == 0) {
    throw EmptyDataCollectionException("Error: element cannot be found in an empty dataset");
  } 

  // Compute hash index 
  unsigned int hashCode = hashFunction( target.getUserName() );


  if ( hashTable[hashCode]->getUserName() == target.getUserName() ) {
    // Element found in computed index. Return pointer stored in index.
    return hashTable[hashCode];

  } else if ( hashTable[hashCode] == nullptr ) {
    // Element is not in the table 
    throw ElementDoesNotExistException("Element not found");

  } else {
    // Perform a linear search 
    for ( unsigned int i = 0; i < CAPACITY; i++ ) {
      hashCode = ( hashCode + i + 1 ) % CAPACITY;

      if ( hashTable[hashCode]->getUserName() == target.getUserName() ) {
        return hashTable[hashCode];
      }
    }
  }

  return nullptr; 
}
   
// Description: Prints all elements stored in the Dictionary (unsorted).
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
void Dictionary::printDictionary()  const {
  if ( elementCount == 0 ) 
     throw EmptyDataCollectionException("In printDictionary(): hashTable is empty.");

  cout << endl << "Printing the Dictionary with " << this->elementCount << " elements: " << endl;
  for (unsigned int index = 0; index < CAPACITY; index++) {
    if ( hashTable[index] != nullptr ) 
		cout << "HashTable[" << index << "] = " << *(hashTable[index]) << endl; 
  }   
  return;
}
