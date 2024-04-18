CXX = g++
CXXFLAGS = -g

SRCS := $(wildcard *.cpp)
BINS := $(patsubst %.cpp, %, $(SRCS))

.PHONY: all clean

all: $(BINS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	$(RM) $(BINS)
