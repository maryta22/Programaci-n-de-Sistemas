
programa: main.o distanceFunc.o
	gcc -o programa main.o distanceFunc.o

main.o: main.c
	gcc -o main.o -c -I. main.c

distanceFun.o: distanceFunc.c
	gcc -o distanceFunc.o -c -I. distanceFunc.c

.PHONY: clean
clean:
	rm *.o programa


