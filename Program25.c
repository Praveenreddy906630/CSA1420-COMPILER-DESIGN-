Write a LEX program to check whether the given input is digit or not.
code:
%{
#include <stdio.h>
%}

%%

[0-9]    { printf("Digit: %s\n", yytext); }
.        { printf("Not a Digit: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}


Input :
5
A
8
$
Output:
Digit: 5
Not a Digit: A
Digit: 8
Not a Digit: $
