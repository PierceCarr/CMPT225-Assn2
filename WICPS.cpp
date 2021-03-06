/*
 * WICPS.cpp
 * 
 * Class Description: Implementation/interface of the walk in clinic system. 
 * The idea is that any receptionist can sit down at her computer and run this program.
 * 
 * Class Invariant: Operators and getters do not affect the Patient objects.
 *
 * Last modified on: May 2017
 * Authors: Sina Khalili and Pierce Carruthers
 */
#include <iostream>
#include <sstream>
#include "Patient.h"
#include "List.h"
using namespace std;

void runRegistry();
int getChoice(int numberOfOptions);
bool doMainOption(int userChoice, List& registry);
void displayMainOptions();
void displayPatients(List registry);
void enterPatient(List& registry);
void editPatient(Patient& patient);
void displayEditOptions();
bool doEditOptions(int userChoice, Patient& patient);
string getPatientInput(string prompt);
string getLegalCareCard();
bool removePatient(List& registry);
void searchForPatient(List& registry);
void getPatientToEdit(List& registry);

int main(){
	runRegistry();
	return 0; 
}

void runRegistry(){
	List patientRegistry;
	cout << "Welcome to the Walk-In Clinic Patient System!" << endl;
	cout << "Please proceed by entering one of the following main option numbers: " << endl;
	displayMainOptions();
		 
	bool runMainMenu = true;
	while(runMainMenu){
		cout << endl << "Please enter a main option. Enter 1 to see all options." << endl;

		const int MAIN_OPTIONS = 7;
		int choice = getChoice(MAIN_OPTIONS);
		runMainMenu = doMainOption(choice, patientRegistry); //Breaks loop by returning false if Exit option is selected
	}
}

void displayMainOptions(){
	cout << endl << "***OPTIONS FOR THE MAIN MENU***" << endl;
	cout << "1. Display these options again." << endl
		 << "2. Display registered patients." << endl
		 << "3. Enter a patient to the registry." << endl
		 << "4. Remove a patient from the registry." << endl
		 << "5. Search for a patient in the registry." << endl
		 << "6. Edit a patient's information." << endl
		 << "7. Exit program." << endl;
}

int getChoice(int numberOfOptions){ //NEEDS TO BE COMPILED USING C++ 11 (g++ --std=c++11 WICPS.cpp) because of stoi()
	bool repromptNeeded = true;
	string userInput;

	while(repromptNeeded){ //Prompts the user on the legality of their input until they enter an expected option
		//Recieve user input

		cout << "Enter an option number: ";
		cin >> userInput;

		//Check legality of user input

		bool legalOption = true;
		string promptMessage = "BUG - NO PROMPT ASSIGNED."; //The user will only see this specific message if there is a bug

		const int LENGTH_OF_A_DIGIT = 1; //Make sure user input is a single character
		bool oneCharacter = (userInput.length() == LENGTH_OF_A_DIGIT);
		if(!oneCharacter){ 
			legalOption = false;
				promptMessage = "Choose an option from 1 to ";

				//numberOfOptions          // string which will contain the result

				ostringstream convert;   // stream used for the conversion

				convert << numberOfOptions;      // insert the textual representation of 'Number' in the characters in the stream

				promptMessage += convert.str(); // set 'Result' to the contents of the stream(numberOfOptions);
				
				promptMessage += ".";
			/*promptMessage = "Please enter a single digit from 1 to ";
			promptMessage += to_string(numberOfOptions);
			promptMessage += ".";*/
		}

		if(legalOption){ //If the user input is at least a single character, we check if it's an integer
			try{
				

				int test;          //number which will contain the result

				istringstream convert(userInput); // stringstream used for the conversion constructed with the contents of 'Text' 
                             // ie: the stream will start containing the characters of 'Text'

				convert >> test; //give the value to 'Result' using the characters in the stream
    			
				
				//int test = stoi(userInput, nullptr);
			}
			catch(...){
				legalOption = false;
				promptMessage = "Please enter the associated number of the option you desire.";
			}

		}

		const int MIN_OPTION = 1;
		const int MAX_OPTION = numberOfOptions;
		if(legalOption){ //Finally, we check if the user's number is within the range of provided options
			int userNumber;          //number which will contain the result

				istringstream convert(userInput); // stringstream used for the conversion constructed with the contents of 'Text' 
                             // ie: the stream will start containing the characters of 'Text'

				convert >> userNumber; //give the value to 'Result' using the characters in the stream

			//int userNumber = stoi(userInput, nullptr);
			bool legalRange = (userNumber >= MIN_OPTION && userNumber <= MAX_OPTION);
			if(!legalRange){
				legalOption = false;
				promptMessage = "Choose an option from 1 to ";

				//numberOfOptions          // string which will contain the result

				ostringstream convert;   // stream used for the conversion

				convert << numberOfOptions;      // insert the textual representation of 'Number' in the characters in the stream

				promptMessage += convert.str(); // set 'Result' to the contents of the stream(numberOfOptions);
				
				promptMessage += ".";
			}
		}

		if(legalOption){ //Make sure the user is repromted if needed, otherwise the loop ends
			repromptNeeded = false;
		} else {
			cout << endl << promptMessage << endl;
		}
	}

				int returnNumber;          //number which will contain the result

				istringstream convert(userInput); // stringstream used for the conversion constructed with the contents of 'Text' 
                             // ie: the stream will start containing the characters of 'Text'

				convert >> returnNumber;
	return returnNumber;
}

