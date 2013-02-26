/*************************************************************************
 * stack.c
 *
 * Implements a simple stack structure for char* s.
 ************************************************************************/

// for strdup() in the testing code
#define _XOPEN_SOURCE 500

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the capacity of the stack
#define CAPACITY 10

typedef struct
{
    // storage for the elements in the stack
    char* strings[CAPACITY];

    // the number of elements currently in the stack
    int size;
}
stack;

// declare a stack (as a global variable)
stack s;

/**
 * Puts a new element into the stack onto the "top" of the data structure
 * so that it will be retrived prior to the elements already in the stack.
 */
bool push(char* str)
{
    if (s.size < CAPACITY)
    {
        s.size++;
        s.strings[s.size - 1] = str;
        return true;
    }
    else
        return false;
}

/**
 * Retrieves ("pops") the last ("top") element off of the stack, following
 * the "last-in, first-out" (LIFO) ordering of the data structure. Reduces
 * the size of the stack.
 */
char* pop(void)
{
    if (s.size > 0)
    {
        s.size--;
        return s.strings[s.size];
    }
    return NULL;
}

/**
 * Implements some simple test code for our stack
 */
int main(void)
{
    // initialize the stack
    s.size = 0;

    printf("Pushing %d strings onto the stack...", CAPACITY);
    for (int i = 0; i < CAPACITY; i++)
    {
        char str[12];
        sprintf(str, "%d", i);
        push(strdup(str));
    }
    printf("done!\n");

    printf("Making sure that the stack size is indeed %d...", CAPACITY);
    assert(s.size == CAPACITY);
    printf("good!\n");

    printf("Making sure that push() now returns false...");
    assert(!push("too much!"));
    printf("good!\n");

    printf("Popping everything off of the stack...");
    char* str_array[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        str_array[i] = pop();
    }
    printf("done!\n");

    printf("Making sure that pop() returned values in LIFO order...");
    for (int i = 0; i < CAPACITY; i++)
    {
        char str[12];
        sprintf(str, "%d", CAPACITY - i - 1);
        assert(strcmp(str_array[i], str) == 0);
        free(str_array[i]);
    }
    printf("good!\n");

    printf("Making sure that the stack is now empty...");
    assert(s.size == 0);
    printf("good!\n");

    printf("Making sure that pop() now returns NULL...");
    assert(pop() == NULL);
    printf("good!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}
