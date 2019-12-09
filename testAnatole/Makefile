but : snake

OFILES = main.o \
         dessin.o \
         timer.o

CC = gcc 

timer.o : timer.h 

dessin.o : dessin.h timer.h

main.o : timer.h dessin.h 

snake : $(OFILES)
	$(CC) -o snake $(OFILES) -lgraph -lx11 -lxpm
