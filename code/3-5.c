#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char buf[64];

    while (fscanf(fp, "%s", buf) == 1) {
        int num;
        if (sscanf(buf, "%d", &num) == 1) {
            sum += num;
        } else {
            fprintf(stderr, "invalid input %s\n", buf);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