bool doMainOption(int userChoice, List& registry){
	//Option enums for clairity
	enum e_choices{
		DISPLAY_OPTIONS = 1,
		DISPLAY_PATIENTS,
		ENTER_PATIENT,
		REMOVE_PATIENT,
		SEARCH_PATIENT,
		EDIT_PATIENT,
		EXIT
	};

	bool patientRemoved = false;

	switch(userChoice){
		case DISPLAY_OPTIONS:
			displayMainOptions();
			return true;
		case DISPLAY_PATIENTS:
			displayPatients(registry);
			return true;
		case ENTER_PATIENT:
			enterPatient(registry);
			return true;
		case REMOVE_PATIENT:
			patientRemoved = removePatient(registry);
			if(patientRemoved){
				cout << "Patient was removed." << endl;
			} else {
				cout << "Target patient was not found in registry." << endl;
			}
			return true;
		case SEARCH_PATIENT:
			searchForPatient(registry);
			return true;
		case EDIT_PATIENT:
			getPatientToEdit(registry);
			return true;
		case EXIT:
			cout << "Stay healthy!" << endl;
			return false;
	}

	cout << "BUG: A NUMBER OTHER THAN 1 - 7 WAS PASSED TO doMainOption()!" << endl; //This should never be displayed
	return false;
}

void displayPatients(List registry){
	registry.printList();
}

void enterPatient(List& registry){

	Patient newPatient(getLegalCareCard());

	bool editing = true;

	while(editing){
		cout << endl << "This is the new patient: " << endl;
		newPatient.printPatient();
		cout << endl;
		cout << "Enter '1' to edit patient." << endl
			 <<	"Enter '2' to add patient to registry." << endl
			 <<	"Enter '3' to discard patient." << endl;

		const int ADD_OPTIONS = 3;
		int choice = getChoice(ADD_OPTIONS);

		const int EDIT_PATIENT = 1;
		const int ADD_PATIENT = 2;
		const int DISCARD_PATIENT = 3;

		bool registered = false;

		switch(choice){
			case EDIT_PATIENT:
				editPatient(newPatient);
				break;
			case ADD_PATIENT:
				registered = registry.insert(newPatient);
				if(registered){
					editing = false;
				}
				break;
			case DISCARD_PATIENT:
				editing = false;
				break;
		}

	}
	
}

void editPatient(Patient& patient){
	bool editing = true;

	cout << endl << "You are now editing the following patient: " << endl;
	patient.printPatient();
	cout << endl << "You have the following options: " << endl;
	displayEditOptions();

	while(editing){
		cout << endl << "Select an edit option. Press 1 to see all options." << endl;

		const int EDIT_OPTIONS = 7;
		int choice = getChoice(EDIT_OPTIONS);
		editing = doEditOptions(choice, patient);

	}
}

