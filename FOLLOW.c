#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10

// Production rules
char productions[MAX_NON_TERMINALS][20];
int numProductions = 0;

// Follow sets
char followSets[MAX_NON_TERMINALS][MAX_TERMINALS];
int numFollowSets = 0;

// Function to add a character to a set
void addToSet(char *set, char c) {
    if (strchr(set, c) == NULL) {
        set[strlen(set)] = c;
    }
}

// Function to calculate FOLLOW set
void calculateFollowSet(char nonTerminal) {
    char set[MAX_TERMINALS] = "";
    if (nonTerminal == productions[0][0]) {
        addToSet(set, '$'); // $ for the start symbol
    }

    for (int i = 0; i < numProductions; i++) {
        char *rhs = strchr(productions[i], '>');
        if (rhs != NULL) {
            rhs++; // Move to the right-hand side of the production
            while (*rhs != '\0') {
                if (*rhs == nonTerminal) {
                    if (*(rhs + 1) == '\0') {
                        calculateFollowSet(productions[i][0]);
                        addToSet(set, '\0');
                    } else {
                        char *firstSet = strchr(followSets[nonTerminal - 'A'], '\0');
                        addToSet(set, *(firstSet + 1));
                    }
                }
                rhs++;
            }
        }
    }

    strcpy(followSets[nonTerminal - 'A'], set);
    numFollowSets++;
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // Consume the newline character

    printf("Enter the productions (one per line):\n");
    for (int i = 0; i < numProductions; i++) {
        fgets(productions[i], sizeof(productions[i]), stdin);
    }

    // Initialize followSets
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        strcpy(followSets[i], "");
    }

    // Calculate FOLLOW sets
    for (int i = 0; i < numProductions; i++) {
        calculateFollowSet(productions[i][0]);
    }

    // Print the calculated FOLLOW sets
    printf("FOLLOW sets:\n");
    for (int i = 0; i < numFollowSets; i++) {
        printf("FOLLOW(%c) = {%s}\n", 'A' + i, followSets[i]);
    }

    return 0;
}
