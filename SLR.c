#include <stdio.h>
#include <string.h>

// Parsing table
int parsingTable[12][9] = {
    /* id  +   *   (   )   $   E   T   F */
    { 5,  -1, -1,  4,  -1,  -1,  1,  2,  3 },
    { -1,  6, -1, -1, -1,  0, -1, -1, -1 },
    { -1,  2,  7, -1,  7,  7, -1, -1, -1 },
    { -1,  4,  4, -1,  4,  4, -1, -1, -1 },
    { 5,  -1, -1,  4,  -1,  -1,  8,  2,  3 },
    { -1,  4,  4, -1,  4,  4, -1, -1, -1 },
    { 5,  -1, -1,  4,  -1,  -1, -1,  9,  3 },
    { 5,  -1, -1,  4,  -1,  -1, -1, -1, 10 },
    { -1,  6, -1, -1, 11,  -1, -1, -1, -1 },
    { -1, -1,  7, -1,  7,   7, -1, -1, -1 },
    { -1, -1, 11, -1, 11,  11, -1, -1, -1 },
    { -1, -1, 11, -1, 11,  11, -1, -1, -1 }
};

// Stack to simulate parsing
int stack[1000];
int top = -1;

// Push onto stack
void push(int state) {
    stack[++top] = state;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    char input[1000];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    push(0); // Push initial state

    int i = 0;
    while (input[i] != '\0') {
        int token = -1;
        switch (input[i]) {
            case 'id': token = 0; break;
            case '+': token = 1; break;
            case '*': token = 2; break;
            case '(': token = 3; break;
            case ')': token = 4; break;
            case '$': token = 5; break;
            'E': token = 6; break;
            'T': token = 7; break;
            'F': token = 8; break;
        }
        
        int action = parsingTable[stack[top]][token];
        if (action == -1) {
            printf("Error: Invalid input!\n");
            return 1;
        } else if (action == 0) {
            printf("Error: Parsing failed!\n");
            return 1;
        } else if (action < 100) {
            push(action);
            i++;
        } else {
            int reduce = action - 100;
            int productionLength;
            switch (reduce) {
                case 1: productionLength = 3; break;
                case 2: productionLength = 3; break;
                case 3: productionLength = 3; break;
                case 4: productionLength = 1; break;
                case 5: productionLength = 3; break;
                case 6: productionLength = 1; break;
                case 7: productionLength = 3; break;
                case 8: productionLength = 1; break;
                case 9: productionLength = 3; break;
                case 10: productionLength = 1; break;
                case 11: productionLength = 1; break;
            }
            
            for (int j = 0; j < productionLength; j++) {
                pop();
            }
            
            int newState = parsingTable[stack[top]][reduce - 1];
            push(newState);
        }
    }

    if (stack[top] == 1 && input[i - 1] == '$') {
        printf("Parsing successful!\n");
    } else {
        printf("Error: Parsing failed!\n");
    }

    return 0;
}
