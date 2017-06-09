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
	const int FIRST_CHARACTER = 0;
	string careCard = newElement.getCareCard();
	char firstChar = careCard[FIRST_CHARACTER];

	const int ASCII_ZERO = 48;
	int firstDigit = firstChar - ASCII_ZERO;

	int digitArrCount = 0;
	int* digitArrSize;

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
	switch(firstDigit){
		case DIGIT_ZERO:
			digitArrCount = elementCountZero;
			digitArrSize = &arrZeroSize;
			elementCountZero++;
		case DIGIT_ONE:
			digitArrCount = elementCountOne;
			digitArrSize = &arrOneSize;
			elementCountOne++;
		case DIGIT_TWO:
			digitArrCount = elementCountTwo;
			digitArrSize = &arrTwoSize;
			elementCountTwo++;
		case DIGIT_THREE:
			digitArrCount = elementCountThree;
			digitArrSize = &arrThreeSize;
			elementCountThree++;
		case DIGIT_FOUR:
			digitArrCount = elementCountFour;
			digitArrSize = &arrFourSize;
			elementCountFour++;
		case DIGIT_FIVE:
			digitArrCount = elementCountFive;
			digitArrSize = &arrFiveSize;
			elementCountFive++;
		case DIGIT_SIX:
			digitArrCount = elementCountSix;
			digitArrSize = &arrSixSize;
			elementCountSix++;
		case DIGIT_SEVEN:
			digitArrCount = elementCountSeven;
			digitArrSize = &arrSevenSize;
			elementCountSeven++;
		case DIGIT_EIGHT:
			digitArrCount = elementCountEight;
			digitArrSize = &arrEightSize;
			elementCountEight++;
		case DIGIT_NINE:
			digitArrCount = elementCountNine;
			digitArrSize = &arrNineSize;
			elementCountNine++;
	}

	if(digitArrCount < *digitArrSize){ //If there's still space left in the array
		patientArr[firstDigit][digitArrCount + 1] = newElement; //Place the element in the next space
		return true;
	} else { //If the array is full
		const int DOUBLE_SIZE = 2;
		Patient* newArr = new Patient[*digitArrSize * DOUBLE_SIZE]; //IF THERE'S A SEGFAULT BUG, IT ORIGINATES HERE

		for(int i = 0; i < digitArrCount; ++i){
			newArr[i] = patientArr[firstDigit][i];
		}

		newArr[digitArrCount + 1] = newElement;
		patientArr[firstDigit] = newArr;
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