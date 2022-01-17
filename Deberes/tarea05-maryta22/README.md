# Tarea05

La tarea consiste en mejorar el código del taller realizado de encriptación/desencriptación, deberá realizar las modificaciones necesarias para que ahora su código adicionalmente pueda encriptar/desencriptar todos los archivos dentro de una carpeta especificada

```
$ ./secret -h
secret encripta o desincripta un archivo usando el algoritmo Blowfish.
uso:
 ./secret [-d] [-c] -k <key> <nombre_archivo|nombre_carpeta>
 ./secret -h
Opciones:
 -h			Ayuda, muestra este mensaje
 -d			Desencripta el archivo en lugar de encriptarlo.
 -c			Encripta/Desencripta una carpeta en vez de un archivo
 -k <key>		Específica la clave (key) de encriptación, 8 bytes en hex.
```

El argumento *<nombre_archivo|nombre_carpeta>* es obligatorio, y dependiendo si recibe la opción -c servirá para identificar si es el nombre de un archivo o una carpeta. 

## Ejemplos de uso
Si se desea desencriptar un archivo
```
./secret -d -k PALABRACLAVE archivo_encriptado.txt
```

Si se desea desencriptar una carpeta
```
./secret -d -k PALABRACLAVE carpeta_con_archivos -c
```

La palabra clave, deberá convertise a [SHA1](http://www.sha1-online.com/) y tomar los 16 primeros caracteres para luego transformarlos a connotación hexadecimal.


Deberá crearse, en tiempo de ejecución, dos carpetas llamadas _archivos_encriptados_ y _archivos_desencriptados_ donde se guardarán los archivos dependiendo del caso. No poner la extensión .enc o .dec a los archivos.

## Retos

1. Leer varios archivos de una carpeta
2. Encriptar/Desencriptar cada archivo leído


## Evaluacion

* Crear carpetas. 1pt
* Leer achivos de carpeta. 1pt
* Convertir palabra clave a SHA1. 1pt
* Encriptar/Desencriptar todos archivos. 2pts
