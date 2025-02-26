Write a LEX program to identify the capital words from the given input
CODE:
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isCapitalWord(const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isupper(word[i])) {
            return 0; // Not a capital letter
        }
    }
    return 1; // All characters are capital letters
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \t\n"); // Split input into tokens
    while (token != NULL) {
        if (isCapitalWord(token)) {
            printf("Capital word: %s\n", token);
        }
        token = strtok(NULL, " \t\n");
    }

    return 0;
}

output:
Enter a string: HELLO WORLD IS IN THE TEST
Capital word: HELLO
Capital word: WORLD
Capital word: IS
Capital word: IN
Capital word: THE
Capital word: TEST
