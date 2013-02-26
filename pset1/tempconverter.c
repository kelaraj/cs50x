/**************************************** 
 *Program to convert Celcius to Farenheit
 *Dev Mehta
 *dpmehta02@gmail.com
 ****************************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("C: ");
    float c = GetFloat();
    float f = (c*(9.0/5)) + 32;
    printf("F: %.1f\n", f);
    return 0;
}
