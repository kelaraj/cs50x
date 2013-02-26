/****************************************************************************
 * dictionary.c
 *
 * cs50x
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// prototype
int hash(const char *word);

// global word varialbes
char word[LENGTH + 1];
int word_count = 0;

typedef struct node 
{
    char *word;
    struct node *next;
} node;

node *hasht[HT_SIZE];

// check if word is in dictionary

bool check(const char *word)
{
    node *newnode = malloc(sizeof(newnode));
    int hashv = hash(word);
    newnode = hasht[hashv];
    
    while(newnode != NULL) 
    {
        if (strcasecmp(word, newnode->word) == 0)
        {
	        return true;
        }
        newnode = newnode->next;
    }
    return false;
}


// loads dictionary

bool load(const char *dictionary)
{
    FILE *fp = NULL;
    int hv;
 
    for (int i = 0; i < HT_SIZE; i++) 
    {
        hasht[i] = NULL;
    }

    if (!(fp = fopen(dictionary, "r")))
    {
        return false;
    }
  

    while (fscanf(fp,"%s\n",word) != EOF)
    {
        node *nodep = malloc(sizeof(node));
        nodep->word = malloc(strlen(word) +1);
        strcpy(nodep->word,word);
    
        hv = hash(word);
  
        word_count++;
    
    if(hasht[hv] == NULL)
    {
    	hasht[hv] = nodep;
	    nodep->next = NULL;
    }
    else 
    {
	    nodep->next = hasht[hv];
	    hasht[hv] = nodep;
    }
  }
  
  return true;
}

// # of words loaded in dictionary

unsigned int size(void)
{
  return word_count;
}

//unloads the dictionary
bool unload(void)
{
    node *nextnodep,*nodep;
    
    for (int i = 0; i<HT_SIZE; i++)
    {
        nodep = hasht[i];
        while (nodep)
        {
	        free(nodep->word);
	        nextnodep  = nodep->next;
	        free(nodep);
	        nodep = nextnodep;
        }   
        hasht[i] = NULL;
    }
  
  return true;
}


int hash(const char *word) 
{
    int len = strlen(word);
    int hash = 0;

    for(int i = 0; i < len; i++)
    {
        int x = word[i];
        if (x > 64 && x < 91)
        {
            hash += word[i] + 32;
        }
        else
        {
            hash += word[i];
        }
    }
    
    return hash % HT_SIZE; 
}
