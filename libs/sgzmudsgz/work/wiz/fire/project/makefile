all: messser discli cmdcli

cmdcli: cmdcli.o unp.o ms.o
	cc -o cmdcli cmdcli.o unp.o ms.o
cmdcli.o: cmdcli.c unp.h ms.h
	cc -c cmdcli.c
discli: discli.o unp.o ms.o
	cc -o discli discli.o unp.o ms.o
discli.o: discli.c unp.h ms.h
	cc -c discli.c
messser: messser.o ms.o unp.o
	cc -o messser messser.o ms.o unp.o
messer.o: messser.c ms.h unp.h 
	cc -c messer.c
ms.o: ms.c ms.h unp.h
	cc -c ms.c
unp.o: unp.c
	cc -c unp.c
clean:
	rm -f *.o core messser discli cmdcli

