//P1-SSOO-23/24

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>
#include <limits.h>


int main(int argc, char *argv[])
{
    struct dirent *entry;// Pointer to a dirent 
    DIR *dir;			// Pointer to a directory 
    char path[PATH_MAX];// Character array to store the current working directory path
    if (argc > 2){
      printf("Too many arguments\n");
      return -1;
    }
    if (argv[1] == NULL) { // If argument is empty we will select current directory
        if (getcwd(path, PATH_MAX)!=NULL) { // Get the current working directory
          dir = opendir(path); // Open the current working directory
        }
        else{
          printf("Error: could not open current directory\n");	// Print error message if current directory cannot be opened
          return -1; //Return -1 if an error occurs
        }
    } else {
        dir = opendir(argv[1]);// Open the directory entered by the argument
    }

    if (dir == NULL) { // Check if directory exists
        printf("Error: opening directory\n");
        return -1;// Return -1 if an error occurs
    }

    while ((entry = readdir(dir)) != NULL) { // Loop through the directory entries
        printf("%s\n", entry->d_name); // Print the name of each entry
    }

    if (closedir(dir)<0) { // Check if directory closes properly
        printf("Error: opening directory\n");
        return -1;// Return -1 if an error occurs
    }

    return 0; // Return 0 if everything went correctly
}
