En funciones.c :
-Incluimos al header.
-El método es un float para trabajar con decimales.
-EL método recibe un FIle.
-Creo los datos que voy a utilizar.
-Mientras el archivo no llegue a su final:
	-Cuento los elefantes con la variable count.
	-Obtengo el valor para acomular la suma de los pesos.
	-Incremento la suma en la varibale sum.
-Hallo el promedio dividiento la suma para el total.
-Imprimo ese promedio (con 2 decimales) para visualizarlo en consola.
-Devuelvo el promedio

En main.c :
-Preparo el archivo en modo lectura.
-Verifico que exista
-Obtengo el promedio llamando a la funcion promedio y pasándole como parámetro el archivo elephant.txt.
-Cierro el archivo.
-Se retorna el promedio.

Makefile
-Makefile realizado con el modelo 7 ( con el archivo .h)
