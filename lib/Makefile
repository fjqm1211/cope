cc = gcc
.PHONY = clean
libfuncs.a: func1.o func2.o
	ar rv libfuncs.a func1.o func2.o 
func1.o: func1.c
	$(cc) -c -g -I../include func1.c -o func1.o
func2.o: func2.c
	$(cc) -c -g -I../include func2.c -o func2.o

clean:
	rm *.o libfuncs.a
