main: stack.o lib_test.o
	g++ -o $@ $^
lib_test.o: lib_test.cpp stack.h
	g++ -c $^
stack.o: stack.cpp stack.h
clean:
	rm -rf *.o main