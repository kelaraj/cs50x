/**********************************
 *Dev Mehta
 *dpmehta02@gmail.com
 *A program that asks a user how much change is owed, and then splits the amount into the least amount of coins
 *Instructed to use GetFloat to accept the user input, and printf to output the answer
 **********************************/
 
 #include <stdio.h>
 #include <cs50.h>
 #include <math.h>
 
 int main(void)
 {
    //ask the user how much change is needed (non-negative required), convert to cents, round
    float x;
    int y;
    do
    {
    printf("How much change do you need? ");
    x = (100*GetFloat());
    y = roundf(x);
    }
    while (x < 0);
    //divide total by quarters, dimes, nickels, pennies, add + print total
    int q = y / 25;
    int d = (y - (25 * q)) / 10;
    int n = (y - ((25 * q) + (10 * d))) / 5;
    int p = (y - ((25 * q) + (10 * d) + (5 * n)));
    int t = q + d + n + p;
    printf("%d\n", t);
    return 0;
 }
