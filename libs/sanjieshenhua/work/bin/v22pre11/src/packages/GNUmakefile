
SRC=uids.c contrib.c sockets.c math.c 
OBJ=uids.o contrib.o sockets.o math.o 

OBJ=$(addprefix $(OBJDIR)/,$(subst .c,.o,$(SRC)))

$(OBJDIR)/%.o: %.c
	$(CC) -I$(OBJDIR) -I.. $(CFLAGS) -o $@ -c $<

all: $(OBJ)
	ar rcu packages.a $(OBJ)
	$(RANLIB) packages.a

clean:
	-rm -f *.o
	-rm -f packages.a
