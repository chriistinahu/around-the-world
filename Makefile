EXENAME = main
OBJS = main.o loader.o airport.o route.o graph.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp loader.h route.h airport.h graph.h
	$(CXX) $(CXXFLAGS) main.cpp loader.h

loader.o: loader.cpp loader.h
	$(CXX) $(CXXFLAGS) loader.cpp

airport.o: airport.cpp airport.h
	$(CXX) $(CXXFLAGS) airport.cpp

route.o: route.h route.cpp 
	$(CXX) $(CXXFLAGS) route.cpp

graph.o: graph.h graph.cpp edge.h
	$(CXX) $(CXXFLAGS) graph.cpp


test: output_msg catchmain.o tests/tests.cpp airport.o route.o graph.o loader.o
	$(LD) catchmain.o tests/tests.cpp main.o airport.o route.o graph.o loader.o $(LDFLAGS) -o test

catchmain.o: catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

clean:
	-rm -f *.o $(EXENAME) test
