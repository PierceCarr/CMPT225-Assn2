//List.cpp Hey Guys it's me 

#pragma once
#include "List.h"
#include <sstream>

using namespace std;


int List::getElementCount() const{
	return elementCountZero + elementCountOne + elementCountTwo + elementCountThree + 
	   elementCountFour + elementCountFive + elementCountSix + elementCountSeven + 
	   elementCountEight + elementCountNine;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate 
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
bool List::insert(const Patient& newElement){

}

// Description: Remove an element. 
//              If the removal is successful, true is returned otherwise, false is returned.
// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved );

// Description: Remove all elements.
void List::removeAll(){
	const int EMPTY = 0;
	elementCount = EMPTY;
	elementCountZero = EMPTY;
	elementCountOne = EMPTY;
	elementCountTwo = EMPTY;
	elementCountThree = EMPTY;
	elementCountFour = EMPTY;
	elementCountFive = EMPTY;
	elementCountSix = EMPTY;
	elementCountSeven = EMPTY;
	elementCountEight = EMPTY;
	elementCountNine = EMPTY;
}

// Description: Search for target element and returns a pointer to it if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
	string card = target.getCareCard();
	int cardNumber;
	istringstream(card) >> cardNumber;
	int cardNumberFirstDigit = cardNumber[0];
	int size;
	switch(cardNumberFirstDigit){
		case  DIGIT_ZERO;
			size = elementCountZero;
		case  DIGIT_ONE;
			size = elementCountOne
		case  DIGIT_TWO;
			size = elementCountTwo;
		case  DIGIT_THREE;
			size = elementCountThree;
		case  DIGIT_FOUR;
			size = elementCountFour;
		case  DIGIT_FIVE;
			size = elementCountFive;
		case  DIGIT_SIX;
			size = elementCountSix;
		case  DIGIT_SEVEN;
			size = elementCountSeven;
		case  DIGIT_EIGHT;
			size = elementCountEight;
		case  DIGIT_NINE;
			size = elementCountNine;
	}
	int i = 0; 
	for(i = 0; i < size; ++i){
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
	int size = elementCountZero;
	while(currDigit < 10){
		for (i = 0; i< size; ++i){
			patientArr[currDigit][i].printPatient();
		}
		++currDigit;
		switch(currDigit){
			case  DIGIT_ONE;
				size = elementCountOne
			case  DIGIT_TWO;
				size = elementCountTwo;
			case  DIGIT_THREE;
				size = elementCountThree;
			case  DIGIT_FOUR;
				size = elementCountFour;
			case  DIGIT_FIVE;
				size = elementCountFive;
			case  DIGIT_SIX;
				size = elementCountSix;
			case  DIGIT_SEVEN;
				size = elementCountSeven;
			case  DIGIT_EIGHT;
				size = elementCountEight;
			case  DIGIT_NINE;
				size = elementCountNine;
		}
	}
}	