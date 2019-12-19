name = Snake

but : $(name)

OFILES = snake.o \
	grid.o \
	gameMap.o \
	dessin.o \
	main.o

CC = gcc

CFLAGS = -lgraph -ansi

snake.o : ./include/snake.h

grid.o : ./include/grid.h ./include/snake.h

gameMap.o : ./include/gameMap.h ./include/grid.h ./include/snake.h

dessin.o : ./include/dessin.h ./include/gameMap.h ./include/grid.h ./include/snake.h 

main.o : ./include/dessin.h ./include/gameMap.h ./include/grid.h ./include/snake.h

Snake : $(OFILES)
	$(CC) -o $(name) $(OFILES) $(CFLAGS)

clean : 
	-rm -f $(OFILES) $(name)

run :
	./$(name)

.PHONY : but clean