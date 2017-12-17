F = func
CC = gcc -c
libfuncs.a: $(F)1.o $(F)2.o
	ar rv lib$(F)s.a $(F)1.o $(F)2.o 
$(F)1.o: $(F)1.c
	$(CC) $(F)1.c
$(F)2.o: $(F)2.c
	$(CC) $(F)2.c
 
