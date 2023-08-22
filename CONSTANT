digit [0-9]
%{
int cons=0;
%}
%%
[0-9]+.[0-9]+ { cons++; printf("%s is a constant\n", yytext);  }
.|\n { }
%%
int yywrap(void) {
return 1; }
int main(void)
{
FILE *f;
char file[10];
printf("Enter File Name : ");
scanf("%s",file);
f = fopen("c.txt","r");
yyin = f;
yylex();
printf("Number of Constants : %d\n", cons);
fclose(yyin);  
}
