CXX = g++
CXXTEST=cxxtestgen
CXXFLAGS = -Wall  $(CXXFLAGS_diff)
LDFLAGS = $(LDFLAGS_mac)*
LIBS = -larmadillo


SOLUTIONS_OBJ=solutions.o
TEST_CPP=t.cpp
TEST_OBJ=t.o

BIN_DIR=../bin
SRC_DIR=../src
TEST_SRC=test_solutions.h
SOLUTIONS_SRC=$(SRC_DIR)/solutions.cpp
TARGET = test

all:$(TARGET)

$(TEST_CPP):$(TEST_SRC)
	$(CXXTEST) --error-printer -o $(TEST_CPP) $(TEST_SRC)

$(SOLUTIONS_OBJ):$(SOLUTIONS_SRC)
	$(CXX) $(CXXFLAGS) -c $(SOLUTIONS_SRC) -o $(SOLUTIONS_OBJ)

$(TEST_OBJ):$(TEST_CPP)
	$(CXX) $(CXXFLAGS) -c $(TEST_CPP) -o $(TEST_OBJ)     

$(TARGET):$(TEST_OBJ) $(SOLUTIONS_OBJ)
	$(CXX) $(TEST_OBJ) $(SOLUTIONS_OBJ) -o $(TARGET) $(LIBS)



.PHONY: clean
clean:
	rm -f $(TEST_CPP) $(SOLUTIONS_OBJ) $(TEST_OBJ)
	rm -f $(TARGET) 




