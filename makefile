all: test

test: List_Test_Driver.o List.o Patient.o
	g++ -Wall -o test List_Test_Driver.o List.o Patient.o

List_Test_Driver.o: List_Test_Driver.cpp List.h Patient.h
	g++ -Wall -c List_Test_Driver.cpp

List.o: List.h List.cpp
	g++ -Wall -c List.cpp

Patient.o: Patient.h Patient.cpp
	g++ -Wall -c Patient.cpp

clean:
	rm -f test *.o