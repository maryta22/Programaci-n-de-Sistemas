#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <syslog.h>
#define BUFFER_LEN 1024

void separar_tokens(char* argv[], char* linea, char* delim);
void recoger_hijos(int signal);
void imprimirAyuda();

int main(){
       	char line[BUFFER_LEN];
	char* path= "/bin/";
	char* delim = " ";
	char* argv[100];
       	char progpath[20];
	int argc;

while(1){

	signal(SIGCHLD, recoger_hijos);

       	printf(">> ");                    //prompt

	if(!fgets(line, BUFFER_LEN, stdin))
		break;

	size_t length = strlen(line);

	if(line[length-1] == '\n')
		line[length -1] = '\0';

	if(strcmp(line, "QUIT") == 0){
        	printf("BYE\n");
		exit(0);
	}

       	separar_tokens(argv,line,delim);

       	strcpy(progpath, path);
       	strcat(progpath, argv[0]);

       	for(int i=0; i<strlen(progpath); i++){
           	if(progpath[i]=='\n')
               		progpath[i]='\0';
       	}

       	int pid = fork();

       	if(pid == 0){
           	execvp(progpath,argv);
           	fprintf(stderr, "No se pudo realizar el execvp\n");
       	}else{
           	wait(NULL);
		fprintf(stderr,"Éxito\n");
       	}
}
}

void separar_tokens(char* argv[], char* linea, char* delim){
	char *token;
	int i = 0;

	printf("Separación en tokens:\n");

	/* obtiene el primer token */
	token = strtok(linea, delim);

	/*recorre todos los tokens */
	while( token != NULL ){
		argv[i] = token;
		if(i==1 && argv[1] == "-h")
                        imprimirAyuda();
		printf("%d. %s\n", ++i, token);
		token = strtok(NULL, delim);
	}

}

void recoger_hijos(int signal){
	while(waitpid(-1,0,WNOHANG) > 0);
	return;
}

void imprimirAyuda(){
	printf("Servidor simple de ejecución remota de comandos.\n");
	printf(" -h \n");
	printf("Opciones:\n");
	printf(" -h\t\t\tAyuda, muestra este mensaje\n");
}
