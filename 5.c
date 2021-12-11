#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[]) {
        FILE *file;
        file=fopen(argv[1], "r");
        FILE *file_copy;
        file_copy=fopen(argv[2], "wt");

        if (!file || !file_copy) {
          printf("%s", "File open error\n");
          return 1;
        }

        int s;
  
        while ((s=getc(file)) != EOF) {
          fputc(s, file_copy);
        }

        if ((fclose(file) == -1) || (fclose(file_copy) == -1)) {
          printf("%s", "File close error\n");
          return 1;
        }
  
        return 0;
}
