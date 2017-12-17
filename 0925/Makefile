CC = gcc
F = func
OUT = main
.SUFFIXES: .o .c

$(OUT): main.o $(F)1.o $(F)2.o
	$(CC) -o $(OUT) main.o $(F)1.o $(F)2.o
main.o: main.c
	$(CC) -c main.c
func2.o: $(F)2.c $(F)1.c
	$(CC) -c $(F)2.c
func1.o: $(F)1.c
	$(CC) -c $(F)1.c

clean:
	rm *.o $(OUT)
