/*
 * List_Test_Driver.cpp - Assignment 1
 * 
 * Class Description: Test Driver for List (and Patient) class
 *
 * Modified on: May 2017
 * Author: AL + NH
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

int main() {

    // Variables declaration
    List* patients = new List(); 

    Patient p1234567890("1234567890");
    Patient p2345678901("2345678901");
    Patient p3456789012("3456789012");
    Patient p4567890123("4567890123");
    Patient p5678901234("5678901234");
   	   	   	   
    cout << endl;
    cout << "Add Patient p2345678901 to List";
    patients->insert(p2345678901);

    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;	
    patients->printList();

    cout << endl;
    cout << "Add Patient p5678901234 to List";
    patients->insert(p5678901234);

    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;	
    patients->printList();

    cout << endl;
    cout << "Add Patient p1234567890 to List";
    patients->insert(p1234567890);

    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;	
    patients->printList();

    cout << endl;
    cout << "Add Patient p1234567890 AGAIN to List";
    patients->insert(p1234567890);

    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;	
    patients->printList();

    cout << endl;
    cout << "Add the Forth Patient p4567890123 to List (Should not add it)";
    patients->insert(p4567890123);

    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();

    cout << endl;
    cout << "Remove All the Patients from the List";
    patients-> removeAll();
    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();

    cout << endl;
    cout << "Add all Patients into the List";
    patients->insert(p2345678901);
    patients->insert(p5678901234);
    patients->insert(p1234567890);
    patients->insert(p4567890123);
    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();

    cout<<endl;
    cout << "Remove Patient p4567890123 from the List";
    patients-> remove(p4567890123);
    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();

    cout<<endl;
    cout << "Remove Patient p1234567890 from the List";
    patients-> remove(p1234567890);
    cout << "\nThere are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();

    return 0;
}