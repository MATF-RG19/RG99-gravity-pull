PROGRAM = GravityPull
CC      = gcc
LDLIBS  = -lglut -lGLU -lGL -lm
CFLAGS  = -g -std=c99 -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
$(PROGRAM): main.o onKeyboard.o onTimer.o onDisplay.o header.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) main.o onTimer.o onKeyboard.o onDisplay.o header.o $(LDLIBS)
	
main.o: main.c
	$(CC) -c $(LDFLAGS) -o main.o main.c $(LDLIBS)

onTimer.o: ./../libraries/onTimer.c
	$(CC) -c $(LDFLAGS) -o onTimer.o ./../libraries/onTimer.c $(LDLIBS)

onDisplay.o: ./../libraries/onDisplay.c
	$(CC) -c $(LDFLAGS) -o onDisplay.o ./../libraries/onDisplay.c $(LDLIBS)

onKeyboard.o: ./../libraries/onKeyboard.c
	$(CC) -c $(LDFLAGS) -o onKeyboard.o ./../libraries/onKeyboard.c $(LDLIBS)

header.o: ./../libraries/header.c
	$(CC) -c $(LDFLAGS) -o header.o ./../libraries/header.c $(LDLIBS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM)