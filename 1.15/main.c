#include <stdio.h>

#define LOWER 0.0f
#define UPPER 300.0f
#define STEP 20.0f

float CelsToFahr(float temp);
float FahrToCels(float temp);

int main() {
    float cels, fahr;
    fahr = 0;
    printf("%5c %8c\n", 'F', 'C');
    while(fahr <= UPPER)
    {
        cels = FahrToCels(fahr);
        printf("%5.1f %8.1f\n", fahr, cels);
        fahr += STEP;
    }
    printf("\n%5c %8c\n", 'C', 'F');
    cels = 0;
    while(cels <= UPPER)
    {
        fahr = CelsToFahr(cels);
        printf("%5.1f %8.1f\n", cels, fahr);
        cels += STEP;
    }
}

float CelsToFahr(float temp)
{
    float result;
    result = (temp * 9.0)/5.0 + 32.0;
    return result;
}

float FahrToCels(float temp)
{
    float result;
    result = (temp - 32.0) * 5.0 / 9.0;
    return result;
}