bool doEditOptions(int userChoice, Patient& patient){
	enum e_options {
		DISPLAY_OPTIONS = 1,
		DISPLAY_PATIENT,
		EDIT_NAME,
		EDIT_ADDRESS,
		EDIT_PHONE,
		EDIT_EMAIL,
		STOP_EDITING
	};

	//Predeclared so switch doesn't jump over declarations and beg for -fpermissive
	string newName = "Nothing entered";
	string newAddress = "Nothing entered";
	string newPhone = "Nothing entered";
	string newEmail = "Nothing entered";
				string ABrandnewName = "";


	switch(userChoice){
		case DISPLAY_OPTIONS:
			displayEditOptions();
			return true;
		case DISPLAY_PATIENT:
			patient.printPatient();
			return true;
		case EDIT_NAME: // need to use getline()
			cout << "Please enter the patient's name: " << endl;
			cin.ignore();
			getline(cin, newName);
			patient.setName(newName);
			return true;
		case EDIT_ADDRESS: // need to use getline()
			cout << "Please enter the patient's address: " << endl;
			cin.ignore();
			getline(cin, newAddress);
			patient.setAddress(newAddress);
			return true;
		case EDIT_PHONE:
			newPhone = getPatientInput("Please enter the patient's phone number: ");
			patient.setPhone(newPhone);
			return true;
		case EDIT_EMAIL:
			newEmail = getPatientInput("Please enter the patient's e-mail: ");
			patient.setEmail(newEmail);
			return true;
		case STOP_EDITING:
			return false;
	}

	//Nothing below should run
	cout << "BUG - NUMBER OTHER THAN 1 - 7 PASSED TO doEditOptions()!" << endl;
	return false;
}

string getPatientInput(string prompt){
	cout << prompt << endl;
	string userInput;
	cin >> userInput;
	return userInput;
}

void displayEditOptions(){
	cout << endl << "***OPTIONS FOR EDITING PATIENTS***" << endl;
	cout << "1. Display these options again." << endl
		 << "2. Display patient." << endl
		 << "3. Edit patient's name." << endl
		 << "4. Edit patient's address." << endl
		 << "5. Edit patient's phone number." << endl
		 << "6. Edit patient's e-mail." << endl
		 << "7. Stop editing patient." << endl;
}

string getLegalCareCard(){
	string userInput;
	string prompt = "Please enter patient's care card number: ";

	while(true){
		cout << endl << prompt;
		cin >> userInput;

		bool legalEntry = true;

		const int DIGITS_IN_CARE_CARD = 10; //Check if care card has ten characters
		if(userInput.length() != DIGITS_IN_CARE_CARD){
			legalEntry = false;
			prompt = "A care card has ten digits. Please enter them now: ";
		}

		if(legalEntry){ //If 10 characters, check if they are all numerals
			const char ASCII_ZERO = 48;
			const char ASCII_NINE = 57;
			for(int i = 0; i < DIGITS_IN_CARE_CARD - 1; ++i){
				char currentCharacter = userInput[i];

				bool betweenOneAndNine = (currentCharacter >= ASCII_ZERO && currentCharacter <= ASCII_NINE);
				if(!betweenOneAndNine){
					legalEntry = false;
					prompt = "Care cards are composed of ten numerical digits. Please enter them now: ";
					break;
				}
			}
		}

		if(legalEntry){
			return userInput;
		}
	}
}

bool removePatient(List& registry){
	cout << endl << "Please enter the care card number of the patient you would like to remove from the registry: ";
	string targetCard = getLegalCareCard();
	Patient targetPatient(targetCard);

	return registry.remove(targetPatient);
}

void searchForPatient(List& registry){
	cout << endl << "Please enter the care card number of the patient you are looking for: ";
	string targetCard = getLegalCareCard();

	Patient tempPatient(targetCard);
	Patient* targetPatient = registry.search(tempPatient);

	if(targetPatient != NULL){
		cout << endl << "Here is the information of the patient you were searching for: " << endl;
		tempPatient = *targetPatient;
		tempPatient.printPatient();
	} else {
		cout << "No patient found in registry with care card number " << targetCard << "." << endl;
	}
}

void getPatientToEdit(List& registry){
	cout << endl << "Please enter the care card number of the patient you would like to edit: ";
	string targetCard = getLegalCareCard();

	Patient tempPatient(targetCard);
	Patient* targetPatient = registry.search(tempPatient);

	if(targetPatient != NULL){
		editPatient(*targetPatient);
	} else {
		cout << "No patient found in registry with care card number " << targetCard << "." << endl;
	}
}