/****************************************************************************
 * recover.c
 *
 * Computer Science 50 - Dev Mehta
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (void)
{   
    //open card file
    FILE* rawdata = fopen("card.raw", "r");
    
    //check if you can open the file
    if (rawdata == NULL)
    {
        fprintf(stderr, "Could not create card.raw.\n");
        return 3;
    }

    //declare output file
    FILE* output = NULL;
    //create a counter for # of jpgs
    int jpgs = 0;
    
    //until end of rawdata
    while (!feof(rawdata))
    {
        //create a 512 space
        BYTE buffer[512];

        //name placeholder
        char jpgname[8];
        
        //test for start of jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            //close the previous file, if it exists
            if (output != NULL)
            {
                fclose(output);
            }
            //make name
            sprintf(jpgname, "%03d.jpg", jpgs);
            //open a new file
            output = fopen(jpgname, "w");
            //increment counter
            jpgs++;
            //write buffer into new file
            fwrite(buffer, sizeof(buffer), 1, output);
        }
        else
        {
            if (jpgs > 0)
            {
                //write buffer into new file
                fwrite(buffer, sizeof(buffer), 1, output);            
            }
        }
        //read 512 bytes into a buffer
        fread(buffer, sizeof(buffer), 1, rawdata);
        
    }
    //close last jpeg, if open
    if (jpgs > 0)
    {
        fclose(output);
    }
    
    //close card file
    fclose(rawdata);

    return 0;
}
