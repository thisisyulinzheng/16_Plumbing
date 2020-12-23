#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int buff_size = 256;
    
    char input[buff_size]; 
    char output[buff_size]; 

    int send = open("harry", O_WRONLY); 
    int receive = open("potter", O_RDONLY); 

    while(1) {
        printf("Input:\n"); 
        fgets(input, buff_size, stdin);

        write(send, input, buff_size);  
        read(receive, output, buff_size);

        printf("\nOutput:\n"); 
        printf("Number of Characters: %d\n\n", output[0]); 
    }
}
