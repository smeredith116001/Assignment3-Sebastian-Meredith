CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
VPATH = src:lib
OBJECTS = PPlot.o SVGPainter.o test.o main.o 

assignment3: $(OBJECTS)
	$(CC) $(OBJECTS) -o assignment3

PPlot.o: PPlot.cpp PPlot.h
	$(CC) $(FLAGS) -c lib/PPlot.cpp

SVGPainter.o: SVGPainter.cpp SVGPainter.h
	$(CC) $(FLAGS) -c lib/SVGPainter.cpp

test.o: test.cpp DynamicArray.h LinkedList.h Collection.h
	$(CC) $(FLAGS) -Ilib -c src/test.cpp

main.o: main.cpp
	$(CC) $(FLAGS) -Ilib -c src/main.cpp

clean:
	rm assignment3 *.o *.svg
