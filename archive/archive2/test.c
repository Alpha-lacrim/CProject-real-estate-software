#include<stdio.h>
#include<time.h>

int main() {
    FILE *fp;
    time_t t;
    time(&t);
    printf("\nADDED_ON: %s", ctime(&t));
    fp = fopen("txt.txt", "w");

    if (feof(fp) == 0) {
        fprintf(fp, "ADDED_ON: %s", ctime(&t));
        fflush(stdout);
    }
    fclose(fp);
    return 0;
}