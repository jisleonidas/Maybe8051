SRCFILES=main.cpp decoder.cpp opcodes.cpp internal.cpp constants.cpp
OBJFILES=main.o decoder.o opcodes.o internal.o constants.o

main: $(OBJFILES)
	g++ -o main $(OBJFILES)
OBJFILES: $(SRCFILES)
	g++ -c $(SRCFILES)

.PHONY=clean
clean:
	rm *.o
	rm main