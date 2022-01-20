
# ===================================================================
#					MAKEFILE FOR ASSIGNMENT 2
#					Francisco Chanivet Sánchez
# ===================================================================

CXX = g++
CXXFLAGS = -std=c++11 -Wall -O3
OBJS = solver.o
EXES = resoulution

all: resolution

resolution: solver.o
	$(CXX) -o resolution $(CXXFLAGS) solver.o

solver.o: solver.cpp generator.h translator.h
	$(CXX) -c $(CXXFLAGS) solver.cpp
	
clean:
	${RM} ${EXES} ${OBJS} core *~
