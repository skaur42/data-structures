main.out: main.cpp DiGraphAdjList.cpp
	@$(CXX) -g -Wall -std=c++11 $(CXXFLAGS) $^ -o $@

test: main.out
	@valgrind --leak-check=full ./main.out

clean:
	@rm -f *.out
