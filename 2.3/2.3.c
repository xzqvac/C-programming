#include <stdio.h>
#include <string.h>

int htoi(char s[])
{
    int result = 0;
    int weight = 1;
    int length = strlen(s);
    int digit = 0;
    for (int i = length -1; i >= 0; --i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'F')
            digit = s[i] - 'A' + 10;
        else if (s[i] >= 'a' && s[i] <= 'f')
            digit = s[i] - 'A' + 10;
        result += digit * weight;
        weight *= 16;
    }
    return result;

}

void squeeze(char s[], int c)
{
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int main()
{
    printf("%s\n", "Hello world");
    printf("%d\n", htoi("AB1"));
    char s[] = "KLAWIATURA";
    squeeze(s, 'A');
    printf("%s", s);
}