#include <stdio.h>

#define MAXLINE 10

int getline(char s[], int lim);
int deleteSpaces(char s[]);

int main() {
    int c, len;
    char line[MAXLINE];
    while((getline(line, MAXLINE)) > 0)
    {
        if(deleteSpaces(line) > 0) // Blank line is -1, so it won't be printed
            printf("%s", line);
    }
}

int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int deleteSpaces(char s[])
{
    int i;
    i = 0;
    while(s[i] != '\n')
        ++i;
    --i; // Skip to char before '\n'
    while(i >= 0 && (s[i] == '\t' || s[i] == ' '))
        --i;
    if(i >= 0)
    {
        s[++i] = '\n';
        s[++i] = '\0';
    }
    //i = -1, means that, it is blank line
    return i;
}
