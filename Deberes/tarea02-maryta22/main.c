#include "header.h"
float main(){ //float para majear decimales.

	FILE *fileptr; //para leer el archivo.

	fileptr = fopen("elephant.txt" , "r"); //las separaciones estarán señaladas por espacios o saltos de línea.

	if (fileptr == NULL){ //verificar si exite el archivo.
		fprintf(stderr,"ERROR: The file elephant.txt doesnt exits \n"); //si no exite se enviará este mensaje.
		return 0; //si no existe retornará 0
	}

	float prom = promedio(fileptr); //se obtiene el promedio del método promedio() en la clase funciones.c.

	fclose(fileptr); //se cierra el archivo.

	return prom; //se retorna el promedio.
}
