/*
 * List.h
 * 
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate 
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: May 2017
 * Author: AL
 */

#pragma once
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:	
// We must complete this section
	const int NUMBER_OF_DIGITS = 10;
	Patient* patientArr[10]; //Ten digits
	int sizes[10]; //Ten digits
	int elements[10]; //Ten digits
	int totalElementCount; //Must return in O(1), so we must count the total as we input
 
public:

// We must add at least 1 constructor and a destructor
	
	// Default constructor
	List(){
		const int DEFAULT_ARRAY_SIZE = 1;
		const int EMPTY = 0;

		for(int i = 0; i < NUMBER_OF_DIGITS; ++i){
			sizes[i] = DEFAULT_ARRAY_SIZE;
			patientArr[i] = new Patient[DEFAULT_ARRAY_SIZE];
			elements[i] = EMPTY;
		}
	};

	~List(){
		for(int i = 0; i < NUMBER_OF_DIGITS; ++i){
			delete[] patientArr[i];
		}
	}

// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate 
    //              a new element. This is done unbeknown to the client code.
	//              If the insertion is successful, true is returned otherwise, false is returned.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	//              If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);
   
	// Description: Prints all n elements stored in List in sort order and does so in O(n).
	void printList();
	
// *** End of Public Interface ***

}; // end List