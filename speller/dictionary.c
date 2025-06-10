// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 27 * 27 *27;

// Hash table
node *table[N];

unsigned int dict_size = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char w[len + 1];
    strcpy(w, word);

    for (int i = 0; i < len; i ++)
    {
        w[i] = tolower(w[i]);
    }
    w[len] = '\0';

    for (node *n = table[hash(w)]; n != NULL; n = n->next)
    {
        if (strcmp(n->word, w) ==  0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int L = 4;
    int len = strlen(word);
    unsigned int hv = 0;

    int x = fmin(len, L);

    for (int i = 0; i < x; i ++)
    {
        if (isalpha(word[i]))
        {
            hv = hv * 27 + word[i] - 'a';
        }

        else
        {
            hv = hv * 27 + 26;
        }
    }

    if (len < L)
    {
        for (int i = 0; i < L - len; i ++)
        {
            hv = hv * 27 + 26;
        }
    }
return hv % N;

}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(dict, "%s", buffer) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }

        for (int i = 0; buffer[i] != '\0' && i < LENGTH; i++)
        {
            n->word[i] = tolower((unsigned char)buffer[i]);
        }
        n->word[strlen(buffer) < LENGTH ? strlen(buffer) : LENGTH] = '\0';

        n->next = table[hash(n->word)];
        table[hash(n->word)] = n;

        dict_size ++;

    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i ++)
    {
        node *n = table[i];

        while (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    dict_size = 0;
    return true;
}

