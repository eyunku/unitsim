#include <stdio.h>

#define BUFFSIZE 255

int main(int argc, char* argv[]) {
    FILE *fp;
    if (argc == 1) {
        printf("Input file to read: ");
        char filename[BUFFSIZE];
        char c;
        int i = 0;
        while ((c = fgetc(stdin)) != '\n' && c != EOF) {
            *(filename + i++) = c;
        }
        *(filename + i) = '\0';

        if ((fp = fopen(filename, "r")) == NULL) {
            printf("Unable to open file\n");
            return -1;
        }
    } else if (argc == 2) {
        char *filename = argv[1];

        if ((fp = fopen(filename, "r")) == NULL) {
            printf("Unable to open file\n");
            return -1;
        }
    }


}