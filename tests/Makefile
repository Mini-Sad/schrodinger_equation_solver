CXX = g++
CXXTEST=cxxtestgen
CXXFLAGS = -Wall -O3 -std=c++14 $(CXXFLAGS_diff)
LDFLAGS = $(LDFLAGS_mac)
LIBS = -larmadillo
LIBS_TEST=--error-printer
OBJS=test.o solutions.o
TEST_DIR= tests
TARGET = test

all:$(Target)


$(TARGET): $(OBJS)
    $(CXX) $(LDFLAGS) $^ -o $@ 

%.o: %.c %.h
    $(CXX) $(CXXFLAGS) -c $< -o $@	

%.o: %.c %.h
    $(CXXTEST) $(LIBS_TEST) -o $@ $<	

.PHONY: all clean
clean:
    rm -f $(OBJS)
    rm -f $(TARGET)