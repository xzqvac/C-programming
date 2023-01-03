#include <stdio.h>

#define MAXLINE 10

void reverse(char line[]);
int getline(char s[], int lim);
void copy(char to[], const char from[]);

int main()
{
    char orgline[MAXLINE];

    while((getline(orgline, MAXLINE)) > 0)
    {
        reverse(orgline);
        printf("%s", orgline);
    }
}

int getline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if(i < lim - 2)
        {
            s[j] = c;
            ++j;
        }
    if (c == '\n')
    {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

void reverse(char line[])
{

    int len, i;
    char reversed[MAXLINE];
    char temp[MAXLINE];

    len = 0;
    copy(temp, line);
    while(line[len] != '\0')
        ++len;
    --len;
    if(line[len] == '\n')
        --len;

    for(i = 0; i <= len; i++)
    {
        line[i] = temp[len - i];
    }

}

void copy(char to[], const char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

