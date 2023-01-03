#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned righrot(unsigned x, int n);

int countLength(unsigned number);

int main()
{
    printf("%d\n", setbits(10, 2, 2, 2));
    printf("%d\n", invert(10, 3, 2));
    printf("%d\n", righrot(10, 1));

}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1)) & ~(~0 << n);    
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p + 1 -n)) | (y & ~(~0 << n) << (p + 1 -n));   
}

unsigned invert(unsigned x, int p, int n)
{
    return x & ~(~(~0 << n) << (p + 1 -n)) | ~x & (~(~0 << n) << (p + 1 -n)); 
}

unsigned righrot(unsigned x, int n)
{
    int numberLength = countLength(x);
    int modulo = n % numberLength;

    if (n == numberLength)
        return x;

    else if (n < numberLength)
        return (x >> n) | ((x & ~(~0 << n)) << (numberLength - n));
    else
        return (x >> modulo) | ((x & ~(~0 << modulo)) << (numberLength - modulo));
}

int countLength(unsigned number)
{
    int i;
    for (i = 1; (number = number >> 1) > 0; i++)
        ;
    return i;
}