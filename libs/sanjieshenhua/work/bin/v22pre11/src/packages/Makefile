
SRC=uids.c contrib.c sockets.c math.c 
OBJ=uids.o contrib.o sockets.o math.o 

.c.o:
	$(CC) $(CFLAGS) -I.. -c $*.c

all: $(OBJ)
	ar rcu packages.a $(OBJ)
	$(RANLIB) packages.a

clean:
	-rm -f *.o
	-rm -f packages.a
