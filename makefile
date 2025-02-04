CXX = g++
CXXFLAGS = -Wall -g
IODIR =../../proj5_IO/

proj5: NavigationEntry.o Browser.o Stack.o proj5.cpp
	$(CXX) $(CXXFLAGS) NavigationEntry.o Browser.o Stack.o proj5.cpp -o proj5

NavigationEntry.o: NavigationEntry.h NavigationEntry.cpp
	$(CXX) $(CXXFLAGS) -c NavigationEntry.cpp

Browser.o: Browser.h Browser.cpp Stack.o NavigationEntry.o
	$(CXX) $(CXXFLAGS) -c Browser.cpp

Stack.o: Stack.cpp
	$(CXX) $(CXXFLAGS) -c Stack.cpp

##Use this when you want to test just your Queue
stest: Stack.o stack_test.cpp
	$(CXX) $(CXXFLAGS) Stack.o stack_test.cpp -o stest

##Use this when you want to valgrind your Queue tests
stest2:
	valgrind ./stest

clean:
	rm *.o*
	rm *~ 

run1:
	./proj5 proj5_data1.txt

run2:
	./proj5 proj5_data2.txt

run3:
	./proj5 proj5_data3.txt

val1:
	valgrind ./proj5 proj5_data1.txt

val2:
	valgrind ./proj5 proj5_data2.txt

val3:
	valgrind ./proj5 proj5_data3.txt

##Used for grading and testing
##Copies all test files into current directory
copy:
	cp $(IODIR)proj5* .

submit:
	cp NavigationEntry.h NavigationEntry.cpp Browser.h Browser.cpp Stack.cpp proj5.cpp ~/cs202proj/proj5

