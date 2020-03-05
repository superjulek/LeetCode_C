#name
NAME = LeetCode
# type of compiler
CC = gcc

CFLAGS = -c -Wall

# default target:
all: $(NAME)

$(NAME): main.o
	$(CC) main.o -o $(NAME)
main.o: main.c
	$(CC) $(CFLAGS) main.c 

# clean:
clean:
	rm -rf *o $(NAME)
