#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(void)
{ 
    size_t RD, WR;
    char *buff = NULL;
    size_t len = 0;

            while(1)
            {
            write(STDOUT_FILENO, "$", 1);        
            RD = getline(&buff, &len, stdin);
            if (RD ==  '\0')
            {
                free(buff);
                write(STDOUT_FILENO, "Exiting the shell...\n", 23);
                exit(0);
            }
            WR = fwrite(buff, 1, RD, stdout);
            buff[RD] = '\0';
            if (WR != RD)
            {
                write(STDERR_FILENO, "can't write back from standart input\n", 39);
                exit(100);
            }
            }
            return (0);
}