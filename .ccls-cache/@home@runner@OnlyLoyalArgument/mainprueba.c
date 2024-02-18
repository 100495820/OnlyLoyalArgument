//P1-SSOO-23/24

#include <stdio.h>


int main(int argc, char *argv[])
{
  /*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
  if(argc < 2)
  {
    printf("Too few arguments\n");
    return -1;

  }
      FILE *file;
      int lines = 0;
      int words = 0; 
      int bytes = 0;
      char c;
      int inaword = 0;

      file = fopen(argv[1], "r");

    if (file == NULL) {
          printf("Cannot open file.\n");
          return 1;
    }

    while ((c = fgetc(file)) != EOF) {
      bytes++;
        if (c == '\n') {
          lines++;
        }
        if (c == ' ' || c == '\n') {
          inaword = 0;
        } 
        else if (inaword == 0) {
          inaword = 1;
          words++;
        }
    }

      fclose(file);
      printf("%d %d %d %s\n", lines, words, bytes, argv[1]);
    return 0;
}
