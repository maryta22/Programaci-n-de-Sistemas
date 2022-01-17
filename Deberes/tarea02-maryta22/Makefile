promedio: main.o funciones.o
	gcc -o promedio main.o funciones.o

%.o: %.c header.h
	gcc -c -I. -o $@ $<

.PHONY: clean
clean:
	rm *.o promedio
