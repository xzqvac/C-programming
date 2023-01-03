#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80
#define RIGHT 1
#define FALSE 0

int getline(char line[], int limit);

int main() {
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if(len > MINLINE)
            printf("%s", line);
    }
    return 0;
}

int getline(char line[], int limit)
{
    int i, j, c;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < limit - 2) // Keep place for 'n' and '\0' in char table
        {
            line[j] = c;
            ++j;
        }
    if (c == '\n')
    {
        line[j] = c;
        ++i;
        ++j;
    }
    line[i] = '\0';
    return i;
}
