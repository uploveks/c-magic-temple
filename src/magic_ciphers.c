#include "./include/magic_utils.h"

#define LETTER_NUM 26
#define DIGITS_NUM 10
#define MAX_KEY_LEN 15
#define BUFFER_LEN 1024
#define MAX_KEY_LEN 256

/**
 * @brief Function to print a string literal
 * on the stdout
 * 
 * @param str a pointer to a string object
 */
void print_string(const char* str) {
    if (str == NULL) {
        return;
    }
    printf("%s", str);
}

/**
 * @brief Function to reverse a string object
 * 
 * @param str a pointer to a string object
 */
void reverse_string(char* str) {
    if (str == NULL) {
        return;
    }

    size_t str_len = strlen(str);
    size_t half_str_len = str_len / 2;

    /* Reverse string */
    for (size_t i = 0; i < half_str_len; ++i) {
        char temp_chr = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = temp_chr;
    }
}

/**
 * @brief Deciphers a message that was encoded using the Caesar cipher
 * 
 * @param code[in/out] A pointer to the encoded message. The deciphered
 *                     message will be written back to this pointer.
 * @param code_key The encryption key used to encode the message. Must be
 *                 a number between 0 and 25.
 */
void caesar_decipher(char * const code, int32_t code_key) {
    if (code == NULL) {
        return;
    }
    // Ensure that the code key is within the valid range
    code_key = code_key % LETTER_NUM;
    
    // Decipher each character in the message
    for (int32_t iter = 0; code[iter] != '\0'; ++iter) {
        if ((code[iter] >= 'a') && (code[iter] <= 'z')) {
            // Decipher a small letter
            code[iter] = (code[iter] - code_key < 'a') ?
                            code[iter] - code_key + LETTER_NUM : code[iter] - code_key;
        } else if ((code[iter] >= 'A') && (code[iter] <= 'Z')) {
            // Decipher a big letter
            code[iter] = (code[iter] - code_key < 'A') ?
                            code[iter] - code_key + LETTER_NUM : code[iter] - code_key;
        } else if ((code[iter] >= '0') && (code[iter] <= '9')) {
            // Decipher a digit
            code[iter] = (code[iter] - code_key < '0') ?
                            code[iter] - code_key + DIGITS_NUM : code[iter] - code_key;
        }
    }
}

/**
 * @brief Subroutine program to decipher a string of numbers
 * encrypted by caesar cipher. The string will be modified in-place
 *
 * @param code[in/out] a pointer to a string object
 * @param code_key the caesar encryption key
 */
void caesar_decipher_numbers(char * const code, int32_t code_key) {
    if (code == NULL) {
        return;
    }

    /* Decipher */
    for (int32_t iter = 0; code[iter] != '\0'; ++iter) {
        if (isdigit(code[iter])) {
            if (code[iter] - code_key < '0') {
                code[iter] += DIGITS_NUM - code_key;
            } else {
                code[iter] -= code_key;
            }
        }
    }
}

/**
 * @brief Program to decipher the vigenere encryption. The decoded
 * message will be found in-place in the encoded message
 *
 * @param code[in/out] a pointer to a string object
 * @param str_key the string vigenere encryption key
 */
void vigenere_decipher(char * const code, const char * const str_key) {
    if ((code == NULL) || (str_key == NULL)) {
        return;
    }

    size_t str_key_len = strlen(str_key);

    /* Decipher */
    for (int32_t iter = 0; code[iter] != '\0'; ++iter) {

        /* Get the code key from string encryption key */
        int code_key = toupper(str_key[iter % str_key_len]) - 'A';

        if (islower(code[iter])) {

            /* Decipher a small letter */
            if (code[iter] - code_key % LETTER_NUM < 'a') {
                code[iter] += LETTER_NUM - code_key % LETTER_NUM;
            } else {
                code[iter] -= code_key % LETTER_NUM;
            }
        } else if (isupper(code[iter])) {

            /* Decipher a big letter */
            if (code[iter] - code_key % LETTER_NUM < 'A') {
                code[iter] += LETTER_NUM - code_key % LETTER_NUM;
            } else {
                code[iter] -= code_key % LETTER_NUM;
            }
        } else if (isdigit(code[iter])) {

            /* Decipher a number */
            if (code[iter] - code_key % DIGITS_NUM < '0') {
                code[iter] += DIGITS_NUM - code_key % DIGITS_NUM;
            } else {
                code[iter] -= code_key % DIGITS_NUM;
            }
        }
    }
}

/**
 * @brief Function to calculate the sum of two numbers represented as string literals.
 * 
 * @param str1 A pointer to the biggest string object.
 * @param str2 A pointer to the smallest string object.
 * @return char* A pointer to an allocated string object or NULL.
 */
