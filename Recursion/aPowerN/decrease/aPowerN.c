#include <stdio.h>

void powerSeriesToFile(int base, int exponent, int constantFactor, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "Size\tOperation Count\n");

    for (int size = 10; size <= 100; size += 10) {
        int term = base;
        int operationCount = 1;  // Include  initial term in the count

        for (int i = 1; i <= exponent; i++) {
            term = term / constantFactor;
            operationCount++;
        }

        fprintf(file, "%d\t%d\n", size, operationCount);
        base += 10;  // Increase the base value for the next iteration
    }

    fclose(file);
}

int main() {
    int base = 2;  // Base value
    int exponent = 3;  // Exponent
    int constantFactor = 2;  // Constant factor
    const char* filename = "size_vs_operation_count.txt";

    powerSeriesToFile(base, exponent, constantFactor, filename);

    printf("Data has been written to %s.\n", filename);

    return 0;
}
