#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for (i, j = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
            ;
        if (s2[k] == '\0')
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int any(char s1[], char s2[])
{
    int i, k;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for(k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k])
                return i;
        }
    }
         return -1;
}

int main()
{
    char s1[] = "MELATONINA";
    char s2[] = "M";
    //squeeze(s1, s2);

    //printf("%s", s1);
    printf("%d", any(s1, s2));
}