char* add_two_strings(const char * const str1, const char * const str2) {
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    /* Allocate the result string */
    char* add_str = malloc(str1_len + 2);

    if (add_str == NULL) {
        return NULL;
    }

    int32_t rest = 0, current_count = 0;

    /* Add the two strings */
    for (size_t iter = 0; iter < str1_len; ++iter) {
        if (iter < str2_len) {
            current_count = str1[str1_len - iter - 1] - '0' + str2[str2_len - iter - 1] - '0' + rest;
        } else {
            current_count = str1[str1_len - iter - 1] - '0' + rest;
        }

        add_str[iter] = current_count % 10 + '0';
        rest = current_count / 10;
    }

    /* Add the last remaining */
    if (rest != 0) {
        add_str[str1_len] = rest + '0';
        add_str[str1_len + 1] = '\0';
    } else {
        add_str[str1_len] = '\0';
    }

    /* Reverse the result string */
    size_t len = strlen(add_str);
    for (size_t i = 0; i < len / 2; ++i) {
        char temp = add_str[i];
        add_str[i] = add_str[len - i - 1];
        add_str[len - i - 1] = temp;
    }

    /* Return the result string */
    return add_str;
}

void magic_ciphers(void) {
    /* Allocate a string buffer */
    char *encoded = (char*)malloc(BUFFER_LEN);

    if (encoded == NULL) {
        return;
    }

    /* Read the buffer */
    if (scanf("%s", encoded) < 1) {
        free(encoded);
        return;
    }

    if (strcmp(encoded, "caesar") == 0) {
        /* The encoded buffer will solve the caesar decipher */
        int32_t code_key = 0;

        /* Read the encryption key */
        if (scanf("%d", &code_key) < 1) {
            free(encoded);
            return;
        }

        /* Read the encoded string to decipher */
        if (scanf("%s", encoded) < 1) {
            free(encoded);
            return;
        }

        /* Decipher the message and print it */
        caeser_deciphering(encoded, code_key);
        print_code(encoded);
        printf("\n");

        free(encoded);
    } else if (strcmp(encoded, "vigenere") == 0) {
        /* The encoded buffer will solve the vigenere decipher */
        char *str_key = (char*)malloc(MAX_KEY_LEN);

        if (str_key == NULL) {
            free(encoded);
            return;
        }

        /* Read the encryption string key */
        if (scanf("%s", str_key) < 1) {
            free(str_key);
            free(encoded);
            return;
        }

        /* Read the encoded message */
        if (scanf("%s", encoded) < 1) {
            free(str_key);
            free(encoded);
            return;
        }

        /* Decipher the code and print it */
        vigenere_deciphering(encoded, str_key);
        print_code(encoded);
        printf("\n");

        free(str_key);
        free(encoded);
    } else if (strcmp(encoded, "addition") == 0) {
        /* The encoded buffer will solve the two string addition */
        free(encoded);

        int32_t code_key = 0;

        /* Allocate two strings to add */
        char *str1_nums = (char*)malloc(BUFFER_LEN);
        char *str2_nums = (char*)malloc(BUFFER_LEN);

        if (str1_nums == NULL || str2_nums == NULL) {
            free(str1_nums);
            free(str2_nums);
            return;
        }

        /* Read the caeser cipher key for numbers */
        if (scanf("%d", &code_key) < 1) {
            free(str1_nums);
            free(str2_nums);
            return;
        }

        /* Read the string literals */
        if (scanf("%s%s", str1_nums, str2_nums) < 2) {
            free(str1_nums);
            free(str2_nums);
            return;
        }

        /* Decipher the strings */
        caeser_deciphering_numbers(str1_nums, code_key % DIGITS_NUM);
        caeser_deciphering_numbers(str2_nums, code_key % DIGITS_NUM);

        /* Reverse the strings so you could add them */
        reverse_string(str1_nums);
        reverse_string(str2_nums);

        size_t str1_nums_len = strlen(str1_nums);
        size_t str2_nums_len = strlen(str2_nums);

        char *add_str = NULL;

        /* Compute the addition strings result */
    if (str1_nums_len > str2_nums_len) {
        add_str = add_two_strings(str1_nums, str2_nums, str1_nums_len, str2_nums_len);
    } else {
        add_str = add_two_strings(str2_nums, str1_nums, str2_nums_len, str1_nums_len);
    }

    /* Reverse the result string */
    reverse_string(add_str);

    int trailling_zero = 0;

    /* Calculate the trailling zeros from the beginning of number */
    for (int32_t iter = 0; add_str[iter] != '\0'; ++iter) {
        if (add_str[iter] != '0') {
            break;
        } else {
            ++trailling_zero;
        }
    }

    /* Print the result string without trailling zeros */
    print_code(add_str + trailling_zero);

    free(str1_nums);
    str1_nums = NULL;

    free(str2_nums);
    str2_nums = NULL;

    free(add_str);
    add_str = NULL;

    printf("\n");

    } else {

        /* Encoded buffer does NOT know what to solve */
        printf("Unknown command ........ EXIT!\n");

        free(encoded);
        encoded = NULL;

        return;
    }
}