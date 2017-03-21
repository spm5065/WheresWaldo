#compiler
CC=g++

CFLAGS= -c -Wall
COPENCV= `pkg-config --cflags opencv`
CLIBRAW= `pkg-config --cflags libraw_r`

LIBOPENCV= `pkg-config --libs opencv`
LIBLIBRAW= `pkg-config --libs libraw_r`

waldoSOURCE=WheresWaldo.cpp
waldoTARGET=WheresWaldo.o

all: waldo

waldo:
	$(CC) $(COPENCV) $(waldoSOURCE) $(LIBOPENCV) -o $(waldoTARGET)
