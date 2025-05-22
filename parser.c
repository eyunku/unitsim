#include <stdio.h>
#include <stdbool.h>

#define BUFFSIZE 255

int main(int argc, char* argv[]) {
    // parse input file
    FILE *fp;
    if (argc == 1) {
        printf("Input file to read: ");
        char filename[BUFFSIZE];
        int c, i = 0;
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

    // parse units file
    char keys[32][BUFFSIZE];
    char values[7][BUFFSIZE];

    FILE *unitfile;
    if ((unitfile = fopen("units.uf", "r")) == NULL) {
        printf("Unable to open units file\n");
        return -1;
    }
    
    // writekey is true when writing to key
    int i = 0, j = 0, writekey = true, c;
    while ((c = fgetc(unitfile)) != EOF) {
        if (i <= BUFFSIZE) {
            printf("Maximum number of units inputted, ignoring rest of file\n");
            break;
        }

        if (c == '\n') { // move to next entry
            i++;
            writekey = true;
            j = 0;
        } else if (c == ' ') { // terminate key string
            *(keys[i] + j) = '\0';
            writekey = false;
        } else {
            if (writekey) {
                *(keys[i] + j++) = c;
            } else if (c == ',') {
                continue;
            } else {
                // parse minus signs and stuff idk ill think about it later
            }
        }
    }
}