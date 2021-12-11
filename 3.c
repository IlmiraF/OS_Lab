#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    FILE *fd;
    fd = fopen(argv[1],"w");

    if (fd == NULL) {
      printf("%s","Error in open file.\n");
      return 1;
    }
 
    int c;
    while ((c=getc(stdin)) != EOF)
      fputc(c,fd);
 
    if (fclose(fd) != 0) {
      printf("%s","Error in close file.\n");
      return 1;
    }
  
    return 0;
}
