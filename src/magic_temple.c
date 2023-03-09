#include "./include/magic_utils.h"

/**
 * @brief Function to solve every task
 * depending on the task number selector
 * 
 * @return int 0 if execution went successfully
 */
int main(void) {
    int32_t task_number = 0;

    /* Read the task number */
    if (scanf("%d", &task_number) > 1) {
        fprintf(stderr, "Error: Invalid input format\n");
        return EXIT_FAILURE;
    }

    /* Solve the desired task */
    switch (task_number) {
        case 1:
            magic_words();
            break;
        case 2:
            magic_ciphers();
            break;
        case 3:
            two_grams();
            break;
        default:
            fprintf(stderr, "Error: Undefined task number.\n");
            return EXIT_FAILURE;
    }

    /* Everything went successfully */
    return 0;
}