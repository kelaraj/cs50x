/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define SIZEOFHASH 46

// size counter
int sizecounter = 0;

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* hashtable[SIZEOFHASH];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char wordbuffer[strlen(word) + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] != '\'')
        {
            wordbuffer[i] = tolower(word[i]);
        }
        else
        {
            wordbuffer[i] = word[i];
        }
    }
    int h = strlen(word);
    wordbuffer[h] = '\0';

    int hashindex = h % SIZEOFHASH;
    
    //check linked list for match at correct hash index
    node* j = malloc(sizeof(node));
    j->next = hashtable[hashindex];
    
    while (j->next != NULL)
    {
        if (strcmp(wordbuffer, j->word) == 0)
        {
            return true;
        }
        j = j->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char* dictionary)
{
    // load the dictionary, and check if it actually loaded
    FILE *fp=fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    for (int j = 0; j < SIZEOFHASH; j++)
    {
        hashtable[j] = NULL;
    }
    // iterate over words in dictionary
    while (!feof(fp))
    {
        // allocate memory for each word, and read dictionary word into node
        node* newnode = malloc(sizeof(node));
        int y = fscanf(fp, "%s", newnode->word);
        if (y < 1)
        {
            free (newnode);
            break;
        }
        int h = strlen(newnode->word);
        int hashindex = h % SIZEOFHASH;

        // insert into beginning of linked list
        if (hashtable[hashindex] == NULL)
        {
            hashtable[hashindex] = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = hashtable[hashindex];
            hashtable[hashindex] = newnode;
        }
        sizecounter++;
    }
    // close the dictionary
    fclose (fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (load)
    {
        return sizecounter;
    }
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < SIZEOFHASH; i++)
    {
        while (hashtable[i] != NULL)
        {
            node * cursor = hashtable[i];
            hashtable[i] = hashtable[i]->next;
            free(hashtable[i]->word);
            free (cursor);
        }
    }
    return true;
}
