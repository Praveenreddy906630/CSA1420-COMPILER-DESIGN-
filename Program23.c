Implement a LEX program to check whether the mobile number is valid or not.
code:
%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[6-9][0-9]{9}    { printf("Valid Mobile Number: %s\n", yytext); }
[0-9]+           { printf("Invalid Mobile Number: %s\n", yytext); }
.                { /* Ignore other characters */ }
%%

int main() {
    printf("Enter a mobile number: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

Output:Valid Mobile Number: 9876543210
