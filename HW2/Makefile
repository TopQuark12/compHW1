CXX	= g++
CFLAGS = -I.

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

main: main.o pa2.o
	$(CXX) -o main main.o pa2.o -O3

clean:
	rm -f *.o *~ core