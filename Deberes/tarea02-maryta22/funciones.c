#include "header.h"

float promedio(FILE *file){
	float count = 0 , sum = 0 , n , prom ;

	while(!feof(file)){
		fscanf(file,"%f",&n); //obtengo el número a sumar
		sum=sum + n; //sumo
		count ++;//cuento los elefantes
	}

	prom = (sum-n)/(count-1); //hallo el promedio (le resto n y 1 porque el valor final lo toma 2 veces)

	printf("Peso promedio: %.2f",prom);

	return prom;
}
