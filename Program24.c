Write a LEX program to count the number of vowels in the given sentence.
code:
%{
#include <stdio.h>
int vowel_count = 0;
%}

%%
[aAeEiIoOuU] { vowel_count++; }
.   ;  // Ignore other characters
\n  return 0; // Stop reading input on a new line
%%

int main() {
    printf("Enter a sentence: ");
    yylex(); // Invoke the lexer
    printf("Number of vowels: %d\n", vowel_count);
    return 0;
}

int yywrap() {
    return 1;
}
input:Enter a sentence: Hello, how are you?
Output:Number of vowels: 7
