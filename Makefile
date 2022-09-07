CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include 
TEST    := test
APPLICATION := application

LIBRARIES   :=
EXECUTABLE  := main
UNITTESTABLE:= unittest
APPTESTABLE := apptest


run: $(BIN)/$(EXECUTABLE)
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp $(APPLICATION)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

unittest: $(BIN)/$(UNITTESTABLE)
	clear
	./$(BIN)/$(UNITTESTABLE)

$(BIN)/$(UNITTESTABLE): $(SRC)/*.cpp $(TEST)/UnitTest.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

apptest: $(BIN)/$(APPTESTABLE)
	clear
	./$(BIN)/$(APPTESTABLE)

$(BIN)/$(APPTESTABLE): $(SRC)/*.cpp $(TEST)/ApplicationTest.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
