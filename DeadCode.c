#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isUnconditionalBranch(const char *line) {
    return strstr(line, "return") || strstr(line, "exit(");
}

int main() {
    printf("Enter your code (type 'exit' to end input):\n");
    char code[1000];
    char input[100];
    bool isDeadCode = false;

    code[0] = '\0';

    while (1) {
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        strcat(code, input);

        if (isUnconditionalBranch(input)) {
            isDeadCode = true;
        }
    }

    printf("\nOriginal code:\n%s", code);

    if (isDeadCode) {
        printf("\nCode after elimination of dead code:\n");

        char *line = strtok(code, "\n");
        while (line != NULL) {
            if (!isUnconditionalBranch(line)) {
                printf("%s\n", line);
            } else {
                printf("... (Dead Code)\n");
                break;
            }
            line = strtok(NULL, "\n");
        }
    } else {
        printf("\nNo dead code detected.\n");
    }

    return 0;
}
