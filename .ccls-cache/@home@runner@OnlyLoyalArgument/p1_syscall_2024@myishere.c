//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	/* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
	if(argc < 3)
	{
		printf("Too few arguments\n");
		return -1;
	}

  DIR *dir;
  struct dirent *entry;
  int found = 0;

  dir = opendir(argv[1]);

  if (dir == NULL){
    printf("Error: opening directory\n");
    return -1;
  }

  while ((entry = readdir(dir)) != NULL && found != 1) {
    if (strcmp(entry->d_name, argv[2]) == 0){
      found = 1;
    }
  }
  if (closedir(dir)<0){
    printf("Error: closing directory\n");
    return -1;
  }
  if (found == 1) {
    printf("File %s is in directory %s\n", argv[2], argv[1]);
  }
  else {
    printf("File %s is not in directory %s\n", argv[2], argv[1]);
    }

	return 0;
}
