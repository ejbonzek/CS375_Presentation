all:	sorting

sorting: sorting.o
	g++ -o sorting sorting.o

sorting.o: sorting.cpp
	g++ -c sorting.cpp

clean:
	rm -f *.o sorting
