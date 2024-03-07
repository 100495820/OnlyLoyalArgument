//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
  /* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
  if(argc < 3) // Check if the correct number of arguments are provided
  {
    printf("Too few arguments\n");
    return -1;
  }
  else if (argc>3){  // Check if there are more than expected arguments
    printf("Too many arguments\n");
    return -1;
  }
  DIR *dir;
  struct dirent *entry;
  int found = 0;

  dir = opendir(argv[1]); // Open the directory provided as the second argument

  if (dir == NULL){ // Check if the directory can be opened
    printf("Error: opening directory\n"); 
    return -1;
  }

  while ((entry = readdir(dir)) != NULL && found != 1) { // Look through all the entries while the file hasn't been found
    if (strcmp(entry->d_name, argv[2]) == 0){ // Check if the current entry matches the file name provided as the third argument
      found = 1; // If a match is found set found to 1
    }
  }
  if (closedir(dir)<0){ // Close the directory
    printf("Error: closing directory\n");
    return -1;
  }
  if (found == 1) { // Check if the file was found in the directory when found = 1
    printf("File %s is in directory %s\n", argv[2], argv[1]);
  }
  else {
    printf("File %s is not in directory %s\n", argv[2], argv[1]);
    }

  return 0; // Return 0 if everything works correctly
}
