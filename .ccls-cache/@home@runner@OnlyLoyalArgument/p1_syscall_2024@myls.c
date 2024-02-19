//P1-SSOO-23/24

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
    struct dirent *entry;
    DIR *dir;
    char path[PATH_MAX];

    if (argv[1] == NULL) {
        if (getcwd(path, sizeof(path))!=NULL) {
          dir = opendir(path);
        }

    } else {
        dir = opendir(argv[1]);
    }

    if (dir == NULL) {
        printf("Error opening directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}