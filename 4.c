#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[]) {
        FILE *fd;
        fd = fopen(argv[1], "r");
        int n = atoi(argv[2]);

        if (!fd) {
          printf("%s", "File open error\n");
          return 1;
        }

        if (n == 0) {
          n = 2147483646;
        }

        char s;
        int count = 1;

        while ((s=getc(fd)) != EOF) {
          if ((count == n) && (s == '\n')) {
            count = 1;
            
            if (getc(stdin)) {
              printf("\n");
            }
            
            continue;
          }
          
          if (count <= n) {
            printf("%c", s);
          }

          if (s == '\n') {
            count++;
          }
        }

        if (fclose(fd) == -1) {
          printf("%s", "File close error\n");
          return 1;
        }
  
        return 0;
}
