#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME_SIZE 32
#define MAX_LINE 256


int file_updater(char filename[FILENAME_SIZE], int replace_line, char replace[MAX_LINE]) {
    char temp_filename[FILENAME_SIZE], buffer[MAX_LINE];
    int line_cur = 1;
    FILE *fp, *fp_temp;

    strcpy(temp_filename, "temp__");
    strcat(temp_filename, filename);


    fp = fopen(filename, "r");
    fp_temp = fopen(temp_filename, "w");

    if (fp_temp == NULL || fp == NULL) {
        printf("FILE ERROR: FILE CAN NOT BE OPENED");
        return 1;
    }

    bool reading = true;

    do {
        fgets(buffer, MAX_LINE, fp);

        if (feof(fp)) {
            reading = false;
        }
        else {
            if (line_cur == replace_line) {

                fprintf(fp_temp, replace);
                fprintf(fp_temp, "\n");
            }

            else {
                fputs(buffer, fp_temp);
            }
        }

        line_cur += 1;

    } while (reading);

    fclose(fp);
    fclose(fp_temp);

    remove(filename);
    rename(temp_filename, filename);

}

void main() {
    file_updater("txt.txt", 1, "STATUS: DEACTIVE");
}