/*
 * Dev Mehta
 * dpmehta02@gmail.com
 * This is a program that encrypts a message, based on a user's input, using Caesar's Cypher
 *
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1) // kicks user out if incorrect number of arguments, or negative second argument
    {
    printf("./caesar\n");
    return 1;
    }
    else if (argc > 2 || argc < 1 || atoi(argv[1]) < 0)
    {
        return 1;
    }
    else
    {
    int k = ((atoi(argv[1])) % 26); //calculate the shift    
    
    //ask the user for a string input
    string s = GetString();
 
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i])) // if a letter
        {
            char u = s[i];
            int v = u;
            if (isupper(s[i])) // if capital letter
            {
                if (v + k > 90)
                {
                    int w = ((v + k) - 26);
                    printf("%c", w);
                }
                else
                {
                    int w = v + k;
                    printf("%c", w);
                }
            }
            else // through logic, has to be lowercase letters
            {
                if (v + k > 122)
                {
                    int w = ((v + k) - 26);
                    printf("%c", w);
                }
                else
                {
                    int w = v + k;
                    printf("%c", w);
                }                
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
    }
}
