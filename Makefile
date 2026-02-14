CXX = g++
CXXFLAGS = -g -Wall -std=c++11

OBJS = main.o buildTree.o traversals.o treeUtils.o
TARGET = P1

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp node.h buildTree.h traversals.h
	$(CXX) $(CXXFLAGS) -c main.cpp

buildTree.o: buildTree.cpp buildTree.h node.h
	$(CXX) $(CXXFLAGS) -c buildTree.cpp

traversals.o: traversals.cpp traversals.h node.h
	$(CXX) $(CXXFLAGS) -c traversals.cpp

treeUtils.o: treeUtils.h treeUtils.cpp node.h
	$(CXX) $(CXXFLAGS) -c treeUtils.cpp

clean:
	rm -f *.o $(TARGET)
