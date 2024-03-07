//P1-SSOO-23/24

#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#define BUF_SIZE 1 
// Define the buffer size as 1

int main(int argc, char *argv[]) 
{
  /*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
  if(argc < 2) // Check if the number of arguments is less than 2
  {
    printf("Too few arguments\n"); 
    return -1; // Return -1 as an error code

  }
  else if (argc > 3) // Check if the number of arguments is greater than 3
  {
    printf("Too many arguments\n");
  }
      int file; // Variable for file descriptor
      int lines = 0; 
      int words = 0; 
      int bytes = 0; 
      int inaword = 0; // Variable to keep track if currently reading a word or not
      char buffer[BUF_SIZE]; // Declaring a character array named buffer with a size of BUF_SIZE = 1


    file = open(argv[1], O_RDONLY); // Open the file in read-only mode

    if (file < 0) { // Check if the file can be opened
          printf("Can't open file.\n");
          return -1; // Return -1 as an error
    }

    lseek(file, 0, SEEK_SET); // Set the file pointer to the beginning of the file

    while (read(file,buffer,1) > 0) { // Read the file one byte at a time
      bytes++; //Add to byte count
        if (buffer[0] == '\n') { // Check if there is a new line
          lines++; // Add to line count
        }
        if (buffer[0] == ' ' || buffer[0] == '\n' || buffer[0] == '\t') { // Check if the character read is a space, a new line, or tab
          inaword = 0; // Set inaword to 0 as we aren't in a word
        }
        else if (inaword == 0) { // Check if we weren't in a word
          inaword = 1; // Set that we are in a word
          words++; // Add to word count
        }
    }

      if (close(file)<0){ // Check if the file can be closed
        printf("Error: closing file\n");
          return -1; // Return -1 as an error
      };

      printf("%d %d %d %s\n", lines, words, bytes, argv[1]); // Print the number of lines, words, bytes and the name of the file
    return 0; // Return 0 as everything went correctly
}