#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *file;

    fd = open("esra.txt", O_RDONLY);

        printf("olmadııı");
    while ((file = get_next_line(fd)) != NULL)
    {
        printf("%s", file);
        free(file);
    }
    close(fd);
}