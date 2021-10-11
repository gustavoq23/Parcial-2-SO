#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[]) {

    pid_t pid_hijo;
    FILE *inFile = fopen("./text.txt","w+");
        if (inFile == NULL){
            perror("open file fails: ");
            return(EXIT_FAILURE);
        }

    char *endptr;
    int numeros[argc - 1];
    int maximo;
    errno = 0;
    char *args[] = {"./nuevo_proceso", NULL};

    pid_hijo = fork();

    switch(pid_hijo) {
        case -1: /* Error */
            printf("Error al crear el proceso");
            return -1;
        case 0: /* Código ejecutado por el hijo */
            for (int i = 1; i < argc; i++) {
                numeros[i - 1] = strtol(argv[i], &endptr, 10);
            }

            if(errno != 0) {
                perror("strtol");
                exit(EXIT_FAILURE);
            }

            maximo = numeros[0];
            for (int i = 1; i < argc - 1; i++) {
                if(numeros[i] > maximo) {
                    maximo = numeros[i];
                }
            }

            fprintf(inFile, "%d", maximo);
            //fclose(inFile);
        break;
        default: /* Código ejecutado por el padre */
            execv(args[0],args);
    }
    exit(EXIT_SUCCESS);
}
