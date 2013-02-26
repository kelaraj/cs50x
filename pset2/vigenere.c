/*
 * Dev Mehta
 * dpmehta02@gmail.com
 * Vigenere cipher to encrypt user input
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <ctype.h>
 #include <string.h>
 
 int main(int argc, string argv[])
 {
 if (argc == 1 || argc > 2 || argc < 2) //kicks a user out if they entered too many or too few arguments
 {
    printf("./vigenere\n");
    return 1;
 }
 
 string s = argv[1];
 for (int i = 0; i < strlen(s); i++) //checks that user input alpha, kicks user out if not
 {
    if (isalpha(s[i]) == 0)
    {
        printf("./vigenere\n");
        return 1;
    }
 }
 
 string p = GetString();
 int counter = 0;
 for (int j = 0; j < strlen(p); j++)
 {   
    if (isalpha(p[j]) == 0) //if a character is non-alpha, print it
    {
        printf("%c", p[j]);
        counter++;
    }
    else //else, apply the cipher
    {
        char h = p[j];
        int z = h; //input character as number
        
        int l = ((j - counter) % strlen(s)); //loops use of key, uses counter variable to remember where it is
        char m = s[l];
        int d = m; //key character as int
                    
        if (z > 64 || z < 91) //if input character is upper case
        {
            if (d < 91) //if key character is upper case
            {
                int e = d - 65;
                int n = e + z;             
                if (n > 90) //loops through alphabet for lower case
                {
                    int o = n - 26;
                    printf("%c", o);
                }
                else
                {
                    printf("%c", n);
                }
            }
            else // if key character is lower case
            {
                int e = d - 97;
                int n = e + z;              
                if (n > 122) //loops through alphabet for lower case
                {
                    int o = n - 26;
                    printf("%c", o);
                }
                else
                {
                    printf("%c", n);
                }
            }
        }            
    }   
}
printf("\n");
return 0;
}
