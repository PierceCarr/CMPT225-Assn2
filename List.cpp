//List.cpp Hey Guys it's me 

//#pragma once
#include "List.h"
#include <iostream>


using namespace std;

/**
Bug List:
-Spaghetti errors when I try to 'display registered patients' and patients exist in registry.
-When I search for a patient that exists, spaghetti is outputted before patient is correctly displayed.
-Spaghetti before a patient is correctly removed.
-Spaghetti before program correctly exits.
**/


int List::getElementCount() const{
	int sum = 0 ; 
	for(int i = 0; i < 10; i++){
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
	const int FIRST_CHARACTER = 0;
	string careCard = newElement.getCareCard();
	char firstChar = careCard[FIRST_CHARACTER];

	const int ASCII_ZERO = 48;
	int firstDigit = firstChar - ASCII_ZERO;

	elements[firstDigit]+=1;
	cout << "The array for the number " << firstDigit << " now has " << elements[firstDigit] << " elements"<< endl; 


	bool lastEl = true;
	int i = 0;
	for(i=0;i<elements[firstDigit]-1; i++){
		if(patientArr[firstDigit][i] == newElement){
			cout << "Element already exists, you FOOL!" << endl; 
			return false;
		}
		if(patientArr[firstDigit][i] > newElement){
			lastEl = false;
			break;
		}
	}

	if(elements[firstDigit]>sizes[firstDigit]){

		const int DOUBLE_SIZE = 2;
		Patient* newArr = new Patient[sizes[firstDigit] * DOUBLE_SIZE]; //IF THERE'S A SEGFAULT BUG, IT ORIGINATES HERE
		
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
			patientArr[firstDigit] = newArr;
			return true;
		}	

		else{
			for(int q = 0; q < elements[firstDigit]-1; q++){
				newArr[q] = patientArr[firstDigit][q];
			}
			patientArr[firstDigit] = newArr;
		}
		//newArr[digitArrCount + 1] = newElement;
	}
	
	if(lastEl){
		cout << "I made it this far" << endl; 
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

	cout << "now searching array " << cardNumberFirstDigit << endl;
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
	//int size = elementCountZero;
	if(this->getElementCount() == 0){
		cout << "There are no patients! What kind of a clinic are you running here?" << endl; 
	}
	while(currDigit < 10){
		for (i = 0; i< elements[currDigit]; ++i){
			patientArr[currDigit][i].printPatient();
		}
		++currDigit;
	}
}	