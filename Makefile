all: hftd

hftd: hashFunctionTestDriver.o Dictionary.o Profile.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o
	g++ -o hftd -Wall hashFunctionTestDriver.o Dictionary.o Profile.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o
	
hashFunctionTestDriver.o: hashFunctionTestDriver.cpp 
	g++ -c -Wall hashFunctionTestDriver.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c -Wall Dictionary.cpp

Profile.o: Profile.cpp Profile.h
	g++ -c -Wall Profile.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.cpp ElementAlreadyExistsException.h
	g++ -c -Wall  ElementAlreadyExistsException.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.cpp ElementDoesNotExistException.h
	g++ -c -Wall  ElementDoesNotExistException.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

UnableToInsertException.o: UnableToInsertException.cpp UnableToInsertException.h
	g++ -c -Wall UnableToInsertException.cpp

clean:	
	rm -f hftd *.o

