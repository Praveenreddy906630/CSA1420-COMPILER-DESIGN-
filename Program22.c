Write a LEX Program to check the email address is valid or not.

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

CODE:
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidEmail(const char *email) {
    int atCount = 0, dotCount = 0;
    int len = strlen(email);

    // Check if the email contains exactly one '@'
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atCount++;
        }
    }
    if (atCount != 1) {
        return false;
    }

    // Check if there is at least one '.' after the '@'
    const char *atPosition = strchr(email, '@');
    if (atPosition == NULL) {
        return false;
    }
    if (strchr(atPosition, '.') == NULL) {
        return false;
    }

    // Check if the local part and domain are not empty
    if (atPosition == email || atPosition == email + len - 1) {
        return false;
    }

    return true;
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline character

    if (isValidEmail(email)) {
        printf("Valid email: %s\n", email);
    } else {
        printf("Invalid email: %s\n", email);
    }

    return 0;
}
OUTPUT:
Enter an email address: praveen906630@gmail.com
Valid email: praveen906630@gmail.com
