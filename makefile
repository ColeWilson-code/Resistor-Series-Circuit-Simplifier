
output: Driver.o LinkedList.o DataClass.o 
	g++ Driver.o LinkedList.o DataClass.o  -o output

Driver.o: Driver.cpp
	g++ -c Driver.cpp

LinkedList.o: DataClass.cpp
	g++ -c DataClass.cpp

DataClass.o: DataClass.cpp
	g++ -c DataClass.cpp

clean: 
	rm *.o output