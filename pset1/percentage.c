/********************************************
 *prompts the user for two integers, a non-negative numerator and a positive denominator,
 *and then displays numerator ÷ denominator as a percentage to 2 decimal places
 *
 ********************************************/
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get first number
    float x;
    do
    {
    printf("non-negative numerator: ");
    x = GetFloat();
    }
    while (x < 0);
    
    //Get second number
    float y;
    do
    {
    printf("positive denominator: ");
    y = GetFloat();
    }
    while (y <= 0);
    
    //calculate and print percentage
    float z = (x/y)*100;
    printf("%.2f%%\n", z);
    
    return 0;        
}
