#include <unistd.h> // (Unix standard) -1.Basic I/O operations - read(), write(), close(), 2.0 Process_control - fork(), exec(),
lseek()
#include <stdio.h> // standard input/output) printf(), scanf(), fopen(), fclose(), fprintf(), fscanf()
#include <fcntl.h> //(File control), open()
int main () {
//Variable declaration
int fd; //file descriptor to represent opened files
char buffer[80]; // character array used to store the content read from the file.
char msg[50] = "Hello World"; //A character array containing the message "Hello World" to be written to the file
fd = open("check.txt", O_RDWR); //opens a file named "check.txt" with both read and write access (O_RDWR).
printf("fd = %d ", fd); // print the descriptor
if (fd != -1) { //Checks if the file was opened successfully
printf("\n Check.txt opened with read write access ");
write(fd, msg, sizeof(msg)); //Writes the content of the msg array ("Hello World") to the file
lseek(fd,0, SEEK_SET); //Moves the file cursor (or file pointer) to the beginning of the file using lseek to prepare for
reading.
read(fd, buffer,sizeof(msg)); //Reads the content of the file into the buffer array.
printf("\n %s was written to my file \n ", buffer); //Prints the content that was read from the file.
close(fd); //Closes the file using close().
}
return 0; //Indicates a successful execution of the program.
}