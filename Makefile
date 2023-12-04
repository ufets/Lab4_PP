
CFLAGS = -c -Wall -std=c11 -g -o2 -fopenmp

LDFLAGS = -fopenmp

SRCS= main.c open_mp_w.c alghorithm.c

OBJS = main.o open_mp_w.o alghorithm.o

all: project $(SRCS)

project: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o project

open_mp_w.o: open_mp_w.c
	$(CC) $(CFLAGS) open_mp_w.c -o open_mp_w.o
alghorithm.o: alghorithm.c
	$(CC) $(CFLAGS) alghorithm.c -o alghorithm.o
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

clean:
	rm -rf $(OBJS)