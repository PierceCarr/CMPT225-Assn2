/*
 * List.cpp 
 * 
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate 
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: June 2017
 * Author: Pierce Carruthers And Sina Khalili
 */

//#pragma once
#include "List.h"
#include <iostream>


using namespace std;



int List::getElementCount() const{
	int sum = 0 ; 
	const int NUMBER_OF_DIGITS = 10;
	for(int i = 0; i < NUMBER_OF_DIGITS; i++){
		sum+=elements[i];
	}
	return sum;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate 
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
bool List::insert(const Patient& newElement){
	string careCard = newElement.getCareCard();
	const int FIRST_CHARACTER = 0;
	char firstChar = careCard[FIRST_CHARACTER];

	const int ASCII_ZERO = 48;
	int firstDigit = firstChar - ASCII_ZERO;

	// elements[firstDigit]+=1; //We haven't added the element yet or decided whether it already exists, so why increase now?
	// cout << "The array for the number " << firstDigit << " now has " << elements[firstDigit] << " elements"<< endl; 

	//Check to see if element already exists in registry
	bool lastEl = true;
	int i = 0;
	for(i = 0; i < elements[firstDigit]; i++){
		if(patientArr[firstDigit][i] == newElement){
			cout << "Patient already exists, you FOOL!" << endl; 
			return false;
		}
		if(patientArr[firstDigit][i] > newElement){ // Isn't this comparing strings?? What does that do? Seems to work in ideone though.
			//cout << "Caught at index " << i << endl; 
			lastEl = false;
			break;
		}
	}

	//Check to see if more space is needed in element's digit array

	elements[firstDigit]+=1; //We're adding it at this point

	if(elements[firstDigit] > sizes[firstDigit]){ //Changed > to >=, because there is no room in an equal sized array either

		//cout << "I now will try to create a new array" << endl;
		const int DOUBLE_SIZE = 2;
		Patient* newArr = new Patient[sizes[firstDigit] * DOUBLE_SIZE]; //IF THERE'S A SEGFAULT BUG, IT ORIGINATES HERE
		sizes[firstDigit]*=2;
		//cout << "I have made a new array of the size " << sizes[firstDigit] << endl;

		if(!lastEl){
			int j = 0;
			for( j = 0; j < i; j++){
				newArr[j] = patientArr[firstDigit][j];
			}

			newArr[j] = newElement;
			j++;

			for(j = j; j<elements[firstDigit]; j++){
				newArr[j] = patientArr[firstDigit][j-1];
			}
			delete[] patientArr[firstDigit]; //Added this
			patientArr[firstDigit] = newArr;
			return true;
		}	

		else{
			for(int q = 0; q < elements[firstDigit]-1; q++){
				newArr[q] = patientArr[firstDigit][q];
			}
			delete[] patientArr[firstDigit]; //Added this
			patientArr[firstDigit] = newArr;
		}
		//newArr[digitArrCount + 1] = newElement;
	}
	
	if(lastEl){
		//cout << "I made it this far" << endl; 
		patientArr[firstDigit][elements[firstDigit]-1]= newElement;
		return true; 
	}

	if(elements[firstDigit]<sizes[firstDigit] && !lastEl){
		//These two loops find where to put the new element, and then put it there.
		//If there is enough room, that is. 
			int amountToBeMoved = elements[firstDigit] - i - 1; 
			int elementToBeCopiedOnto = elements[firstDigit]-1;
			for(int ii = 0; ii<amountToBeMoved; ii++){
				patientArr[firstDigit][elementToBeCopiedOnto] = patientArr[firstDigit][elementToBeCopiedOnto-1];
			}
			patientArr[firstDigit][i] = newElement;
			return true;			
		}
	return false;

}


// Description: Remove an element. 
//              If the removal is successful, true is returned otherwise, false is returned.
// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ){
	string card = toBeRemoved.getCareCard();
	int cardNumberFirstDigit;
	const int ASCII_ZERO = 48;
	char firstDigit = card[0];
	cardNumberFirstDigit = firstDigit - ASCII_ZERO;

	int i = 0; 
	for(i = 0; i < elements[cardNumberFirstDigit]; ++i){
		if(patientArr[cardNumberFirstDigit][i] == toBeRemoved){
			
			for(int ii = i+1; ii < elements[cardNumberFirstDigit] ; ++ii){ 
				patientArr[cardNumberFirstDigit][ii-1] = patientArr[cardNumberFirstDigit][ii];
			}
			elements[cardNumberFirstDigit]--;
			return true;
		}

	}
	return false;
}

// Description: Remove all elements.
void List::removeAll(){
	const int EMPTY = 0;
	const int NUMBER_OF_DIGITS = 10;
	for(int i = 0 ; i < NUMBER_OF_DIGITS ; i ++){
		elements[i] = EMPTY;
	}
}

// Description: Search for target element and returns a pointer to it if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
	string card = target.getCareCard();
	int cardNumberFirstDigit;
	const int ASCII_ZERO = 48;
	char firstDigit = card[0];
	cardNumberFirstDigit = firstDigit - ASCII_ZERO;

	//cout << "now searching array " << cardNumberFirstDigit << endl;
	int i = 0; 
	for(i = 0; i < elements[cardNumberFirstDigit]; ++i){
			/*cout << "comparing " << patientArr[cardNumberFirstDigit][i].getCareCard() << 
			"to" << target.getCareCard() << endl;*/
		if(patientArr[cardNumberFirstDigit][i] == target){
			return &patientArr[cardNumberFirstDigit][i];
		}
	}	
	return NULL;
}

// Description: Prints all n elements stored in List in sort order and does so in O(n).
void List::printList(){
	int i = 0; 
	int currDigit = 0;
	const int NUMBER_OF_DIGITS = 10;
	//int size = elementCountZero;
	if(this->getElementCount() == 0){
		cout << "There are no patients! What kind of a clinic are you running here?" << endl; 
		return;
	}
	//patientArr[currDigit][9].printPatient();
	while(currDigit < NUMBER_OF_DIGITS){
		for (i = 0; i< elements[currDigit]; ++i){
			patientArr[currDigit][i].printPatient();
		}
		++currDigit;
	}
}	