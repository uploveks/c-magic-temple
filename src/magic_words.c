#include "./include/magic_utils.h"

#define MAX_MATRIX_DIM 100
#define WORD_SEPARATOR " "
#define MAX_TYPE_A_LEN 5
#define TENS_NUM       10
#define DIRECTION_NUMBERS 4
#define BUFFER_LEN 100


/**
 * @brief Function to check if a string is palindrome
 * 
 * @param str a pointer to a string object
 * @param str_len the length of the string object
 * @return uint8_t 1 if string is palindrome, 0 otherwise
 */
uint8_t is_palindrome(const char *str, const int32_t str_len) {
    if (NULL == str) {
        return 0;
    }

    const int32_t half_len = str_len / 2;

    for (int32_t iter = 0; iter < half_len; ++iter) {
        if (str[iter] != str[str_len - iter - 1]) {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Function to check if an integer number
 * is prime or not.
 * 
 * @param check_num number to check 
 * @return uint8_t 1 if number is prime, 0 otherwise
 */
uint8_t is_prime(const int32_t check_num) {
    if (check_num < 2) {
        return 0;
    } else if (check_num == 2) {
        return 1;
    }

    for (int32_t iter = 2; (iter * iter) <= check_num; ++iter) {
        if (check_num % iter == 0) {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Function to solve "magic words" task explained
 * in the readme file
 * 
 */
void magic_words(void) {
    /* Initialize dimensions and the path matrix */
    int32_t row_dim = 0, col_dim = 0;
    int32_t path[MAX_MATRIX_DIM][MAX_MATRIX_DIM] = {{0}};

    int32_t last_x = 0, last_y = 0, count_steps = 1;

    /* Initialize string buffers */
    char line[BUFFER_LEN] = "", code[BUFFER_LEN] = "";

    if (scanf("%d%d\n", &row_dim, &col_dim) < 2) {
        return;
    }

    path[last_y][last_x] = count_steps;

    if (fgets(line, BUFFER_LEN, stdin) == NULL) {
        return;
    }

    /* Traverse every word from line */
    for (char *token = strtok(line, WORD_SEPARATOR); token != NULL; token = strtok(NULL, WORD_SEPARATOR)) {
        const char c = tolower(token[0]);

        /* Processing code is the first type */
        if (c == 'a') {
            const size_t len = strlen(token);

            /* Find the maximum number from code */
            char max_code_char = '0';
            int32_t max_code_index = 0;
            for (int32_t i = 1; i < len && i < MAX_TYPE_A_LEN; ++i) {
                if (token[i] > max_code_char) {
                    max_code_char = token[i];
                    max_code_index = i;
                }
            }
            /* Compute the moving path */
            if (circular_sum == 0) {
                --last_x;
            } else if (circular_sum == 1) {
                --last_y;
            } else if (circular_sum == 2) {
                ++last_x;
            } else {
                ++last_y;
            }
        } else {

            /* Code type unknown */
            printf("Uknown opperand ... moving to next\n");
        }

        /* Update path matrix */
        path[last_y][last_x] = count_steps;

        /* Extract the next word */
        code = __strtok_r(NULL, WORD_SEPARATOR, &rest);
    }

    /* Print the resulting matrix after all operations */
    for (int32_t iter_i = 0; iter_i < row_dim; ++iter_i) {
        for (int32_t iter_j = 0; iter_j < col_dim; ++iter_j) {
            printf("%d ", path[iter_i][iter_j]);
        }

        printf("\n");
    }
}