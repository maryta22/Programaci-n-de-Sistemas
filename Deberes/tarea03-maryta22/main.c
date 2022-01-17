#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

bool cflag = false;
bool fflag = false;

#define MAXWORD 20

int count_words(char *filename, int size){
	int count = 0;
	char word[100];
	FILE *file = fopen(filename, "r");
	if (file == NULL){
		fprintf(stderr,"ERROR: The file doesnt exits \n");
		return 0;
	}else{
		while( fscanf(file, "%s", &word) != -1 ){
                	if( strlen(word) >= size ){
                        	count++;
                	}
		}
        }
        return count;
}


void print_help(char *command){
	printf("Programa en C ejemplo, imprime argumentos ingresados en consola.\n");
	printf("uso:\n %s [-h] [-c] [-f] [arg 1] [arg 2] ... [arg n]\n", command);
	printf(" %s -h\n", command);
	printf("Opciones:\n");
	printf(" -h\t\t\tAyuda, muestra este mensaje\n");
	printf(" -c\t\t\tIngresa mínimo de letras por palabra\n");
	printf(" -f\t\t\tIngresa archivo\n");
}

int main(int argc, char **argv)
{
	int opt;
	int n = 0;
	char *file;

	//helper: https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html#Example-of-Getopt
	/* Este lazo recorre los argumentos buscando las opciones -c, -f */
	while ((opt = getopt (argc, argv, "hc:f:")) != -1){
		switch(opt){
			// atoi( texto ) --> convierte a entero
			case 'h':
				print_help(argv[0]);
				return 0;
			case 'c':
				cflag = true;
				n = atoi(optarg);
				break;
			case 'f':
				fflag = true;
				file = optarg;
				break;
			case '?':
			default:
				fprintf(stderr, "uso: %s [-c N] [-f filename] [arg 1] [arg 2] ... [arg n]\n", argv[0]);
				fprintf(stderr, "     %s -h\n", argv[0]);
				return -1;
		}
	}

	//Valida que opciones con argumentos haya sido ingresados
	if(n<0){
		fprintf(stderr, "Su número no es entero positivo");
		return -1;
	}


	int count = count_words(file, n);
	printf("The number of words with length>=%d in '%s' file is %d.\n",n,file,count);

	/* El programa se invocó sin usar opciones o argurmentos */
	if(argc == 1)
		print_help(argv[0]);
}
