#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isKeyword(char *token) {
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;  
        }
    }

    return 0;  
}


void tokenizeSourceCode(char *sourceCode) {
    char delimiters[] = " \t\n(){};=";
    char *token;

    token = strtok(sourceCode, delimiters);
    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isalpha(token[0])) {
            printf("Identifier: %s\n", token);
        } else {
            printf("Other: %s\n", token);
        }
        token = strtok(NULL, delimiters);
    }
}

int main() {
    char sourceCode[1000];  

    printf("Enter your  source code:\n");
    fgets(sourceCode, sizeof(sourceCode), stdin);

    tokenizeSourceCode(sourceCode);

    return 0;
}
