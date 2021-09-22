main.out: main.cpp Calculator.cpp
	@$(CXX) -g -Wall -std=c++11 $(CXXFLAGS) $^ -o $@ -L. -lbigint

test: main.out
	@valgrind --leak-check=full ./main.out

clean:
	@rm -f *.out
