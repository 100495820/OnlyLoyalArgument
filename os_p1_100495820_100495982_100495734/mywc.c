//P1-SSOO-23/24

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
  /*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
  if(argc < 2)
  {
    printf("Too few arguments\n");
    return -1;

  }
      int file;
      int lines = 0;
      int words = 0; 
      int bytes = 0;
      int inaword = 0;
      int buffer[BUF_SIZE];

    if (argv[1]==NULL) {
      printf("No file entered\n");
      return -1;
    }
  
    file = open(argv[1], O_RDONLY);

    if (file < 0) {
          printf("Can't open file.\n");
          return -1;
    }
    
    lseek(file, 0, SEEK_SET); //We set the file pointer to the beginning of the file.
  
    while (read(file,buffer,1) > 0) {
      bytes++;
        if (buffer[0] == '\n') {
          lines++;
        }
        if (buffer[0] == ' ' || buffer[0] == '\n' || buffer[0] == '\t') {
          inaword = 0;
        } 
        else if (inaword == 0) {
          inaword = 1;
          words++;
        }
    }

      if (close(file)<0){
        printf("Error: closing file");
          return -1;
      };
  
      printf("%d %d %d %s\n", lines, words, bytes, argv[1]);
    return 0;
}


