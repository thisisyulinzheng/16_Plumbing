#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char *count(char *string) {
    char *c = malloc(sizeof(char));
    c[0] = -1;
    int i;
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') {
            (c[0])++;
        }
    }
    return c;
}

int main() {
    int buff_size = 256;
    char input[buff_size]; 
    char output[buff_size]; 

    mkfifo("harry", 0666); 
    mkfifo("potter", 0666); 

    int receive = open("harry", O_RDONLY); 
    int send = open("potter", O_WRONLY); 
    
    while(1) {
        read(receive, input, buff_size); 
        write(send, count(input), buff_size); 
    }
}
