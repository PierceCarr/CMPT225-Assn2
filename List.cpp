//List.cpp Hey Guys it's me 

#pragma once
#include "List.h"
#include <sstream>

using namespace std;


int List::getElementCount() const{
	return totalElementCount;
	// return elementCountZero + elementCountOne + elementCountTwo + elementCountThree + 
	//    elementCountFour + elementCountFive + elementCountSix + elementCountSeven + 
	//    elementCountEight + elementCountNine;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate 
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.

/**
	Insertion: When the receptionist add a new patient (for example, a new Patient with the care card 
	number "7865432189") to WICPS, the system first needs to ascertain whether this Patient object is 
	already in the List. This must be done in O(m), where m is the number of Patient objects with care 
	card numbers starting with the same digit, for example, "7". Then insert( ) must verify whether the 
	section of the data structure storing Patient objects with care card numbers starting with, for example, 
	"7", is full (or not) and it must do so in O(1).

	If it is full, it must first be expanded in a transparent fashion, i.e., unbeknown to the user. This 
	is to say that the WICPS application (the client code) should not be aware of it. This expansion must 
	be done in O(1) (amortized). This expansion must leave all the other sections, i.e., sections storing
	Patient objects with care card numbers starting with other digits then, for example, "7", unaffected.
	Once the expansion is done, the new Patient object is inserted into the newly expanded section of the
	data structure. See next bullet item for more information about insertion.

	If it is not full, it must insert this Patient object in O(m), where m is the number of Patient objects 
	with care card numbers starting with the same digit, for example, "7", into this section of the data 
	structure. As it is inserting this particular Patient object, it cannot access other sections of the data 
	structure containing Patient objects with care card numbers starting with other digits then, for example, "7".

**/	
bool List::insert(const Patient& newElement){ //This is just a draft. I'm pretty certain the final two paragraphs of the above are not fullfilled.
	bool result = NULL;

	const int FIRST_CHARACTER = 0;
	string careCard = newElement.getCareCard();
	char firstChar = careCard[FIRST_CHARACTER];

	const int ASCII_ZERO = 48;
	int firstDigit = firstChar - ASCII_ZERO;

	//Check if already on list in O(m)
	bool found = false;
	for(int i = 0; i < arrSizes[firstDigit] && !found; ++i){
		if(patientArr[firstDigit] == newElement){
			result = false;
			found = true;
		}
	}
	//Check if full

	bool isFull = (arrCounts[firstDigit] == arrSizes[firstDigit]);

	if(isFull && !found){//if full
		const int DOUBLE_SIZE = 2;
		int newCount = arrCounts[firstDigit] + 1;
		Patient* expandedArr = Patient[arrSizes[firstDigit] * DOUBLE_SIZE]; 
		for(int i = 0; i < arrCounts[firstDigit]; ++i){
			expandedArr[i] = patientArr[firstDigit][i];
		}
		expandedArr[newCount] = newElement;
		arrCounts[firstDigit] = newCount;
		arrSizes[firstDigit] *= DOUBLE_SIZE;
		result = true;
	}else if(!found){//if space
		int newCount = arrCounts[firstDigit] + 1;
		patientArr[firstDigit][newCount] = newElement;
		arrCounts[firstDigit] = newCount;
		arrSizes[firstDigit]++;
		result = true;
	}


	return result;
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
	int size;

	const int DIGIT_ZERO = 0;
	const int DIGIT_ONE = 1;
	const int DIGIT_TWO = 2;
	const int DIGIT_THREE = 3;
	const int DIGIT_FOUR = 4;
	const int DIGIT_FIVE = 5;
	const int DIGIT_SIX = 6;
	const int DIGIT_SEVEN = 7;
	const int DIGIT_EIGHT = 8;
	const int DIGIT_NINE = 9;
	switch(cardNumberFirstDigit){
		case  DIGIT_ZERO:
			size = elementCountZero;
		case  DIGIT_ONE:
			size = elementCountOne;
		case  DIGIT_TWO:
			size = elementCountTwo;
		case  DIGIT_THREE:
			size = elementCountThree;
		case  DIGIT_FOUR:
			size = elementCountFour;
		case  DIGIT_FIVE:
			size = elementCountFive;
		case  DIGIT_SIX:
			size = elementCountSix;
		case  DIGIT_SEVEN:
			size = elementCountSeven;
		case  DIGIT_EIGHT:
			size = elementCountEight;
		case  DIGIT_NINE:
			size = elementCountNine;
	}
	int i = 0; 
	for(i = 0; i < size; ++i){
		if(patientArr[cardNumberFirstDigit][i] == toBeRemoved){
			
			for(int ii = i+1; ii < size; ++ii){ 
				patientArr[cardNumberFirstDigit][ii-1] = patientArr[cardNumberFirstDigit][ii];
			}

			const int DIGIT_ZERO = 0;
			const int DIGIT_ONE = 1;
			const int DIGIT_TWO = 2;
			const int DIGIT_THREE = 3;
			const int DIGIT_FOUR = 4;
			const int DIGIT_FIVE = 5;
			const int DIGIT_SIX = 6;
			const int DIGIT_SEVEN = 7;
			const int DIGIT_EIGHT = 8;
			const int DIGIT_NINE = 9;
			switch(cardNumberFirstDigit){
				case  DIGIT_ZERO:
					elementCountZero++;
				case  DIGIT_ONE:
					elementCountOne++;
				case  DIGIT_TWO:
					elementCountTwo++;
				case  DIGIT_THREE:
					elementCountThree++;
				case  DIGIT_FOUR:
					elementCountFour++;
				case  DIGIT_FIVE:
					elementCountFive++;
				case  DIGIT_SIX:
					elementCountSix++;
				case  DIGIT_SEVEN:
					elementCountSeven++;
				case  DIGIT_EIGHT:
					elementCountEight++;
				case  DIGIT_NINE:
					elementCountNine++;
			
			}
			return true;
		}

	}
	return false;
}

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

/**
	Searching: The search( ) must perform in O(x), where x is the number of Patient objects with care card numbers starting with the 
	same digit as the starting digit of the care card number of the target Patient object. For example, if the receptionist wishes 
	to search for a Patient object with the care card number "6754322189", the search must performed in O(p) where p is the number 
	Patient objects with care card numbers starting with "6", where p ≤ n. This signifies that the only section of the data structure 
	that is searched is the section containing Patient objects with care card numbers starting with "6".
**/
Patient* List::search(const Patient& target){
	string card = target.getCareCard();
	int cardNumberFirstDigit;
	const int ASCII_ZERO = 48;
	char firstDigit = card[0];
	cardNumberFirstDigit = firstDigit - ASCII_ZERO;
	int size;

	const int DIGIT_ZERO = 0;
	const int DIGIT_ONE = 1;
	const int DIGIT_TWO = 2;
	const int DIGIT_THREE = 3;
	const int DIGIT_FOUR = 4;
	const int DIGIT_FIVE = 5;
	const int DIGIT_SIX = 6;
	const int DIGIT_SEVEN = 7;
	const int DIGIT_EIGHT = 8;
	const int DIGIT_NINE = 9;
	switch(cardNumberFirstDigit){
		case  DIGIT_ZERO:
			size = elementCountZero;
		case  DIGIT_ONE:
			size = elementCountOne;
		case  DIGIT_TWO:
			size = elementCountTwo;
		case  DIGIT_THREE:
			size = elementCountThree;
		case  DIGIT_FOUR:
			size = elementCountFour;
		case  DIGIT_FIVE:
			size = elementCountFive;
		case  DIGIT_SIX:
			size = elementCountSix;
		case  DIGIT_SEVEN:
			size = elementCountSeven;
		case  DIGIT_EIGHT:
			size = elementCountEight;
		case  DIGIT_NINE:
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

		const int DIGIT_ZERO = 0;
		const int DIGIT_ONE = 1;
		const int DIGIT_TWO = 2;
		const int DIGIT_THREE = 3;
		const int DIGIT_FOUR = 4;
		const int DIGIT_FIVE = 5;
		const int DIGIT_SIX = 6;
		const int DIGIT_SEVEN = 7;
		const int DIGIT_EIGHT = 8;
		const int DIGIT_NINE = 9;
		switch(currDigit){
			case  DIGIT_ONE:
				size = elementCountOne;
			case  DIGIT_TWO:
				size = elementCountTwo;
			case  DIGIT_THREE:
				size = elementCountThree;
			case  DIGIT_FOUR:
				size = elementCountFour;
			case  DIGIT_FIVE:
				size = elementCountFive;
			case  DIGIT_SIX:
				size = elementCountSix;
			case  DIGIT_SEVEN:
				size = elementCountSeven;
			case  DIGIT_EIGHT:
				size = elementCountEight;
			case  DIGIT_NINE:
				size = elementCountNine;
		}
	}
}	