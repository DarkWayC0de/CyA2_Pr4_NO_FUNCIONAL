CC=g++
CXXFLAGS=-g -std=c++17 -pedantic
ODIR=src
BUILD=build

_OBJ=$(BUILD)/main.o $(BUILD)/Estados.o $(BUILD)/Automata.o $(BUILD)/Eliminar_Comentarios.o
OBJ=$(patsubst %,%,$(_OBJ))

all:Program
$(BUILD)/main.o: $(ODIR)/main.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/Estados.o: $(ODIR)/Estados.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/Automata.o: $(ODIR)/Automata.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/Eliminar_Comentarios.o: $(ODIR)/Eliminar_Comentarios.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

Program: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* Program

