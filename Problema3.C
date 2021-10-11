#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <ctype.h>

#define BUF_SIZE 100

char commando[64];

void* recibe_comando(void *parg) {

    /*
    *   Desactivacion Echo
    */
    struct termios tp;

    /* Retrieve current terminal settings, turn echoing off */

    if (tcgetattr(STDIN_FILENO, &tp) == -1)
        exit(EXIT_FAILURE);
    
    tp.c_lflag &= ~ECHO;                /* ECHO off, other bits unchanged */
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp) == -1)
        exit(EXIT_FAILURE);

    while (1) {
        fgets(commando, 64, stdin);
    }
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]){

    FILE *inFile = fopen(argv[1],"r");
    if (inFile == NULL){
        perror("open file fails: ");
        exit(EXIT_FAILURE);
    }

    pthread_t threadID1;
    char buffer[64];
    char *status =  NULL;
    char upper[10] = "upper";
    char words[10] = "words";
    char vowels[10] = "vowels";
    char none[10] = "none";
    char *token;
    char sep[2] = " ";

    pthread_create(&threadID1,NULL,recibe_comando, NULL);
    
    do{
        status = fgets(buffer, sizeof(buffer),inFile);
        if(status != NULL){
            printf("%s",buffer);

            if (strcmp(name, upper) == 10) {
                int i = 0;
                char chars; 

                while (status[i]) { 
                    chars = status[i];
                    printf("%c", toupper(chars)); 
                    i++; 
                }
            }

            if (strcmp(name, words) == 10) {
                int i = 0;
                token = strtok(status, sep);
                while (token != 0) {
                    token = strtok(NULL, sep);
                    i++;
                }
                printf("Palabras = %d\n", i);
            }

            if (strcmp(name, vowels) == 10) {
                int i = 0;
                int j = 0;
                char chars; 

                while (status[i]) { 
                    chars = status[i];
                    if (chars == 97) j++;
                    if (chars == 101) j++;
                    if (chars == 105) j++;
                    if (chars == 111) j++;
                    if (chars == 117) j++;
                    if (chars == 160) j++;
                    if (chars == 130) j++;
                    if (chars == 161) j++;
                    if (chars == 162) j++;
                    if (chars == 163) j++;
                    i++;
                }
                printf("Vocales = %d\n", j);
            }

            if (strcmp(name, none) == 10) {
                // No hace nada
            }
            sleep(1);
        }
    }while (status !=NULL);

    printf("\n");
    fclose(inFile);

    exit(EXIT_SUCCESS);
}