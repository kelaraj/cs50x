/***********************************
 *Dev Mehta
 *Program to create Mario tower of #
 *based on user input (0-23 hashes)
 ***********************************/
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
    //get an integer 0-23
    int x;
    do
    {
    printf("Height: ");
    x = GetInt();
    }
    while (x > 23 || x < 0);
    
    //print the pyramid;
    if (x == 1)
    {
    printf("##\n");
    }
    else if (x > 1)
    {
    //calculate the number of lines
    int i;
    for (i = 0; i < x; i++)
    {
        //calculate the number of spaces
        int j;
        for (j = i; x > (j + 1); j++)
        {
        printf(" ");
        }
        //calculate the number of hashes
        int k;
        for (k = i; k + 2 > 0; k--)
        {
        printf("#");
        }    
    printf("\n");
    }   
    }
    return 0;
 }
