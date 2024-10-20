#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    // Step 1: Convert argv[1] to an integer and allocate memory
    int size = atoi(argv[1]);
    if (size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    void *memory = malloc(size);
    if (!memory) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Step 2: Fill the memory with 'A' to 'Z' and '1' to '9' repeatedly
    char *char_ptr = (char *)memory;
    char pattern[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    int pattern_len = strlen(pattern);

    for (int i = 0; i < size; i++) {
        char_ptr[i] = pattern[i % pattern_len];
    }

    // Print the filled memory as a string (it might not be null-terminated)
    printf("Filled memory: ");
    for (int i = 0; i < size; i++) {
        printf("%c", char_ptr[i]);
    }
    printf("\n");

    // Step 3: Use an int* to print memory content and its subtract-1 value
    int *int_ptr = (int *)memory;
    int remaining_bytes = size;

    printf("\nInteger memory content:\n");
    while (remaining_bytes >= sizeof(int)) {
        int current_value = *int_ptr;
        printf("%d : %d\n", current_value, current_value - 1);
        int_ptr++;
        remaining_bytes -= sizeof(int);
    }

    // Step 4: Clean up memory
    free(memory);

    return 0;
}
