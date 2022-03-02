#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
    // kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    if (newTable == NULL) return 0;
    newTable->table =(Bin**)malloc(size * sizeof(Bin));
    if (newTable->table == NULL) return 0;

    newTable->size = size;
    newTable->load = 0;

    for (int i = 0; i <= size; i++)
        newTable->table[i] = NULL;

    return newTable;
}

unsigned int hash(char *word)
{
    // od kljuca generira hash kod
    unsigned int key = 0;
    while(*word != '\0')
    {
        key = key*HCONST + *word;
        word++;
    }
    return key;
}

Bin* createElement(char* word)
{
    Bin* newSlot = (Bin*)malloc(sizeof(Bin));
    if (newSlot == NULL) return 0;

    newSlot->word = _strdup(word);
    newSlot->next = NULL;

    return newSlot;
}

void Insert(HashTable *ht, char *word)
{
    // dodaje novu rijec u listu na odgovarajucem pretincu
    int key = hash(word) % ht->size;

    if (ht->table[key] == NULL)
        ht->table[key] = createElement(word);
    else
    {
        Bin* lastWord = ht->table[key];

        while (lastWord->next)
            lastWord = lastWord->next;
        lastWord->next = createElement(word);
    }
    (ht->load)++;
}

int Get(HashTable *ht, char *word)
{
    // vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
    int key = hash(word) % ht->size;

    return (ht->table[key] == NULL) ? 0 : 1;
}

void DeleteTable(HashTable *ht)
{
    // brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->table[i] == NULL)
            continue;
        else
        {
            Bin* curr = ht->table[i];
            while (curr)
            {
                Bin* delete = curr;
                curr = curr->next;
                free(delete->word);
                free(delete);
            }
        }
    }
}



