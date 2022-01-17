CC= gcc
CFLAGS= -I.
OBJ= main.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

programa: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm *.o programa
