CXX = g++

CXXFLAGS = -std=c++14 -Wall -g

BINARY = hw07

TARFILE = hw07.tar

all: $(BINARY)

$(BINARY):
	$(CXX) $(CXXFLAGS) hw07.cpp -o $(BINARY)
clean:
	rm -rf $(BINARY) $(TARFILE)
tar:
	tar cf $(TARFILE) Makefile hw07.scr hw07.cpp hw07.h