#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTIONS 100

// Function to check if a grammar is ambiguous
bool isAmbiguous(char productions[][50], int numProductions) {
    for (int i = 0; i < numProductions; i++) {
        for (int j = i + 1; j < numProductions; j++) {
            if (strcmp(productions[i], productions[j]) == 0) {
                return true; // Found two identical productions
            }
        }
    }
    return false; // No identical productions found
}

int main() {
    int numProductions;
    char productions[MAX_PRODUCTIONS][50];

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // Consume the newline character

    printf("Enter the productions (one per line):\n");
    for (int i = 0; i < numProductions; i++) {
        fgets(productions[i], sizeof(productions[i]), stdin);
        productions[i][strcspn(productions[i], "\n")] = '\0'; // Remove newline character
    }

    if (isAmbiguous(productions, numProductions)) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}
