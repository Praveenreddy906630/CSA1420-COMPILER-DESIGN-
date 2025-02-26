{\rtf1\ansi\ansicpg1252\deff0\nouicompat\deflang1033{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Riched20 10.0.22621}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\f0\fs22\lang9 Write a C program to find FIRST( ) - predictive parser for the given grammar\par
\par
#include <stdio.h>\par
#include <stdlib.h>\par
#include <string.h>\par
\par
#define MAX 100\par
#define MAX_PRODUCTIONS 50\par
#define MAX_SYMBOLS 10\par
\par
char productions[MAX_PRODUCTIONS][MAX_SYMBOLS];\par
char first[MAX][MAX_SYMBOLS];\par
int numProductions;\par
\par
void initializeFirst() \{\par
    for (int i = 0; i < MAX; i++) \{\par
        first[i][0] = '\\0'; // Initialize FIRST sets\par
    \}\par
\}\par
\par
int isTerminal(char c) \{\par
    return (c >= 'a' && c <= 'z'); // Assuming lowercase letters are terminals\par
\}\par
\par
void addToFirst(char nonTerminal, char terminal) \{\par
    int index = nonTerminal - 'A'; // Assuming non-terminals are uppercase letters\par
    if (strchr(first[index], terminal) == NULL) \{\par
        strncat(first[index], &terminal, 1); // Add terminal to FIRST set\par
    \}\par
\}\par
\par
void computeFirst(char nonTerminal) \{\par
    int index = nonTerminal - 'A';\par
    for (int i = 0; i < numProductions; i++) \{\par
        if (productions[i][0] == nonTerminal) \{\par
            int j = 2; // Start after non-terminal and arrow\par
            while (productions[i][j] != '\\0') \{\par
                if (isTerminal(productions[i][j])) \{\par
                    addToFirst(nonTerminal, productions[i][j]);\par
                    break; // Stop after adding the first terminal\par
                \} else \{\par
                    // If it's a non-terminal, compute its FIRST set\par
                    computeFirst(productions[i][j]);\par
                    // Add FIRST set of the non-terminal to the current non-terminal's FIRST set\par
                    for (int k = 0; first[productions[i][j] - 'A'][k] != '\\0'; k++) \{\par
                        addToFirst(nonTerminal, first[productions[i][j] - 'A'][k]);\par
                    \}\par
                    // If the FIRST set contains epsilon (represented by '$'), continue\par
                    if (strchr(first[productions[i][j] - 'A'], '$') == NULL) \{\par
                        break;\par
                    \}\par
                \}\par
                j++;\par
            \}\par
        \}\par
    \}\par
\}\par
\par
void printFirstSets() \{\par
    for (int i = 0; i < MAX; i++) \{\par
        if (first[i][0] != '\\0') \{\par
            printf("FIRST(%c) = \{ ", 'A' + i);\par
            for (int j = 0; first[i][j] != '\\0'; j++) \{\par
                printf("%c ", first[i][j]);\par
            \}\par
            printf("\}\\n");\par
        \}\par
    \}\par
\}\par
\par
int main() \{\par
    printf("Enter the number of productions: ");\par
    scanf("%d", &numProductions);\par
    getchar(); // Consume newline character\par
\par
    printf("Enter the productions (e.g., A->aB | A->$):\\n");\par
    for (int i = 0; i < numProductions; i++) \{\par
        fgets(productions[i], MAX_SYMBOLS, stdin);\par
        productions[i][strcspn(productions[i], "\\n")] = 0; // Remove newline\par
    \}\par
\par
    initializeFirst();\par
\par
    for (int i = 0; i < numProductions; i++) \{\par
        computeFirst(productions[i][0]); // Compute FIRST for each non-terminal\par
    \}\par
\par
    printFirstSets();\par
\par
    return 0;\par
\}\par
OUTPUT:\par
Enter the number of productions: 2\par
Enter the productions (e.g., A->aB | A->$):\par
\par
A->aB\par
\par
\par
=== Code Execution Successful ===\par
}
