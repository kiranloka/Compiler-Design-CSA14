%{
#include <stdio.h>
%}

%option noyywrap

%%
int|float|char|if|else|while|for   { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*             { printf("Identifier: %s\n", yytext); }
.|\n                              { /* Ignore all other characters */ }
%%

int main() {
    yylex();
    return 0;
}
