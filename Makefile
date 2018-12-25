CC = gcc
CFLAGS = -Wall

benchmark : benchmark.c
	@echo "Creating object file without main..."
	$(CC) $(CFLAGS) -c $^